#include "data_loader.hpp"
#include "linear_regression_exception.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

std::vector<std::pair<double, double>>
DataLoader::loadData(const std::string& filename)
{
    std::vector<std::pair<double, double>> data;
    std::ifstream file(filename);
    if (!file) {
        throw LinearRegressionException("Error opening file: " + filename);
    }
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        double x, y;
        if (!(iss >> x >> y)) {
            throw LinearRegressionException("Error reading line: " + line);
        }
        data.emplace_back(x, y);
    }
    return data;
}