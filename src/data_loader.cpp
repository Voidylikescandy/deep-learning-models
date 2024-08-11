#include "data_loader.hpp"
#include "logging.hpp"
#include "model_exception.hpp"
#include <fstream>
#include <sstream>

SingleFeatureSingleTargetData
DataLoader::loadSingleFeatureSingleTargetData(const std::string& filename)
{
  MODEL_LOG_INFO("Initiating Single Feature Single Target Data loading.");
  SingleFeatureSingleTargetData data;
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
    MODEL_LOG_DEBUG("x : " + std::to_string(x) + ", y : " + std::to_string(y));
    data.emplace_back(x, y);
  }

  file.close();
  MODEL_LOG_INFO(
    "Single Feature Single Target Data has been loaded successfully.");
  return data;
}

MultiFeatureSingleTargetData
DataLoader::loadMultiFeatureSingleTargetData(const std::string& filename)
{
  MODEL_LOG_INFO("Initiating Multi Feature Single Target Data loading.");
  MultiFeatureSingleTargetData data;
  std::ifstream file(filename);
  if (!file) {
    file.close();
    MODEL_LOG_ERROR("Invalid file.");
    throw ModelException("Error opening file: " + filename);
  }
  std::string line;
  size_t numFeatures = 0;

  // Determine the number of features by reading the first line
  if (std::getline(file, line)) {
    std::istringstream iss(line);
    std::vector<double> features;
    double value;
    while (iss >> value) {
      features.push_back(value);
    }
    if (features.empty()) {
      MODEL_LOG_ERROR("No data found in file.");
      throw ModelException("No data found in file: " + filename);
    }
    numFeatures = features.size() - 1; // Last value is the target
  } else {
    MODEL_LOG_ERROR("File is empty.");
    throw ModelException("File is empty: " + filename);
  }

  file.clear();
  file.seekg(0, std::ios::beg);

  while (std::getline(file, line)) {
    std::istringstream iss(line);
    std::vector<double> features(numFeatures);
    double target;
    for (size_t i = 0; i < numFeatures; ++i) {
      if (!(iss >> features[i])) {
        MODEL_LOG_ERROR("Invalid data line: " + line);
        throw ModelException("Error reading features from line: " + line);
      }
    }
    if (!(iss >> target)) {
      MODEL_LOG_ERROR("Target value missing in line: " + line);
      throw ModelException("Error reading target value from line: " + line);
    }
    MODEL_LOG_DEBUG("Features: " + std::to_string(features.size()) +
                    ", Target: " + std::to_string(target));
    data.emplace_back(features, target);
  }

  file.close();
  MODEL_LOG_INFO(
    "Multi Feature Single Target Data has been loaded successfully.");
  return data;
}