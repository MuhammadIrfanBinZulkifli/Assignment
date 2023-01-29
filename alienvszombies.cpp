// *********************************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Year: Trimester 1, 2022/23 (T2215)
// Lab: TT8L
// Names: RAJA FITRI HAZIQ BIN RAJA MOHD FUAD | MUHAMMAD IRFAN BIN ZULKIFLI   |
// IDs:                            1211101242 | 1211103094                    | 
// Emails:      1211101242@student.mmu.edu.my | 1211103094@student.mmu.edu.my | 
// Phones:                         0132720692 | 0194313650                    | 
// *********************************************************

#include "table-making.hpp"
#include "player-stats.hpp"

void gameMainMenu() // Void function for Alien Vs Zombies Main Menu
{
    // Game Menu for Alien Vs Zombies
    cout << " +-+-+-+-+-+-+-+-+-+-+-+-+ " << endl;
    cout << "   .: Alien Vs Zombies :.  " << endl;
    cout << " +-+-+-+-+-+-+-+-+-+-+-+-+ " << endl;
    cout << " | 1. Start Game          |" << endl;
    cout << " | 2. Load Game           |" << endl;
    cout << " | 3. About Game          |" << endl;
    cout << " | 4. Exit                |" << endl;
    cout << " +-+-+-+-+-+-+-+-+-+-+-+-+ " << endl;
}


