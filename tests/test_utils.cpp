#include "model_exception.hpp"
#include "utils.hpp"
#include <gtest/gtest.h>

TEST(UtilsTest, SplitData)
{
  SingleFeatureSingleTargetData data = { { 1, 1 },  { 2, 2 }, { 3, 3 },
                                         { 4, 4 },  { 5, 5 }, { 6, 6 },
                                         { 7, 7 },  { 8, 8 }, { 9, 9 },
                                         { 10, 10 } };
  SingleFeatureSingleTargetData train, validation, test;
  Utils::splitData(data, train, validation, test, 0.6, 0.2);

  EXPECT_EQ(train.size(), 6);
  EXPECT_EQ(validation.size(), 2);
  EXPECT_EQ(test.size(), 2);
}

TEST(UtilsTest, InvalidRatio)
{
  SingleFeatureSingleTargetData data, train, validation, test;
  EXPECT_THROW(Utils::splitData(data, train, validation, test, 1.0, 1.0),
               ModelException);
}