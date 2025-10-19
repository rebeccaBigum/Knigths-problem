#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>


#define SIZE 8     
#define MOVE_COUNT 8 
//prototypes

int tour(int start_Y,int start_x);
bool make_a_move (int move_id, int x, int y, int board [SIZE][SIZE]);

//OPRETTER DE moves som hesten kan laver
const int MOVES_X[MOVE_COUNT] = {2 ,2 ,1 ,-1 ,-2 ,-2 ,-1 ,1 };
const int MOVES_Y[MOVE_COUNT] = {-1 ,1 ,2 ,2 ,1 ,-1 ,-2 ,-2 };

//laver type for board som bruges i tour
typedef int board_t[SIZE][SIZE];
int result [SIZE][SIZE]={0};
int start_pos_x = 0;
int start_pos_y = 0;
int pos_Knigth_X = 0;
int pos_Knigth_Y=0;
bool moved = false;
bool koerer = true;
int moves = 0;

int main(){

//kører hver enkelt placering på pladern og kører en tour
    for (int start_tour_y = 0 ; start_tour_y< SIZE;start_tour_y++){
        for( int start_tour_x=0; start_tour_x<SIZE;start_tour_x++){
            result [start_tour_y][start_tour_x]=(tour(start_tour_y,start_tour_x));
        }

    }

    //print resultat af alle tours
  for(int i = 0; i<SIZE;i++){
        for(int j = 0; j<SIZE;j++){ 
         if(result[i][j]<10){
             printf(" %d  ",result[i][j]);
         }else{
            printf("%d  ",result[i][j]);
         }
    }
    printf("\n");
    }


}



bool make_a_move (int move_id, int x, int y, int board [SIZE][SIZE]){

    x+=MOVES_X[move_id];
    y+=MOVES_Y[move_id];
    //tjekker om jeg kan lave en flytning
    if(x >= 0 && x < SIZE && y >= 0 && y < SIZE &&board[y][x]==0){
    board[y][x]=moves+1;
    moves++;
    pos_Knigth_X = x;
    pos_Knigth_Y = y;

    return true;  // Flytningen var mulig
    } else {
        //sætter værdierne tilbage hvis jeg ikke kan flytte
    x-=MOVES_X[move_id];
    y-=MOVES_Y[move_id];
    return false;
    }


}


int tour(int start_Y,int start_x){

moves = 1;          // nulstil antallet af træk
koerer = true;       // sørg for at while-løkken kører
board_t board={0}; //laver et nyt bræt
pos_Knigth_X = start_x;
pos_Knigth_Y=start_Y;
board[pos_Knigth_Y][pos_Knigth_X] = 1;
moved=false;

//mens at turen kører
    while(koerer){
    //kører for alle mulige moves
   for(int i =0 ; i<MOVE_COUNT;i++){
    //kalder make a move funktion for at se om jeg kan rykke
        if(make_a_move (i, pos_Knigth_X, pos_Knigth_Y, board) && !moved){
        moved=true;
        break;
        }
    } 
    //hvis der ikke er flyttet er touren færdig
    if(!moved){
        koerer=false;
    }else
    moved=false;
}


return moves;
}