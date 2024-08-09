#ifndef LOGGING_HPP
#define LOGGING_HPP

#include "spdlog/spdlog.h"

#define FILENAME                                                               \
  (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#define MODEL_LOG_ERROR(message)                                               \
  spdlog::error("{}/{}:{}: {}", FILENAME, __LINE__, __FUNCTION__, message)
#define MODEL_LOG_INFO(message)                                                \
  spdlog::info("{}/{}:{}: {}", FILENAME, __LINE__, __FUNCTION__, message)
#define MODEL_LOG_DEBUG(message)                                               \
  spdlog::debug("{}/{}:{}: {}", FILENAME, __LINE__, __FUNCTION__, message)
#define MODEL_LOG_WARN(message)                                                \
  spdlog::warn("{}/{}:{}: {}", FILENAME, __LINE__, __FUNCTION__, message)
#define MODEL_LOG_CRITICAL(message)                                            \
  spdlog::critical("{}/{}:{}: {}", FILENAME, __LINE__, __FUNCTION__, message)

#endif // LOGGING_HPP
