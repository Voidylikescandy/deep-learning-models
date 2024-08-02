#include "data_loader.hpp"
#include "model_exception.hpp"
#include <gtest/gtest.h>

TEST(DataLoaderTest, LoadDataSuccess)
{
    SingleFeatureSingleTargetData sfst_data =
      DataLoader::loadSingleFeatureSingleTargetData("../data/sfst_data.txt");
    EXPECT_EQ(sfst_data.size(), 6);

    MultiFeatureSingleTargetData mfst_data =
      DataLoader::loadMultiFeatureSingleTargetData("../data/mfst_data.txt");
    EXPECT_EQ(mfst_data.size(), 6);
}

TEST(DataLoaderTest, LoadDataFileNotFound)
{
    EXPECT_THROW(
      DataLoader::loadSingleFeatureSingleTargetData("non_existent_file.txt"),
      ModelException);

    EXPECT_THROW(
      DataLoader::loadMultiFeatureSingleTargetData("non_existent_file.txt"),
      ModelException);
}
