// *********************************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Year: Trimester 1, 2022/23 (T2215)
// Lab: TT8L
// Names: RAJA FITRI HAZIQ BIN RAJA MOHD FUAD | MUHAMMAD IRFAN BIN ZULKIFLI   |
// IDs:                            1211101242 | 1211103094                    |
// Emails:      1211101242@student.mmu.edu.my | 1211103094@student.mmu.edu.my |
// Phones:                         0132720692 | 0194313650                    |
// *********************************************************

#include "table-making.hpp" // Include everything inside a hpp file called "table-making"

// A void function to print the Game Board
void tablePrinting(vector<vector<char>> &table, vector<int> &alienStats, vector<vector<int>> &allZombiesStats, const int x, const int y, const int z)
{
    // Program starts printing the Game Board based on the row, column and zombies numbers
    cout << "=================================== " << endl;
    cout << "Player! Welcome To Alien Vs Zombies " << endl;
    cout << "=================================== " << endl;
    cout << endl;

    for (int j = 0; j < y; ++j)
    {
        cout << "+-";
    }
    cout << '+' << endl;
    for (int i = 0; i < table.size(); ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            cout << '|';
            cout << table[i][j];
        }
        cout << '|' << setw(3) << i + 1 << endl;
        for (int k = 0; k < y; ++k)
        {
            cout << "+-";
        }
        cout << '+' << endl;
    }
    for (int j = 0; j < y; ++j)
    {
        int digit = (j + 1) / 10;
        cout << " ";
        if (digit == 0)
        {
            cout << " ";
        }
        else
        {
            cout << digit;
        }
    }
    cout << endl;
    for (int j = 0; j < y; ++j)
    {
        cout << " " << (j + 1) % 10;
    }

    cout << endl
         << endl;
    cout << endl;

    cout << "Alien     :"
         << " Life " << alienStats[0] << " , "
         << " Attack " << alienStats[1] << endl;
    for (int i = 0; i < z; i++)
    {
        cout << "Zombie " << i + 1 << "  :"
             << " Life " << allZombiesStats[i][0] << " , "
             << " Attack " << allZombiesStats[i][1] << " , "
             << " Range " << allZombiesStats[i][2] << endl;
    }
    // Program stops printing out the Game Board based on the row, column and zombies number
}

// An int function to identify the number of rows to insert Alien in the middle of the Game Board
int rowCoordinate(vector<vector<char>> &table, const int y)
{
    // Defining a variable called row with "int"
    int row;

    // Program starts going through for loop to identify the middle and of the Game Board and insert Alien
    for (int i = 0; i < table.size(); ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            if (table[i][j] == 'A')
            {
                row = i;
            }
        }
    }
    return row;
    // Program stops going through for loop to identify the middle and of the Game Board and insert Alien
}

// An int function to identify the number of column being printed based on the players' choices
int colCoordinate(vector<vector<char>> &table, const int y)
{
    // Defining a variable called col with "int"
    int col;

    // Program starts going through for loop to identify the middle and of the Game Board and insert Alien
    for (int i = 0; i < table.size(); ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            if (table[i][j] == 'A')
            {
                col = j;
            }
        }
    }
    return col;
    // Program stops going through for loop to identify the middle and of the Game Board and insert Alien
}

// A void function to change the direction of arrows based on the players' choice that are present in the Game Board
void changeArrow(vector<vector<char>> &table, int arrRow, int arrCol, string direction)
{
    //An if statement if the player wants to change the direction of the arrow from any direction to up
    if (direction.compare("up") == 0)
    {
        table[arrRow - 1][arrCol - 1] = '^';
    }
    //An if statement if the player wants to change the direction of the arrow from any direction to down
    else if (direction.compare("down") == 0)
    {
        table[arrRow - 1][arrCol - 1] = 'v';
    }
    //An if statement if the player wants to change the direction of the arrow from any direction to left
    else if (direction.compare("left") == 0)
    {
        table[arrRow - 1][arrCol - 1] = '<';
    }
    //An if statement if the player wants to change the direction of the arrow from any direction to right
    else if (direction.compare("right") == 0)
    {
        table[arrRow - 1][arrCol - 1] = '>';
    }

}

// An int function to identify empty row spaces inside the Game Board to insert Zombies
int zombiesRow(vector<vector<char>> &table, char zombChar, const int y)
{
    // Defining a variable called rowZ with "int"
    int rowZ;

    // Program starts to identify empty row spaces to insert Zombies
    for (int i = 0; i < table.size(); ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            if (table[i][j] == zombChar)
            {
                rowZ = i;
            }
        }
    }
    return rowZ;
    // Program stops to identify empty row spaces to insert Zombies
}

// An int function to identify empty column spaces inside the Game Board to insert Zombies
int zombiesCol(vector<vector<char>> &table, char zombChar, const int y)
{
    // Defining a variable called colZ with "int"
    int colZ;

    // Program starts to identify column empty spaces to insert Zombies
    for (int i = 0; i < table.size(); ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            if (table[i][j] == zombChar)
            {
                colZ = j;
            }
        }
    }
    return colZ;
    // Program starts to identify empty column spaces to insert Zombies
}

// An int function to check whether or not up is empty before Zombies start moving up
int checkUp(vector<vector<char>> &table, const int rowZ, const int colZ)
{
    // An if statement if the space upward of the zombies is occupied by Alien or Zombies
    if ((table[rowZ - 1][colZ] == 'A') || (table[rowZ - 1][colZ] == '1') || (table[rowZ - 1][colZ] == '2') || (table[rowZ - 1][colZ] == '3') || (table[rowZ - 1][colZ] == '4') || (table[rowZ - 1][colZ] == '5') || (table[rowZ - 1][colZ] == '6') || (table[rowZ - 1][colZ] == '7') || (table[rowZ - 1][colZ] == '8') || (table[rowZ - 1][colZ] == '9'))
    {
        return 0; 
    }
    // An else if statement if the space upward of the zombies is not occupied by Alien or Zombies
    else
    {
        return 1; 
    }
}

// An int function to check whether or not up is empty before Zombies start moving down
int checkDown(vector<vector<char>> &table, const int rowZ, const int colZ)
{
    // An if statement if the space downward of the zombies is occupied by Alien or Zombies
    if ((table[rowZ + 1][colZ] == 'A') || (table[rowZ + 1][colZ] == '1') || (table[rowZ + 1][colZ] == '2') || (table[rowZ + 1][colZ] == '3') || (table[rowZ + 1][colZ] == '4') || (table[rowZ + 1][colZ] == '5') || (table[rowZ + 1][colZ] == '6') || (table[rowZ + 1][colZ] == '7') || (table[rowZ + 1][colZ] == '8') || (table[rowZ + 1][colZ] == '9'))
    {
        return 0; 
    }
    // An if statement if the space downward of the zombies is not occupied by Alien or Zombies
    else
    {
        return 1; 
    }
}

// An int function to check whether or not up is empty before Zombies start moving left
int checkLeft(vector<vector<char>> &table, const int rowZ, const int colZ)
{
    // An if statement if the space left of the zombies is occupied by Alien or Zombies
    if ((table[rowZ][colZ - 1] == 'A') || (table[rowZ][colZ - 1] == '1') || (table[rowZ][colZ - 1] == '2') || (table[rowZ][colZ - 1] == '3') || (table[rowZ][colZ - 1] == '4') || (table[rowZ][colZ - 1] == '5') || (table[rowZ][colZ - 1] == '6') || (table[rowZ][colZ - 1] == '7') || (table[rowZ][colZ - 1] == '8') || (table[rowZ][colZ - 1] == '9'))
    {
        return 0; 
    }
    // An if statement if the space left of the zombies is not occupied by Alien or Zombies
    else
    {
        return 1; 
    }
}

// An int function to check whether or not up is empty before Zombies start moving right
int checkRight(vector<vector<char>> &table, const int rowZ, const int colZ)
{
    // An if statement if the space right of the zombies is occupied by Alien or Zombies
    if ((table[rowZ][colZ + 1] == 'A') || (table[rowZ][colZ + 1] == '1') || (table[rowZ][colZ + 1] == '2') || (table[rowZ][colZ + 1] == '3') || (table[rowZ][colZ + 1] == '4') || (table[rowZ][colZ + 1] == '5') || (table[rowZ][colZ + 1] == '6') || (table[rowZ][colZ + 1] == '7') || (table[rowZ][colZ + 1] == '8') || (table[rowZ][colZ + 1] == '9'))
    {
        return 0; 
    }
    // An if statement if the space right of the zombies is not occupied by Alien or Zombies
    else
    {
        return 1; 
    }
}

