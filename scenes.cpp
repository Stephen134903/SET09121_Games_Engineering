#include <iostream>
#include "scenes.hpp"
#include "level_system.hpp"
#include "player.hpp"
#include "game_parameters.hpp"
#include "game_system.hpp"

using param = Parameters;
using ls = LevelSystem;
using gs = GameSystem;

void MazeScene::load(){
    std::shared_ptr<Entity> player = std::make_shared<Player>();
    _entities.push_back(player);

    reset();
}

void MazeScene::reset(){
    ls::load_level(_file_path);
    for (size_t y = 0; y < ls::get_height(); ++y) {
        for (size_t x = 0; x < ls::get_width(); ++x) {
            std::cout << ls::get_tile({x, y});
        }
        std::cout << std::endl;
    }
    _entities[0]->set_position(ls::get_start_position());
}

void MazeScene::update(const float &dt){
    if(ls::get_tile_at(_entities[0]->get_position()) == ls::END){
        if(_file_path == std::string(param::maze_1)){
            _file_path = param::maze_2;
            reset();
        }
        else{
           unload();
           gs::set_active_scene(Scenes::end);
        }
        return;
    }
    Scene::update(dt);
}

void MazeScene::render(sf::RenderWindow &window){
    ls::render(window);
    Scene::render(window);
}

void MazeScene::set_file_path(const std::string &file_path){
    _file_path=file_path;
}

void EndScene::load(){
    win_text.setString("Well Done !!!");
    font.loadFromFile("resources/fonts/RobotoMono-Regular.ttf");
    win_text.setFont(font);
    win_text.setPosition(param::game_width/2.f-100,(param::game_height/2.f));
    win_text.setCharacterSize(60);
    win_text.setColor(sf::Color(0,255,0));
}

void EndScene::render(sf::RenderWindow &window){
    Scene::render(window);
    window.draw(win_text);  
}

std::shared_ptr<Scene> Scenes::maze;
std::shared_ptr<Scene> Scenes::end;