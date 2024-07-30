#include "data_loader.hpp"
#include "linear_regression.hpp"
#include "model_exception.hpp"
#include "spdlog/spdlog.h"
#include "utils.hpp"
#include <iostream>

void
runRegression(const std::string& filename)
{
    try {
        std::vector<std::pair<double, double>> data =
          DataLoader::loadData(filename);

        if (data.empty()) {
            spdlog::error("Empty data.");
            throw ModelException("No data loaded. Please check the data file.");
        }

        LinearRegression model(0.000001, 100);
        model.fit(data);

        double x;
        std::cout << "Enter a value for x: ";
        std::cin >> x;
        std::cout << "Predicted value for y: " << model.predict(x) << std::endl;
    } catch (const ModelException& e) {
        spdlog::error("Exception: {}", e.what());
        std::cerr << "\033[31mException: " << e.what() << "\033[0m"
                  << std::endl;
    } catch (const std::exception& e) {
        spdlog::error("Standard Exception: {}", e.what());
        std::cerr << "\033[31mStandard Exception: " << e.what() << "\033[0m"
                  << std::endl;
    } catch (...) {
        spdlog::error("Unknown Exception.");
        std::cerr << "\033[31mUnknown error occurred.\033[0m" << std::endl;
    }
}

int
main()
{
    spdlog::set_level(spdlog::level::debug);
    spdlog::info("Starting Univariate Linear Regression application.");

    const std::string filename = "../data/data.txt";
    runRegression(filename);

    spdlog::info("Univariate Linear Regression application finished.");
    return 0;
}