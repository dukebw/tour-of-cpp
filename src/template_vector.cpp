#include <algorithm>
#include <iostream>
#include <stdexcept>

template <typename T>
class Vector {
private:
  T *elem;
  int sz;

public:
  explicit Vector(int n);
  ~Vector() { delete[] elem; }

  // copy and move operations...

  T &operator[](int i);
  int size() { return sz; }
};

template <typename T>
Vector<T>::Vector(int n) {
  if (n < 0) {
    throw std::length_error{"Vector::Vector"};
  }

  elem = new T[n];
  sz = n;
}

template <typename T>
T &Vector<T>::operator[](int i) {
  if ((i < 0) || (i >= size())) {
    throw std::out_of_range{"Vector::operator[]"};
  }

  return elem[i];
}

template <typename T>
T *begin(Vector<T> &v) {
  if (v.size() == 0) {
    return nullptr;
  }

  return &v[0];
}

template <typename T>
T *end(Vector<T> &v) {
  if (v.size() == 0) {
    return nullptr;
  }

  return begin(v) + v.size();
}

int main() {
  Vector<char> vc(200);
  std::fill(begin(vc), end(vc), 'a');
  for (auto c : vc) {
    std::cout << c << std::endl;
  }

  Vector<double> v(1);
}
