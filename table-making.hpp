//this file is table-making.hpp
#ifndef TABLE_MAKING_HPP_
#define TABLE_MAKING_HPP_
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <ctime>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

class MakingTable 
{
    public:
    vector<char> table;
    MakingTable(int x, int y, int z);
    char objectGenerator();
    int randomCoordinateForZombies(const int x, const int y);
    void alienPlacement(vector<char>& table, const int x, const int y);
    void zombiePlacement(vector<char>& table, const int x, const int y, const int z);
    void tablePrinting(vector<char>& table, const int y);    
};
#endif