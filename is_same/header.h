template< typename X >
typename std::enable_if<std::is_same<std::basic_string<X>, double >::value, int>::type foo(X const *v) {
  return 2;
}
