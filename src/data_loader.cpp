#include "data_loader.hpp"
#include "model_exception.hpp"
#include "spdlog/spdlog.h"
#include <fstream>
#include <iostream>
#include <sstream>

std::vector<std::pair<double, double>>
DataLoader::loadData(const std::string& filename)
{
    spdlog::info("Initiating data loading");
    std::vector<std::pair<double, double>> data;
    std::ifstream file(filename);
    if (!file) {
        spdlog::error("Invalid file.");
        throw ModelException("Error opening file: " + filename);
    }
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        double x, y;
        if (!(iss >> x >> y)) {
            spdlog::error("Invalid data line - x : {}, y : {}", x, y);
            throw ModelException("Error reading line: " + line);
        }
        spdlog::debug("x : {}, y : {}", x, y);
        data.emplace_back(x, y);
    }

    spdlog::info("Data has been loaded successfully.");
    return data;
}