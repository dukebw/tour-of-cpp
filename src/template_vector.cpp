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

int main() {
  Vector<char> vc(200);
  Vector<double> v(1);
}
