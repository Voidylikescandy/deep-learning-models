#include "menu_state.hpp"
#include "ui_constants.hpp"

extern State currentState;
extern ModelType selectedModel;

MenuState::MenuState()
  : menu(800, 600)
{
}

void
MenuState::handleEvent(const sf::Event& event)
{
  if (event.type == sf::Event::KeyPressed) {
    if (event.key.code == sf::Keyboard::Up) {
      menu.moveUp();
    } else if (event.key.code == sf::Keyboard::Down) {
      menu.moveDown();
    } else if (event.key.code == sf::Keyboard::Enter) {
      switch (menu.getPressedItem()) {
        case 0:
          selectedModel = ModelType::MODEL_UNIVARIATE_LINEAR_REGRESSION;
          break;
        case 1:
          selectedModel = ModelType::MODEL_MULTIPLE_LINEAR_REGRESSION;
          break;
        case 2:
          selectedModel = ModelType::MODEL_END;
          break;
      }

      currentState = State::STATE_TRAINING_SCREEN;
    }
  }
}

void
MenuState::update(sf::RenderWindow& window)
{
}

void
MenuState::render(sf::RenderWindow& window)
{
  window.clear();
  menu.draw(window);
  window.display();
}