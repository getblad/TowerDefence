#include <iostream>
#include "./Game_elements/game_elements.h"
int main() {


    Game_field* a = Game_field::get_field(2, 1, 2, 2);
    auto res = a->get_players("lion");


    return 0;
}
