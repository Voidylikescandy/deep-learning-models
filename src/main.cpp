#include "data_loader.hpp"
#include "linear_regression.hpp"
#include "utils.hpp"
#include <iostream>

void
runRegression(const std::string& filename)
{
    std::vector<std::pair<double, double>> data =
      DataLoader::loadData(filename);

    if (data.empty()) {
        std::cerr << "No data loaded. Please check the data file." << std::endl;
        return;
    }

    LinearRegression model(0.000001, 100);
    model.fit(data);

    double x;
    std::cout << "Enter a value for x: ";
    std::cin >> x;
    std::cout << "Predicted value for y: " << model.predict(x) << std::endl;
}

int
main()
{
    const std::string filename = "../data/data.txt";
    runRegression(filename);
    return 0;
}