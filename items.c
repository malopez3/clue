#include <stdio.h>
#include <stdlib.h>
#include "rooms.h"
#include <string.h>

struct Player{
    char* name;
    struct Room* curRoom;
    struct Item* itemList;
};

struct Character{
    char* name;
    struct Room* curRoom;
    struct Character* next;
    int roomNum;
};

struct Item{
    char* name;
    struct Item* next;
    struct Room* curRoom;
};

char *itemsList[] = {"candlestick", "dagger", "leadpipe", "revolver", "rope", "wrench"};

void addCharacters(char* name, int roomNum){
    struct Character *newCharacter = (struct Character*)(malloc(sizeof(struct Character)));
    struct Character *lastCharacter = rooms[roomNum].characterList;
    newCharacter->name = name;
    newCharacter->next = NULL;
    if(lastCharacter == NULL) {
        rooms[roomNum].characterList = newCharacter;
    }
    else{
        while(lastCharacter->next != NULL){
            lastCharacter = lastCharacter->next;
        }
        lastCharacter->next = newCharacter;
    }
}
//Adds items into rooms
void addItems(char* name, int roomNum){
    struct Item *newItem = (struct Item*)(malloc(sizeof(struct Item)));
    struct Item *lastItem = rooms[roomNum].itemList;
    newItem->name = name;
    newItem->next = NULL;
    if(lastItem == NULL){
        rooms[roomNum].itemList = newItem;
    }
    else{
        while(lastItem->next != NULL){
            lastItem = lastItem -> next;
        }
        lastItem->next = newItem;
    }
}

//Initialize items, allocating memory and placing into random rooms

void initializeItems(){
    //Initialize candlestick
    struct Item* candlestick = malloc(sizeof(struct Item));
    candlestick->name = "candlestick";
    int randNum = rand() % 9;
    candlestick -> curRoom = &rooms[randNum];
    addItems("candlestick", randNum);
    //printf("LOCATION FOR CANDLESTICK: %s \n", candlestick->curRoom->name);
    //Initialize dagger
    struct Item* dagger = malloc(sizeof(struct Item));
    dagger->name = "dagger";
    randNum = rand() % 9;
    while(&rooms[randNum] == candlestick->curRoom) {
        randNum = rand() % 9;
    }
    dagger->curRoom = &rooms[randNum];
    addItems("dagger", randNum);
    //printf("LOCATION FOR DAGGER: %s \n", dagger->curRoom->name);
    //Initialize leadpipe
    struct Item* leadpipe = malloc(sizeof(struct Item));
    leadpipe->name = "leadpipe";
    randNum = rand() % 9;
    while(&rooms[randNum] == candlestick->curRoom || &rooms[randNum] == dagger-> curRoom){
        randNum = rand() % 9;
    }
    leadpipe->curRoom = &rooms[randNum];
    addItems("leadpipe", randNum);
    //printf("LOCATION FOR leadpipe: %s \n", leadpipe->curRoom->name);
    //Initialize revolver
    struct Item* revolver = malloc(sizeof(struct Item));
    revolver->name = "revolver";
    while(&rooms[randNum] == candlestick->curRoom || &rooms[randNum] == dagger-> curRoom
    || &rooms[randNum] == leadpipe-> curRoom){
        randNum = rand() % 9;
    }
    revolver->curRoom = &rooms[randNum];
    addItems("revolver", randNum);
    //printf("LOCATION FOR revolver: %s \n", revolver->curRoom->name);
    //Initialize rope
    struct Item* rope = malloc(sizeof(struct Item));
    rope->name = "rope";
    while(&rooms[randNum] == candlestick->curRoom || &rooms[randNum] == dagger-> curRoom
          || &rooms[randNum] == leadpipe-> curRoom || &rooms[randNum] == revolver -> curRoom){
        randNum = rand() % 9;
    }
    rope->curRoom = &rooms[randNum];
    addItems("rope", randNum);
    //printf("LOCATION FOR rope: %s \n", rope->curRoom->name);
    //Initialize wrench
    struct Item* wrench = malloc(sizeof(struct Item));
    wrench->name = "wrench";
    while(&rooms[randNum] == candlestick->curRoom || &rooms[randNum] == dagger-> curRoom
          || &rooms[randNum] == leadpipe-> curRoom || &rooms[randNum] == revolver -> curRoom
          || &rooms[randNum] == rope -> curRoom){
        randNum = rand() % 9;
    }
    wrench->curRoom = &rooms[randNum];
    addItems("wrench", randNum);
    //printf("LOCATION FOR wrench: %s \n", wrench->curRoom->name);
}

struct Character characters[NUM_CHARACTERS];
struct Character characters[NUM_CHARACTERS] = {{"Miss Scarlet", &rooms[0], NULL, 0},
        {"Colonel Mustard", &rooms[1], NULL, 1},
        {"Mrs. White", &rooms[2], NULL, 2},
        {"The Reverend Green", &rooms[3], NULL, 3},
        {"Mrs. Peacock", &rooms[4], NULL, 4},
        {"Professor Plum", &rooms[5]}, NULL, 5};

//Randomizes characters into random rooms

