#pragma once
#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <fstream>
using namespace std;

struct SetAssociative
{
    int numSets;
    bool fifo;
    int numBlocks;
    int blockSize;
    int hits;
    int misses;
    int numLines;
    vector <deque<int>> cacheLines;
    int cacheSize;
    int offsetSize;

    SetAssociative(int, int, int,bool);
    string HexToBin(string);
    bool checkHit(string);
    string replace;
    string RemoveOffset(string);
    int BinToDec(string);
    void Simulate(string);
    string GetTag(string);
    string GetSet(string);
};

