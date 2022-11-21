#include <iostream>
#include <thread>
#include <vector>

class ScopedThread {
private:
  std::thread t;

public:
  explicit ScopedThread(std::thread t_) : t{std::move(t_)} {
    if (!t.joinable()) {
      throw std::logic_error("No thread");
    }
  }

  ~ScopedThread() { t.join(); }

  ScopedThread(ScopedThread const &) = delete;
  ScopedThread &operator=(ScopedThread const &) = delete;
};

void heartbeat() {
  while (true) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Heartbeat! Thread ID: " << std::this_thread::get_id()
              << std::endl;
  }
}

std::vector<double> init(int n) {
  std::thread t_{heartbeat};
  // NOTE: move because copy is not allowed
  ScopedThread t{std::move(t_)};

  std::vector<double> vec(n);
  for (int i = 0; i < n; ++i) {
    vec[i] = 777;
  }

  // NOTE: move because copy is unwanted for large vectors
  return vec;
}

int main() { auto v = init(1'000'000); }