int main()
{
    bool mainMenu = true;
    
    while(mainMenu)
    {
        int playerChoice;

        system("CLS");
        gameMainMenu(); // Display main menu for Alien Vs Zombies
        cout << "Your choice => ";
        cin >> playerChoice; // Ask the player to choose an option (1, 2, 3 or 4)

        // If statement if player chose 1 to start game
        if (playerChoice == 1)
        {
            mainMenu = false; // Ignore mainMenu
            int rowNum = 9, colNum = 21, zombiesNum = 9; // Default values for the number of row, column and zombies
            char playerChoice;                           // Define the variable for player's choice to change the default values
            bool gameSettings = true;                    // Define the variable for gameSettings for loop purposes

            while (gameSettings)
            {
                // Display default values before printing the Game Board
                system("CLS");
                cout << " Game Board Settings " << endl;
                cout << " +-+-+-+-+-+-+-+-+-+ " << endl;
                cout << " Row => " << rowNum << endl;
                cout << " Column => " << colNum << endl;
                cout << " Zombies => " << zombiesNum << endl;
                cout << " +-+-+-+-+-+-+-+-+-+ " << endl;

                // Ask the player if he/she wants to change the default values
                cout << " Do you want to change the default values? (y/n) => ";
                cin >> playerChoice;

                // If statement if player decides to change the default value
                if (playerChoice == 'Y' || playerChoice == 'y')
                {
                    gameSettings = false;                       // Ignore gameSettings
                    int rowNum = 0, colNum = 0, zombiesNum = 0; // Resets default values to 0
                    char playerChoice;                          // Define the variable for player's choice
                    bool resetSettings = true;                  // Define the variable for newSettings and resetStatement for loop purposes

                    while (resetSettings)
                    {
                        // Ask the player to type in new values for row, column and zombies
                        system("CLS");
                        cout << " Enter a new value for row => ";
                        cin >> rowNum;
                        cout << " Enter a new value for column => ";
                        cin >> colNum;
                        cout << " Enter a new value for zombies => ";
                        cin >> zombiesNum;

                        if (rowNum > 9 || rowNum < 3)
                        {
                            cout << " Reminder: Minimum number of row is 3 and maximum number of row is 9" << endl;
                            system("PAUSE");
                            resetSettings = true;
                        }
                        else if (colNum > 21 || colNum < 3)
                        {
                            cout << " Reminder: Minimum number of column is 3 and maximum number of column is 21" << endl;
                            system("PAUSE");
                            resetSettings = true;
                        }
                        else if (zombiesNum > 9 || zombiesNum < 1)
                        {
                            cout << " Reminder: Minimum number of zombies is 1 and maximum number of column is 9" << endl;
                            system("PAUSE");
                            resetSettings = true;
                        }
                        else
                        {
                            // Prints out the new updated value from previous statement
                            system("CLS");
                            cout << " Game Board Settings " << endl;
                            cout << " +-+-+-+-+-+-+-+-+-+ " << endl;
                            cout << " Row => " << rowNum << endl;
                            cout << " Column => " << colNum << endl;
                            cout << " Zombies => " << zombiesNum << endl;
                            cout << " +-+-+-+-+-+-+-+-+-+ " << endl;

                            // Ask whether or not the player wants to continue with the updated value or resets it
                            cout << " C to continue/R to reset " << endl;
                            cout << " Continue? (c/r)=> ";
                            cin >> playerChoice;

                            // If statement if the player wants to continue
                            if (playerChoice == 'C' || playerChoice == 'c')
                            {
                                resetSettings = false; // Ignore resetSettings
                                gameSettings = false;  // Ignore gameSettings

                                system("CLS");
                                MakingTable(rowNum, colNum, zombiesNum);
                                cout << endl;
                                PlayerStats stats(rowNum, colNum, zombiesNum);
                                stats.displayStats(stats.alienStats, stats.allZombiesStats, zombiesNum);
                                system("PAUSE");
                            }
                            // Else if statement if the player wants to reset
                            else if (playerChoice == 'r' || playerChoice == 'R')
                            {
                                resetSettings = true; // Return newSettings
                                gameSettings = false; // Ignore gameSettings
                            }
                            // Else statement if the player inputs in neither C or R
                            else
                            {
                                cout << " Invalid input! Please try again..." << endl;
                                system("PAUSE");
                                resetSettings = true; // Ignore newSettings
                                gameSettings = false; // Ignore gameSettings
                            }
                        }
                    }
                }
                // Else if statement if the player doesn't want to change the value
                else if (playerChoice == 'N' || playerChoice == 'n')
                {
                    gameSettings = false; // Ignore gameSettings

                    system("CLS");
                    MakingTable(rowNum, colNum, zombiesNum);
                    cout << endl;
                    PlayerStats stats(rowNum, colNum, zombiesNum);
                    stats.displayStats(stats.alienStats, stats.allZombiesStats, zombiesNum);
                    system("PAUSE");
                }
                else
                {
                    cout << " Invalid input! Please try again... " << endl;
                    system("PAUSE");
                    gameSettings = true; // Return gameSettings
                }
            }
        }
        else if (playerChoice == 2)
        {
            mainMenu = false;

            system("CLS");
            cout << "Work In Progress..." << endl;
            system("PAUSE");
        }
        else if (playerChoice == 3)
        {
            mainMenu = false;
            
            char playerChoice;
            bool aboutGame = true;

            while (aboutGame)
            {
                system("CLS");
                cout << " +-+-+-+-+-+-++-+-+-+-+-+-++-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ " << endl;
                cout << "                          About Game                       " << endl;
                cout << " +-+-+-+-+-+-++-+-+-+-+-+-++-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ " << endl;
                cout << "| Alien vs Zombie is a turn-based combat game            |\n| in which the player controls Alien to defeat           |\n| a group of Zombies. Prior to the game, the player      |\n| can customize settings including game board dimensions |\n| and number of zombies. The player can also save        |\n| a game into a file and load a game from a file.        |" << endl;
                cout << " +-+-+-+-+-+-++-+-+-+-+-+-++-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ " << endl;
                cout << "Return to main menu? (y/n) => ";
                cin >> playerChoice;
                if (playerChoice == 'y' || playerChoice == 'y')
                {
                    aboutGame = false;
                    mainMenu = true;
                }
                else if (playerChoice == 'N' || playerChoice == 'n')
                {
                    aboutGame = false;
                    mainMenu = false;
                    cout << "Goodbye! " << endl;
                    system("PAUSE");
                    break;
                }
                else
                {
                    aboutGame = true;
                    mainMenu = false;
                    cout << "Invalid input! Please try again..." << endl;
                    system("PAUSE");
                }
            }
        }
        else if (playerChoice == 4)
        {
            mainMenu = false;
            cout << endl;
            cout << "Goodbye! Thanks for playing..." << endl;
            system("PAUSE");
            break;
        }
        else
        {
            mainMenu = true;
            cout << endl;
            cout << "Invalid input! Please try again..." << endl;
            system("PAUSE");
        }
    }
}