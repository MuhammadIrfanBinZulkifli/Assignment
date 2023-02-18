//this file is table-making.hpp
#ifndef TABLE_MAKING_HPP_
#define TABLE_MAKING_HPP_
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <ctime>
#include <string>
#include <cstring>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

class MakingTable 
{
    public:
    vector<vector<char>> table;// store game board information
    vector<int> alienStats = {100, 0}; // contain alien stats for health and attack attribute in the early game
    vector<vector<int>>allZombiesStats; // contain zombies stats for health, attack and range attribute
    MakingTable(int x, int y, int z); // creating game board class
    void zombiesStats(const int x, const int y, const int z); // generating random stats for zombies at the beginning of the game.
    char objectGenerator(); // randomly generate object for the table making purpose such as arrow, pod, and rock
    void zombiePlacement(vector<vector<char>>& table, const int x, const int y, const int z); // place zombies in the gameboard
    void tablePrinting(vector<vector<char>>& table, vector<int>& alienStats, vector<vector<int>>& allZombiesStats, const int x, const int y, const int z); // print the gameboard
};
#endif