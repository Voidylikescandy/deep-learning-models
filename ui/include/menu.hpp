#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Graphics.hpp>
#include <functional>
#include <string>
#include <vector>

class Menu
{
public:
  Menu(float width, float height);
  void draw(sf::RenderWindow& window);
  void moveUp();
  void moveDown();
  int getPressedItem() const;

private:
  int selectedItemIndex;
  std::vector<sf::Text> menuItems;
  sf::Font font;
};

#endif // MENU_HPP