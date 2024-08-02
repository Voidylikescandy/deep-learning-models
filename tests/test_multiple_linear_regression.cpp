#include "multiple_linear_regression.hpp"
#include <gtest/gtest.h>

TEST(MultipleLinearRegressionTest, Fit)
{
    MultiFeatureSingleTargetData data = {
        { { 500 }, 500 }, { { 600 }, 600 }, { { 700 }, 700 },
        { { 800 }, 800 }, { { 900 }, 900 }, { { 1000 }, 1000 }
    };
    MultipleLinearRegression model(0.000001, 100, 1);
    model.fit(data);
    EXPECT_NEAR(model.predict({ 500 }), 500, 10);
    EXPECT_NEAR(model.predict({ 1000 }), 1000, 10);
}
