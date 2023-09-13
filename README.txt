How to compile the code:

The code can be compiled with the gcc command. "gcc adventure.c rooms.c items.c -o clue"
After the code has been compiled, it can be run by typing the executable: "./clue"

How to manage user input:

User input is managed in adventure.c starting at line 42.
The user input functionality works with what is an infinite while loop until the clue winning state breaks
the loop.
Within the while loop, the gets() method receives user input and puts it into a character array called "userInput"
Then it will compare the userInput to the list of commands using strcmp and execute the corresponding method
and functionality.

Overview/Description:

2a. The game has 9 rooms including the starting room, all connected via pointers in a 3x3 map.
This is satisfied in rooms.c lines 8-16, with the Room struct that includes pointers to rooms
in the north, south, east, and west.
The game board is created in rooms.c on lines 20-29, all the room structs are stored in an array.
With the pointers connecting all the rooms in the 3x3 map.

2b. The 9 rooms are randomized in rooms.c lines 33-40.
The randomizeRooms function uses a for loop and rand() to randomize and switch the names of each room.
This function is used in adventure.c in line 12.

2c. There are at least 6 items in the game, with the list of items in the game stored in a itemsList
array on line 25.
These items are randomized and put into a different room with a max of 1 item in each room in items.c
on lines 61-120.

2d. The answer to the game is picked in the pickAnswer() method in rooms.c on lines 48-51.
It is then used in the main method in adventure.c on line 22.

2e. The linked list of items for each room is located in rooms.c on lines 14.
The Item itemlist then contains a next pointer that is located in the item struct in items.c on line 21.

2f. Each avatar also has an inventory in the Player Struct located in items.h on lines 3-7.
The player struct contains an itemList with next pointers just like the Room struct.

2g. Commands

i. The help command is implemented in adventure.c lines 57-69 where it prints out all the commands in the game
with their corresponding descriptions.

ii. The list command is implemented in adventure.c lines 70-79. This command prints out the list of all items,
rooms, and characters in the game.

iii. The look command is implemented in items.c on 159-207 in the lookAround() function. This function prints
out all the rooms in each direction based on pointers.
It also prints out all the items and characters in the room by using a while loop to loop through and print out
each item and character from their itemList and characterList in each room.

iv. The "go" command is implemented in items.c from 209-246 in the goTo() function.
The goTo() function takes in the player (avatar) and the direction the user wants to go in
From there it will either move the character in that direction or if the room in that direction is NULL it doesn't
allow the user to move there.

v. The "take" command is implemented in items.c lines 275-309 with the charAddItems() function and in adventure.c
lines 116-156 that will first, checks to see if the item is in the room by iterating through its "items" linked list,
and if it is then add it to the player's inventory.
If the item is not in the room, it will ask the user to try again using the "take" command.
If the user typed in something that is not an item, the program will prompt the user to retype a valid item.

vi. The "drop" command is implemented in items.c 248-273 in the charDropItems() function.
It is implemented in the main function of the game in adventure.c in lines 157-197.
Firstly, the main function will check to see if the item input is a valid item in the game.
Then, in the charDropItems() function, the game will check to make sure that the item is in the user's inventory.

vii. The inventory output is implemented in adventure.c on lines 198-210.
The inventory simply uses a while loop to iterate through the avatar's item list and prints it out.

viii. In adventure.c starting at line 211, the game prompts the user for the name of the character and item that committed the crime.
Using the "strncmp" function, it compares the user string to the name of characters and the items.
If the input is not valid it prompts the user again for a valid name.

ix. In lines 53-55 of adventure.c, if the command typed is not recognized then it restarts the while loop
and looks for a valid command again.

h. "clue" three steps

i. In lines 266-283 in adventure.c, the character that was guessed as the murderer is moved into the current room
This is accomplished first by locating the characters array position that the character is located in, and
then changing the curRoom
Additionally, the character is then added to the room's linkedList of characters.

ii. In lines 307-324, the game compares the received answers to the game answer. It will compare the inputted
character guess and item guess to the game's autogenerated answers.
It will then compare the current room to the room where the character that committed the crime is.

iii. If all three guesses are correct, then the game returns the winning state in lines 304-308 in adventure.c.
In lines 332-336, the game makes sure that the player is still under the maximum number of 10 guesses,
if they are at 10 guesses, then it exits the game and lets the player know that they lost.

Project Requirements

1. C structs are used in this program to create the various game objects. There is a corresponding struct for room
(see rooms.h starting at line 3), a struct for player (the user of the game) starting on line 3 of items.h, a
struct for characters (starting on line 9 of items.h), and an item struct (starting on line 16 of items.h).

2. Pointers are used in my program, they are used to link the rooms in the room struct (see rooms.h line 3).
They are also used in changing the avatar's current location with the Room* curRoom pointer in the Player struct
(see line 5 of items.h). Finally, it is used in the linked list implementation of both the itemList and characterList
in each room with a next pointer that connects each room to each other (see items.h lines 12 and 18).

3. There is dynamic memory allocation in this program for the linked list implementations.
In both addCharacters and addItems, that add a character and an item to the room, they each create a new struct
using malloc to dynamically allocate memory.

4. The memory that was allocated during the game is then freed by the freeMemory() method implemented in rooms.c on
lines 54-75, this method uses free() to free the memory that was stored in each of the rooms item lists and
character lists.




