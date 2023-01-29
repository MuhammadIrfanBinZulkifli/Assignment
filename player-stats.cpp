//this file is player-stats.cpp
#include "player-stats.hpp"

//function and constructor that being used under PlayerStats class
PlayerStats::PlayerStats(const int x, const int y, const int z)
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

void PlayerStats::displayStats(vector<int>& alienStats, vector<vector<int>> allZombiesStats, const int z)
{
    cout << "Alien     :" << " Life " << alienStats[0] << " , " << " Attack " << alienStats[1] << endl;
    for (int i = 0; i < z; i++)
    {
        cout << "Zombie " << i + 1 << "  :" << " Life " << allZombiesStats[i][0] << " , " << " Attack " << allZombiesStats[i][1] << " , " << " Range " << allZombiesStats[i][2] << endl;
    }
}
