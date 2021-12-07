#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

struct DirectMap {
    int numSets;
    int numBlocks;
    int blockSize;
    int hits;
    int misses;
    int numLines;
    vector <int> cacheLines;
    int cacheSize;
    int offsetSize;

    
    DirectMap(int,int,int);
    string HexToBin(string);
    bool checkHit(string);
    string RemoveOffset(string);
    int BinToDec(string);
    void Simulate(string);
};

