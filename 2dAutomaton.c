#include <stdio.h>
#include <time.h>
#include "2dAutomaton.h"
/*
    Brian's Brains cellular automaton;
*/

enum (DEATH , ALIVE, INACTIVE); /**/

int cell=2;
int grid[gHeight[gWidth]];



void main(){
    srand(time(0));

}

int neighbours(int grid[gHeight][gWidth], ){
    int n, w, hn, hw, cell;

    int cellNumber=0;

    for(w = -1; y<2 ;y++){
        for()
    }



}

/* Method sed for generating random number between 0 or 1 and then,
return one or 0 depending on the result.
*/
int randomN(){
    int random = rand() %2;
    return random;    
}

int prinCellStates(int drid[gHeight][gWidth]){

    int w, n; 
    char ch;

    for(w=0; w < gWidth ; w++){
        for(n= 0; n <gHeight; n++){
         if(grid[n][w]==ALIVE) {
             ch="U002A";

         }else if(grid[n][w]==INACTIVE){
             ch="U0026";
         }else if(grid[n][w]==DEATH){
             ch="";
             printf("%c", ch);
         }
         printf("\n");
        }
    }
    printf("\n");
}


void cellGen(int drid[gHeight][gWidth], int random, n, w ){
       
    for(w=0; w <gWidth; w++){
        for(n=0 ; n<gHeight; n++){
            if(random==1){
            grid[gHeight][gWidth]= ACTIVE;

            }else if(random==0){
                griid[gHeight][gWidth]= INACTIVE
            }

            
        }
    }



}

















