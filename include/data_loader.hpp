#ifndef DATA_LOADER_HPP
#define DATA_LOADER_HPP

#include "constants.hpp"
#include <string>

class DataLoader
{
  public:
    static SingleFeatureSingleTargetData loadData(const std::string& filename);
};

#endif // DATA_LOADER_HPP