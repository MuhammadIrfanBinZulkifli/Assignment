//this file is player-stats.hpp
#ifndef PLAYER_STATS_HPP_
#define PLAYER_STATS_HPP_
#include "table-making.hpp"

class PlayerStats
{
    public:
    vector<int> alienStats = {100, 0};
    vector<vector<int>>allZombiesStats;
    PlayerStats(const int x, const int y, const int z);
    void displayStats(vector<int>& alienStats, vector<vector<int>> allZombiesStats, const int z);
    
};
#endif