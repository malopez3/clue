#define NUM_CHARACTERS 6

typedef struct Player{
    char* name;
    struct Room* curRoom;
    struct Item* itemList;
}PLAYER;

typedef struct Character{
    char* name;
    struct Room* curRoom;
    struct Character* next;
    int* roomNum;
}CHARACTER;

typedef struct Item{
    char* name;
    struct Item* next;
    struct Room* curRoom;
}ITEM;

extern char *itemsList[];

extern CHARACTER characters[];
struct Character;
struct characters;
extern PLAYER *Player1;

/**
 * Allows the avatar to look around and see what is in the room, and rooms in all directions
 * @param playerName
 */
 void lookAround(struct Player* playerName);
/**
* Initializes the items onto the board
*/
void initializeItems();
/**
* Randomizes the character locations onto the board
*/
void randomizeCharacters();
/**
* Can add items into rooms
 * @param name
 * @param roomNum
*/
void addItems(char* name, int roomNum);
/**
* Can add characters into rooms
 * @param name
 * @param roomNum
*/
void addCharacters(char* name, int roomNum);
/**
* Allows the character to move from room to room
 * @param player
 * @param direction
*/
void goTo(struct Player *player, char* direction);
/**
* Allows a character to add items into their inventory
 * @param player
 * @param name
*/
void charAddItems(struct Player *player, char* name);
/**
* Allows a character to drop items from their inventory
 * @param player
 * @param name
*/
void charDropItems(struct Player *player, char* name);
/**
* Initializes the player into the game
 * @param player
*/
void initializePlayer(struct Player *inputPlayer);