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

void tablePrinting(vector<vector<char>>& table, vector<int>& alienStats, vector<vector<int>>& allZombiesStats, const int x, const int y, const int z)
{
    cout << "=================================== " << endl;
    cout << "Player! Welcome To Alien Vs Zombies " << endl;
    cout << "=================================== " << endl;
    cout << endl;

    for (int j = 0; j < y; ++j)
    {
        cout << "+-";
    }
    cout << '+' << endl;
    for (int i = 0; i < table.size();++i)
    {
        for (int j = 0; j < y; ++j)
        {
            cout << '|'; cout << table[i][j];
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

    cout << endl << endl;
    cout << endl;

    cout << "Alien     :" << " Life " << alienStats[0] << " , " << " Attack " << alienStats[1] << endl;
    for (int i = 0; i < z; i++)
    {
        cout << "Zombie " << i + 1 << "  :" << " Life " << allZombiesStats[i][0] << " , " << " Attack " << allZombiesStats[i][1] << " , " << " Range " << allZombiesStats[i][2] << endl;
    }
}

int rowCoordinate(vector<vector<char>>& table, const int y)
{
    int row;
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
}

int colCoordinate(vector<vector<char>>& table, const int y)
{
    int col;
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
}

void changeArrow(vector<vector<char>>& table, int arrRow, int arrCol, string direction)
{
    if(direction.compare("up") == 0)
    {
        table[arrRow - 1][arrCol - 1] = '^';
    }
    else if(direction.compare("down") == 0)
    {
        table[arrRow - 1][arrCol - 1] = 'v';
    }
    else if(direction.compare("left") == 0)
    {
        table[arrRow - 1][arrCol - 1] = '<';
    }
    else if(direction.compare("right") == 0)
    {
        table[arrRow - 1][arrCol - 1] = '>';
    }
}

int zombiesRow(vector<vector<char>>& table, char zombChar, const int y)
{
    int rowZ;
    for(int i = 0; i < table.size(); ++i)
    {
        for(int j = 0 ; j < y; ++j)
        {
            if(table[i][j] == zombChar)
            {
                rowZ = i;
            }
        }
    }
    return rowZ;
}

int zombiesCol(vector<vector<char>>& table, char zombChar, const int y)
{
    int colZ;
    for(int i = 0; i < table.size(); ++i)
    {
        for(int j = 0 ; j < y; ++j)
        {
            if(table[i][j] == zombChar)
            {
                colZ = j;
            }
        }
    }
    return colZ;
}

int checkUp(vector<vector<char>>& table, const int rowZ, const int colZ)
{ 
    if((table[rowZ - 1][colZ] == 'A') || (table[rowZ - 1][colZ] == '1') || (table[rowZ - 1][colZ] == '2') || (table[rowZ - 1][colZ] == '3') || (table[rowZ - 1][colZ] == '4') || (table[rowZ - 1][colZ] == '5') || (table[rowZ - 1][colZ] == '6') || (table[rowZ - 1][colZ] == '7') || (table[rowZ - 1][colZ] == '8') || (table[rowZ - 1][colZ] == '9'))
    {
        return 0; // fail potential movement
    }
    else
    {
        return 1; //success potential movemnet
    }
}

int checkDown(vector<vector<char>>& table, const int rowZ, const int colZ)
{
    if((table[rowZ + 1][colZ] == 'A') || (table[rowZ + 1][colZ] == '1') || (table[rowZ + 1][colZ] == '2') || (table[rowZ + 1][colZ] == '3') || (table[rowZ + 1][colZ] == '4') || (table[rowZ + 1][colZ] == '5') || (table[rowZ + 1][colZ] == '6') || (table[rowZ + 1][colZ] == '7') || (table[rowZ + 1][colZ] == '8') || (table[rowZ + 1][colZ] == '9'))
    {
        return 0; // fail potential movement
    }
    else
    {
        return 1; //success potential movemnet
    }
}

int checkLeft(vector<vector<char>>& table, const int rowZ, const int colZ)
{
    if((table[rowZ][colZ - 1] == 'A') || (table[rowZ][colZ - 1] == '1') || (table[rowZ][colZ - 1] == '2') || (table[rowZ][colZ - 1] == '3') || (table[rowZ][colZ - 1] == '4') || (table[rowZ][colZ - 1] == '5') || (table[rowZ][colZ - 1] == '6') || (table[rowZ][colZ - 1] == '7') || (table[rowZ][colZ - 1] == '8') || (table[rowZ][colZ - 1] == '9'))
    {
        return 0; // fail potential movement
    }
    else
    {
        return 1; //success potential movemnet
    }
}

int checkRight(vector<vector<char>>& table, const int rowZ, const int colZ)
{
    if((table[rowZ][colZ + 1] == 'A') || (table[rowZ][colZ + 1] == '1') || (table[rowZ][colZ + 1] == '2') || (table[rowZ][colZ + 1] == '3') || (table[rowZ][colZ + 1] == '4') || (table[rowZ][colZ + 1] == '5') || (table[rowZ][colZ + 1] == '6') || (table[rowZ][colZ + 1] == '7') || (table[rowZ][colZ + 1] == '8') || (table[rowZ][colZ + 1] == '9'))
    {
        return 0; // failmovement
    }
    else
    {
        return 1; //successmovemnet
    }
}

void podDamage(vector<vector<char>>& table, vector<vector<int>>& allZombiesStats, vector<int>& turn , const int x, const int y, const int z)
{
    int rowA = rowCoordinate(table, y); // row of alien  rowA = 5
    //cout << rowA << endl; system("PAUSE");
    int colA = colCoordinate(table, y); // column of alien  colA = 4
    //cout << colA << endl; system("PAUSE");
    int nearestIndex;                        // index of nearest zombies
    int smallValue = 50;
    int indZombInStats;
    vector<int> allRange;               // contain the distance of the zombies from the alien
    vector<vector<int>> zombCoordinate; // contain coordinate of all alive zombies

    for(int i = 1; i < turn.size(); ++i) // loop for finding the coordinate of all alive zombies & store it in the zombCoordinate vector // turn = [0,1,2,3,4]
    {
        vector<int> inCoor;
        char zombChar = '0' + turn[i]; //zombChar = '1'
        //cout << zombChar << endl; system("PAUSE");
        for(int j = 0; j < table.size(); ++j) 
        {
            for(int k = 0; k < y; ++k)
            {
                if(table[j][k] == zombChar) 
                {
                    int rowZomb = zombiesRow(table, zombChar, y); //cout << rowZomb << endl; system("PAUSE");
                    int colZomb = zombiesCol(table, zombChar, y); //cout << colZomb << endl; system("PAUSE");
                    inCoor.push_back(colZomb); inCoor.push_back(rowZomb); // [6,0], [1,1], [3,6], [2,3]
                    zombCoordinate.push_back(inCoor); // [[6,0], [1,1], [3,6], [2,3]]
                }
            }
        }
    }

    for(int i = 0; i < zombCoordinate.size(); ++i) // loop for calculate teh column distance between all zombies and the alien
    {
        int tempDis = 0;
        if(zombCoordinate[i][0] <= colA)
        {
            tempDis = colA - zombCoordinate[i][0]; //cout << tempDis << endl; system("PAUSE");
            allRange.push_back(tempDis); // [4, 3, 2, 1]

        }
        else
        {
            tempDis = zombCoordinate[i][0] - colA; //cout << tempDis << endl; system("PAUSE");
            allRange.push_back(tempDis); // [4, 3, 2, 1]
        }
    }


    for(int i = 0; i < allRange.size(); ++i)
    {
        int rowDistance = 0;
        if(zombCoordinate[i][1] <= rowA)
        {
            rowDistance = rowA - zombCoordinate[i][1]; //cout << rowDistance << endl; system("PAUSE");
            allRange[i] = allRange[i] + rowDistance; //cout << allRange[i] << endl; system("PAUSE");
        }
        else
        {
            rowDistance = zombCoordinate[i][1] - rowA; //cout << rowDistance << endl; system("PAUSE");
            allRange[i] = allRange[i] + rowDistance; //cout << allRange[i] << endl; system("PAUSE");
        }
    }

    for(int i = 0; i < allRange.size(); ++i) // find the nearest distance of the zombie and alien // allRange = [5, 7, 4, 4]
    {
        if(allRange[i] < smallValue) // 4 < 5
        {
            smallValue = allRange[i]; // prevValue = 4
            // nearest = i; // nearest = 0
        }
    }

    for(int i = 0; i < allRange.size(); ++i)
    {
        if(allRange[i] == smallValue)
        {
            nearestIndex = i + 1;
            break;
        }
    }

    int zombieTurn = turn[nearestIndex] - 1; // turn = [0,1,2,3,4]

    if(allZombiesStats[zombieTurn][0] > 10) // zombiestats = [1,2,3]
    {
        allZombiesStats[zombieTurn][0] = allZombiesStats[zombieTurn][0] - 10;
    }
    else
    {
        allZombiesStats[zombieTurn][0] = 0;
        turn.erase(turn.begin() + nearestIndex);
    }

}

void alienMovement(string option, vector<vector<char>>& table, vector<int>& alienStats, vector<vector<int>>& allZombiesStats, MakingTable board, const int x, const int y, const int z, vector<int>& turn)
{
    int rowA = rowCoordinate(table, y); // rowA = 3
    int colA = colCoordinate(table, y); // colA = 2
    int conds;
    int messageInd, stopIndicator = 1;
    int drive = 1, stop = 0, equateX, equateY, prevX, prevY;
    char withinA;
    
    if(option.compare("up") == 0)
    {
        drive = rowA;       // drive = 3
        stop = 0;           
        equateX = rowA - 1; // equateX = 2
        equateY = colA;     // equateY = 2
        prevX = rowA;
        prevY = colA;
        conds = 1;
    }
    else if(option.compare("down") == 0)
    {
        drive = rowA;
        stop = x - 1;
        equateX = rowA + 1;
        equateY = colA;
        prevX = rowA;
        prevY = colA;
        conds = 2;
    }
    else if(option.compare("left") == 0)
    {
        drive = colA;
        stop = 0;
        equateX = rowA;
        equateY = colA - 1;
        prevX = rowA;
        prevY = colA;
        conds = 3;
    }
    else if(option.compare("right") == 0)
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
        cout << endl << "Invalid input. Please make sure you the input are accurate." << endl;
    }

    while((drive != stop) && (stopIndicator != 0)) // drive = 3, stop = 0, stopindicator = 1
    {
        withinA = table[equateX][equateY];
        if((withinA == '^'))
        {
            table[equateX][equateY] = 'A';
            table[rowA][colA] = '.';
            alienStats[1] = alienStats[1] + 20;
            rowA = rowCoordinate(table, y);
            colA = colCoordinate(table, y);
            drive = rowA; stop = 0; equateX = rowA - 1; equateY = colA, conds = 1;
            messageInd = 5;
        }
        else if((withinA == 'v'))
        {
            table[equateX][equateY] = 'A';
            table[rowA][colA] = '.';
            alienStats[1] = alienStats[1] + 20;
            rowA = rowCoordinate(table, y);
            colA = colCoordinate(table, y);
            drive = rowA; stop = x - 1; equateX = rowA + 1; equateY = colA, conds = 2;
            messageInd = 5;

        }
        else if((withinA == '<'))
        {
            table[equateX][equateY] = 'A';
            table[rowA][colA] = '.';
            alienStats[1] = alienStats[1] + 20;
            rowA = rowCoordinate(table, y);
            colA = colCoordinate(table, y);
            drive = colA; stop = 0; equateX = rowA; equateY = colA - 1, conds = 3;
            messageInd = 5;

        }
        else if((withinA == '>'))
        {
            table[equateX][equateY] = 'A';
            table[rowA][colA] = '.';
            alienStats[1] = alienStats[1] + 20;
            rowA = rowCoordinate(table, y);
            colA = colCoordinate(table, y);
            drive = colA; stop = y - 1; equateX = rowA; equateY = colA + 1, conds = 4;
            messageInd = 5;

        }
        else if((withinA == 'r'))
        {
            while(table[equateX][equateY] == 'r')
            {
                table[equateX][equateY] = board.objectGenerator();
            }
            messageInd = 1;
            stopIndicator = 0;
            rowA = rowCoordinate(table, y);
            colA = colCoordinate(table, y);
            if(conds == 1)
            {
                drive = rowA; stop = 0; equateX = rowA - 1; equateY = colA;
            }
            else if(conds == 2)
            {
                drive = rowA; stop = x - 1; equateX = rowA + 1; equateY = colA;
            }
            else if(conds == 3)
            {
                drive = colA; stop = 0; equateX = rowA; equateY = colA - 1;
            }
            else if(conds == 4)
            {
                drive = colA; stop = y - 1; equateX = rowA; equateY = colA + 1;  
            }
        }
        else if((withinA == '1' || withinA == '2' || withinA ==  '3' || withinA ==  '4' || withinA ==  '5' || withinA ==  '6' || withinA ==  '7' || withinA ==  '8' || withinA ==  '9'))
        {
            int indZombie = withinA - '0' - 1;
            int indZombieTurn = withinA - '0';
            if (allZombiesStats[indZombie][0] <= alienStats[1])
            {
                allZombiesStats[indZombie][0] = 0;
                table[equateX][equateY] = 'A'; 
                table[rowA][colA] = '.';
                rowA = rowCoordinate(table, y); // row = 2
                colA = colCoordinate(table, y); // col = 2
                if(conds == 1)
                {
                    drive = rowA; stop = 0; equateX = rowA - 1; equateY = colA;
                }
                else if(conds == 2)
                {
                    drive = rowA; stop = x - 1; equateX = rowA + 1; equateY = colA;
                }
                else if(conds == 3)
                {
                    drive = colA; stop = 0; equateX = rowA; equateY = colA - 1;
                }
                else if(conds == 4)
                {
                    drive = colA; stop = y - 1; equateX = rowA; equateY = colA + 1;  
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
                if(conds == 1)
                {
                    drive = rowA; stop = 0; equateX = rowA - 1; equateY = colA;
                }
                else if(conds == 2)
                {
                    drive = rowA; stop = x - 1; equateX = rowA + 1; equateY = colA;
                }
                else if(conds == 3)
                {
                    drive = colA; stop = 0; equateX = rowA; equateY = colA - 1;
                }
                else if(conds == 4)
                {
                    drive = colA; stop = y - 1; equateX = rowA; equateY = colA + 1;  
                }
            }
        }
        else if((withinA == 'p'))
        {
            table[equateX][equateY] = 'A';
            table[rowA][colA] = '.';
            rowA = rowCoordinate(table, y);
            colA = colCoordinate(table, y);
            messageInd = 4;
            podDamage(table, allZombiesStats, turn, x, y, z); // allzombiestats = [[240, 60, 3], [280, 50, 4], [240, 50, 2], [290, 60, 2]] & turn = [0,1,2,3,4]
            if(conds == 1)
            {
                drive = rowA; stop = 0; equateX = rowA - 1; equateY = colA;
            }
            else if(conds == 2)
            {
                drive = rowA; stop = x - 1; equateX = rowA + 1; equateY = colA;
            }
            else if(conds == 3)
            {
                drive = colA; stop = 0; equateX = rowA; equateY = colA - 1;
            }
            else if(conds == 4)
            {
                drive = colA; stop = y - 1; equateX = rowA; equateY = colA + 1;  
            }
        }
        else if((withinA == ' '))
        {
            table[equateX][equateY] = 'A';   
            table[rowA][colA] = '.';         
            rowA = rowCoordinate(table, y);  
            colA = colCoordinate(table, y);  
            if(conds == 1)
            {
                drive = rowA; stop = 0; equateX = rowA - 1; equateY = colA;  // equateX = 1, equateY = 2
            }
            else if(conds == 2)
            {
                drive = rowA; stop = x - 1; equateX = rowA + 1; equateY = colA;
            }
            else if(conds == 3)
            {
                drive = colA; stop = 0; equateX = rowA; equateY = colA - 1;
            }
            else if(conds == 4)
            {
                drive = colA; stop = y - 1; equateX = rowA; equateY = colA + 1;   
            }
        }
        else if((withinA == 'h'))
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
            if(conds == 1)
            {
                drive = rowA; stop = 0; equateX = rowA - 1; equateY = colA;  // equateX = 1, equateY = 2
            }
            else if(conds == 2)
            {
                drive = rowA; stop = x - 1; equateX = rowA + 1; equateY = colA;
            }
            else if(conds == 3)
            {
                drive = colA; stop = 0; equateX = rowA; equateY = colA - 1;
            }
            else if(conds == 4)
            {
                drive = colA; stop = y - 1; equateX = rowA; equateY = colA + 1;   
            }
        }
        else
        {
            table[equateX][equateY] = 'A';
            table[rowA][colA] = '.';
            rowA = rowCoordinate(table, y);
            colA = colCoordinate(table, y); 
            if(conds == 1)
            {
                drive = rowA; stop = 0; equateX = rowA - 1; equateY = colA;
            }
            else if(conds == 2)
            {
                drive = rowA; stop = x - 1; equateX = rowA + 1; equateY = colA;
            }
            else if(conds == 3)
            {
                drive = colA; stop = 0; equateX = rowA; equateY = colA - 1;
            }
            else if(conds == 4)
            {
                drive = colA; stop = y - 1; equateX = rowA; equateY = colA + 1;     
            }
        }
        system("CLS");
        tablePrinting(table, alienStats, allZombiesStats, x, y, z);
        if(messageInd == 1)
        {
            cout << endl << "You have encountered a rock. Your turn has ended." << endl << "Secret objects awaits you....." << endl;
        }
        else if(messageInd == 2)
        {
            cout << endl << "You have encountered a zombie whose life value is higher than your attack value." << endl << "Your turn has ended." << endl;
        }
        else if(messageInd == 3)
        {
            cout << endl << "Congrats!!! You have found a health pack with a value of 20." << endl << "Have a safe journey." << endl;
        }
        else if(messageInd == 4)
        {
            cout << endl << "You encounterd a pod. 10 value of damage is applied to the nearest zombie." << endl;
        }
        else if(messageInd == 5)
        {
            cout << endl << "You endcountered an arrow. Your attack value increase by 20." << endl;
        }
        system("PAUSE");
    }
    for(int i = 0; i < table.size(); ++i)
    {
        for(int j = 0; j < y; ++j)
        {
            if(table[i][j] == '.')
            {
                table[i][j] = board.objectGenerator();
            }
        }
    }
    alienStats[1] = 0;
}

void zombieMovement(vector<vector<char>>& table, vector<int>& alienStats, vector<vector<int>>& allZombiesStats, int zombTurn, vector<int>& turn, const int x, const int y, const int z)
{
    int move = 1;                               // move variable used to complete 2 attacking routine of the zombies
    int rowA = rowCoordinate(table, y);         // get the row of the Alien
    int colA = colCoordinate(table, y);         // get the column of the Alien 
    char zombChar =  '0' + zombTurn;            // get the char of the alien such as '1', '2', ....
    int zombStatsIndex = zombTurn - 1;
    int rowZ = zombiesRow(table, zombChar, y);  // get the row of the zombie
    int colZ = zombiesCol(table, zombChar, y);  // get the col of the zombie
    while(move < 3)
    {
        if(move == 1)
        {
            if(rowZ == 0)
            {
                if(colZ == 0)
                {
                    //check right & down
                    int withinRight = checkRight(table, rowZ, colZ);
                    int withinDown = checkDown(table, rowZ, colZ);
                    if(withinRight == 1)
                    {
                        table[rowZ][colZ + 1] = zombChar;
                        table[rowZ][colZ] = ' ';
                        move = move + 1;
                        system("CLS");
                        tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                        cout << endl << "Zombie " << zombChar << " moves to the right." << endl;
                        system("PAUSE");
                    }
                    else if(withinDown == 1)
                    {
                        table[rowZ + 1][colZ] = zombChar;
                        table[rowZ][colZ] = ' ';
                        move = move + 1;
                        system("CLS");
                        tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                        cout << endl << "Zombie " << zombChar << " moves downwards." << endl;
                        system("PAUSE");
                    }
                    else
                    {
                        system("CLS");
                        move = move + 1;
                        tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                        cout << endl << "Zombie " << zombChar << " are restricted to move." << endl;
                        system("PAUSE");
                    }

                }
                else if(colZ == y - 1)
                {
                    //check left & down
                    int withinLeft = checkLeft(table, rowZ, colZ);
                    int withinDown = checkDown(table, rowZ, colZ);
                    if(withinLeft == 1)
                    {
                        table[rowZ][colZ - 1] = zombChar;
                        table[rowZ][colZ] = ' ';
                        move = move + 1;
                        system("CLS");
                        tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                        cout << endl << "Zombie " << zombChar << " moves to the left." << endl;
                        system("PAUSE");
                    }
                    else if(withinDown == 1)
                    {
                        table[rowZ + 1][colZ] = zombChar;
                        table[rowZ][colZ] = ' ';
                        move = move + 1;
                        system("CLS");
                        tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                        cout << endl << "Zombie " << zombChar << " moves downwards." << endl;
                        system("PAUSE");
                    }
                    else
                    {
                        system("CLS");
                        move = move + 1;
                        tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                        cout << endl << "Zombie " << zombChar << " are restricted to move." << endl;
                        system("PAUSE");
                    }
                }
                else
                {
                    //check left & right & down
                    int withinLeft = checkLeft(table, rowZ, colZ);
                    int withinRight = checkRight(table, rowZ, colZ);
                    int withinDown = checkDown(table, rowZ, colZ);
                    if(withinLeft == 1)
                    {
                        table[rowZ][colZ - 1] = zombChar;
                        table[rowZ][colZ] = ' ';
                        move = move + 1;
                        system("CLS");
                        tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                        cout << endl << "Zombie " << zombChar << " moves to the left." << endl;
                        system("PAUSE");
                    }
                    else if(withinRight == 1)
                    {
                        table[rowZ][colZ + 1] = zombChar;
                        table[rowZ][colZ] = ' ';
                        move = move + 1;
                        system("CLS");
                        tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                        cout << endl << "Zombie " << zombChar << " moves to the right." << endl;
                        system("PAUSE");
                    }
                    else if(withinDown == 1)
                    {
                        table[rowZ + 1][colZ] = zombChar;
                        table[rowZ][colZ] = ' ';
                        move = move + 1;
                        system("CLS");
                        tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                        cout << endl << "Zombie " << zombChar << " moves downwards." << endl;
                        system("PAUSE");
                    }
                    else
                    {
                        system("CLS");
                        move = move + 1;
                        tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                        cout << endl << "Zombie " << zombChar << " are restricted to move." << endl;
                        system("PAUSE");
                    }
                }
            }
            else if(rowZ == x - 1)
            {
                if(colZ == 0)
                {
                    //check up & right
                    int withinUp = checkUp(table, rowZ, colZ);
                    int withinRight = checkRight(table, rowZ, colZ);
                    if (withinUp == 1)
                    {
                        table[rowZ - 1][colZ] = zombChar;
                        table[rowZ][colZ] = ' ';
                        move = move + 1;
                        system("CLS");
                        tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                        cout << endl << "Zombie " << zombChar << " moves upwards." << endl;
                        system("PAUSE");
                    }
                    else if(withinRight == 1)
                    {
                        table[rowZ][colZ + 1] = zombChar;
                        table[rowZ][colZ] = ' ';
                        move = move + 1;
                        system("CLS");
                        tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                        cout << endl << "Zombie " << zombChar << " moves to the right." << endl;
                        system("PAUSE");
                    }
                    else
                    {
                        system("CLS");
                        move = move + 1;
                        tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                        cout << endl << "Zombie " << zombChar << " are restricted to move." << endl;
                        system("PAUSE");
                    }
                }
                else if(colZ == y - 1)
                {
                    //check up & left
                    int withinUp = checkUp(table, rowZ, colZ);
                    int withinLeft = checkLeft(table, rowZ, colZ);
                    if(withinUp == 1)
                    {
                        table[rowZ - 1][colZ] = zombChar;
                        table[rowZ][colZ] = ' ';
                        move = move + 1;
                        system("CLS");
                        tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                        cout << endl << "Zombie " << zombChar << " moves upwards." << endl;
                        system("PAUSE");
                    }
                    else if(withinLeft == 1)
                    {
                        table[rowZ][colZ - 1] = zombChar;
                        table[rowZ][colZ] = ' ';
                        move = move + 1;
                        system("CLS");
                        tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                        cout << endl << "Zombie " << zombChar << " moves to the left." << endl;
                        system("PAUSE");
                    }
                    else
                    {
                        system("CLS");
                        move = move + 1;
                        tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                        cout << endl << "Zombie " << zombChar << " are restricted to move." << endl;
                        system("PAUSE");
                    }
                }
                else
                {
                    //check left & right & up
                    int withinLeft = checkLeft(table, rowZ, colZ);
                    int withinRight = checkRight(table, rowZ, colZ);
                    int withinUp = checkUp(table, rowZ, colZ);
                    if(withinLeft == 1)
                    {
                        table[rowZ][colZ - 1] = zombChar;
                        table[rowZ][colZ] = ' ';
                        move = move + 1;
                        system("CLS");
                        tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                        cout << endl << "Zombie " << zombChar << " moves to the left." << endl;
                        system("PAUSE");
                    }
                    else if(withinRight == 1)
                    {
                        table[rowZ][colZ + 1] = zombChar;
                        table[rowZ][colZ] = ' ';
                        move = move + 1;
                        system("CLS");
                        tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                        cout << endl << "Zombie " << zombChar << " moves to the right." << endl;
                        system("PAUSE");
                    }
                    else if(withinUp == 1)
                    {
                        table[rowZ - 1][colZ] = zombChar;
                        table[rowZ][colZ] = ' ';
                        move = move + 1;
                        system("CLS");
                        tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                        cout << endl << "Zombie " << zombChar << " moves upwards." << endl;
                        system("PAUSE");
                    }
                    else
                    {
                        system("CLS");
                        move = move + 1;
                        tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                        cout << endl << "Zombie " << zombChar << " are restricted to move." << endl;
                        system("PAUSE");
                    }
                }
            }
            else if(colZ == 0)
            {
                //check up & down & right
                int withinUp = checkUp(table, rowZ, colZ);
                int withinDown = checkDown(table, rowZ, colZ);
                int withinRight = checkRight(table, rowZ, colZ);
                if(withinUp == 1)
                {
                    table[rowZ - 1][colZ] = zombChar;
                    table[rowZ][colZ] = ' ';
                    move = move + 1;
                    system("CLS");
                    tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                    cout << endl << "Zombie " << zombChar << " moves upwards." << endl;
                    system("PAUSE");
                }
                else if(withinDown == 1)
                {
                    table[rowZ + 1][colZ] = zombChar;
                    table[rowZ][colZ] = ' ';
                    move = move + 1;
                    system("CLS");
                    tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                    cout << endl << "Zombie " << zombChar << " moves downwards." << endl;
                    system("PAUSE");
                }
                else if(withinRight == 1)
                {
                    table[rowZ][colZ + 1] = zombChar;
                    table[rowZ][colZ] = ' ';
                    move = move + 1;
                    system("CLS");
                    tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                    cout << endl << "Zombie " << zombChar << " moves to the right." << endl;
                    system("PAUSE");
                }
                else
                {
                    system("CLS");
                    move = move + 1;
                    tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                    cout << endl << "Zombie " << zombChar << " are restricted to move." << endl;
                    system("PAUSE");
                }

            }
            else if(colZ == y - 1)
            {
                //check up & down & left
                int withinUp = checkUp(table, rowZ, colZ);
                int withinDown = checkDown(table, rowZ, colZ);
                int withinLeft = checkLeft(table, rowZ, colZ);
                if(withinUp == 1)
                {
                    table[rowZ - 1][colZ] = zombChar;
                    table[rowZ][colZ] = ' ';
                    move = move + 1;
                    system("CLS");
                    tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                    cout << endl << "Zombie " << zombChar << " moves upwards." << endl;
                    system("PAUSE");
                }
                else if(withinDown == 1)
                {
                    table[rowZ + 1][colZ] = zombChar;
                    table[rowZ][colZ] = ' ';
                    move = move + 1;
                    system("CLS");
                    tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                    cout << endl << "Zombie " << zombChar << " moves downwards." << endl;
                    system("PAUSE");
                }
                else if(withinLeft == 1)
                {
                    table[rowZ][colZ - 1] = zombChar;
                    table[rowZ][colZ] = ' ';
                    move = move + 1;
                    system("CLS");
                    tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                    cout << endl << "Zombie " << zombChar << " moves to the left." << endl;
                    system("PAUSE");
                }
                else
                {
                    move = move + 1;
                    system("CLS");
                    tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                    cout << endl << "Zombie " << zombChar << " are restricted to move." << endl;
                    system("PAUSE");
                }
            }
            else
            {
                //check up & down & left & right
                int withinUp = checkUp(table, rowZ, colZ);
                int withinDown = checkDown(table, rowZ, colZ);
                int withinLeft = checkLeft(table, rowZ, colZ);
                int withinRight = checkRight(table, rowZ, colZ);
                if(withinUp == 1)
                {
                    table[rowZ - 1][colZ] = zombChar;
                    table[rowZ][colZ] = ' ';
                    move = move + 1;
                    system("CLS");
                    tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                    cout << endl << "Zombie " << zombChar << " moves upwards." << endl;
                    system("PAUSE");
                }
                else if(withinDown == 1)
                {
                    table[rowZ + 1][colZ] = zombChar;
                    table[rowZ][colZ] = ' ';
                    move = move + 1;
                    system("CLS");
                    tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                    cout << endl << "Zombie " << zombChar << " moves downwards." << endl;
                    system("PAUSE");
                }
                else if(withinLeft == 1)
                {
                    table[rowZ][colZ - 1] = zombChar;
                    table[rowZ][colZ] = ' ';
                    move = move + 1;
                    system("CLS");
                    tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                    cout << endl << "Zombie " << zombChar << " moves to the left." << endl;
                    system("PAUSE");
                }
                else if(withinRight == 1)
                {
                    table[rowZ][colZ + 1] = zombChar;
                    table[rowZ][colZ] = ' ';
                    move = move + 1;
                    system("CLS");
                    tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                    cout << endl << "Zombie " << zombChar << " moves to the right." << endl;
                    system("PAUSE");
                }
                else
                {
                    move = move + 1;
                    system("CLS");
                    tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                    cout << endl << "Zombie " << zombChar << " are restricted to move." << endl;
                    system("PAUSE");
                }
            }

        }
        else if (move == 2)
        {
            rowZ = zombiesRow(table, zombChar, y);
            colZ = zombiesCol(table, zombChar, y);
            if(rowZ == rowA)
            {
                int rangeDis;
                if(colZ >= colA)
                {
                    rangeDis = colZ - colA;
                    if(rangeDis <= allZombiesStats[zombStatsIndex][2])
                    {
                        move = move + 1;
                        if(alienStats[0] > allZombiesStats[zombStatsIndex][1])
                        {
                            move = move + 1;
                            alienStats[0] = alienStats[0] - allZombiesStats[zombStatsIndex][1];
                            system("CLS");
                            tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                            cout << endl << "Zombie " << zombChar << " attack Alien." << endl;
                            cout << "Alien receives a damage of " << allZombiesStats[zombStatsIndex][1] << endl;
                            system("PAUSE");
                        }
                        else
                        {
                            move = move + 1;
                            alienStats[0] = 0;
                            system("CLS");
                            tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                            cout << endl << "Zombie " << zombChar << " attack Alien." << endl;
                            cout << "Alien receives a damage of " << allZombiesStats[zombStatsIndex][1] << endl;
                            turn.erase(turn.begin());
                            system("PAUSE");
                        }
                    }
                    else
                    {
                        move = move + 1;
                        system("CLS");
                        tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                        cout << endl << "Zombie " << zombChar << " unable to attack Alien because too far away." << endl;
                        system("PAUSE");
                    }
                }
                else
                {
                    rangeDis = colA - colZ;
                    if(rangeDis <= allZombiesStats[zombStatsIndex][2])
                    {
                        if(alienStats[0] > allZombiesStats[zombStatsIndex][1])
                        {
                            move = move + 1;
                            alienStats[0] = alienStats[0] - allZombiesStats[zombStatsIndex][1];
                            system("CLS");
                            tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                            cout << endl << "Zombie " << zombChar << " attack Alien." << endl;
                            cout << "Alien receives a damage of " << allZombiesStats[zombStatsIndex][1] << endl;
                            system("PAUSE");
                        }
                        else
                        {
                            move = move + 1;
                            alienStats[0] = 0;
                            system("CLS");
                            tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                            cout << endl << "Zombie " << zombChar << " attack Alien." << endl;
                            cout << "Alien receives a damage of " << allZombiesStats[zombStatsIndex][1] << endl;
                            turn.erase(turn.begin());
                            system("PAUSE");
                        }
                    }
                    else
                    {
                        move = move + 1;
                        system("CLS");
                        tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                        cout << endl << "Zombie " << zombChar << " unable to attack Alien because too far away." << endl;
                        system("PAUSE");
                    }
                }
            }
            else if(colZ == colA)
            {
                int rangeDis;
                if(rowZ >= rowA)
                {
                    rangeDis = rowZ - rowA;
                    if(rangeDis <= allZombiesStats[zombStatsIndex][2])
                    {
                        if(alienStats[0] > allZombiesStats[zombStatsIndex][1])
                        {
                            move = move + 1;
                            alienStats[0] = alienStats[0] - allZombiesStats[zombStatsIndex][1];
                            system("CLS");
                            tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                            cout << endl << "Zombie " << zombChar << " attack Alien." << endl;
                            cout << "Alien receives a damage of " << allZombiesStats[zombStatsIndex][1] << endl;
                            system("PAUSE");
                        }
                        else
                        {
                            move = move + 1;
                            alienStats[0] = 0;
                            system("CLS");
                            tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                            cout << endl << "Zombie " << zombChar << " attack Alien." << endl;
                            cout << "Alien receives a damage of " << allZombiesStats[zombStatsIndex][1] << endl;
                            turn.erase(turn.begin());
                            system("PAUSE");
                        }
                    }
                    else
                    {
                        move = move + 1;
                        system("CLS");
                        tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                        cout << endl << "Zombie " << zombChar << " unable to attack Alien because too far away." << endl;
                        system("PAUSE");
                    }
                }
                else
                {
                    rangeDis = rowA - rowZ;
                    if(rangeDis <= allZombiesStats[zombStatsIndex][2])
                    {
                        if(alienStats[0] > allZombiesStats[zombStatsIndex][1])
                        {
                            move = move + 1;
                            alienStats[0] = alienStats[0] - allZombiesStats[zombStatsIndex][1];
                            system("CLS");
                            tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                            cout << endl << "Zombie " << zombChar << " attack Alien." << endl;
                            cout << "Alien receives a damage of " << allZombiesStats[zombStatsIndex][1] << endl;
                            system("PAUSE");
                        }
                        else
                        {
                            move = move + 1;
                            alienStats[0] = 0;
                            system("CLS");
                            tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                            cout << endl << "Zombie " << zombChar << " attack Alien." << endl;
                            cout << "Alien receives a damage of " << allZombiesStats[zombStatsIndex][1] << endl;
                            turn.erase(turn.begin());
                            system("PAUSE");
                        }
                    }
                    else
                    {
                        move = move + 1;
                        system("CLS");
                        tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                        cout << endl << "Zombie " << zombChar << " unable to attack Alien because too far away." << endl;
                        system("PAUSE");
                    }
                }
            }
            else
            {
                move = move + 1;
                system("CLS");
                tablePrinting(table, alienStats, allZombiesStats, x, y, z);
                cout << endl << "Zombie " << zombChar << " unable to attack Alien because too far away." << endl;
                system("PAUSE");
            }
        }
    }
}

void saveGame(vector<vector<char>>& table, vector<int>& alienStats, vector<vector<int>>& allZombiesStats, vector<int>& turn, const int x, const int y, const int z)
{
    string fileName; // Define variable for file's name
    cout << "Type in your own filename (without .txt) => "; // Asks user to input in a file name without .txt as the program will automatically add .txt for them
    cin >> fileName; // Input in file's name

    ofstream file; // Open file
    file.open(fileName + ".txt"); // Open file based on user's file's name

    file << x << endl; file << y << endl; file << z << endl; // save the rowNum, colNum and zombiesNum information;

    for(int i = 0; i < alienStats.size(); ++i) // save the alienStats information
    {
        file << alienStats[i] << " ";
    }

    file << endl;

    for(int i = 0 ; i < allZombiesStats.size(); ++i) // save the zombies stats information
    {
        for(int j = 0; j < 3; ++j)
        {
            file << allZombiesStats[i][j] << " ";
        }
    }

    file << endl;

    for(int i = 0; i < turn.size(); ++i) // save the turn information
    {
        file << turn[i] << " ";
    }

    file << endl;

    for(int i = 0; i < table.size(); ++i) // save the gameboard information
    {
        for(int j = 0; j < y; ++j)
        {
            file << table[i][j];
        }
    }

    file << endl;

    file.close(); // Close file

    cout << "Game Saved " << endl; // Program prints out confirmation after saving files
    system("PAUSE"); // Pause screen to give user time to read the confirmation message
}

void gameMainMenu() // Void function for Alien Vs Zombies Main Menu
{
    // Game Menu for Alien Vs Zombies
    cout << "========================== " << endl;
    cout << "  .: Alien Vs Zombies :.  " << endl;
    cout << "========================== " << endl;
    cout << "| 1. Start Game          | " << endl;
    cout << "| 2. Load Game           | " << endl;
    cout << "| 3. About Game          | " << endl;
    cout << "| 4. Exit                | " << endl;
    cout << "========================== " << endl;
}

int main()
{
    bool mainMenu = true;
    srand(time(NULL));
    while(mainMenu)
    {
        int playerChoice;
        vector<int> turn;
        system("CLS");
        gameMainMenu(); // Display main menu for Alien Vs Zombies
        cout << "Your choice => ";
        cin >> playerChoice; // Ask the player to choose an option (1, 2, 3 or 4)

        // If statement if player chose 1 to start game
        if (playerChoice == 1)
        {
            mainMenu = false; // Ignore mainMenu
            int rowNum = 3, colNum = 19, zombiesNum = 2; // Default values for the number of row, column and zombies
            char playerChoice;                           // Define the variable for player's choice to change the default values
            bool gameSettings = true;                    // Define the variable for gameSettings for loop purposes

            while (gameSettings)
            {
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
                        cout << " ====================================================================================== " << endl;
                        cout << " REMINDER! Game Requirements\n 1. Insert odd value only to ensure the Alien spawns in the middle of the Game Board\n 2. Minimum number of row is 3 and maximum number of row is 9\n 3. Minimum number of column is 3 and maximum number of column is 21\n 4. Minimum number of zombies is 1 and maximum number of column is 9 " << endl;
                        cout << " ====================================================================================== " << endl;
                        cout << " Enter a new value for row => ";
                        cin >> rowNum;
                        cout << " Enter a new value for column => ";
                        cin >> colNum;
                        cout << " Enter a new value for zombies => ";
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
                                    for (int i = 0; i < turn.size(); )
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
                                                cout << "Command Guides\n- up = Alien moves upward\n- down = Alien moves downwards\n- left = Alien moves left\n- right = Alien moves right\n- arrow = Switch the direction of an arrow object in the Game Board\n- save = Save the current game to a file\n- quit = Quit the game " << endl;
                                                cout << "============================================= " << endl;
                                                system("PAUSE");
                                            }
                                            else if (option.compare("save") == 0)
                                            {
                                                saveGame(board.table, board.alienStats, board.allZombiesStats, turn, rowNum, colNum, zombiesNum);
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
                                            cout << "It is zombie " << turn[i] << " turn...."; cout << endl;
                                            system("PAUSE");  
                                            zombieMovement(board.table, board.alienStats, board.allZombiesStats, turn[i], turn, rowNum, colNum, zombiesNum);
                                            if(turn[0] != 0)
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
                                            cout << "It is zombie " << turn[i] << " turn...."; cout << endl;
                                            system("PAUSE");  
                                            zombieMovement(board.table, board.alienStats, board.allZombiesStats, turn[i], turn, rowNum, colNum, zombiesNum);
                                            if(turn[0] != 0)
                                            {
                                                lose = 0;
                                                break;
                                            }
                                            ++i;
                                        }
                                    }

                                    if(quitBefLosing == 0)
                                    {
                                        inGame = false;
                                        gameSettings = false;
                                        mainMenu = true;
                                        cout << endl << "Entering main menu...." << endl; system("PAUSE");
                                    }
                                    else if(lose == 0)
                                    {
                                        inGame = false;
                                        gameSettings = false;
                                        mainMenu = true;
                                        cout << "You lost the game" << endl;
                                        cout << endl << "Entering main menu...." << endl; system("PAUSE");
                                    }
                                    else
                                    {
                                        bool endGame = true;
                                        while(endGame)
                                        {
                                            cout << endl;
                                            cout << "You have won the game!!!!" << endl;
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
                        for (int i = 0; i < turn.size(); )
                        {
                            if (i == 0)
                            {
                                system("CLS");
                                tablePrinting(board.table, board.alienStats, board.allZombiesStats, rowNum, colNum, zombiesNum);
                                cout << endl;
                                cout << "It is your turn, the mightiest Alien in the milky way" << endl;
                                cout << endl;
                                cout << "Enter Your Command => "; cin >> option;
                                if(option.compare("arrow") == 0)
                                {
                                    int arrRow, arrCol;
                                    int truthFlag = 1;
                                    string direct;

                                    cout << endl;
                                    cout << "Enter row of the arrow    => "; cin >> arrRow;// cout << endl;
                                    cout << "Enter column of the arrow => "; cin >> arrCol;// cout << endl;
                                    cout << "Enter the direction that you want (up/down/left/right) => "; cin >> direct; cout << endl;
                                    for(int i = 0; i < board.table.size(); ++i)
                                    {
                                        for(int j = 0; j < colNum; ++j)
                                        {
                                            if((board.table[arrRow - 1][arrCol - 1] == '^' || board.table[arrRow - 1][arrCol - 1] == 'v' || board.table[arrRow - 1][arrCol - 1] == '<' || board.table[arrRow - 1][arrCol - 1] == '>'))
                                            {
                                                truthFlag = 0;
                                            }
                                        }
                                    }
                                    if(truthFlag == 0)
                                    {
                                        changeArrow(board.table, arrRow, arrCol, direct);
                                    }
                                    else if(truthFlag != 0)
                                    {
                                        cout << endl << "You enter the input in the wrong format." << endl << "Please make sure the coordinate and the direction are correct." << endl;
                                        system("PAUSE");
                                    }
                                }
                                else if((option.compare("up") == 0 || option.compare("down") == 0 || option.compare("left") == 0 || option.compare("right") == 0))
                                {
                                    ++i;
                                    alienMovement(option, board.table, board.alienStats, board.allZombiesStats, board, rowNum, colNum, zombiesNum, turn);
                                }
                                else if(option.compare("help") == 0)
                                {
                                    cout << endl;
                                    cout << "============================================= " << endl;
                                    cout << "Command Guides\n- up = Alien moves upward\n- down = Alien moves downwards\n- left = Alien moves left\n- right = Alien moves right\n- arrow = Switch the direction of an arrow object in the Game Board\n- save = Save the current game to a file\n- quit = Quit the game " << endl;
                                    cout << "============================================= " << endl;
                                    system("PAUSE");
                                }
                                else if (option.compare("save") == 0)
                                {
                                    saveGame(board.table, board.alienStats, board.allZombiesStats, turn, rowNum, colNum, zombiesNum);
                                }
                                else if(option.compare("quit") == 0)
                                {
                                    quitBefLosing = 0;
                                    break;
                                }
                                else
                                {
                                    cout << "Invalid input. Make sure the input are accurate." << endl << "Please refer to help option for more information of the commands." << endl;
                                    system("PAUSE");
                                }
                            }
                            else if (i == turn.size() - 1)
                            {
                                system("CLS");
                                tablePrinting(board.table, board.alienStats, board.allZombiesStats, rowNum, colNum, zombiesNum);
                                cout << endl;
                                cout << "It is zombie " << turn[i] << " turn...."; cout << endl;
                                system("PAUSE");  
                                zombieMovement(board.table, board.alienStats, board.allZombiesStats, turn[i], turn, rowNum, colNum, zombiesNum);
                                if(turn[0] != 0)
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
                                cout << "It is zombie " << turn[i] << " turn...."; cout << endl;
                                system("PAUSE");
                                zombieMovement(board.table, board.alienStats, board.allZombiesStats, turn[i], turn, rowNum, colNum, zombiesNum);
                                if(turn[0] != 0)
                                {
                                    lose = 0;
                                    break;
                                }
                                ++i;
                            }
                        }
                        if(quitBefLosing == 0)
                        {
                            inGame = false;
                            gameSettings = false;
                            mainMenu = true;
                            cout << endl << "Entering main manu...." << endl; system("PAUSE");
                        }
                        else if(lose == 0)
                        {
                            inGame = false;
                            gameSettings = false;
                            mainMenu = true;
                            cout << "You have lose the game." << endl;
                            cout << endl << "Entering main manu...." << endl; system("PAUSE");
                        }
                        else
                        {
                            bool endGame = true;
                            while (endGame)
                            {
                                char choice;
                                system("CLS");
                                cout << "You have won the game!!!!" << endl;
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

                //game settings

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

            cout << "Enter the file name you want to load => "; cin >> filename;
            ifstream fileOpen(filename + ".txt");

            if(fileOpen.fail())
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
                for(int i = 0; i < zombiesNum; ++i)
                {
                    vector<int> inZomStats;
                    for(int j = 0; j < 3; ++j)
                    {
                        int zombiesInfo;
                        fileOpen >> zombiesInfo;
                        inZomStats.push_back(zombiesInfo);
                    }
                    allZombiesStats.push_back(inZomStats);
                }
                cout << allZombiesStats.size() << endl;

                // retrieve turn
                for(int i = 0; i < zombiesNum + 1; ++i)
                {
                    int attTurn;
                    fileOpen >> attTurn;
                    turn.push_back(attTurn);
                }
                cout << turn.size() << endl;

                // retrieve the table information into string variable string line
                int currLine = 0;
                while(!fileOpen.eof())
                {
                    currLine++;
                    getline(fileOpen, line);
                    if(line.size() > 1)
                    {
                        break;
                    }
                }

                int k = 0;
                while(k < line.size())
                {
                    vector<char> inCol;
                    for(int i = 0; i < colNum; ++i)
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
                while(inGame)
                {
                    for (int i = 0; i < turn.size(); )
                    {
                        if (i == 0)
                        {
                            system("CLS");
                            tablePrinting(table, alienStats, allZombiesStats, rowNum, colNum, zombiesNum);
                            cout << endl;
                            cout << "It is your turn, the mightiest Alien in the milky way" << endl;
                            cout << endl;
                            cout << "Enter Your Command => "; cin >> option;
                            if(option.compare("arrow") == 0)
                            {
                                int arrRow, arrCol;
                                int truthFlag = 1;
                                string direct;

                                cout << endl;
                                cout << "Enter row of the arrow    => "; cin >> arrRow;// cout << endl;
                                cout << "Enter column of the arrow => "; cin >> arrCol;// cout << endl;
                                cout << "Enter the direction that you want (up/down/left/right) => "; cin >> direct; cout << endl;
                                for(int i = 0; i < table.size(); ++i)
                                {
                                    for(int j = 0; j < colNum; ++j)
                                    {
                                        if((table[arrRow - 1][arrCol - 1] == '^' || table[arrRow - 1][arrCol - 1] == 'v' || table[arrRow - 1][arrCol - 1] == '<' || table[arrRow - 1][arrCol - 1] == '>'))
                                        {
                                            truthFlag = 0;
                                        }
                                    }
                                }
                                if(truthFlag == 0)
                                {
                                    changeArrow(table, arrRow, arrCol, direct);
                                }
                                else if(truthFlag != 0)
                                {
                                    cout << endl << "You enter the input in the wrong format." << endl << "Please make sure the coordinate and the direction are correct." << endl;
                                    system("PAUSE");
                                }
                            }
                            else if((option.compare("up") == 0 || option.compare("down") == 0 || option.compare("left") == 0 || option.compare("right") == 0))
                            {
                                ++i;
                                alienMovement(option, table, alienStats, allZombiesStats, justFunction, rowNum, colNum, zombiesNum, turn);
                            }
                            else if(option.compare("help") == 0)
                            {
                                cout << endl;
                                cout << "============================================= " << endl;
                                cout << "Command Guides\n- up = Alien moves upward\n- down = Alien moves downwards\n- left = Alien moves left\n- right = Alien moves right\n- arrow = Switch the direction of an arrow object in the Game Board\n- save = Save the current game to a file\n- quit = Quit the game " << endl;
                                cout << "============================================= " << endl;
                                system("PAUSE");
                            }
                            else if (option.compare("save") == 0)
                            {
                                saveGame(table, alienStats, allZombiesStats, turn, rowNum, colNum, zombiesNum);
                            }
                            else if(option.compare("quit") == 0)
                            {
                                quitBefLosing = 0;
                                break;
                            }
                            else
                            {
                                cout << "Invalid input. Make sure the input are accurate." << endl << "Please refer to help option for more information of the commands." << endl;
                                system("PAUSE");
                            }
                        }
                        else if (i == turn.size() - 1)
                        {
                            system("CLS");
                            tablePrinting(table, alienStats, allZombiesStats, rowNum, colNum, zombiesNum);
                            cout << endl;
                            cout << "It is zombie " << turn[i] << " turn...."; cout << endl;
                            system("PAUSE");  
                            zombieMovement(table, alienStats, allZombiesStats, turn[i], turn, rowNum, colNum, zombiesNum);
                            if(turn[0] != 0)
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
                            cout << "It is zombie " << turn[i] << " turn...."; cout << endl;
                            system("PAUSE");
                            zombieMovement(table, alienStats, allZombiesStats, turn[i], turn, rowNum, colNum, zombiesNum);
                            if(turn[0] != 0)
                            {
                                lose = 0;
                                break;
                            }
                            ++i;
                        }
                    }

                    if(quitBefLosing == 0)
                    {
                        inGame = false;
                        mainMenu = true;
                        cout << endl << "Entering main manu...." << endl; system("PAUSE");
                    }
                    else if(lose == 0)
                    {
                        inGame = false;
                        mainMenu = true;
                        cout << "You have lose the game." << endl;
                        cout << endl << "Entering main manu...." << endl; system("PAUSE");
                    }
                    else
                    {
                        inGame = false;
                        mainMenu = true;
                        cout << "You have won the game." << endl;
                        cout << endl << "Entering main manu...." << endl; system("PAUSE");
                    }
                }
            }
        }
        else if (playerChoice == 3)
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