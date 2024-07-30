#ifndef DATA_LOADER_HPP
#define DATA_LOADER_HPP

#include <string>
#include <utility>
#include <vector>

class DataLoader
{
  public:
    static std::vector<std::pair<double, double>> loadData(
      const std::string& filename);
};

#endif // DATA_LOADER_HPP