// A void function for in-game attribute called pod to refelct damage to nearby zombies
void podDamage(vector<vector<char>> &table, vector<vector<int>> &allZombiesStats, vector<int> &turn, const int x, const int y, const int z)
{
    // Defining variables called rowA, colA, nearestIndex, smallValue and indZombInStats with "int",
    // a variable called allRange with vector<int> (contain the distance of the zombies from the alien)
    // and a variable called zombCoordinate with vector<vector<int>> (contain the coordinate of all zombies that are still alive)
    int rowA = rowCoordinate(table, y), colA = colCoordinate(table, y), nearestIndex, smallValue = 50, indZombInStats;
    vector<int> allRange;               
    vector<vector<int>> zombCoordinate;

    // Program starts going through loop to find the coordinate of all zombies that are alive & store it in the vector of zombCoordinate
    for (int i = 1; i < turn.size(); ++i) 
    {
        vector<int> inCoor;
        char zombChar = '0' + turn[i]; 
        
        for (int j = 0; j < table.size(); ++j)
        {
            for (int k = 0; k < y; ++k)
            {
                if (table[j][k] == zombChar)
                {
                    int rowZomb = zombiesRow(table, zombChar, y); 
                    int colZomb = zombiesCol(table, zombChar, y); 
                    inCoor.push_back(colZomb);
                    inCoor.push_back(rowZomb);        
                    zombCoordinate.push_back(inCoor); 
                }
            }
        }
    }
    // Program stops going through for loop to find the coordinate of all zombies that are alive & store it in the vector of zombCoordinate

    // Program starts going through for loop to calculate the column distance between all zombies and the alien itself
    for (int i = 0; i < zombCoordinate.size(); ++i)
    {
        int tempDis = 0;
        if (zombCoordinate[i][0] <= colA)
        {
            tempDis = colA - zombCoordinate[i][0]; 
            allRange.push_back(tempDis);          
        }
        else
        {
            tempDis = zombCoordinate[i][0] - colA; 
            allRange.push_back(tempDis);           
        }
    }
    // Program stops going through for loop to calculate the column distance between all zombies and the alien itself

    // Program starts going through for loop to calculate the row distance between all zombies and the alien itself
    for (int i = 0; i < allRange.size(); ++i)
    {
        int rowDistance = 0;
        if (zombCoordinate[i][1] <= rowA)
        {
            rowDistance = rowA - zombCoordinate[i][1]; 
            allRange[i] = allRange[i] + rowDistance;   
        }
        else
        {
            rowDistance = zombCoordinate[i][1] - rowA; 
            allRange[i] = allRange[i] + rowDistance;   
        }
    }
    // Program stops going through for loop to calculate the row distance between all zombies and the alien itself

    // Program starts going through for loop to find the nearest distance of the zombies and the alien itself
    for (int i = 0; i < allRange.size(); ++i) 
    {
        if (allRange[i] < smallValue) 
        {
            smallValue = allRange[i]; 
        }
    }

    for (int i = 0; i < allRange.size(); ++i)
    {
        if (allRange[i] == smallValue)
        {
            nearestIndex = i + 1;
            break;
        }
    }
    // Program stops going through for loop to find the nearest distance of the zombies and the alien itself

    int zombieTurn = turn[nearestIndex] - 1; 

    if (allZombiesStats[zombieTurn][0] > 10) 
    {
        allZombiesStats[zombieTurn][0] = allZombiesStats[zombieTurn][0] - 10;
    }
    else
    {
        allZombiesStats[zombieTurn][0] = 0;
        turn.erase(turn.begin() + nearestIndex);
    }
}

// A void function for Alien's movement
void alienMovement(string option, vector<vector<char>> &table, vector<int> &alienStats, vector<vector<int>> &allZombiesStats, MakingTable board, const int x, const int y, const int z, vector<int> &turn)
{
    int rowA = rowCoordinate(table, y), colA = colCoordinate(table, y), conds, messageInd, stopIndicator = 1, drive = 1, stop = 0, equateX, equateY, prevX, prevY;
    char withinA;

    if (option.compare("up") == 0)
    {
        drive = rowA; 
        stop = 0;
        equateX = rowA - 1; 
        equateY = colA;     
        prevX = rowA;
        prevY = colA;
        conds = 1;
    }
    else if (option.compare("down") == 0)
    {
        drive = rowA;
        stop = x - 1;
        equateX = rowA + 1;
        equateY = colA;
        prevX = rowA;
        prevY = colA;
        conds = 2;
    }
    else if (option.compare("left") == 0)
    {
        drive = colA;
        stop = 0;
        equateX = rowA;
        equateY = colA - 1;
        prevX = rowA;
        prevY = colA;
        conds = 3;
    }
    else if (option.compare("right") == 0)
    {
        drive = colA;
        stop = y - 1;
        equateX = rowA;
        equateY = colA + 1;
        prevX = rowA;
        prevY = colA;
        conds = 4;
    }
    else
    {
        cout << "Invalid input. Please make sure you the input are accurate." << endl;
    }

    while ((drive != stop) && (stopIndicator != 0)) 
    {
        withinA = table[equateX][equateY];

        if ((withinA == '^'))
        {
            table[equateX][equateY] = 'A';
            table[rowA][colA] = '.';
            alienStats[1] = alienStats[1] + 20;
            rowA = rowCoordinate(table, y);
            colA = colCoordinate(table, y);
            drive = rowA;
            stop = 0;
            equateX = rowA - 1;
            equateY = colA, conds = 1;
            messageInd = 5;
        }
        else if ((withinA == 'v'))
        {
            table[equateX][equateY] = 'A';
            table[rowA][colA] = '.';
            alienStats[1] = alienStats[1] + 20;
            rowA = rowCoordinate(table, y);
            colA = colCoordinate(table, y);
            drive = rowA;
            stop = x - 1;
            equateX = rowA + 1;
            equateY = colA, conds = 2;
            messageInd = 5;
        }
        else if ((withinA == '<'))
        {
            table[equateX][equateY] = 'A';
            table[rowA][colA] = '.';
            alienStats[1] = alienStats[1] + 20;
            rowA = rowCoordinate(table, y);
            colA = colCoordinate(table, y);
            drive = colA;
            stop = 0;
            equateX = rowA;
            equateY = colA - 1, conds = 3;
            messageInd = 5;
        }
        else if ((withinA == '>'))
        {
            table[equateX][equateY] = 'A';
            table[rowA][colA] = '.';
            alienStats[1] = alienStats[1] + 20;
            rowA = rowCoordinate(table, y);
            colA = colCoordinate(table, y);
            drive = colA;
            stop = y - 1;
            equateX = rowA;
            equateY = colA + 1, conds = 4;
            messageInd = 5;
        }
        else if ((withinA == 'r'))
        {
            while (table[equateX][equateY] == 'r')
            {
                table[equateX][equateY] = board.objectGenerator();
            }

            messageInd = 1;
            stopIndicator = 0;
            rowA = rowCoordinate(table, y);
            colA = colCoordinate(table, y);

            if (conds == 1)
            {
                drive = rowA;
                stop = 0;
                equateX = rowA - 1;
                equateY = colA;
            }
            else if (conds == 2)
            {
                drive = rowA;
                stop = x - 1;
                equateX = rowA + 1;
                equateY = colA;
            }
            else if (conds == 3)
            {
                drive = colA;
                stop = 0;
                equateX = rowA;
                equateY = colA - 1;
            }
            else if (conds == 4)
            {
                drive = colA;
                stop = y - 1;
                equateX = rowA;
                equateY = colA + 1;
            }
        }
        else if ((withinA == '1' || withinA == '2' || withinA == '3' || withinA == '4' || withinA == '5' || withinA == '6' || withinA == '7' || withinA == '8' || withinA == '9'))
        {
            int indZombie = withinA - '0' - 1;
            int indZombieTurn = withinA - '0';

            if (allZombiesStats[indZombie][0] <= alienStats[1])
            {
                allZombiesStats[indZombie][0] = 0;
                table[equateX][equateY] = 'A';
                table[rowA][colA] = '.';
                rowA = rowCoordinate(table, y); 
                colA = colCoordinate(table, y); 
                if (conds == 1)
                {
                    drive = rowA;
                    stop = 0;
                    equateX = rowA - 1;
                    equateY = colA;
                }
                else if (conds == 2)
                {
                    drive = rowA;
                    stop = x - 1;
                    equateX = rowA + 1;
                    equateY = colA;
                }
                else if (conds == 3)
                {
                    drive = colA;
                    stop = 0;
                    equateX = rowA;
                    equateY = colA - 1;
                }
                else if (conds == 4)
                {
                    drive = colA;
                    stop = y - 1;
                    equateX = rowA;
                    equateY = colA + 1;
                }
                for (int i = 0; i < turn.size(); ++i)
                {
                    if (turn[i] == (withinA - '0'))
                    {
                        turn.erase(turn.begin() + i);
                    }
                }
            }
            else
            {
                stopIndicator = 0;
                allZombiesStats[indZombie][0] = allZombiesStats[indZombie][0] - alienStats[1];
                messageInd = 2;
                rowA = rowCoordinate(table, y);
                colA = colCoordinate(table, y);

                if (conds == 1)
                {
                    drive = rowA;
                    stop = 0;
                    equateX = rowA - 1;
                    equateY = colA;
                }
                else if (conds == 2)
                {
                    drive = rowA;
                    stop = x - 1;
                    equateX = rowA + 1;
                    equateY = colA;
                }
                else if (conds == 3)
                {
                    drive = colA;
                    stop = 0;
                    equateX = rowA;
                    equateY = colA - 1;
                }
                else if (conds == 4)
                {
                    drive = colA;
                    stop = y - 1;
                    equateX = rowA;
                    equateY = colA + 1;
                }
            }
        }
        else if ((withinA == 'p'))
        {
            table[equateX][equateY] = 'A';
            table[rowA][colA] = '.';
            rowA = rowCoordinate(table, y);
            colA = colCoordinate(table, y);
            messageInd = 4;
            podDamage(table, allZombiesStats, turn, x, y, z); 

            if (conds == 1)
            {
                drive = rowA;
                stop = 0;
                equateX = rowA - 1;
                equateY = colA;
            }
            else if (conds == 2)
            {
                drive = rowA;
                stop = x - 1;
                equateX = rowA + 1;
                equateY = colA;
            }
            else if (conds == 3)
            {
                drive = colA;
                stop = 0;
                equateX = rowA;
                equateY = colA - 1;
            }
            else if (conds == 4)
            {
                drive = colA;
                stop = y - 1;
                equateX = rowA;
                equateY = colA + 1;
            }
        }
        else if ((withinA == ' '))
        {
            table[equateX][equateY] = 'A';
            table[rowA][colA] = '.';
            rowA = rowCoordinate(table, y);
            colA = colCoordinate(table, y);

            if (conds == 1)
            {
                drive = rowA;
                stop = 0;
                equateX = rowA - 1;
                equateY = colA; 
            }
            else if (conds == 2)
            {
                drive = rowA;
                stop = x - 1;
                equateX = rowA + 1;
                equateY = colA;
            }
            else if (conds == 3)
            {
                drive = colA;
                stop = 0;
                equateX = rowA;
                equateY = colA - 1;
            }
            else if (conds == 4)
            {
                drive = colA;
                stop = y - 1;
                equateX = rowA;
                equateY = colA + 1;
            }
        }
        else if ((withinA == 'h'))
        {
            table[equateX][equateY] = 'A';
            table[rowA][colA] = '.';
            rowA = rowCoordinate(table, y);
            colA = colCoordinate(table, y);

            if (alienStats[0] < 80)
            {
                alienStats[0] = alienStats[0] + 20;
            }
            else
            {
                alienStats[0] = 100;
            }

            messageInd = 3;

            if (conds == 1)
            {
                drive = rowA;
                stop = 0;
                equateX = rowA - 1;
                equateY = colA; 
            }
            else if (conds == 2)
            {
                drive = rowA;
                stop = x - 1;
                equateX = rowA + 1;
                equateY = colA;
            }
            else if (conds == 3)
            {
                drive = colA;
                stop = 0;
                equateX = rowA;
                equateY = colA - 1;
            }
            else if (conds == 4)
            {
                drive = colA;
                stop = y - 1;
                equateX = rowA;
                equateY = colA + 1;
            }
        }
        else
        {
            table[equateX][equateY] = 'A';
            table[rowA][colA] = '.';
            rowA = rowCoordinate(table, y);
            colA = colCoordinate(table, y);

            if (conds == 1)
            {
                drive = rowA;
                stop = 0;
                equateX = rowA - 1;
                equateY = colA;
            }
            else if (conds == 2)
            {
                drive = rowA;
                stop = x - 1;
                equateX = rowA + 1;
                equateY = colA;
            }
            else if (conds == 3)
            {
                drive = colA;
                stop = 0;
                equateX = rowA;
                equateY = colA - 1;
            }
            else if (conds == 4)
            {
                drive = colA;
                stop = y - 1;
                equateX = rowA;
                equateY = colA + 1;
            }
        }

        system("CLS");

        tablePrinting(table, alienStats, allZombiesStats, x, y, z);

        if (messageInd == 1)
        {
            cout << endl << "You have encountered a rock. Your turn has ended." << endl << "Secret objects awaits you....." << endl;
        }
        else if (messageInd == 2)
        {
            cout << endl << "You have encountered a zombie whose life value is higher than your attack value." << endl << "Your turn has ended." << endl;
        }
        else if (messageInd == 3)
        {
            cout << endl << "Congrats!!! You have found a health pack with a value of 20." << endl << "Have a safe journey." << endl;
        }
        else if (messageInd == 4)
        {
            cout << endl << "You encounterd a pod. 10 value of damage is applied to the nearest zombie." << endl;
        }
        else if (messageInd == 5)
        {
            cout << endl << "You endcountered an arrow. Your attack value increase by 20." << endl;
        }

        system("PAUSE");
    }

    for (int i = 0; i < table.size(); ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            if (table[i][j] == '.')
            {
                table[i][j] = board.objectGenerator();
            }
        }
    }
    alienStats[1] = 0;
}

