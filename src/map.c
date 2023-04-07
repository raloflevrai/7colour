#include "../head/map.h"
#include "display.c"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

Map map = {.map = NULL, .size = 0};
void create_empty_map (Map* map, int size){
	map -> size = size;
	if (map -> map != NULL)
		{
			free(map -> map);			
		}		
	map -> map = malloc(size * size ); //* sizeof(int)
}

void set_map_value (Map* map, int x, int y, Color value){
	map -> map[y * map -> size + x] = value;
}

Color get_map_value (Map* map, int x, int y){
	if (map -> map == NULL || x > map -> size || y > map -> size)
	{
		printf("[ERROR] map not big enough or not initialized %p %i access (%i %i)", map -> map, map -> size, x, y);
		return ERROR;
	}
	return map -> map[y * map -> size + x];
}

void fill_map(Map* map){
	srand(time(NULL));
	for (int i=0; i<map -> size; i++){  // is it <= or < im not sure
		for (int j=0; j<map -> size; j++){
			Color color = 3+rand()%7; // it was a Color and not an int
			set_map_value(map, i, j, color);
		}
	}
	set_map_value(map, 0, map -> size-1, 1);
	set_map_value(map, map -> size-1, 0, 2);
}

int main(int argc, char** argv){

	if (argc < 2) {
        printf("please enter size of board\n");
        exit(EXIT_FAILURE);
    }
	int size = strtol(argv[1], NULL, 10); // pb : argv[1] is a char* ????
	//int size = 10;
	create_empty_map(&map,size);  // so that its a Map*
	
	fill_map(&map);
	print_board(&map);
	change_world(&map, 1, RED);
	print_board(&map);
}


