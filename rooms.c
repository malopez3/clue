
#include <stdio.h>
#include <stdlib.h>
#include "items.h"

#define NUM_CHARACTERS 6

struct Room {
    char* name;
    struct Room * North;
    struct Room * South;
    struct Room * East;
    struct Room * West;
    struct Item * itemList;
    struct Character * characterList;
};

//Initialize all 9 rooms

struct Room rooms[9];
struct Room rooms[9] = {{"lounge", NULL, &rooms[3], &rooms[1], NULL, NULL, NULL},
{"conservatory", NULL, &rooms[4], &rooms[2], &rooms[0], NULL, NULL},
{"ballroom", NULL, &rooms[5], NULL, &rooms[1], NULL, NULL},
{"dining room", &rooms[0], &rooms[6], &rooms[4], NULL, NULL, NULL},
{"kitchen", &rooms[1], &rooms[7], &rooms[5], &rooms[3], NULL, NULL},
{"library", &rooms[2], &rooms[8], NULL, &rooms[4], NULL, NULL},
{"billiard room", &rooms[3], NULL, &rooms[7], NULL, NULL, NULL},
{"study", &rooms[4], NULL, &rooms[8], &rooms[6], NULL, NULL},
{"hall", &rooms[5], NULL, NULL, &rooms[7], NULL, NULL}};

void randomizeRooms(){
    for(int i = 0; i < 9; i++){
        int randNum = rand() % 9;
        struct Room save = rooms[i];
        rooms[i].name = rooms[randNum].name;
        rooms[randNum].name = save.name;
    }
}

//Selects game answer: who did it, with what, and where

char * roomAnswer = "";
char * itemAnswer = "";
char * charAnswer = "";

void pickAnswer(){
    roomAnswer = rooms[rand()%9].name;
    itemAnswer = itemsList[rand()%6];
    charAnswer = characters[rand()%6].name;
}

void freeMemory(){
    free(rooms[0].itemList);
    free(rooms[1].itemList);
    free(rooms[2].itemList);
    free(rooms[3].itemList);
    free(rooms[4].itemList);
    free(rooms[5].itemList);
    free(rooms[6].itemList);
    free(rooms[7].itemList);
    free(rooms[8].itemList);
    free(rooms[9].itemList);
    free(rooms[0].characterList);
    free(rooms[1].characterList);
    free(rooms[2].characterList);
    free(rooms[3].characterList);
    free(rooms[4].characterList);
    free(rooms[5].characterList);
    free(rooms[6].characterList);
    free(rooms[7].characterList);
    free(rooms[8].characterList);
    free(rooms[9].characterList);
}


