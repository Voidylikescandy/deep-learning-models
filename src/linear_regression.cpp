#include "linear_regression.hpp"
#include "model_exception.hpp"
#include "spdlog/spdlog.h"
#include <cmath>
#include <iostream>

LinearRegression::LinearRegression(double alpha, int iterations)
  : alpha(alpha)
  , iterations(iterations)
  , theta0(0.5)
  , theta1(0.5)
{
    spdlog::info(
      "LinearRegression initialized with alpha = {}, iterations = {}",
      alpha,
      iterations);
}

void
LinearRegression::fit(const std::vector<std::pair<double, double>>& data)
{
    int m = data.size();
    spdlog::info("Starting fit with {} data points.", m);

    if (m == 0) {
        spdlog::error("Size of data is 0.");
        throw ModelException("Training data is empty.");
    }

    for (int iter = 0; iter < iterations; ++iter) {
        double sum0 = 0;
        double sum1 = 0;

        for (const auto& [x, y] : data) {
            double h = theta0 + theta1 * x;
            sum0 += (h - y);
            sum1 += (h - y) * x;
        }

        theta0 -= alpha * (1.0 / m) * sum0;
        theta1 -= alpha * (1.0 / m) * sum1;

        double cost = computeCost(data);
        spdlog::debug("Iteration {}: Cost = {}, theta0 = {}, theta1 = {}",
                      iter + 1,
                      cost,
                      theta0,
                      theta1);

        if (std::isnan(cost) || std::isnan(theta0) || std::isnan(theta1) ||
            std::isinf(cost) || std::isinf(theta0) || std::isinf(theta1)) {
            spdlog::error("Numerical issues detected. Halting training.");
            throw ModelException("Numerical issues detected during training.");
        }
    }

    spdlog::info("Finished fit.");
}

double
LinearRegression::predict(double x) const
{
    return theta0 + theta1 * x;
}

double
LinearRegression::computeCost(
  const std::vector<std::pair<double, double>>& data) const
{
    double totalCost = 0;
    int m = data.size();
    for (const auto& [x, y] : data) {
        double h = theta0 + theta1 * x;
        totalCost += std::pow(h - y, 2);
    }
    return totalCost / (2 * m);
}