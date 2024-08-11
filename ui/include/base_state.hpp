#ifndef BASE_STATE_HPP
#define BASE_STATE_HPP

#include <SFML/Graphics.hpp>

class BaseState
{
public:
  virtual ~BaseState() = default;
  virtual void handleEvent(const sf::Event& event) = 0;
  virtual void update(sf::RenderWindow& window) = 0;
  virtual void render(sf::RenderWindow& window) = 0;
};

#endif // BASE_STATE_HPP