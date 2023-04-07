#include <stdio.h>
#include <stdlib.h>
#include "../head/map.h"
#include "../head/display.h"

void print_board(Map* map)
{
    //printf("i am printing");
    int i, j;
    for (i = 0; i < map -> size; i++) {
        for (j = 0; j < map -> size; j++) {
            enum Color color = get_map_value(map,i,j);
            switch(color){
                case 1:
                    printf("1 ");
                    break;
                case 2:
                    printf("2 ");
                    break;
                case 3:
                    printf("r ");
                    break;
                case 4:
                    printf("g ");
                    break;
                case 5:
                    printf("b ");
                    break;
                case 6:
                    printf("y ");
                    break;
                case 7:
                    printf("m ");
                    break;
                case 8:
                    printf("c ");
                    break;
                case 9:
                    printf("w ");
                    break;
                case 0:
                    printf("- ");
                    break;
                case -1:
                    printf("ERROR ");
                    break;
            }
        }
        printf("\n");
    }
}

int compteur = 0;
int change = 0;

void run_world(Map* map, Color player, Color color_played){
    int i, j;
    for (i = 0; i < map -> size; i++) { //la ligne
        for (j = 0; j < map -> size; j++) { // la colonne
            for (int k=-1; k<=1; k++){
                for (int l=-1; l<=1; l++){
                    Color color_case = get_map_value(map, i, j);
                    // the condition is too much?
                    // printf("case %i, player %i", color_case, player);
                    if (color_case == player){
                        printf("its the player");
                        if ((i+k >= 0) && (j+l >= 0) && (i+k < map -> size) && (j+l < map -> size) && (color_case == player) && ((k==0) | (l==0)) && (get_map_value(map, i+k, j+l) == color_played)) {
                            set_map_value(map, i+k, j+l, player);
                            compteur ++;
                            change = 1;
                            printf("something changed\n");
                        }
                    }
                }
            }
        }
    }
}

void change_world(Map* map, int player, Color color_played){    
    run_world(map, player, color_played);
    while (change){
        change = 0;
        run_world(map, player, color_played);        
    }
    printf("%i",compteur);
    exit(EXIT_FAILURE);
}