#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rooms.h"
#include "items.h"
#include "time.h"

int main(){
//Seed random number generator
srand(time(NULL));
//Randomize the room locations
randomizeRooms();
//Randomize the room locations of each character
randomizeCharacters();
//Initialize items in the game
initializeItems();
//Creates the player's avatar
struct Player Player1 = {"Player 1", NULL, NULL};
//Initializes the player into the game
initializePlayer(&Player1);
//Selects the game's final answer
pickAnswer();

//Welcome user to the game
printf("Welcome to the text adventure game Clue! \nType \"help\" to see a list of commands \n");
//Initialize variable to hold user input
char userInput[30];
//Holds the number of guesses used up (maximum 10 guesses)
int guesses = 0;
//Initialize variables to check for commands
int help;
int list;
int look;
int go;
int take;
int drop;
int inventory;
int clue;

while(1){
    //Collects user input
    gets(userInput);
    //Compares user input to available commands
    help = strncmp(userInput, "help", 4);
    list = strncmp(userInput, "list", 4);
    look = strncmp(userInput, "look", 4);
    go = strncmp(userInput, "go", 2);
    take = strncmp(userInput, "take", 4);
    drop = strncmp(userInput, "drop", 4);
    clue = strncmp(userInput, "clue", 4);
    inventory = strncmp(userInput, "inventory", 9);
    //Prompts the user to try again if the command is invalid
    if((help&list&look&go&take&drop&clue&inventory) == 1){
        printf("The command you typed is invalid. Please try again. \n");
        continue;
    }
    if(help == 0) {
        printf("Command \t Description \n");
        printf("---------------------------- \n");
        printf("help \t \t Prints all available commands \n");
        printf("list \t \t Prints list of items, rooms, and characters \n");
        printf("look \t \t Prints rooms in each direction, characters in the room, and items in room \n");
        printf("go \t \t Allows player to move either north, east, south, or west \n");
        printf("take \t \t Allows player to pickup items \n");
        printf("drop \t \t Allows player to drop an item \n");
        printf("inventory \t Prints items in avatar's inventory \n");
        printf("clue \t \t Allows player to make a guess to win the game \n");
        continue;
    }
    if(list == 0){
        printf("List of Characters, Rooms, and Items \n");
        printf("--------------------------------------- \n");
        printf("Characters: Miss Scarlet, Colonel Mustard, Mrs. White, The Reverend Green, Mrs. Peacock,"
               " and Professor Plum \n");
        printf("Rooms: kitchen, ballroom, conservatory, dining room, billiard room, library,"
               " lounge, hall, and study \n");
        printf("Items: candlestick, dagger, leadpipe, revolver, rope, and wrench \n");
        continue;
    }
    if(look == 0){
        lookAround(&Player1);
        continue;
    }
    if(go == 0){
        printf("In which direction you would like to go?\nType \"north\", \"south\", \"east\", "
        "or \"west\"\n");
        char goInput[30];
        gets(goInput);
        int north = strncmp(goInput, "north", 5);
        int south = strncmp(goInput, "south", 5);
        int east = strncmp(goInput, "east", 4);
        int west = strncmp(goInput, "west", 4);
        while((north & south & east & west) == 1){
            printf("Direction not valid. Please type either \"north\", \"south\", \"east\", "
                   "or \"west\" \n");
            gets(goInput);
            north = strncmp(goInput, "north", 5);
            south = strncmp(goInput, "south", 5);
            east = strncmp(goInput, "east", 4);
            west = strncmp(goInput, "west", 4);
        }
        if(north == 0){
            goTo(&Player1, "North");
        }
        if(south == 0){
            goTo(&Player1, "South");
        }
        if(east == 0) {
            goTo(&Player1, "East");
        }
        if(west == 0){
            goTo(&Player1, "West");
        }
        continue;
    }
    if(take == 0){
        printf("Type an item that you would like to take \n");
        char takeInput[30];
        gets(takeInput);
        int candlestick = strncmp(takeInput, "candlestick", 11);
        int dagger = strncmp(takeInput, "dagger", 6);
        int leadpipe = strncmp(takeInput, "leadpipe", 8);
        int revolver = strncmp(takeInput, "revolver", 8);
        int rope = strncmp(takeInput, "rope", 4);
        int wrench = strncmp(takeInput, "wrench", 6);
        while((candlestick & dagger & leadpipe & revolver & rope & wrench) == 1){
            printf("Item not valid. Please type either \"candlestick\", \"dagger\", \"leadpipe\", "
                   "\"revolver\", \"rope\", \"wrench\" \n");
            gets(takeInput);
            candlestick = strncmp(takeInput, "candlestick", 11);
            dagger = strncmp(takeInput, "dagger", 6);
            leadpipe = strncmp(takeInput, "leadpipe", 8);
            revolver = strncmp(takeInput, "revolver", 8);
            rope = strncmp(takeInput, "rope", 4);
            wrench = strncmp(takeInput, "wrench", 6);
        }
        if(candlestick == 0){
            charAddItems(&Player1, "candlestick");
        }
        if(dagger == 0){
            charAddItems(&Player1, "dagger");
        }
        if(leadpipe == 0){
            charAddItems(&Player1, "leadpipe");
        }
        if(revolver == 0){
            charAddItems(&Player1, "revolver");
        }
        if(rope == 0){
            charAddItems(&Player1, "rope");
        }
        if(wrench == 0){
            charAddItems(&Player1, "wrench");
        }
        continue;
    }
    if(drop == 0){
        printf("Type an item that you would like to drop \n");
        char dropInput[30];
        gets(dropInput);
        int candlestick = strncmp(dropInput, "candlestick", 11);
        int dagger = strncmp(dropInput, "dagger", 6);
        int leadpipe = strncmp(dropInput, "leadpipe", 8);
        int revolver = strncmp(dropInput, "revolver", 8);
        int rope = strncmp(dropInput, "rope", 4);
        int wrench = strncmp(dropInput, "wrench", 6);
        while((candlestick & dagger & leadpipe & revolver & rope & wrench) == 1){
            printf("Item not valid. Please type either \"candlestick\", \"dagger\", \"leadpipe\", "
                   "\"revolver\", \"rope\", \"wrench\" \n");
            gets(dropInput);
            candlestick = strncmp(dropInput, "candlestick", 11);
            dagger = strncmp(dropInput, "dagger", 6);
            leadpipe = strncmp(dropInput, "leadpipe", 8);
            revolver = strncmp(dropInput, "revolver", 8);
            rope = strncmp(dropInput, "rope", 4);
            wrench = strncmp(dropInput, "wrench", 6);
        }
        if(candlestick == 0){
            charDropItems(&Player1, "candlestick");
        }
        if(dagger == 0){
            charDropItems(&Player1, "dagger");
        }
        if(leadpipe == 0){
            charDropItems(&Player1, "leadpipe");
        }
        if(revolver == 0){
            charDropItems(&Player1, "revolver");
        }
        if(rope == 0){
            charDropItems(&Player1, "rope");
        }
        if(wrench == 0){
            charDropItems(&Player1, "wrench");
        }
        continue;
    }
    if(inventory == 0){
        if(Player1.itemList == NULL){
            printf("Your inventory is empty \n");
        }
        else {
            printf("Your inventory: \n");
            struct Item *newItem = Player1.itemList;
            while(newItem != NULL) {
                printf("%s \n", newItem->name);
                newItem = newItem->next;
            }
        }
    }
    if(clue == 0){
        printf("Please type in which character you think committed the crime.\n");
        printf("As a reminder, the valid characters are Miss Scarlet, Colonel Mustard,"
               " Mrs. White, The Reverend Green, Mrs. Peacock, andProfessor Plum \n");
        char clueInput[30];
        gets(clueInput);
        int scarlet = strncmp(clueInput, "Miss Scarlet", 7);
        int mustard = strncmp(clueInput, "Colonel Mustard", 7);
        int white = strncmp(clueInput, "Mrs. White", 7);
        int green = strncmp(clueInput, "The Reverend Green", 7);
        int peacock = strncmp(clueInput, "Mrs. Peacock", 7);
        int plum = strncmp(clueInput, "Professor Plum", 7);
        if((scarlet&mustard&white&green&peacock&plum) == 1){
            printf("The character you typed is invalid. Please retype a valid character. \n");
            printf("As a reminder, the valid characters are Miss Scarlet, Colonel Mustard,"
                   " Mrs. White, The Reverend Green, Mrs. Peacock,and Professor Plum. \n");
            gets(clueInput);
            scarlet = strncmp(clueInput, "Miss Scarlet", 7);
            mustard = strncmp(clueInput, "Colonel Mustard", 7);
            white = strncmp(clueInput, "Mrs. White", 7);
            green = strncmp(clueInput, "The Reverend Green", 7);
            peacock = strncmp(clueInput, "Mrs. Peacock", 7);
            plum = strncmp(clueInput, "Professor Plum", 7);
        }
        if((scarlet&mustard&white&green&peacock&plum) == 1){
            printf("Please type a new command to get started \n");
            continue;
        }
        printf("Please type in the item that you think was used to commit the crime.\n");
        printf("As a reminder, the valid items are candlestick, dagger, leadpipe, revolver, rope, "
               "and wrench. \n");
        char clueItemInput[30];
        gets(clueItemInput);
        int candlestick = strncmp(clueItemInput, "candlestick", 7);
        int dagger = strncmp(clueItemInput, "dagger", 6);
        int leadpipe = strncmp(clueItemInput, "leadpipe", 7);
        int revolver = strncmp(clueItemInput, "revolver", 7);
        int rope = strncmp(clueItemInput, "rope", 4);
        int wrench = strncmp(clueItemInput, "wrench", 6);
        if((candlestick&dagger&leadpipe&revolver&rope&wrench) == 1){
            printf("The item you typed is invalid. Please retype a valid item. \n");
            printf("As a reminder, the valid items are candlestick, dagger, leadpipe, revolver, rope, "
                   "and wrench. \n");
            gets(clueItemInput);
            candlestick = strncmp(clueItemInput, "candlestick", 7);
            dagger = strncmp(clueItemInput, "dagger", 6);
            leadpipe = strncmp(clueItemInput, "leadpipe", 7);
            revolver = strncmp(clueItemInput, "revolver", 7);
            rope = strncmp(clueItemInput, "rope", 4);
            wrench = strncmp(clueItemInput, "wrench", 6);
        }
        if((candlestick&dagger&leadpipe&revolver&rope&wrench) == 1){
            printf("Type a new command to get started \n");
            continue;
        }
        //Moves guessed character into same room as the avatar
        struct Character *clueCharacter = (struct Character*)(malloc(sizeof(struct Character)));
        for(int i = 0; i < NUM_CHARACTERS; i++){
            if(strncmp(characters[i].name, clueInput, 7) == 0){
                clueCharacter = &characters[i];
            }
        }
        *clueCharacter->curRoom = *Player1.curRoom;
        struct Character *lastCharacter = Player1.curRoom->characterList;
        if(Player1.curRoom->characterList == NULL){
            Player1.curRoom->characterList = clueCharacter;
        }
        else{
            while(lastCharacter->next != NULL){
                lastCharacter = lastCharacter->next;
            }
            lastCharacter->next = clueCharacter;
        }
        //Reveal if the character and item guesses are correct
        if(strncmp(Player1.curRoom->name, roomAnswer, 5) == 0){
            printf("ROOM MATCH \n");
        }
        else{
            printf("The room does not match. \n");
        }
        if(strncmp(clueItemInput, itemAnswer, 4) == 0) {
            printf("ITEM MATCH \n");
        }
        else{
            printf("The item guess does not match. \n");
        }
        if(strncmp(clueInput, charAnswer, 6) == 0) {
            printf("CHARACTER MATCH \n");
        }
        else{
            printf("The character guess does not match. \n");
        }
        //Returns game winning result
        if((strncmp(Player1.curRoom->name, roomAnswer, 5) == 0)& (strncmp(clueItemInput, itemAnswer, 4) == 0) &
        (strncmp(clueInput, charAnswer, 6) == 0)){
            printf("Congratulations. You have won the game.");
            freeMemory();
            return 0;
        }
        guesses++;
        if(guesses == 10){
            printf("Sorry, you have ran out of guesses. You have lost the game.");
            freeMemory();
            return 0;
        }
    }
}
}
