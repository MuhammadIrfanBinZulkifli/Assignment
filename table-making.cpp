//this file is table-making.cpp
#include "table-making.hpp"

char MakingTable::objectGenerator()
{
    int index;
    char theObject[10] = {'h', '^', ' ', 'p', '<', ' ', 'r', ' ', '>', 'v'};
    char finalObject;
    for (int i = 0; i < 3; ++i)
    {
        if (i == 1)
        {
            index = rand() % 10;
            finalObject = theObject[index];
        }
    }
    return finalObject;
}

void MakingTable::zombiePlacement(vector<vector<char>>& table, const int x, const int y, const int z)
{
    char zombiesTroop[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int randomCoordinateRow, randomCoordinateCol;
    randomCoordinateRow = rand() % x;
    randomCoordinateCol = rand() % y;
    vector<int> tempX; tempX.push_back(randomCoordinateRow);
    vector<int> tempY; tempY.push_back(randomCoordinateCol);
    int zombiesCount = 0;
    while (zombiesCount < z)
    {
        int flag = 1;
        randomCoordinateRow = rand() % x;
        randomCoordinateCol = rand() % y;

        for (int i = 0; i < tempX.size(); ++i)
        {
            if (randomCoordinateRow == tempX[i] && randomCoordinateCol == tempY[i])
            {
                flag = 0;
            }
        }
        
        if (flag == 1)
        {
            if (table[randomCoordinateRow][randomCoordinateCol] != 'A')
            {
                //randomCoordinate = randomCoordinateForZombies(tempRowNum, tempColNum);
                table[randomCoordinateRow][randomCoordinateCol] = zombiesTroop[zombiesCount];
                vector<int> inCoordinate;
                tempX.push_back(randomCoordinateRow);
                tempY.push_back(randomCoordinateCol);
                zombiesCount = zombiesCount + 1;
            }
        }
    }
}

void MakingTable::zombiesStats(const int x, const int y, const int z)
{
    for (int i = 1; i <= z; i++)
    {
        vector<int> inStats;
        for (int j = 0; j < 3; j++)
        {
            int life, attack, range, smallest;
            if (x < y)
                smallest = x;
            else
                smallest = y;

            if (j == 0)
            {

                do
                {
                    life = rand() % 200 + 100;
                } while (life % 10 != 0);
                inStats.push_back(life);

            }
            else if (j == 1)
            {

                do
                {
                    attack = rand() % 70 + 30;
                } while (attack % 10 != 0);
                inStats.push_back(attack);
                
            }
            else
            {
                do
                {
                    range = rand() % smallest;
                } while (range == 0);
                inStats.push_back(range);
            }
        }
        allZombiesStats.push_back(inStats);
    }
}

void MakingTable::tablePrinting(vector<vector<char>>& table, vector<int>& alienStats, vector<vector<int>>& allZombiesStats, const int x, const int y, const int z)
{
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
    for (int j = 0; j < y; ++j) // j== 0..14
    {
        cout << " " << (j + 1) % 10;
    }
    cout << endl
        << endl;
    cout << endl;

    cout << "Alien     :" << " Life " << alienStats[0] << " , " << " Attack " << alienStats[1] << endl;
    for (int i = 0; i < z; i++)
    {
        cout << "Zombie " << i + 1 << "  :" << " Life " << allZombiesStats[i][0] << " , " << " Attack " << allZombiesStats[i][1] << " , " << " Range " << allZombiesStats[i][2] << endl;
    }
}

MakingTable::MakingTable(int x, int y, int z)
{
    for (int i = 0; i < x; ++i)
    {
        vector<char> inObjects;
        for (int j = 0; j < y; ++j)
        {
            char obj = objectGenerator();
            inObjects.push_back(obj);
        }
        table.push_back(inObjects);
    }
    table[x/2][y/2] = 'A';
    // alienPlacement(table, x, y);
    zombiePlacement(table, x, y, z);
    zombiesStats(x, y, z);
}