#ifndef LINEAR_REGRESSION_HPP
#define LINEAR_REGRESSION_HPP

#include <utility>
#include <vector>

class LinearRegression
{
  public:
    LinearRegression(double alpha, int iterations);
    void fit(const std::vector<std::pair<double, double>>& data);
    double predict(double x) const;

  private:
    double alpha;
    int iterations;
    double theta0;
    double theta1;

    double computeCost(
      const std::vector<std::pair<double, double>>& data) const;
};

#endif // LINEAR_REGRESSION_HPP
