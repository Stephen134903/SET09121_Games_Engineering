#pragma once
#include <string>

struct Parameters
{
    static constexpr int game_width = 800;
    static constexpr int game_height = 600;
    static constexpr float time_step = 0.017f;
    static constexpr char const* maze_1 = "resources/levels/maze.txt";
    static constexpr char const* maze_2 = "resources/levels/maze_2.txt";    
};