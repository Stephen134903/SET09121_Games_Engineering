#include <iostream>
#include "player.hpp"
#include "game_parameters.hpp"
#include "level_system.hpp"

using param = Parameters;
using ls = LevelSystem;

void Player::update(const float &dt) {
  //Move in four directions based on keys
  sf::Vector2f new_pos(_position.x,_position.y);
  //Move up
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && 
      _position.y > _radius) {
      new_pos.y -= _speed*dt;
  }
  //Move down
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && 
      _position.y < param::game_height-_radius) {
      new_pos.y += _speed*dt;
  }
  //Move left
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && 
      _position.x > _radius) {
      new_pos.x -= _speed*dt;
  }
  //Move Right
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
      _position.x < param::game_width - _radius) {
      new_pos.x += _speed*dt;
  }

  if(ls::get_tile_at(new_pos) != ls::WALL){
    set_position(new_pos);
  }

  Entity::update(dt);
}

Player::Player()
    : Entity(std::make_unique<sf::CircleShape>(_radius)) {   
  _shape->setFillColor(sf::Color::Magenta);
  _shape->setOrigin(sf::Vector2f(_radius, _radius));
}

void Player::render(sf::RenderWindow &window) const {
  window.draw(*_shape);
}