// A void function for Zombies' movement
void zombieMovement(vector<vector<char>> &table, vector<int> &alienStats, vector<vector<int>> &allZombiesStats, int zombTurn, vector<int> &turn, const int x, const int y, const int z)
{
    char zombChar = '0' + zombTurn;
    int move = 1, rowA = rowCoordinate(table, y), colA = colCoordinate(table, y), zombStatsIndex = zombTurn - 1, rowZ = zombiesRow(table, zombChar, y), colZ = zombiesCol(table, zombChar, y); 
    
    while (move < 3)
    {
        if (move == 1)
        {
            if (rowZ == 0)
            {
                if (colZ == 0)
                {
                    int withinRight = checkRight(table, rowZ, colZ), withinDown = checkDown(table, rowZ, colZ);
                    
                    if (withinRight == 1)
                    {
                        table[rowZ][colZ + 1] = zombChar;
                        table[rowZ][colZ] = ' ';
                        move = move + 1;

                        system("CLS");

                        tablePrinting(table, alienStats, allZombiesStats, x, y, z);

                        cout << endl; cout << "Zombie " << zombChar << " moves to the right." << endl;

                        system("PAUSE");
                    }
                    else if (withinDown == 1)
                    {
                        table[rowZ + 1][colZ] = zombChar;
                        table[rowZ][colZ] = ' ';
                        move = move + 1;

                        system("CLS");

                        tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                        
                        cout << endl; cout << "Zombie " << zombChar << " moves downwards." << endl;

                        system("PAUSE");
                    }
                    else
                    {
                        system("CLS");

                        move = move + 1;

                        tablePrinting(table, alienStats, allZombiesStats, x, y, z);

                        cout << endl; cout << "Zombie " << zombChar << " are restricted to move." << endl;
                        
                        system("PAUSE");
                    }
                }
                else if (colZ == y - 1)
                {
                    int withinLeft = checkLeft(table, rowZ, colZ), withinDown = checkDown(table, rowZ, colZ);

                    if (withinLeft == 1)
                    {
                        table[rowZ][colZ - 1] = zombChar;
                        table[rowZ][colZ] = ' ';
                        move = move + 1;

                        system("CLS");

                        tablePrinting(table, alienStats, allZombiesStats, x, y, z);

                        cout << endl; cout << "Zombie " << zombChar << " moves to the left." << endl;
                        
                        system("PAUSE");
                    }
                    else if (withinDown == 1)
                    {
                        table[rowZ + 1][colZ] = zombChar;
                        table[rowZ][colZ] = ' ';
                        move = move + 1;

                        system("CLS");

                        tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                        cout << endl; cout << "Zombie " << zombChar << " moves downwards." << endl;

                        system("PAUSE");
                    }
                    else
                    {
                        system("CLS");

                        move = move + 1;

                        tablePrinting(table, alienStats, allZombiesStats, x, y, z);

                        cout << endl; cout << "Zombie " << zombChar << " are restricted to move." << endl;
                        
                        system("PAUSE");
                    }
                }
                else
                {
                    int withinLeft = checkLeft(table, rowZ, colZ), withinRight = checkRight(table, rowZ, colZ), withinDown = checkDown(table, rowZ, colZ);
                    
                    if (withinLeft == 1)
                    {
                        table[rowZ][colZ - 1] = zombChar;
                        table[rowZ][colZ] = ' ';
                        move = move + 1;

                        system("CLS");

                        tablePrinting(table, alienStats, allZombiesStats, x, y, z);

                        cout << endl; cout << "Zombie " << zombChar << " moves to the left." << endl;

                        system("PAUSE");
                    }
                    else if (withinRight == 1)
                    {
                        table[rowZ][colZ + 1] = zombChar;
                        table[rowZ][colZ] = ' ';
                        move = move + 1;

                        system("CLS");

                        tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                        
                        cout << endl; cout << "Zombie " << zombChar << " moves to the right." << endl;
                        
                        system("PAUSE");
                    }
                    else if (withinDown == 1)
                    {
                        table[rowZ + 1][colZ] = zombChar;
                        table[rowZ][colZ] = ' ';
                        move = move + 1;

                        system("CLS");

                        tablePrinting(table, alienStats, allZombiesStats, x, y, z);

                        cout << endl; cout << "Zombie " << zombChar << " moves downwards." << endl;
                        
                        system("PAUSE");
                    }
                    else
                    {
                        system("CLS");

                        move = move + 1;

                        tablePrinting(table, alienStats, allZombiesStats, x, y, z);

                        cout << endl; cout << "Zombie " << zombChar << " are restricted to move." << endl;
                        
                        system("PAUSE");
                    }
                }
            }
            else if (rowZ == x - 1)
            {
                if (colZ == 0)
                {
                    int withinUp = checkUp(table, rowZ, colZ), withinRight = checkRight(table, rowZ, colZ);
                    
                    if (withinUp == 1)
                    {
                        table[rowZ - 1][colZ] = zombChar;
                        table[rowZ][colZ] = ' ';
                        move = move + 1;

                        system("CLS");

                        tablePrinting(table, alienStats, allZombiesStats, x, y, z);

                        cout << endl; cout << "Zombie " << zombChar << " moves upwards." << endl;
                        
                        system("PAUSE");
                    }
                    else if (withinRight == 1)
                    {
                        table[rowZ][colZ + 1] = zombChar;
                        table[rowZ][colZ] = ' ';
                        move = move + 1;

                        system("CLS");

                        tablePrinting(table, alienStats, allZombiesStats, x, y, z);

                        cout << endl; cout << "Zombie " << zombChar << " moves to the right." << endl;
                        
                        system("PAUSE");
                    }
                    else
                    {
                        system("CLS");

                        move = move + 1;

                        tablePrinting(table, alienStats, allZombiesStats, x, y, z);

                        cout << endl; cout << "Zombie " << zombChar << " are restricted to move." << endl;
                        
                        system("PAUSE");
                    }
                }
                else if (colZ == y - 1)
                {
                    int withinUp = checkUp(table, rowZ, colZ), withinLeft = checkLeft(table, rowZ, colZ);
                    if (withinUp == 1)
                    {
                        table[rowZ - 1][colZ] = zombChar;
                        table[rowZ][colZ] = ' ';
                        move = move + 1;

                        system("CLS");

                        tablePrinting(table, alienStats, allZombiesStats, x, y, z);

                        cout << endl; cout << "Zombie " << zombChar << " moves upwards." << endl;
                        
                        system("PAUSE");
                    }
                    else if (withinLeft == 1)
                    {
                        table[rowZ][colZ - 1] = zombChar;
                        table[rowZ][colZ] = ' ';
                        move = move + 1;

                        system("CLS");

                        tablePrinting(table, alienStats, allZombiesStats, x, y, z);

                        cout << endl; cout << "Zombie " << zombChar << " moves to the left." << endl;
                        
                        system("PAUSE");
                    }
                    else
                    {
                        system("CLS");

                        move = move + 1;
                        
                        tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                        
                        cout << endl; cout << "Zombie " << zombChar << " are restricted to move." << endl;
                        
                        system("PAUSE");
                    }
                }
                else
                {
                    int withinLeft = checkLeft(table, rowZ, colZ), withinRight = checkRight(table, rowZ, colZ), withinUp = checkUp(table, rowZ, colZ);
                    
                    if (withinLeft == 1)
                    {
                        table[rowZ][colZ - 1] = zombChar;
                        table[rowZ][colZ] = ' ';
                        move = move + 1;

                        system("CLS");

                        tablePrinting(table, alienStats, allZombiesStats, x, y, z);

                        cout << endl; cout << "Zombie " << zombChar << " moves to the left." << endl;
                       
                        system("PAUSE");
                    }
                    else if (withinRight == 1)
                    {
                        table[rowZ][colZ + 1] = zombChar;
                        table[rowZ][colZ] = ' ';
                        move = move + 1;

                        system("CLS");

                        tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                        
                        cout << endl; cout << "Zombie " << zombChar << " moves to the right." << endl;
                        
                        system("PAUSE");
                    }
                    else if (withinUp == 1)
                    {
                        table[rowZ - 1][colZ] = zombChar;
                        table[rowZ][colZ] = ' ';
                        move = move + 1;

                        system("CLS");

                        tablePrinting(table, alienStats, allZombiesStats, x, y, z);

                        cout << endl; cout << "Zombie " << zombChar << " moves upwards." << endl;
                        
                        system("PAUSE");
                    }
                    else
                    {
                        system("CLS");

                        move = move + 1;
                        tablePrinting(table, alienStats, allZombiesStats, x, y, z);

                        cout << endl; cout << "Zombie " << zombChar << " are restricted to move." << endl;
                        
                        system("PAUSE");
                    }
                }
            }
            else if (colZ == 0)
            {
                int withinUp = checkUp(table, rowZ, colZ), withinDown = checkDown(table, rowZ, colZ), withinRight = checkRight(table, rowZ, colZ);
                
                if (withinUp == 1)
                {
                    table[rowZ - 1][colZ] = zombChar;
                    table[rowZ][colZ] = ' ';
                    move = move + 1;

                    system("CLS");

                    tablePrinting(table, alienStats, allZombiesStats, x, y, z);

                    cout << endl; cout << "Zombie " << zombChar << " moves upwards." << endl;
                    
                    system("PAUSE");
                }
                else if (withinDown == 1)
                {
                    table[rowZ + 1][colZ] = zombChar;
                    table[rowZ][colZ] = ' ';
                    move = move + 1;

                    system("CLS");

                    tablePrinting(table, alienStats, allZombiesStats, x, y, z);

                    cout << endl; cout << "Zombie " << zombChar << " moves downwards." << endl;
                    
                    system("PAUSE");
                }
                else if (withinRight == 1)
                {
                    table[rowZ][colZ + 1] = zombChar;
                    table[rowZ][colZ] = ' ';
                    move = move + 1;

                    system("CLS");

                    tablePrinting(table, alienStats, allZombiesStats, x, y, z);

                    cout << endl; cout << "Zombie " << zombChar << " moves to the right." << endl;
                    
                    system("PAUSE");
                }
                else
                {
                    system("CLS");

                    move = move + 1;

                    tablePrinting(table, alienStats, allZombiesStats, x, y, z);

                    cout << endl; cout << "Zombie " << zombChar << " are restricted to move." << endl;
                    
                    system("PAUSE");
                }
            }
            else if (colZ == y - 1)
            {
                int withinUp = checkUp(table, rowZ, colZ), withinDown = checkDown(table, rowZ, colZ), withinLeft = checkLeft(table, rowZ, colZ);
                
                if (withinUp == 1)
                {
                    table[rowZ - 1][colZ] = zombChar;
                    table[rowZ][colZ] = ' ';
                    move = move + 1;

                    system("CLS");

                    tablePrinting(table, alienStats, allZombiesStats, x, y, z);

                    cout << endl; cout << "Zombie " << zombChar << " moves upwards." << endl;
                    
                    system("PAUSE");
                }
                else if (withinDown == 1)
                {
                    table[rowZ + 1][colZ] = zombChar;
                    table[rowZ][colZ] = ' ';
                    move = move + 1;

                    system("CLS");

                    tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                    
                    cout << endl; cout << "Zombie " << zombChar << " moves downwards." << endl;
                    
                    system("PAUSE");
                }
                else if (withinLeft == 1)
                {
                    table[rowZ][colZ - 1] = zombChar;
                    table[rowZ][colZ] = ' ';
                    move = move + 1;
                    
                    system("CLS");
                    
                    tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                    
                    cout << endl; cout << "Zombie " << zombChar << " moves to the left." << endl;
                    
                    system("PAUSE");
                }
                else
                {
                    move = move + 1;
                    
                    system("CLS");
                    
                    tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                    
                    cout << endl; cout << "Zombie " << zombChar << " are restricted to move." << endl;
                    
                    system("PAUSE");
                }
            }
            else
            {
                int withinUp = checkUp(table, rowZ, colZ), withinDown = checkDown(table, rowZ, colZ), withinLeft = checkLeft(table, rowZ, colZ), withinRight = checkRight(table, rowZ, colZ);
                
                if (withinUp == 1)
                {
                    table[rowZ - 1][colZ] = zombChar;
                    table[rowZ][colZ] = ' ';
                    move = move + 1;

                    system("CLS");

                    tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                    
                    cout << endl; cout << "Zombie " << zombChar << " moves upwards." << endl;
                    
                    system("PAUSE");
                }
                else if (withinDown == 1)
                {
                    table[rowZ + 1][colZ] = zombChar;
                    table[rowZ][colZ] = ' ';
                    move = move + 1;

                    system("CLS");

                    
                    tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                    
                    cout << endl; cout << "Zombie " << zombChar << " moves downwards." << endl;
                    
                    system("PAUSE");
                }
                else if (withinLeft == 1)
                {
                    table[rowZ][colZ - 1] = zombChar;
                    table[rowZ][colZ] = ' ';
                    move = move + 1;

                    system("CLS");

                    tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                    
                    cout << endl; cout << "Zombie " << zombChar << " moves to the left." << endl;
                    
                    system("PAUSE");
                }
                else if (withinRight == 1)
                {
                    table[rowZ][colZ + 1] = zombChar;
                    table[rowZ][colZ] = ' ';
                    move = move + 1;
                    
                    system("CLS");

                    tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                    
                    cout << endl; cout << "Zombie " << zombChar << " moves to the right." << endl;
                    
                    system("PAUSE");
                }
                else
                {
                    move = move + 1;

                    system("CLS");

                    tablePrinting(table, alienStats, allZombiesStats, x, y, z);

                    cout << endl; cout << "Zombie " << zombChar << " are restricted to move." << endl;
                    
                    system("PAUSE");
                }
            }
        }
        else if (move == 2)
        {
            rowZ = zombiesRow(table, zombChar, y);
            colZ = zombiesCol(table, zombChar, y);
            
            if (rowZ == rowA)
            {
                int rangeDis;
                
                if (colZ >= colA)
                {
                    rangeDis = colZ - colA;
                    
                    if (rangeDis <= allZombiesStats[zombStatsIndex][2])
                    {
                        move = move + 1;
                        
                        if (alienStats[0] > allZombiesStats[zombStatsIndex][1])
                        {
                            move = move + 1;
                            alienStats[0] = alienStats[0] - allZombiesStats[zombStatsIndex][1];
                            
                            system("CLS");
                            
                            tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                            
                            cout << endl; cout << "Zombie " << zombChar << " attack Alien." << endl; cout << "Alien receives a damage of " << allZombiesStats[zombStatsIndex][1] << endl;
                            
                            system("PAUSE");
                        }
                        else
                        {
                            move = move + 1;
                            alienStats[0] = 0;
                            
                            system("CLS");
                            
                            tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                            
                            cout << endl; cout << "Zombie " << zombChar << " attack Alien." << endl; cout << "Alien receives a damage of " << allZombiesStats[zombStatsIndex][1] << endl;
                            
                            turn.erase(turn.begin());
                            
                            system("PAUSE");
                        }
                    }
                    else
                    {
                        move = move + 1;

                        system("CLS");

                        tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                        
                        cout << endl; cout << "Zombie " << zombChar << " unable to attack Alien because too far away." << endl;
                        
                        system("PAUSE");
                    }
                }
                else
                {
                    rangeDis = colA - colZ;
                    
                    if (rangeDis <= allZombiesStats[zombStatsIndex][2])
                    {
                        if (alienStats[0] > allZombiesStats[zombStatsIndex][1])
                        {
                            move = move + 1;
                            alienStats[0] = alienStats[0] - allZombiesStats[zombStatsIndex][1];
                            
                            system("CLS");
                            
                            tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                            
                            cout << endl; cout << "Zombie " << zombChar << " attack Alien." << endl; cout << "Alien receives a damage of " << allZombiesStats[zombStatsIndex][1] << endl;
                            
                            system("PAUSE");
                        }
                        else
                        {
                            move = move + 1;
                            alienStats[0] = 0;
                            
                            system("CLS");

                            tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                            
                            cout << endl; cout << "Zombie " << zombChar << " attack Alien." << endl; cout << "Alien receives a damage of " << allZombiesStats[zombStatsIndex][1] << endl;
                            
                            turn.erase(turn.begin());
                            
                            system("PAUSE");
                        }
                    }
                    else
                    {
                        move = move + 1;
                        
                        system("CLS");
                        
                        tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                        
                        cout << endl; cout << "Zombie " << zombChar << " unable to attack Alien because too far away." << endl;
                        
                        system("PAUSE");
                    }
                }
            }
            else if (colZ == colA)
            {
                int rangeDis;
                if (rowZ >= rowA)
                {
                    rangeDis = rowZ - rowA;
                    if (rangeDis <= allZombiesStats[zombStatsIndex][2])
                    {
                        if (alienStats[0] > allZombiesStats[zombStatsIndex][1])
                        {
                            move = move + 1;
                            alienStats[0] = alienStats[0] - allZombiesStats[zombStatsIndex][1];
                            
                            system("CLS");
                            
                            tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                            
                            cout << endl; cout << "Zombie " << zombChar << " attack Alien." << endl; cout << "Alien receives a damage of " << allZombiesStats[zombStatsIndex][1] << endl;
                            
                            system("PAUSE");
                        }
                        else
                        {
                            move = move + 1;
                            alienStats[0] = 0;
                            
                            system("CLS");
                            
                            tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                            
                            cout << endl; cout << "Zombie " << zombChar << " attack Alien." << endl; cout << "Alien receives a damage of " << allZombiesStats[zombStatsIndex][1] << endl;
                            
                            turn.erase(turn.begin());
                            
                            system("PAUSE");
                        }
                    }
                    else
                    {
                        move = move + 1;
                        
                        system("CLS");
                        
                        tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                        
                        cout << endl; cout << "Zombie " << zombChar << " unable to attack Alien because too far away." << endl;
                        
                        system("PAUSE");
                    }
                }
                else
                {
                    rangeDis = rowA - rowZ;
                    
                    if (rangeDis <= allZombiesStats[zombStatsIndex][2])
                    {
                        if (alienStats[0] > allZombiesStats[zombStatsIndex][1])
                        {
                            move = move + 1;
                            alienStats[0] = alienStats[0] - allZombiesStats[zombStatsIndex][1];
                            
                            system("CLS");
                            
                            tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                            
                            cout << endl; cout << "Zombie " << zombChar << " attack Alien." << endl; cout << "Alien receives a damage of " << allZombiesStats[zombStatsIndex][1] << endl;
                            
                            system("PAUSE");
                        }
                        else
                        {
                            move = move + 1;
                            alienStats[0] = 0;
                            
                            system("CLS");
                            
                            tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                            
                            cout << endl; cout << "Zombie " << zombChar << " attack Alien." << endl; cout << "Alien receives a damage of " << allZombiesStats[zombStatsIndex][1] << endl;
                            
                            turn.erase(turn.begin());
                            
                            system("PAUSE");
                        }
                    }
                    else
                    {
                        move = move + 1;
                        
                        system("CLS");
                        
                        tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                        
                        cout << endl; cout << "Zombie " << zombChar << " unable to attack Alien because too far away." << endl;
                        
                        system("PAUSE");
                    }
                }
            }
            else
            {
                move = move + 1;
                
                system("CLS");
                
                tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                
                cout << endl; cout << "Zombie " << zombChar << " unable to attack Alien because too far away." << endl;
                
                system("PAUSE");
            }
        }
    }
}

