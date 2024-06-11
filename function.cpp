#include <iostream>
#include "dec.h"
#include <stdlib.h>
#include <string> //Used to convert the set color macro to a string
//globally defined
using namespace std;

#define RESET_COLOR "\033[0m" 
//Set Color Macro
#define SET_COLOR(color) "\033[" + std::string(color)
//Set Color Macro

string board[9] = {" ", " ", " ", " ", " ", " ", " ", " ", " "}; 
int player = 1; //represents current player  
int position = 0;  //represents position chosen by the player
//displays introduction to the game
void introduction()
{
  cout << SET_COLOR("\033[35m"); // Set text color to magenta
  cout<<"Press [Enter] to begin: ";
  getchar(); //haults the screen  
  cout<<"\n";

   cout<<"\n";
  //headers
  cout << SET_COLOR("\033[37m"); // Set text color to white
  cout<< SET_COLOR("\033[30m") << "***********\n";
  cout<<SET_COLOR("\033[37m")  << "Tic-Tac-Toe\n";
  cout<< SET_COLOR("\033[30m") <<"***********\n";

  cout<< SET_COLOR("\033[34m") << "Player 1) X\n";
  cout<< SET_COLOR("\033[31m") << "Player 2) O\n";
cout << SET_COLOR("\033[37m");
  
//displays grid
  cout<<"The 3x3 grid is shown below:\n\n";

  cout << "     |     |      \n";
  cout << "  "<< SET_COLOR("\033[35m") << "1  " << SET_COLOR("\033[37m") << "|  " << SET_COLOR("\033[35m") << "2  " << SET_COLOR("\033[37m") << "|  " << SET_COLOR("\033[35m") << "3   \n";
  cout << SET_COLOR("\033[37m"); // Set text color to white
  cout << "_____|_____|_____ \n";
  cout << "     |     |      \n";
  cout << "  "<< SET_COLOR("\033[35m") << "4  " << SET_COLOR("\033[37m") << "|  " << SET_COLOR("\033[35m") << "5  " << SET_COLOR("\033[37m") << "|  " << SET_COLOR("\033[35m") << "6   \n";
  cout << SET_COLOR("\033[37m"); // Set text color to white
  cout << "_____|_____|_____ \n";
  cout << "     |     |      \n";
  cout << "  "<< SET_COLOR("\033[35m") << "7  " << SET_COLOR("\033[37m") << "|  " << SET_COLOR("\033[35m") << "8  " << SET_COLOR("\033[37m") << "|  " << SET_COLOR("\033[35m") << "9   \n"; 
  cout << SET_COLOR("\033[37m"); // Set text color to white
cout << "     |     |      \n\n";

}



bool is_winner()
{
  bool winner = false;
  //checking the rows
  if((board[0]==board[1]) && (board[1]==board[2]) && board[0] != " ") 
  {
    winner = true;
  }
  else if ((board[3] == board[4]) && (board[4] == board[5]) && board[3] != " ") 
  {
    winner = true;
    } 

  else if ((board[6] == board[7]) && (board[7] == board[8]) && board[6] != " ") 
  {
    winner = true;
    } 

  //checking the columns

  else if((board[0]==board[3]) && (board[3]==board[6]) && board[0] != " ")
  {
    winner = true;
  }

  else if ((board[1] == board[4]) && (board[4] == board[7]) && board[1] != " ")
  {
    winner = true;
   } 

  else if ((board[2] == board[5]) && (board[5] == board[8]) && board[2] != " ") 
  {
    winner = true;
    }

  //checking the diagonals

  else if ((board[0]==board[4]) && (board[4]==board[8]) && board[0] != " ")
  {
    winner = true;
  }

  else if ((board[2]==board[4]) && (board[4]==board[6]) && board[2] != " ")
  {
    winner = true;
  }

  return winner;

}

//checks if board is filled up
bool filled_up()
{
  bool filled = true;

  for(int i = 0; i<9; i++)
  {
    if(board[i]==" ")
    {
      filled = false;
    }
  }

  return filled;
}



//draws current state of the board
void draw()
{
  cout<<  "     |     |      \n";
  cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "\n";
  cout << "_____|_____|_____ \n";
  cout << "     |     |      \n";
  cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "\n";
  cout << "_____|_____|_____ \n";
  cout << "     |     |      \n";
  cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "\n";
  cout << "     |     |      \n";
  cout << "\n";

}



void set_position()
{
  cout<<"Player "<<player<<"'s turn (Enter: 1-9): ";  //getting user input
  while(!(cin>>position))
  {
    cout<<"Please enter a valid number between (1-9)"<<endl; //error trap
    cin.clear();  //flushing the buffer
      cin.ignore();  
  }
  cout<<endl;
  
 //checks if the position is already taken
  while (board[position -1] != " "){
    cout<<"Oops, that position is already filled\nTry again\n";
    cout << "Player " << player << "'s Turn (Enter 1-9): ";
    cin>>position;
    cout<<"\n";


}

}

//updates board after every turn
void update_board()
{

  if (player % 2 == 1){
    board[position - 1] = SET_COLOR("\033[34m") + "X" + SET_COLOR("\033[37m"); // mark player ones move
  
  }
  else
  {
    board[position - 1] = SET_COLOR("\033[31m") + "O" + SET_COLOR("\033[37m"); // mark player twos move
  }
}

//cahnges player after each turn
void change_player() {
  if (player == 1){
    player++; //changes to player 2
  }
  else{
    player--; //changes to player 1
  }
}

//function that executes each turn of the game
void take_turn()
{ 
  while(!is_winner() && !filled_up())  
  {
    //invoking the functions for necessary turns
    set_position();
    update_board();
    change_player();
    draw();
  }
}

//function to end game and display winner
void end_game()
{
  if(is_winner())
  {
    cout<< SET_COLOR("\033[33m") << "There is a winner!"<<endl; //winner message
    cout << SET_COLOR("\033[37m");

  }

  else if(filled_up())
  {
    cout<< SET_COLOR("\033[36m") << "There is a tie!"<<endl; //tie message
    cout << SET_COLOR("\033[37m");
  }
}
