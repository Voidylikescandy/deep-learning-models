#include "data_loader.hpp"
#include "linear_regression.hpp"
#include "linear_regression_exception.hpp"
#include "utils.hpp"
#include <iostream>

void
runRegression(const std::string& filename)
{
    try {
        std::vector<std::pair<double, double>> data =
          DataLoader::loadData(filename);

        if (data.empty()) {
            throw LinearRegressionException(
              "No data loaded. Please check the data file.");
        }

        LinearRegression model(0.000001, 100);
        model.fit(data);

        double x;
        std::cout << "Enter a value for x: ";
        std::cin >> x;
        std::cout << "Predicted value for y: " << model.predict(x) << std::endl;
    } catch (const LinearRegressionException& e) {
        std::cerr << "\033[31mException: " << e.what() << "\033[0m"
                  << std::endl;
    }
}

int
main()
{
    const std::string filename = "../data/a.txt";
    runRegression(filename);
    return 0;
}