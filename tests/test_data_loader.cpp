#include "data_loader.hpp"
#include "model_exception.hpp"
#include <gtest/gtest.h>

TEST(DataLoaderTest, LoadDataSuccess)
{
    std::vector<std::pair<double, double>> data =
      DataLoader::loadData("../data/data.txt");
    EXPECT_EQ(data.size(), 6); // Assuming data.txt has 6 lines of data
}

TEST(DataLoaderTest, LoadDataFileNotFound)
{
    EXPECT_THROW(DataLoader::loadData("non_existent_file.txt"), ModelException);
}
