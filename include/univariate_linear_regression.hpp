#ifndef UNIVARIATE_LINEAR_REGRESSION_HPP
#define UNIVARIATE_LINEAR_REGRESSION_HPP

#include "constants.hpp"

class UnivariateLinearRegression
{
  public:
    UnivariateLinearRegression(double alpha, int iterations);
    void fit(const SingleFeatureSingleTargetData& data);
    double predict(double x) const;

  private:
    double alpha;
    int iterations;
    double theta0;
    double theta1;

    double computeCost(const SingleFeatureSingleTargetData& data) const;
};

#endif // UNIVARIATE_LINEAR_REGRESSION_HPP
