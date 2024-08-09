#include "menu.hpp"

Menu::Menu(float width, float height)
  : selectedItemIndex(0)
{
  if (!font.loadFromFile("../fonts/Courier_New.ttf")) {
    // Handle error
  }

  std::vector<std::string> itemNames = { "Univariate Linear Regression",
                                         "Multiple Linear Regression",
                                         "Exit" };

  for (size_t i = 0; i < itemNames.size(); ++i) {
    sf::Text text;
    text.setFont(font);
    text.setFillColor(i == 0 ? sf::Color::Red : sf::Color::White);
    text.setString(itemNames[i]);
    text.setPosition(
      sf::Vector2f(width / 4, height / (itemNames.size() + 1) * (i + 1)));
    menuItems.push_back(text);
  }
}

void
Menu::draw(sf::RenderWindow& window)
{
  for (const auto& item : menuItems) {
    window.draw(item);
  }
}

void
Menu::moveUp()
{
  if (selectedItemIndex - 1 >= 0) {
    menuItems[selectedItemIndex].setFillColor(sf::Color::White);
    selectedItemIndex--;
    menuItems[selectedItemIndex].setFillColor(sf::Color::Red);
  }
}

void
Menu::moveDown()
{
  if (selectedItemIndex + 1 < menuItems.size()) {
    menuItems[selectedItemIndex].setFillColor(sf::Color::White);
    selectedItemIndex++;
    menuItems[selectedItemIndex].setFillColor(sf::Color::Red);
  }
}

int
Menu::getPressedItem() const
{
  return selectedItemIndex;
}
