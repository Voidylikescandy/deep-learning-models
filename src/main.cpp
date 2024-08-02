#include "data_loader.hpp"
#include "logging.hpp"
#include "model_exception.hpp"
#include "multiple_linear_regression.hpp"
#include "univariate_linear_regression.hpp"
#include "utils.hpp"
#include <iostream>

void
runUnivariateLinearRegression(const std::string& filename)
{
    MODEL_LOG_INFO("Initiating Univariate Linear Regression Model.");

    try {
        SingleFeatureSingleTargetData data =
          DataLoader::loadSingleFeatureSingleTargetData(filename);

        if (data.empty()) {
            MODEL_LOG_ERROR("Empty data.");
            throw ModelException("No data loaded. Please check the data file.");
        }

        UnivariateLinearRegression model(0.000001, 100);
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

void
runMultipleLinearRegression(const std::string& filename)
{
    MODEL_LOG_INFO("Initiating Multiple Linear Regression Model.");

    try {
        MultiFeatureSingleTargetData data =
          DataLoader::loadMultiFeatureSingleTargetData(filename);

        if (data.empty()) {
            MODEL_LOG_ERROR("Empty data.");
            throw ModelException("No data loaded. Please check the data file.");
        }

        int numFeatures = data[0].first.size();
        MultipleLinearRegression model(0.000001, 100, numFeatures);
        model.fit(data);

        std::vector<double> x(numFeatures);
        std::cout << "Enter " << numFeatures << " values for x: ";
        for (size_t i = 0; i < numFeatures; ++i) {
            std::cin >> x[i];
        }
        double predicted_y = model.predict(x);
        std::cout << "Predicted value for y: " << predicted_y << std::endl;
        MODEL_LOG_INFO("Prediction for x, "
                       "y = " +
                       std::to_string(predicted_y));
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

    MODEL_LOG_INFO("Finishing Multiple Linear Regression Model.");
}

int
main()
{
    spdlog::set_level(spdlog::level::debug);
    MODEL_LOG_INFO("Application launched.");

    const std::string filename = "../data/mfst_data.txt";
    runMultipleLinearRegression(filename);

    MODEL_LOG_INFO("Application terminated.");
    return 0;
}