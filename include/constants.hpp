#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <utility>
#include <vector>

using SingleFeatureSingleTargetData = std::vector<std::pair<double, double>>;

using MultiFeatureSingleTargetData =
  std::vector<std::pair<std::vector<double>, double>>;

using SingleFeatureMultiTargetData =
  std::vector<std::pair<double, std::vector<double>>>;

using MultiFeatureMultiTargetData =
  std::vector<std::pair<std::vector<double>, std::vector<double>>>;

#endif // CONSTANTS_HPP
