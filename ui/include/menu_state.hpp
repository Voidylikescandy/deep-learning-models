#ifndef MENU_STATE_HPP
#define MENU_STATE_HPP

#include "base_state.hpp"
#include "menu.hpp"

class MenuState : public BaseState
{
public:
  MenuState();
  void handleEvent(const sf::Event& event) override;
  void update(sf::RenderWindow& window) override;
  void render(sf::RenderWindow& window) override;

private:
  Menu menu;
};

#endif // MENU_STATE_HPP