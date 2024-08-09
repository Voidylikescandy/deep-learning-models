#ifndef MODEL_EXCEPTION_HPP
#define MODEL_EXCEPTION_HPP

#include <exception>
#include <string>

class ModelException : public std::exception
{
public:
  explicit ModelException(const std::string& message)
    : message_(message)
  {
  }

  virtual const char* what() const noexcept override
  {
    return message_.c_str();
  }

private:
  std::string message_;
};

#endif // MODEL_EXCEPTION_HPP