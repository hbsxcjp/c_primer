#include <iostream>

void c2_1() {
  unsigned u = 10, u2 = 42;
  std::cout << u2 - u << std::endl; // 32
  std::cout << u - u2 << std::endl; // ?

  int i = 10, i2 = 42;
  std::cout << i2 - i << std::endl; // 32
  std::cout << i - i2 << std::endl; // -32
  std::cout << i - u << std::endl;  // 0
  std::cout << u - i << std::endl;  // 0

  std::cout << u8"Hi!陈建平" << std::endl;                       // ?
  std::cout << 'a' << L'a' << "a" << L"a" << L'陈' << std::endl; // ?
  std::cout << "2\tM\n" << std::endl;                            // ?
}

void c2_3() {
  int i = 10, j = 20;
  int *pi = &i, *pj = &j;
  std::cout << i << " " << *pi << std::endl; // 10 10
  i = j;
  std::cout << i << " " << *pi << std::endl; // 20 20
  j = 30;
  pi = pj;
  std::cout << i << " " << *pi << std::endl; // 20 30
}

int main() {
  // c2_1();
  c2_3();

  return 0;
}