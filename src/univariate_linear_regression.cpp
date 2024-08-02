#include "univariate_linear_regression.hpp"
#include "logging.hpp"
#include "model_exception.hpp"
#include <cmath>

UnivariateLinearRegression::UnivariateLinearRegression(double alpha,
                                                       int iterations)
  : alpha(alpha)
  , iterations(iterations)
{
    theta0 = 0.5;
    theta1 = 0.5;

    if (alpha <= 0) {
        MODEL_LOG_ERROR("Invalid alpha value.");
        throw ModelException("Alpha must be positive.");
    }
    if (iterations <= 0) {
        MODEL_LOG_ERROR("Invalid iterations value.");
        throw ModelException("Iterations must be positive.");
    }
    MODEL_LOG_INFO("UnivariateLinearRegression initialized with alpha = " +
                   std::to_string(alpha) +
                   ", iterations = " + std::to_string(iterations));
}

void
UnivariateLinearRegression::fit(const SingleFeatureSingleTargetData& data)
{
    int m = data.size();
    MODEL_LOG_INFO("Starting fit with " + std::to_string(m) + " data points.");

    if (m == 0) {
        MODEL_LOG_ERROR("Size of data is 0.");
        throw ModelException("Training data is empty.");
    }

    for (int iter = 0; iter < iterations; ++iter) {
        double sum0 = 0;
        double sum1 = 0;

        for (const auto& [x, y] : data) {
            double h = predict(x);
            sum0 += (h - y);
            sum1 += (h - y) * x;
        }

        theta0 -= alpha * (1.0 / m) * sum0;
        theta1 -= alpha * (1.0 / m) * sum1;

        double cost = computeCost(data);
        MODEL_LOG_DEBUG("Iteration " + std::to_string(iter + 1) +
                        ": Cost = " + std::to_string(cost) +
                        ", "
                        "theta0 = " +
                        std::to_string(theta0) +
                        ", theta1 = " + std::to_string(theta1));

        if (std::isnan(cost) || std::isnan(theta0) || std::isnan(theta1) ||
            std::isinf(cost) || std::isinf(theta0) || std::isinf(theta1)) {
            MODEL_LOG_ERROR("Numerical issues detected. Halting training.");
            throw ModelException("Numerical issues detected during training.");
        }
    }
    MODEL_LOG_INFO("Finished fit.");
}

double
UnivariateLinearRegression::predict(double x) const
{
    return theta0 + theta1 * x;
}

double
UnivariateLinearRegression::computeCost(
  const SingleFeatureSingleTargetData& data) const
{
    double totalCost = 0;
    int m = data.size();
    for (const auto& [x, y] : data) {
        double h = predict(x);
        totalCost += std::pow(h - y, 2);
    }
    return totalCost / (2 * m);
}