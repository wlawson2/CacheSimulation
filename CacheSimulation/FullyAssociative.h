#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <deque>
using namespace std;

struct FullyAssociative
{
    int numSets;
    int numBlocks;
    bool lru;
    int blockSize;
    int hits;
    string replace;
    int misses;
    int numLines;
    deque <int> fifo;
    int cacheSize;
    int offsetSize;

    FullyAssociative(int, int, int, bool);
    string HexToBin(string);
    bool checkHit(string);
    string RemoveOffset(string);
    int BinToDec(string);
    void Simulate(string);
};

