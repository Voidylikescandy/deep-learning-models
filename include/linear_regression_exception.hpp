#ifndef LINEAR_REGRESSION_EXCEPTION_HPP
#define LINEAR_REGRESSION_EXCEPTION_HPP

#include <exception>
#include <string>

class LinearRegressionException : public std::exception
{
  public:
    explicit LinearRegressionException(const std::string& message)
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

#endif // LINEAR_REGRESSION_EXCEPTION_HPP