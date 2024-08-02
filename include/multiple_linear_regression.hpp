#ifndef MULTIPLE_LINEAR_REGRESSION_HPP
#define MULTIPLE_LINEAR_REGRESSION_HPP

#include "constants.hpp"

class MultipleLinearRegression
{
  public:
    MultipleLinearRegression(double alpha, int iterations, int numFeatures);
    void fit(const MultiFeatureSingleTargetData& data);
    double predict(std::vector<double> x) const;

  private:
    double alpha;
    int iterations;
    int numFeatures;
    std::vector<double> theta;

    double computeCost(const MultiFeatureSingleTargetData& data) const;
};

#endif // MULTIPLE_LINEAR_REGRESSION_HPP