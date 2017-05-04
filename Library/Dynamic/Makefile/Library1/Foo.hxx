
inline void Foo::SetMessage(std::string message)
{
    message_ = message;
}

inline const std::string Foo::GetMessage() const
{
    return message_;
}
