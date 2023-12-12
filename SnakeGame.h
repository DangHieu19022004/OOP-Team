// SnakeGame.h
#ifndef SNAKEGAME_H
#define SNAKEGAME_H
#include "Game.h"

//class Snake ke thua tu class Game
class SnakeGame : public Game {
public:
    SnakeGame(); // constructor
    
    //phuong thuc bat dau tro choi
    void batdau();
    
    //phuong thuc bat dau vong lap chinh cua tro choi
    void start();
};

#endif // SNAKEGAME_H
