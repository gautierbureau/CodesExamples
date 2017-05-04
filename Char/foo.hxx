
template <class T>
void foo2(T& message)
{
  std::cout << "length " << std::strlen(message) << std::endl;
  std::cout << "value " << message << std::endl;
}


template <class T>
void foo2(const T& message)
{
  std::cout << "length " << std::strlen(message) << std::endl;
  std::cout << "value " << message << std::endl;
}
