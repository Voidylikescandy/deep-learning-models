#ifndef UTILS_HPP
#define UTILS_HPP

#include <utility>
#include <vector>

namespace Utils {
void
splitData(const std::vector<std::pair<double, double>>& data,
          std::vector<std::pair<double, double>>& train,
          std::vector<std::pair<double, double>>& validation,
          std::vector<std::pair<double, double>>& test,
          double train_ratio,
          double validation_ratio);
}

#endif // UTILS_HPP