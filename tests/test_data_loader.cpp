#include "data_loader.hpp"
#include "model_exception.hpp"
#include <gtest/gtest.h>

TEST(DataLoaderTest, LoadDataSuccess)
{
    SingleFeatureSingleTargetData data =
      DataLoader::loadSingleFeatureSingleTargetData("../data/sfst_data.txt");
    EXPECT_EQ(data.size(), 6); // Assuming sfst_data.txt has 6 lines of data
}

TEST(DataLoaderTest, LoadDataFileNotFound)
{
    EXPECT_THROW(
      DataLoader::loadSingleFeatureSingleTargetData("non_existent_file.txt"),
      ModelException);
}
