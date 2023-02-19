# Part 2

## Video Demo

Please provide the YouTube link to your [Video Demo](https://youtu.be/y_xqtkH0Nrc).

## Minimum Requirements

### Completed

List all the features completed.

1. Game Board 
2. Game Characters
3. Game Objects
4. Game Controls
5. Saving and Loading Game File
6. Game Flow

## Additional Features

Describe the additional features that has been implemented.

1. Added a simple Main Menu to help player navigate the game.
2. Added a section that describes the summary of the game on the Main Menu called "About Game".
3. Added a feature where the player can set random values permanently in the "Settings" on the Main Menu and save it to use the value before starting the game.
4. Added a new game object named "d" that doubles the alien's attack value.

## Contributions

List down the contribution of each group members.

For example:

### Raja Fitri Haziq Bin Raja Mohd Fuad

1. Implemented "Main Menu" that includes Start Game, Load Game, Settings, About Game and Exit features.
2. Implemented "Settings" that allows the player to set a permanenent values for row, column and the amount of
   zombies they want to start the game with. (This feature was implemented using a I/O file functions)
3. Implemented the feature where the player is able to decide for themselves whether or not they want to start
   the game with the default values that has already been set up by the program or the updated values that they
   set up in "Settings".
4. Implemented the feature where the program can detect whether or not the values that the player input into
   the program is valid before printing out the Game Board
5. Implemented "save" feature that allows the player to save the game before quitting the game or returning
   to the Main Menu.
6. Implemented "load" feature that allows the player load the saved file and continue playing it. 
7. Helped Muhammad Irfan in making sure the game flow runs smoother.
8. Implemented the feature where the program can clear the screen and prints out a new output instead of 
   printing all of it in the same screen
9. Organized the code to make the readability better. (Added comments for understanding purposes)
10. Write the documentation.

### Muhammad Irfan Bin Zulkifli

1. Implemented the Game Board that consists of random number of rows, columns and zombies.
2. Implemented Game Objects such as health, pod, arrows and rock into the Game Board.
3. Implemented Alien and Zombies alongside with it attributes such as health, attack and range.
4. Implemented the movement for Alien and how it reacts to the game objects such as health, arrows, pod and
   rock.
5. Implemented the movement for Zombies and how it reacts to the game objects such as the alien itself.
6. Helped Raja Fitri Haziq in implementing the save and load feature for the game.
7. Implemented the feature where the program can clear the screen and prints out a new output instead of 
   printing all of it in the same screen.
8. Implemented the feature where the alien and zombies react to the game objects.
9. Organized the code to make the readability better. (Added comments for understanding purposes).
10. Implemented a new game object named "d" that doubles the alien's attack value.

## Problems Encountered & Solutions

Describe the problems encountered and provide the solutions / plan for the solutions.

1. Problem  => Raja Fitri managed to implement the save and load feature but the load  
               feature only loaded the 
               Game Board instead of letting the player continue playing it after loading it.
   Solution => Muhammad Irfan helped in upgrading the save and load feature by turning it 
               into arrays instead of the string form which is the default form for I/O file functions.
2. Problem  => A minor bug where the player could not return to the Main Menu after 
              finishing the game.
   Solution => Raja Fitri and Muhammad Irfan fixed the bug by making sure the program 
               exits all of the while loop correctly.