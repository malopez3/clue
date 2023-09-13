#define NUM_CHARACTERS 6

typedef struct Room {
    char* name;
    struct Room * North;
    struct Room * South;
    struct Room * East;
    struct Room * West;
    struct Item * itemList;
    struct Character * characterList;
}ROOM;

/**
 * Selects the game answer
 */
void pickAnswer();
/**
 * Randomizes the rooms using a for loop
 */
void randomizeRooms();
/**
 * Frees the memory that was allocated using malloc
 */
void freeMemory();

extern ROOM rooms[];
struct Room;
struct rooms;

extern struct Room *roomAnswer;
extern struct Item *itemAnswer;
extern struct Character *charAnswer;