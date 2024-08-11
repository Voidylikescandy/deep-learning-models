#include "backend/include/data_loader.hpp"
#include "backend/include/logging.hpp"
#include "backend/include/model_exception.hpp"
#include "backend/include/multiple_linear_regression.hpp"
#include "backend/include/univariate_linear_regression.hpp"
#include "backend/include/utils.hpp"
#include "ui/include/menu_state.hpp"
#include "ui/include/ui_constants.hpp"
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
    std::cerr << "\033[31mException: " << e.what() << "\033[0m" << std::endl;
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
    std::cerr << "\033[31mException: " << e.what() << "\033[0m" << std::endl;
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

State currentState = State::STATE_MENU_SCREEN;
ModelType selectedModel;

int
main()
{
  spdlog::set_level(spdlog::level::debug);
  MODEL_LOG_INFO("Application launched.");

  sf::RenderWindow window(sf::VideoMode(800, 600), "Deep Learning Models");

  MenuState menuState;

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }

      switch (currentState) {
        case State::STATE_MENU_SCREEN:
          menuState.handleEvent(event);
          break;
        case State::STATE_TRAINING_SCREEN:

          break;
        case State::STATE_INPUT_SCREEN:

          break;
        case State::STATE_END:
          window.close();
          break;
      }
    }

    switch (currentState) {
      case State::STATE_MENU_SCREEN:
        menuState.update(window);
        break;
      case State::STATE_TRAINING_SCREEN:

        break;
      case State::STATE_INPUT_SCREEN:

        break;
      case State::STATE_END:
        break;
    }

    window.clear();
    switch (currentState) {
      case State::STATE_MENU_SCREEN:
        menuState.render(window);
        break;
      case State::STATE_TRAINING_SCREEN:

        break;
      case State::STATE_INPUT_SCREEN:

        break;
      case State::STATE_END:
        break;
    }
    window.display();
  }

  MODEL_LOG_INFO("Application terminated.");
  return 0;
}