void randomizeCharacters(){
    for(int i = 0; i < 6; i++){
        int randNum = rand() % 6;
        struct Character save = characters[i];
        characters[i].name = characters[randNum].name;
        characters[randNum].name = save.name;
        addCharacters(characters[i].name, characters[i].roomNum);
    }
}

/*
 struct Room save = rooms[i];
        rooms[i].name = rooms[randNum].name;
        rooms[randNum].name = save.name;
 */
//Initializes player with name and random room


void initializePlayer(struct Player *inputPlayer) {
    int randNum = rand() % 9;
    inputPlayer->name = "Player 1";
    inputPlayer->curRoom = &rooms[randNum];
    //printf("%s \n", inputPlayer->curRoom->name);

    //printf("%s \n", (*rooms[randNum].characterList).name);
}

void lookAround(struct Player *player){
    printf("You are currently in the room: %s \n", player->curRoom->name);
    if(player->curRoom->North != NULL) {
        printf("To your north: %s \n", player->curRoom->North->name);
    }
    else{
        printf("To your north: there is no room \n");
    }
    if(player->curRoom->East != NULL) {
        printf("To your east: %s \n", player->curRoom->East->name);
    }
    else{
        printf("To your east: there is no room \n");
    }
    if(player->curRoom->South != NULL) {
        printf("To your south: %s \n", player->curRoom->South->name);
    }
    else{
        printf("To your south: there is no room \n");
    }
    if(player->curRoom->West != NULL) {
        printf("To your west: %s \n", player->curRoom->West->name);
    }
    else{
        printf("To your west: there is no room \n");
    }
    if(player->curRoom->characterList != NULL){
        printf("Character in your room: %s \n", player->curRoom->characterList->name);
        struct Character *finalCharacter = player->curRoom->characterList;
        while(finalCharacter->next != NULL){
            finalCharacter = finalCharacter->next;
            printf("Character in your room: %s \n", finalCharacter->name);
        }
    }
    else{
        printf("Characters in your room: there are none \n");
    }
    if(player->curRoom->itemList != NULL){
        printf("Item in your room: %s \n", player->curRoom->itemList->name);
        struct Item *finalItem = player->curRoom->itemList;
        while(finalItem->next != NULL){
            finalItem = finalItem->next;
            printf("Item in your room: %s \n", finalItem->name);
        }
    }
    else{
        printf("Items in your room: there are none \n");
    }
}

void goTo(struct Player *player, char* direction){
    if(strncmp(direction, "North", 5) == 0){
        if(player->curRoom->North != NULL) {
            player->curRoom = player->curRoom->North;
            printf("You have now moved north \n");
        }
        else{
            printf("There is no room to your north. Please try again by typing \"go\". \n");
        }
    }
    if(strncmp(direction, "South", 5) == 0){
        if(player->curRoom->South != NULL) {
            player->curRoom = player->curRoom->South;
            printf("You have now moved south \n");
        }
        else{
            printf("There is no room to your south. Please try again by typing \"go\". \n");
        }
    }
    if(strncmp(direction, "East", 4) == 0){
        if(player->curRoom->East != NULL){
        player->curRoom = player->curRoom->East;
        printf("You have now moved east \n");
        }
        else{
            printf("There is no room to your east. Please try again by typing \"go\". \n");
        }
    }
    if(strncmp(direction, "West", 4) == 0){
        if(player->curRoom->West != NULL) {
            player->curRoom = player->curRoom->West;
            printf("You have now moved west \n");
        }
        else{
            printf("There is no room to your west. Please try again by typing \"go\". \n");
        }
    }
}

void charDropItems(struct Player *player, char* name){
    if(player->itemList == NULL){
        printf("You have no items in your inventory to drop. Please type another command. \n");
        return;
    }
    if(strncmp(name, player->itemList->name, 3) == 0){
        player->itemList = NULL;
        printf("The item has been dropped and removed from your inventory. \n");
        return;
    }
    else{
        struct Item *lastItem= player->itemList;
        while(lastItem != NULL){
            if(strncmp(name, lastItem->next->name, 3) == 0){
                if(lastItem->next->next == NULL){
                    lastItem->next = NULL;
                }
                else{
                    lastItem->next = lastItem->next->next;
                }
            }
            lastItem = lastItem->next;
        }
        printf("The item has been dropped and removed from your inventory. \n");
    }
}

void charAddItems(struct Player *player, char* name){
    int itemInRoom = 1;
    if(player->curRoom->itemList == NULL){
        printf("The item is not in the room. Please try again with the \"add\" command");
        return;
    }
    else{
        struct Item *newItem = player->curRoom->itemList;
        while(newItem != NULL) {
            if(strncmp(name, newItem->name, 3) == 0){
                itemInRoom = 0;
                break;
            }
            newItem = newItem->next;
        }
        if(itemInRoom == 1){
            printf("The item is not in the room. Please try again with the \"take\" command \n");
            return;
        }
    }
    struct Item *newItem = (struct Item*)(malloc(sizeof(struct Item)));
    struct Item *lastItem = player->itemList;
    newItem->name = name;
    newItem->next = NULL;
    if(lastItem == NULL){
        player->itemList = newItem;
    }
    else{
        while(lastItem->next != NULL){
            lastItem = lastItem -> next;
        }
        lastItem->next = newItem;
    }
    printf("%s has been successfully added to your inventory! \n", name);
}