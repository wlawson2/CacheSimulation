#pragma once
#include <string>
#include <iostream>
using namespace std;

struct cache {
    int numSets;
    int numBlocks;
    int blockSize;
    void GetUserDetails();
    int GetUserInput(string);
};

