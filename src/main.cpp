#include "data_loader.hpp"
#include "linear_regression.hpp"
#include "logging.hpp"
#include "model_exception.hpp"
#include "utils.hpp"
#include <iostream>

void
runUnivariateLinearRegression(const std::string& filename)
{
    MODEL_LOG_INFO("Initiating Univariate Linear Regression Model.");
    try {
        std::vector<std::pair<double, double>> data =
          DataLoader::loadData(filename);

        if (data.empty()) {
            MODEL_LOG_ERROR("Empty data.");
            throw ModelException("No data loaded. Please check the data file.");
        }

        LinearRegression model(0.000001, 100);
        model.fit(data);

        double x;
        std::cout << "Enter a value for x: ";
        std::cin >> x;
        double predicted_y = model.predict(x);
        std::cout << "Predicted value for y: " << predicted_y << std::endl;
        MODEL_LOG_INFO("Prediction for x = " + std::to_string(x) +
                       ": y = " + std::to_string(predicted_y));
    } catch (const ModelException& e) {
        MODEL_LOG_ERROR(e.what());
        std::cerr << "\033[31mException: " << e.what() << "\033[0m"
                  << std::endl;
    } catch (const std::exception& e) {
        MODEL_LOG_ERROR(e.what());
        std::cerr << "\033[31mStandard Exception: " << e.what() << "\033[0m"
                  << std::endl;
    } catch (...) {
        MODEL_LOG_ERROR("Unknown Exception.");
        std::cerr << "\033[31mUnknown error occurred.\033[0m" << std::endl;
    }
    MODEL_LOG_INFO("Finishing Univariate Linear Regression Model.");
}

int
main()
{
    spdlog::set_level(spdlog::level::debug);
    MODEL_LOG_INFO("Starting application.");

    const std::string filename = "../data/data.txt";
    runUnivariateLinearRegression(filename);

    MODEL_LOG_INFO("Application terminated.");
    return 0;
}