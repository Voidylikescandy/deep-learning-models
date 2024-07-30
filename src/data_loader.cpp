#include "data_loader.hpp"
#include "logging.hpp"
#include "model_exception.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

std::vector<std::pair<double, double>>
DataLoader::loadData(const std::string& filename)
{
    MODEL_LOG_INFO("Initiating data loading.");
    std::vector<std::pair<double, double>> data;
    std::ifstream file(filename);
    if (!file) {
        file.close();
        MODEL_LOG_ERROR("Invalid file.");
        throw ModelException("Error opening file: " + filename);
    }
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        double x, y;
        if (!(iss >> x >> y)) {
            MODEL_LOG_ERROR("Invalid data line - x : " + std::to_string(x) +
                            ", y : " + std::to_string(y));
            throw ModelException("Error reading line: " + line);
        }
        MODEL_LOG_DEBUG("x : " + std::to_string(x) +
                        ", y : " + std::to_string(y));
        data.emplace_back(x, y);
    }

    file.close();
    MODEL_LOG_INFO("Data has been loaded successfully.");
    return data;
}