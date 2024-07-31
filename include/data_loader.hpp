#ifndef DATA_LOADER_HPP
#define DATA_LOADER_HPP

#include "constants.hpp"
#include <string>

class DataLoader
{
  public:
    static SingleFeatureSingleTargetData loadSingleFeatureSingleTargetData(
      const std::string& filename);
    static MultiFeatureSingleTargetData loadMultiFeatureSingleTargetData(
      const std::string& filename);
};

#endif // DATA_LOADER_HPP