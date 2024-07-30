#include "data_loader.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

std::vector<std::pair<double, double>>
DataLoader::loadData(const std::string& filename)
{
    std::vector<std::pair<double, double>> data;
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return data;
    }
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        double x, y;
        if (!(iss >> x >> y)) {
            std::cerr << "Error reading line: " << line << std::endl;
            break;
        }
        data.emplace_back(x, y);
    }
    return data;
}