#include "multiple_linear_regression.hpp"
#include "logging.hpp"
#include "model_exception.hpp"
#include <cmath>
#include <numeric>

MultipleLinearRegression::MultipleLinearRegression(double alpha,
                                                   int iterations,
                                                   int numFeatures)
  : alpha(alpha)
  , iterations(iterations)
  , numFeatures(numFeatures)
{
  theta.assign(numFeatures + 1, 0.5);

  if (alpha <= 0) {
    MODEL_LOG_ERROR("Invalid alpha value.");
    throw ModelException("Alpha must be positive.");
  }
  if (iterations <= 0) {
    MODEL_LOG_ERROR("Invalid iterations value.");
    throw ModelException("Iterations must be positive.");
  }
  MODEL_LOG_INFO("MultipleLinearRegression initialized with alpha = " +
                 std::to_string(alpha) +
                 ", iterations = " + std::to_string(iterations));
}

void
MultipleLinearRegression::fit(const MultiFeatureSingleTargetData& data)
{
  int m = data.size();
  MODEL_LOG_INFO("Starting fit with " + std::to_string(m) + " data points.");

  if (m == 0) {
    MODEL_LOG_ERROR("Size of data is 0.");
    throw ModelException("Training data is empty.");
  }

  for (int iter = 0; iter < iterations; ++iter) {
    std::vector<double> sum(numFeatures + 1, 0);

    for (const auto& [x, y] : data) {
      double h = predict(x);

      sum[0] += (h - y);
      for (size_t i = 0; i < x.size(); ++i) {
        sum[i + 1] += (h - y) * x[i];
      }
    }

    for (size_t i = 0; i < theta.size(); ++i) {
      theta[i] -= alpha * (1.0 / m) * sum[i];
    }

    double cost = computeCost(data);
    MODEL_LOG_DEBUG("Iteration " + std::to_string(iter + 1) +
                    ": Cost = " + std::to_string(cost));

    if (std::isnan(cost) || std::isinf(cost)) {
      MODEL_LOG_ERROR("Numerical issues detected in cost. Halting training.");
      throw ModelException("Numerical issues detected during training.");
    }
    for (const auto& theta_value : theta) {
      if (std::isnan(theta_value) || std::isinf(theta_value)) {
        MODEL_LOG_ERROR(
          "Numerical issues detected in theta. Halting training.");
        throw ModelException("Numerical issues detected during training.");
      }
    }
  }
  MODEL_LOG_INFO("Finished fit.");
}

double
MultipleLinearRegression::predict(std::vector<double> x) const
{
  if (x.size() + 1 != theta.size()) {
    MODEL_LOG_ERROR("Expected size of x = " + std::to_string(theta.size() - 1) +
                    ", given = " + std::to_string(x.size()));
    throw ModelException(
      "Size of input vector x must be one less than size of theta vector.");
  }

  double result = theta[0];
  result += std::inner_product(x.begin(), x.end(), theta.begin() + 1, 0.0);

  return result;
}

double
MultipleLinearRegression::computeCost(
  const MultiFeatureSingleTargetData& data) const
{
  double totalCost = 0;
  int m = data.size();
  for (const auto& [x, y] : data) {
    double h = predict(x);
    totalCost += std::pow(h - y, 2);
  }
  return totalCost / (2 * m);
}