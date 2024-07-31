#ifndef UTILS_HPP
#define UTILS_HPP

#include "constants.hpp"

namespace Utils {
void
splitData(const SingleFeatureSingleTargetData& data,
          SingleFeatureSingleTargetData& train,
          SingleFeatureSingleTargetData& validation,
          SingleFeatureSingleTargetData& test,
          double train_ratio,
          double validation_ratio);
}

#endif // UTILS_HPP