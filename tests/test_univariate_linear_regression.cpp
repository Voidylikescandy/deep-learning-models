#include "univariate_linear_regression.hpp"
#include <gtest/gtest.h>

TEST(UnivariateLinearRegressionTest, Fit)
{
    std::vector<std::pair<double, double>> data = {
        { 500, 500 }, { 600, 600 }, { 700, 700 },
        { 800, 800 }, { 900, 900 }, { 1000, 1000 }
    };
    UnivariateLinearRegression model(0.000001, 100);
    model.fit(data);
    EXPECT_NEAR(model.predict(500), 500, 10);
    EXPECT_NEAR(model.predict(1000), 1000, 10);
}
