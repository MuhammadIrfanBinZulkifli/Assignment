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

int MakingTable::randomCoordinateForZombies(const int x, const int y)
{
    int rowSkip = y * 2 + 1;
    int randomCol = 0; int randomRow = 0;
    while (randomCol % 2 == 0)
    {
        randomCol = rand() % (y * 2 + 1);
    }

    // create random row numbers
    while (randomRow % 2 == 0)
    {
        randomRow = rand() % (x * 2 + 1);
    }

    return randomCol + (rowSkip * randomRow);
}

void MakingTable::alienPlacement(vector<char>& table, const int x, const int y)
{
    for (int i = 0; i < table.size(); ++i)
    {
        if (i == ((x * 2 + 1) * y ) + x)
        {
            table[i] = 'A';
        }
    }
}

void MakingTable::zombiePlacement(vector<char>& table, const int x, const int y, const int z)
{
    char zombiesTroop[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int tempRowNum = x;
    int tempColNum = y;
    int randomCoordinate = 0;

    randomCoordinate = randomCoordinateForZombies(tempRowNum, tempColNum);
    vector<int> tempRandomCoordinate;
    tempRandomCoordinate.push_back(randomCoordinate);

    int zombiesCount = 0;
    while (zombiesCount < z)
    {
        int flag = 1;
        randomCoordinate = randomCoordinateForZombies(tempRowNum, tempColNum);

        //check if the coordinate is used before
        for (int i = 0; i < tempRandomCoordinate.size(); ++i)
        {
            if (tempRandomCoordinate[i] == randomCoordinate)
            {
                flag = 0;
            }
        }
        if (flag == 1)
        {

            if (table[randomCoordinate] != 'A')
            {
                //randomCoordinate = randomCoordinateForZombies(tempRowNum, tempColNum);
                table[randomCoordinate] = zombiesTroop[zombiesCount];
                tempRandomCoordinate.push_back(randomCoordinate);
                zombiesCount = zombiesCount + 1;
            }
        }
    }
}

void MakingTable::tablePrinting(vector<char>& table, const int y)
{
    int rowCount = 1;
    int colCount = 1;
    int rowMark = 1;

    for (int i = 0; i < table.size(); i++)
    {
        if (i == (y * 2 + 1) * rowMark)
        {
            ++rowMark;
            cout << endl;
            cout << table.at(i);
        }
        else if (rowMark % 2 == 0 && i == (y * 2 * rowMark) + (rowMark - 1))
        {
            cout << table.at(i);
            cout << right << setw(3);
            cout << rowCount;
            ++rowCount;
        }
        else
        {
            cout << table.at(i);
        }
    }
    cout << endl;
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
}

MakingTable::MakingTable(int x, int y, int z)
{
    char horiBorder[2] = {'+', '-'};
    char vertiBorder[2] = {'|', ' '};
    int zombiesCount = 0;

    // row looping
    for(int rowCount = 0; rowCount < x * 2 + 1; ++rowCount)
    {

        if (rowCount % 2 == 0)
        {
            for (int colCount = 0; colCount < y * 2 + 1; ++colCount)
            {
                if (colCount % 2 == 0)
                {
                    table.push_back(horiBorder[0]);
                }
                else
                {
                    table.push_back(horiBorder[1]);
                }
            }
        }
        else
        {
            for (int colCount = 0; colCount < y * 2 + 1; ++colCount)
            {
                if (colCount % 2 == 0)
                {
                    table.push_back(vertiBorder[0]);
                }
                else //print object
                {
                    vertiBorder[1] = objectGenerator();
                    table.push_back(vertiBorder[1]);
                }
            }
        }
    }

    alienPlacement(table, x, y);
    zombiePlacement(table, x, y, z);
    tablePrinting(table, y);
}