// A void function to save the current game
void saveGame(vector<vector<char>>& table, vector<int>& alienStats, vector<vector<int>>& allZombiesStats, vector<int>& turn, const int x, const int y, const int z)
{
    // Define variable for file's name
    string fileName; 

    // Asks user to input in a file name with
    cout << "Type in your own filename => "; cin >> fileName;

    // Open file
    ofstream file; 
    file.open(fileName);

    // Save the rowNum, colNum and zombiesNum information;  
    file << x << endl; file << y << endl; file << z << endl;

    // Save the alienStats information
    for(int i = 0; i < alienStats.size(); ++i)
    {
        file << alienStats[i] << " ";
    }

    file << endl;

    // Save the zombies stats information
    for(int i = 0 ; i < allZombiesStats.size(); ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            file << allZombiesStats[i][j] << " ";
        }
    }

    file << endl;

    // Save the turn information
    for(int i = 0; i < turn.size(); ++i)
    {
        file << turn[i] << " ";
    }

    file << endl;

    // Save the gameboard information
    for(int i = 0; i < table.size(); ++i)
    {
        for(int j = 0; j < y; ++j)
        {
            file << table[i][j];
        }
    }

    file << endl;

    // Close file
    file.close(); 

    // Program prints out confirmation after saving files
    cout << "Game Saved " << endl;

    system("PAUSE"); 
}

