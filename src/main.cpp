#include "game.h"
#include "map.h"
#include "network.h"

#include <iostream>

int main(){
    Game game;
    try{
        game.start();
    }catch(int result){
        std::cout<<result<<std::endl;
    }
    try{
        game.stop();
    }catch(int result){
        std::cout<<result<<std::endl;
    }
    return 0;
}
