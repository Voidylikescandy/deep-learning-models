#include "utils.hpp"
#include "model_exception.hpp"
#include "spdlog/spdlog.h"
#include <algorithm>
#include <random>

void
Utils::splitData(const std::vector<std::pair<double, double>>& data,
                 std::vector<std::pair<double, double>>& train,
                 std::vector<std::pair<double, double>>& validation,
                 std::vector<std::pair<double, double>>& test,
                 double train_ratio,
                 double validation_ratio)
{
    if (train_ratio + validation_ratio > 1.0) {
        spdlog::error("Invalid ratios.");
        throw ModelException(
          "Invalid split ratios. Ensure train_ratio + validation_ratio <= "
          "1.0.");
    }
    spdlog::info("Splitting data into train, validation and tests.");

    std::vector<std::pair<double, double>> shuffled_data = data;
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(shuffled_data.begin(), shuffled_data.end(), g);

    size_t train_size = data.size() * train_ratio;
    size_t validation_size = data.size() * validation_ratio;

    train.assign(shuffled_data.begin(), shuffled_data.begin() + train_size);
    validation.assign(shuffled_data.begin() + train_size,
                      shuffled_data.begin() + train_size + validation_size);
    test.assign(shuffled_data.begin() + train_size + validation_size,
                shuffled_data.end());

    spdlog::info("Splitting successful.");
}