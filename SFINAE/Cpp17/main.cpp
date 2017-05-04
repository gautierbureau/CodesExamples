#include <iostream>
#include <type_traits>

template <typename T>
using has_typedef_foobar_t = decltype(T::foobar);

struct foo {
  using foobar = float;
};

int main() {
  std::cout << std::boolalpha;
  std::cout << std::is_detected<has_typedef_foobar_t, int>::value << std::endl;
  std::cout << std::is_detected<has_typedef_foobar_t, foo>::value << std::endl;
}

// Not working ? std::experimental::is_detected