// A void function to load the saved game
void loadGame(vector<vector<char>>& table, vector<int>& alienStats, vector<vector<int>>& allZombiesStats, const int x, const int y, const int z)
{
    string fileName, line;
    cout << "Type in the saved file's name => ";
    cin >> fileName;

    system("CLS");
    ifstream file;
    file.open(fileName);

    if (file.is_open())
    {
        while (getline(file, line))
        {
            cout << line << endl;
        }
        file.close();
        system("PAUSE");
    }
    else
    {
        cout << "File doesn't exists" << endl;
        system("PAUSE");
    }
    system("PAUSE");
}

void gameMainMenu() // Void function for Alien Vs Zombies Main Menu
{
    // Game Menu for Alien Vs Zombies
    cout << "========================== " << endl;
    cout << "  .: Alien Vs Zombies :.   " << endl;
    cout << "========================== " << endl;
    cout << "| 1. Start New Game      | " << endl;
    cout << "| 2. Load Game           | " << endl;
    cout << "| 3. Settings            | " << endl;
    cout << "| 4. About Game          | " << endl;
    cout << "| 5. Exit                | " << endl;
    cout << "========================== " << endl;
}

int main()
{
    bool mainMenu = true;

    srand(time(NULL));

    while (mainMenu)
    {
        int playerChoice;
        vector<int> turn;

        system("CLS");
        gameMainMenu(); 
        cout << "Your choice (1, 2, 3, 4, 5) => ";
        cin >> playerChoice; 

        if (playerChoice == 1)
        {
            mainMenu = false;                            // Ignore mainMenu
            int rowNum, colNum, zombiesNum; // Default values for the number of row, column and zombies
            char useDefOrUpd, playerChoice;                           // Define the variable for player's choice to change the default values
            bool gameSettings = true;                    // Define the variable for gameSettings for loop purposes

            while (gameSettings)
            {
                cout << "Do you want to use the default game settings or the updated game settings? (d/u) => "; cin >> useDefOrUpd;

                if (useDefOrUpd == 'D' || useDefOrUpd == 'd')
                {
                    int rowNum = 3, colNum = 19, zombiesNum = 2;
                    // Display default values before printing the Game Board
                    system("CLS");

                    cout << "=================== " << endl;
                    cout << "Game Board Settings " << endl;
                    cout << "=================== " << endl;
                    cout << "Row => " << rowNum << endl;
                    cout << "Column => " << colNum << endl;
                    cout << "Zombies => " << zombiesNum << endl;
                    cout << "=================== " << endl;

                    // Ask the player if he/she wants to change the default values
                    cout << endl;
                    cout << "Do you want to change the default values? (y/n) => ";
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
                            cout << "====================================================================================== " << endl;
                            cout << "REMINDER! Game Requirements\n 1. Insert odd value only to ensure the Alien spawns in the middle of the Game Board\n 2. Minimum number of row is 3 and maximum number of row is 9\n 3. Minimum number of column is 3 and maximum number of column is 21\n 4. Minimum number of zombies is 1 and maximum number of column is 9 " << endl;
                            cout << "====================================================================================== " << endl;
                            cout << endl;
                            cout << "Enter a new value for row => ";
                            cin >> rowNum;
                            cout << "Enter a new value for column => ";
                            cin >> colNum;
                            cout << "Enter a new value for zombies => ";
                            cin >> zombiesNum;

                            if (rowNum > 9 || rowNum < 3 || colNum > 21 || colNum < 3 || zombiesNum > 9 || zombiesNum < 1)
                            {
                                cout << " You did not meet the game requirement! Please try again!" << endl;
                                system("PAUSE");
                                resetSettings = true;
                            }
                            else
                            {
                                // Prints out the new updated value from previous statement
                                system("CLS");
                                cout << "=================== " << endl;
                                cout << "Game Board Settings " << endl;
                                cout << "=================== " << endl;
                                cout << "Row => " << rowNum << endl;
                                cout << "Column => " << colNum << endl;
                                cout << "Zombies => " << zombiesNum << endl;
                                cout << "=================== " << endl;

                                // Ask whether or not the player wants to continue with the updated value or resets it
                                cout << endl;
                                cout << "C to continue/R to reset " << endl;
                                cout << "Continue? (c/r)=> ";
                                cin >> playerChoice;

                                // If statement if the player wants to continue
                                if (playerChoice == 'C' || playerChoice == 'c')
                                {
                                    resetSettings = false; // Ignore resetSettings
                                    gameSettings = false;  // Ignore gameSettings
                                    bool inGame = true;
                                    int quitBefLosing = 1;
                                    int lose = 1;
                                    string option, choice;
                                    MakingTable board(rowNum, colNum, zombiesNum);
                                    system("CLS");
                                    for (int i = 0; i <= zombiesNum; ++i)
                                    {
                                        turn.push_back(i);
                                    }
                                    while (inGame)
                                    {
                                        for (int i = 0; i < turn.size();)
                                        {
                                            if (i == 0)
                                            {
                                                system("CLS");
                                                tablePrinting(board.table, board.alienStats, board.allZombiesStats, rowNum, colNum, zombiesNum);
                                                cout << endl;
                                                cout << "It is your turn, the mightiest Alien in the milky way" << endl;
                                                cout << endl;
                                                cout << "Enter Your Command => ";
                                                cin >> option;
                                                if (option.compare("arrow") == 0)
                                                {
                                                    bool truth = true;
                                                    int arrRow, arrCol;
                                                    int truthFlag = 1;
                                                    string direct;

                                                    cout << endl;
                                                    cout << "Enter row of the arrow    => ";
                                                    cin >> arrRow;
                                                    cout << "Enter column of the arrow => ";
                                                    cin >> arrCol;
                                                    cout << "Enter the direction that you want (up/down/left/right) => ";
                                                    cin >> direct;
                                                    cout << endl;

                                                    for (int i = 0; i < board.table.size(); ++i)
                                                    {
                                                        for (int j = 0; j < colNum; ++j)
                                                        {
                                                            if ((board.table[arrRow - 1][arrCol - 1] == '^' || board.table[arrRow - 1][arrCol - 1] == 'v' || board.table[arrRow - 1][arrCol - 1] == '<' || board.table[arrRow - 1][arrCol - 1] == '>'))
                                                            {
                                                                truthFlag = 0;
                                                            }
                                                        }
                                                    }
                                                    if (truthFlag == 0)
                                                    {
                                                        changeArrow(board.table, arrRow, arrCol, direct);
                                                    }
                                                    else if (truthFlag != 0)
                                                    {
                                                        cout << endl
                                                             << "You enter the input in the wrong format." << endl
                                                             << "Please make sure the coordinate and the direction are correct." << endl;
                                                        system("PAUSE");
                                                    }
                                                }
                                                else if ((option.compare("up") == 0 || option.compare("down") == 0 || option.compare("left") == 0 || option.compare("right") == 0))
                                                {
                                                    ++i;
                                                    alienMovement(option, board.table, board.alienStats, board.allZombiesStats, board, rowNum, colNum, zombiesNum, turn);
                                                    if (turn.size() == 1 && turn[0] == 0)
                                                    {
                                                        break;
                                                    }
                                                }
                                                else if (option.compare("help") == 0)
                                                {
                                                    cout << endl;
                                                    cout << "============================================= " << endl;
                                                    cout << "Command Guides\n- up = Alien moves upward\n- down = Alien moves downwards\n- left = Alien moves left\n- right = Alien moves right\n- arrow = Switch the direction of an arrow object in the Game Board\n- save = Save the current game to a file\n- load = Load a saved game from a file\n- quit = Quit the game " << endl;
                                                    cout << "============================================= " << endl;
                                                    system("PAUSE");
                                                }
                                                else if (option.compare("save") == 0)
                                                {
                                                    cout << endl;
                                                    saveGame(board.table, board.alienStats, board.allZombiesStats, turn, rowNum, colNum, zombiesNum);
                                                }
                                                else if (option.compare("load") == 0)
                                                {
                                                    system("CLS");
                                                    // loadGame(board.table, board.alienStats, board.allZombiesStats, board, rowNum, colNum, zombiesNum);
                                                    system("PAUSE");
                                                }
                                                else if (option.compare("quit") == 0)
                                                {
                                                    quitBefLosing = 0;
                                                    break;
                                                }
                                                else
                                                {
                                                    cout << endl;
                                                    cout << "Invalid input. Make sure the input are accurate." << endl
                                                         << "please refer to help option for more information of the commands." << endl;
                                                    system("PAUSE");
                                                }
                                            }
                                            else if (i == turn.size() - 1)
                                            {
                                                system("CLS");
                                                tablePrinting(board.table, board.alienStats, board.allZombiesStats, rowNum, colNum, zombiesNum);
                                                cout << endl;
                                                cout << "It is zombie " << turn[i] << " turn....";
                                                cout << endl;
                                                system("PAUSE");
                                                zombieMovement(board.table, board.alienStats, board.allZombiesStats, turn[i], turn, rowNum, colNum, zombiesNum);
                                                if (turn[0] != 0)
                                                {
                                                    lose = 0;
                                                    break;
                                                }
                                                i = i - turn.size() + 1;
                                            }
                                            else
                                            {
                                                system("CLS");
                                                tablePrinting(board.table, board.alienStats, board.allZombiesStats, rowNum, colNum, zombiesNum);
                                                cout << endl;
                                                cout << "It is zombie " << turn[i] << " turn....";
                                                cout << endl;
                                                system("PAUSE");
                                                zombieMovement(board.table, board.alienStats, board.allZombiesStats, turn[i], turn, rowNum, colNum, zombiesNum);
                                                if (turn[0] != 0)
                                                {
                                                    lose = 0;
                                                    break;
                                                }
                                                ++i;
                                            }
                                        }

                                        if (quitBefLosing == 0)
                                        {
                                            inGame = false;
                                            gameSettings = false;
                                            mainMenu = true;
                                            cout << endl
                                                 << "Entering main menu...." << endl;
                                            system("PAUSE");
                                        }
                                        else if (lose == 0)
                                        {
                                            inGame = false;
                                            gameSettings = false;
                                            mainMenu = true;
                                            cout << endl;
                                            cout << "THE MIGHTY ALIEN UNFORTUNATELY LOST IT PRECIOUS LIVES! YOU LOST!" << endl;
                                            cout << endl
                                                 << "Entering main menu...." << endl;
                                            system("PAUSE");
                                        }
                                        else
                                        {
                                            bool endGame = true;
                                            while (endGame)
                                            {
                                                cout << endl;
                                                cout << "ALL ZOMBIES HAVE BEEN DEFEATED! YOU WON!" << endl;
                                                cout << "Go back to Main Menu? (Y to return to main menu/N to play the game again)=> ";
                                                cin >> choice;

                                                if (choice == "Y" || choice == "y")
                                                {
                                                    // Program starts returning to Main Menu
                                                    endGame = false;
                                                    inGame = false;
                                                    resetSettings = false;
                                                    gameSettings = false;
                                                    mainMenu = true;
                                                    // Program stops returning to Main Menu
                                                }
                                                else if (choice == "N" || choice == "n")
                                                {
                                                    // Program starts restarting the game
                                                    endGame = false;
                                                    inGame = true;
                                                    resetSettings = false;
                                                    gameSettings = false;
                                                    mainMenu = false;
                                                    // Program stops restarting the game
                                                }
                                                else
                                                {
                                                    cout << "Invalid input! Please try again..." << endl;
                                                    system("PAUSE");
                                                    // Program starts printing endGame statement again
                                                    endGame = true;
                                                    inGame = false;
                                                    resetSettings = false;
                                                    gameSettings = false;
                                                    mainMenu = false;
                                                    // Program stops printing endGame statement again
                                                }
                                            }
                                        }
                                    }
                                }
                                // Else if statement if the player wants to reset
                                else if (playerChoice == 'r' || playerChoice == 'R')
                                {
                                    resetSettings = true; // Return newSettings
                                    gameSettings = false; // Ignore gameSettings
                                }
                                // Else statement if the player inputs in neither C to continue or R to reset
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
                        bool inGame = true;
                        string option;
                        int quitBefLosing = 1;
                        int lose = 1;
                        MakingTable board(rowNum, colNum, zombiesNum);
                        system("CLS");
                        for (int i = 0; i <= zombiesNum; ++i)
                        {
                            turn.push_back(i);
                        }
                        while (inGame)
                        {
                            int goToMainQuit = 1;
                            for (int i = 0; i < turn.size();)
                            {
                                if (i == 0)
                                {
                                    system("CLS");
                                    tablePrinting(board.table, board.alienStats, board.allZombiesStats, rowNum, colNum, zombiesNum);
                                    cout << endl;
                                    cout << "It is your turn, the mightiest Alien in the milky way" << endl;
                                    cout << endl;
                                    cout << "Enter Your Command => ";
                                    cin >> option;
                                    if (option.compare("arrow") == 0)
                                    {
                                        int arrRow, arrCol;
                                        int truthFlag = 1;
                                        string direct;

                                        cout << endl;
                                        cout << "Enter row of the arrow    => ";
                                        cin >> arrRow; // cout << endl;
                                        cout << "Enter column of the arrow => ";
                                        cin >> arrCol; // cout << endl;
                                        cout << "Enter the direction that you want (up/down/left/right) => ";
                                        cin >> direct;
                                        cout << endl;
                                        for (int i = 0; i < board.table.size(); ++i)
                                        {
                                            for (int j = 0; j < colNum; ++j)
                                            {
                                                if ((board.table[arrRow - 1][arrCol - 1] == '^' || board.table[arrRow - 1][arrCol - 1] == 'v' || board.table[arrRow - 1][arrCol - 1] == '<' || board.table[arrRow - 1][arrCol - 1] == '>'))
                                                {
                                                    truthFlag = 0;
                                                }
                                            }
                                        }
                                        if (truthFlag == 0)
                                        {
                                            changeArrow(board.table, arrRow, arrCol, direct);
                                        }
                                        else if (truthFlag != 0)
                                        {
                                            cout << endl
                                                 << "You enter the input in the wrong format." << endl
                                                 << "Please make sure the coordinate and the direction are correct." << endl;
                                            system("PAUSE");
                                        }
                                    }
                                    else if ((option.compare("up") == 0 || option.compare("down") == 0 || option.compare("left") == 0 || option.compare("right") == 0))
                                    {
                                        ++i;
                                        alienMovement(option, board.table, board.alienStats, board.allZombiesStats, board, rowNum, colNum, zombiesNum, turn);
                                    }
                                    else if (option.compare("help") == 0)
                                    {
                                        cout << endl;
                                        cout << "============================================= " << endl;
                                        cout << "Command Guides\n- up = Alien moves upward\n- down = Alien moves downwards\n- left = Alien moves left\n- right = Alien moves right\n- arrow = Switch the direction of an arrow object in the Game Board\n- save = Save the current game to a file\n- load = Load a saved game from a file\n- quit = Quit the game " << endl;
                                        cout << "============================================= " << endl;
                                        system("PAUSE");
                                    }
                                    else if (option.compare("save") == 0)
                                    {
                                        saveGame(board.table, board.alienStats, board.allZombiesStats, turn, rowNum, colNum, zombiesNum);
                                    }
                                    else if (option.compare("load") == 0)
                                    {
                                        string fileName, line;
                                        char array[100];
                                        int i;

                                        cout << "Type in the saved file's name (with .txt) => ";
                                        cin >> fileName;

                                        ifstream file(fileName);

                                        if (!file)
                                        {
                                            cout << "File doesn't exists!" << endl;
                                        }

                                        while (getline(file, line))
                                        {
                                            cout << line << endl;
                                        }

                                        for (i = 0; i < line.length(); ++i)
                                        {
                                            array[i] = line[i];
                                        }

                                        array[i] = '\0';

                                        file.close();

                                        system("CLS");

                                        cout << array << endl;

                                        system("PAUSE");
                                    }
                                    else if (option.compare("quit") == 0)
                                    {
                                        quitBefLosing = 0;
                                        break;
                                    }
                                    else
                                    {
                                        cout << "Invalid input. Make sure the input are accurate." << endl
                                             << "Please refer to help option for more information of the commands." << endl;
                                        system("PAUSE");
                                    }
                                }
                                else if (i == turn.size() - 1)
                                {
                                    system("CLS");
                                    tablePrinting(board.table, board.alienStats, board.allZombiesStats, rowNum, colNum, zombiesNum);
                                    cout << endl;
                                    cout << "It is zombie " << turn[i] << " turn....";
                                    cout << endl;
                                    system("PAUSE");
                                    zombieMovement(board.table, board.alienStats, board.allZombiesStats, turn[i], turn, rowNum, colNum, zombiesNum);
                                    if (turn[0] != 0)
                                    {
                                        lose = 0;
                                        break;
                                    }
                                    i = i - turn.size() + 1;
                                }
                                else
                                {
                                    system("CLS");
                                    tablePrinting(board.table, board.alienStats, board.allZombiesStats, rowNum, colNum, zombiesNum);
                                    cout << endl;
                                    cout << "It is zombie " << turn[i] << " turn....";
                                    cout << endl;
                                    system("PAUSE");
                                    zombieMovement(board.table, board.alienStats, board.allZombiesStats, turn[i], turn, rowNum, colNum, zombiesNum);
                                    if (turn[0] != 0)
                                    {
                                        lose = 0;
                                        break;
                                    }
                                    ++i;
                                }
                            }
                            if (quitBefLosing == 0)
                            {
                                inGame = false;
                                gameSettings = false;
                                mainMenu = true;
                                cout << endl
                                     << "Entering main manu...." << endl;
                                system("PAUSE");
                            }
                            else if (lose == 0)
                            {
                                inGame = false;
                                gameSettings = false;
                                mainMenu = true;
                                cout << endl;
                                cout << "THE MIGHTY ALIEN UNFORTUNATELY LOST IT PRECIOUS LIVES! YOU LOST!" << endl;
                                cout << endl
                                     << "Entering main manu...." << endl;
                                system("PAUSE");
                            }
                            else
                            {
                                bool endGame = true;
                                while (endGame)
                                {
                                    char choice;
                                    system("CLS");
                                    cout << endl;
                                    cout << "ALL ZOMBIES HAVE BEEN DEFEATED! YOU WON!" << endl;
                                    cout << "Go back to Main Menu? (Y to return to main menu/N to play the game again)=> ";
                                    cin >> choice;

                                    if (choice == 'Y' || choice == 'y')
                                    {
                                        // Program starts returning to Main Menu
                                        endGame = false;
                                        inGame = false;
                                        gameSettings = false;
                                        mainMenu = true;
                                        // Program stops returning to Main Menu
                                    }
                                    else if (choice == 'N' || choice == 'n')
                                    {
                                        // Program starts restarting the game
                                        endGame = false;
                                        inGame = true;
                                        gameSettings = false;
                                        mainMenu = false;
                                        // Program stops restarting the game
                                    }
                                    else
                                    {
                                        cout << "Invalid input! Please try again..." << endl;
                                        system("PAUSE");
                                        // Program starts printing endGame statement again
                                        endGame = true;
                                        inGame = false;
                                        gameSettings = false;
                                        mainMenu = false;
                                        // Program stops printing endGame statement again
                                    }
                                }
                            }
                        }
                    }
                    else
                    {
                        cout << " Invalid input! Please try again... " << endl;
                        system("PAUSE");
                        gameSettings = true; // Return gameSettings
                    }
                }
                else if (useDefOrUpd == 'U' || useDefOrUpd == 'u')
                {

                    gameSettings = false;
                    mainMenu = false;

                    string nRowNum, nColNum, nZombiesNum;
                    int rowNum, colNum, zombiesNum;

                    ifstream read("settings.txt");
                    getline(read, nRowNum);
                    getline(read, nColNum);
                    getline(read, nZombiesNum);

                    system("CLS");

                    cout << "=========================== " << endl;
                    cout << "Updated Game Board Settings " << endl;
                    cout << "=========================== " << endl;
                    cout << "Row     => " << nRowNum << endl;
                    cout << "Column  => " << nColNum << endl;
                    cout << "Zombies => " << nZombiesNum << endl;
                    cout << "=========================== " << endl;

                    rowNum = stoi(nRowNum);
                    colNum = stoi(nColNum);
                    zombiesNum = stoi(nZombiesNum);

                    system("PAUSE");

                    system("CLS");

                    bool inGame = true;
                    int quitBefLosing = 1;
                    int lose = 1;
                    string option, choice;
                    MakingTable board(rowNum, colNum, zombiesNum);
                    system("CLS");
                    for (int i = 0; i <= zombiesNum; ++i)
                    {
                        turn.push_back(i);
                    }
                    while (inGame)
                    {
                        for (int i = 0; i < turn.size();)
                        {
                            if (i == 0)
                            {
                                system("CLS");
                                tablePrinting(board.table, board.alienStats, board.allZombiesStats, rowNum, colNum, zombiesNum);
                                cout << endl;
                                cout << "It is your turn, the mightiest Alien in the milky way" << endl;
                                cout << endl;
                                cout << "Enter Your Command => ";
                                cin >> option;
                                if (option.compare("arrow") == 0)
                                {
                                    bool truth = true;
                                    int arrRow, arrCol;
                                    int truthFlag = 1;
                                    string direct;

                                    cout << endl;
                                    cout << "Enter row of the arrow    => ";
                                    cin >> arrRow;
                                    cout << "Enter column of the arrow => ";
                                    cin >> arrCol;
                                    cout << "Enter the direction that you want (up/down/left/right) => ";
                                    cin >> direct;
                                    cout << endl;

                                    for (int i = 0; i < board.table.size(); ++i)
                                    {
                                        for (int j = 0; j < colNum; ++j)
                                        {
                                            if ((board.table[arrRow - 1][arrCol - 1] == '^' || board.table[arrRow - 1][arrCol - 1] == 'v' || board.table[arrRow - 1][arrCol - 1] == '<' || board.table[arrRow - 1][arrCol - 1] == '>'))
                                            {
                                                truthFlag = 0;
                                            }
                                        }
                                    }
                                    if (truthFlag == 0)
                                    {
                                        changeArrow(board.table, arrRow, arrCol, direct);
                                    }
                                    else if (truthFlag != 0)
                                    {
                                        cout << endl
                                             << "You enter the input in the wrong format." << endl
                                             << "Please make sure the coordinate and the direction are correct." << endl;
                                        system("PAUSE");
                                    }
                                }
                                else if ((option.compare("up") == 0 || option.compare("down") == 0 || option.compare("left") == 0 || option.compare("right") == 0))
                                {
                                    ++i;
                                    alienMovement(option, board.table, board.alienStats, board.allZombiesStats, board, rowNum, colNum, zombiesNum, turn);
                                    if (turn.size() == 1 && turn[0] == 0)
                                    {
                                        break;
                                    }
                                }
                                else if (option.compare("help") == 0)
                                {
                                    cout << endl;
                                    cout << "============================================= " << endl;
                                    cout << "Command Guides\n- up = Alien moves upward\n- down = Alien moves downwards\n- left = Alien moves left\n- right = Alien moves right\n- arrow = Switch the direction of an arrow object in the Game Board\n- save = Save the current game to a file\n- load = Load a saved game from a file\n- quit = Quit the game " << endl;
                                    cout << "============================================= " << endl;
                                    system("PAUSE");
                                }
                                else if (option.compare("save") == 0)
                                {
                                    cout << endl;
                                    saveGame(board.table, board.alienStats, board.allZombiesStats, turn, rowNum, colNum, zombiesNum);
                                }
                                else if (option.compare("load") == 0)
                                {
                                    system("CLS");
                                    // loadGame(board.table, board.alienStats, board.allZombiesStats, board, rowNum, colNum, zombiesNum);
                                    system("PAUSE");
                                }
                                else if (option.compare("quit") == 0)
                                {
                                    quitBefLosing = 0;
                                    break;
                                }
                                else
                                {
                                    cout << endl;
                                    cout << "Invalid input. Make sure the input are accurate." << endl
                                         << "please refer to help option for more information of the commands." << endl;
                                    system("PAUSE");
                                }
                            }
                            else if (i == turn.size() - 1)
                            {
                                system("CLS");
                                tablePrinting(board.table, board.alienStats, board.allZombiesStats, rowNum, colNum, zombiesNum);
                                cout << endl;
                                cout << "It is zombie " << turn[i] << " turn....";
                                cout << endl;
                                system("PAUSE");
                                zombieMovement(board.table, board.alienStats, board.allZombiesStats, turn[i], turn, rowNum, colNum, zombiesNum);
                                if (turn[0] != 0)
                                {
                                    lose = 0;
                                    break;
                                }
                                i = i - turn.size() + 1;
                            }
                            else
                            {
                                system("CLS");
                                tablePrinting(board.table, board.alienStats, board.allZombiesStats, rowNum, colNum, zombiesNum);
                                cout << endl;
                                cout << "It is zombie " << turn[i] << " turn....";
                                cout << endl;
                                system("PAUSE");
                                zombieMovement(board.table, board.alienStats, board.allZombiesStats, turn[i], turn, rowNum, colNum, zombiesNum);
                                if (turn[0] != 0)
                                {
                                    lose = 0;
                                    break;
                                }
                                ++i;
                            }
                        }

                        if (quitBefLosing == 0)
                        {
                            inGame = false;
                            gameSettings = false;
                            mainMenu = true;
                            cout << endl
                                 << "Entering main menu...." << endl;
                            system("PAUSE");
                        }
                        else if (lose == 0)
                        {
                            inGame = false;
                            gameSettings = false;
                            mainMenu = true;
                            cout << endl;
                            cout << "THE MIGHTY ALIEN UNFORTUNATELY LOST IT PRECIOUS LIVES! YOU LOST!" << endl;
                            cout << endl
                                 << "Entering main menu...." << endl;
                            system("PAUSE");
                        }
                        else
                        {
                            bool endGame = true;
                            while (endGame)
                            {
                                cout << endl;
                                cout << "ALL ZOMBIES HAVE BEEN DEFEATED! YOU WON!" << endl;
                                cout << "Go back to Main Menu? (Y to return to main menu/N to play the game again)=> ";
                                cin >> choice;

                                if (choice == "Y" || choice == "y")
                                {
                                    // Program starts returning to Main Menu
                                    endGame = false;
                                    inGame = false;
                                    gameSettings = false;
                                    mainMenu = true;
                                    // Program stops returning to Main Menu
                                }
                                else if (choice == "N" || choice == "n")
                                {
                                    // Program starts restarting the game
                                    endGame = false;
                                    inGame = true;
                                    gameSettings = false;
                                    mainMenu = false;
                                    // Program stops restarting the game
                                }
                                else
                                {
                                    cout << "Invalid input! Please try again..." << endl;
                                    system("PAUSE");
                                    // Program starts printing endGame statement again
                                    endGame = true;
                                    inGame = false;
                                    gameSettings = false;
                                    mainMenu = false;
                                    // Program stops printing endGame statement again
                                }
                            }
                        }
                    }
                }
                else
                {
                    cout << endl;
                    cout << "Invalid input! Please try again..." << endl;
                    cout << endl;

                    system("PAUSE");

                    gameSettings = true;
                }

                // game settings
            }
        }
        else if (playerChoice == 2)
        {
            mainMenu = true;
            string filename, line;
            string tableInfoStr, alienHealth, alienAttack;
            int rowNum, colNum, zombiesNum;
            int tableLine = 7;
            vector<vector<char>> table;
            vector<int> alienStats;
            vector<vector<int>> allZombiesStats;
            vector<int> turn;

            cout << "Enter the file name you want to load => ";
            cin >> filename;
            ifstream fileOpen(filename);

            if (fileOpen.fail())
            {
                cout << "Error occured..." << endl;
            }
            else
            {
                // retrieve rowNum
                fileOpen >> rowNum;
                cout << "row => " << rowNum << endl;

                // retrieve colNum
                fileOpen >> colNum;
                cout << "col => " << colNum << endl;

                // retrieve zombiesNum
                fileOpen >> zombiesNum;
                cout << "zombies => " << zombiesNum << endl;

                // retrieve alienStats
                int intAlienHealth;
                fileOpen >> intAlienHealth;
                int intAlienAttack;
                fileOpen >> intAlienAttack;
                alienStats.push_back(intAlienHealth);
                alienStats.push_back(intAlienAttack);
                cout << alienStats.size() << endl;

                // retrieve zombies stats
                for (int i = 0; i < zombiesNum; ++i)
                {
                    vector<int> inZomStats;
                    for (int j = 0; j < 3; ++j)
                    {
                        int zombiesInfo;
                        fileOpen >> zombiesInfo;
                        inZomStats.push_back(zombiesInfo);
                    }
                    allZombiesStats.push_back(inZomStats);
                }
                cout << allZombiesStats.size() << endl;

                // retrieve turn
                for (int i = 0; i < zombiesNum + 1; ++i)
                {
                    int attTurn;
                    fileOpen >> attTurn;
                    turn.push_back(attTurn);
                }
                cout << turn.size() << endl;

                // retrieve the table information into string variable string line
                int currLine = 0;
                while (!fileOpen.eof())
                {
                    currLine++;
                    getline(fileOpen, line);
                    if (line.size() > 1)
                    {
                        break;
                    }
                }

                int k = 0;
                while (k < line.size())
                {
                    vector<char> inCol;
                    for (int i = 0; i < colNum; ++i)
                    {
                        inCol.push_back(line[k]);
                        k = k + 1;
                    }
                    table.push_back(inCol);
                }
                fileOpen.close();

                MakingTable justFunction(rowNum, colNum, zombiesNum);
                bool inGame = true;
                int quitBefLosing = 1;
                int lose = 1;
                string option;
                while (inGame)
                {
                    for (int i = 0; i < turn.size();)
                    {
                        if (i == 0)
                        {
                            system("CLS");
                            tablePrinting(table, alienStats, allZombiesStats, rowNum, colNum, zombiesNum);
                            cout << endl;
                            cout << "It is your turn, the mightiest Alien in the milky way" << endl;
                            cout << endl;
                            cout << "Enter Your Command => ";
                            cin >> option;
                            if (option.compare("arrow") == 0)
                            {
                                int arrRow, arrCol;
                                int truthFlag = 1;
                                string direct;

                                cout << endl;
                                cout << "Enter row of the arrow    => ";
                                cin >> arrRow; // cout << endl;
                                cout << "Enter column of the arrow => ";
                                cin >> arrCol; // cout << endl;
                                cout << "Enter the direction that you want (up/down/left/right) => ";
                                cin >> direct;
                                cout << endl;
                                for (int i = 0; i < table.size(); ++i)
                                {
                                    for (int j = 0; j < colNum; ++j)
                                    {
                                        if ((table[arrRow - 1][arrCol - 1] == '^' || table[arrRow - 1][arrCol - 1] == 'v' || table[arrRow - 1][arrCol - 1] == '<' || table[arrRow - 1][arrCol - 1] == '>'))
                                        {
                                            truthFlag = 0;
                                        }
                                    }
                                }
                                if (truthFlag == 0)
                                {
                                    changeArrow(table, arrRow, arrCol, direct);
                                }
                                else if (truthFlag != 0)
                                {
                                    cout << endl
                                         << "You enter the input in the wrong format." << endl
                                         << "Please make sure the coordinate and the direction are correct." << endl;
                                    system("PAUSE");
                                }
                            }
                            else if ((option.compare("up") == 0 || option.compare("down") == 0 || option.compare("left") == 0 || option.compare("right") == 0))
                            {
                                ++i;
                                alienMovement(option, table, alienStats, allZombiesStats, justFunction, rowNum, colNum, zombiesNum, turn);
                            }
                            else if (option.compare("help") == 0)
                            {
                                cout << endl;
                                cout << "============================================= " << endl;
                                cout << "Command Guides\n- up = Alien moves upward\n- down = Alien moves downwards\n- left = Alien moves left\n- right = Alien moves right\n- arrow = Switch the direction of an arrow object in the Game Board\n- save = Save the current game to a file\n- load = Load a saved game from a file\n- quit = Quit the game " << endl;
                                cout << "============================================= " << endl;
                                system("PAUSE");
                            }
                            else if (option.compare("save") == 0)
                            {
                                saveGame(table, alienStats, allZombiesStats, turn, rowNum, colNum, zombiesNum);
                            }
                            else if (option.compare("load") == 0)
                            {
                                loadGame(table, alienStats, allZombiesStats, rowNum, colNum, zombiesNum);
                            }
                            else if (option.compare("quit") == 0)
                            {
                                quitBefLosing = 0;
                                break;
                            }
                            else
                            {
                                cout << "Invalid input. Make sure the input are accurate." << endl
                                     << "Please refer to help option for more information of the commands." << endl;
                                system("PAUSE");
                            }
                        }
                        else if (i == turn.size() - 1)
                        {
                            system("CLS");
                            tablePrinting(table, alienStats, allZombiesStats, rowNum, colNum, zombiesNum);
                            cout << endl;
                            cout << "It is zombie " << turn[i] << " turn....";
                            cout << endl;
                            system("PAUSE");
                            zombieMovement(table, alienStats, allZombiesStats, turn[i], turn, rowNum, colNum, zombiesNum);
                            if (turn[0] != 0)
                            {
                                lose = 0;
                                break;
                            }
                            i = i - turn.size() + 1;
                        }
                        else
                        {
                            system("CLS");
                            tablePrinting(table, alienStats, allZombiesStats, rowNum, colNum, zombiesNum);
                            cout << endl;
                            cout << "It is zombie " << turn[i] << " turn....";
                            cout << endl;
                            system("PAUSE");
                            zombieMovement(table, alienStats, allZombiesStats, turn[i], turn, rowNum, colNum, zombiesNum);
                            if (turn[0] != 0)
                            {
                                lose = 0;
                                break;
                            }
                            ++i;
                        }
                    }

                    if (quitBefLosing == 0)
                    {
                        inGame = false;
                        mainMenu = true;
                        cout << endl
                             << "Entering main manu...." << endl;
                        system("PAUSE");
                    }
                    else if (lose == 0)
                    {
                        inGame = false;
                        mainMenu = true;
                        cout << "You have lose the game." << endl;
                        cout << endl
                             << "Entering main manu...." << endl;
                        system("PAUSE");
                    }
                    else
                    {
                        inGame = false;
                        mainMenu = true;
                        cout << "You have won the game." << endl;
                        cout << endl
                             << "Entering main manu...." << endl;
                        system("PAUSE");
                    }
                }
            }
        }
        else if (playerChoice == 3)
        {

            int rowNum, colNum, zombiesNum;
            char proceed;
            bool gameSettings = true, updatedGameSettings = true;
            
            while(gameSettings)
            {
                system("CLS");

                cout << "REMINDER! Game Requirements\n 1. Insert odd value only to ensure the Alien spawns in the middle of the Game Board\n 2. Minimum number of row is 3 and maximum number of row is 9\n 3. Minimum number of column is 3 and maximum number of column is 21\n 4. Minimum number of zombies is 1 and maximum number of column is 9 " << endl;
                cout << endl;
                cout << "================================== " << endl;
                cout << "          Game Settings            " << endl;
                cout << "================================== " << endl;
                cout << endl;
                cout << "Type in a new value for row     => "; cin >> rowNum;
                cout << endl;
                cout << "Type in a new value for column  => "; cin >> colNum;
                cout << endl;
                cout << "Type in a new value for zombies => "; cin >> zombiesNum;
                cout << endl;
                cout << "================================== " << endl;

                if (rowNum > 9 || rowNum < 3 || colNum > 21 || colNum < 3 || zombiesNum > 9 || zombiesNum < 1)
                {
                    cout << endl;
                    cout << "You did not meet the game requirement! Please try again!" << endl;
                    system("PAUSE");
                    gameSettings = true;
                }
                else
                {
                    while (updatedGameSettings)
                    {
                        system("CLS");
                        cout << "================================== " << endl;
                        cout << "      Updated Game Settings        " << endl;
                        cout << "================================== " << endl;
                        cout << endl;
                        cout << "Row     => " << rowNum << endl;
                        cout << endl;
                        cout << "Column  => " << colNum << endl;
                        cout << endl;
                        cout << "Zombies => " << zombiesNum << endl;
                        cout << endl;
                        cout << "================================== " << endl;
                        cout << endl;

                        cout << "Proceed? (y/n) => "; cin >> proceed;

                        if (proceed == 'Y' || proceed == 'y')
                        {
                            ofstream file;
                            file.open("settings.txt");
                            file << rowNum; file << endl; file << colNum; file << endl; file << zombiesNum;
                            file.close();

                            cout << "Settings Updated! " << endl;
                            cout << endl;
                            system("PAUSE");

                            updatedGameSettings = false;
                            gameSettings = false;
                            mainMenu = true;
                        }
                        else if (proceed == 'N' || proceed == 'n')
                        {
                            updatedGameSettings = false;
                            gameSettings = false;
                            mainMenu = true;
                        }
                        else
                        {
                            cout << "Invalid input! Please try again... " << endl;
                            cout << endl;
                            system("PAUSE");
                            updatedGameSettings = true;
                        }
                    }
                }
            }
        }
        else if (playerChoice == 4)
        {
            mainMenu = false;

            char playerChoice;
            bool aboutGame = true;

            while (aboutGame)
            {
                system("CLS");
                cout << "========================================================= " << endl;
                cout << "                         About Game                       " << endl;
                cout << "========================================================= " << endl;
                cout << "| Alien vs Zombie is a turn-based combat game            |\n| in which the player controls Alien to defeat           |\n| a group of Zombies. Prior to the game, the player      |\n| can customize settings including game board dimensions |\n| and number of zombies. The player can also save        |\n| a game into a file and load a game from a file.        |" << endl;
                cout << "========================================================= " << endl;
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
        else if (playerChoice == 5)
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