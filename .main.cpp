#include <iostream>
#include "dec.h"
using namespace std;
int main()
{
  //displays introduction to the game
  introduction();
  //starts the game, taking turns until someone wins or board is filled up
  take_turn();
  //end the game and display the result
  end_game();
  return 0;
}
