#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "cache.h"
using namespace std;

int main() {
    string filePath;
    string fileName;
    cache Cache;
    Cache.GetUserDetails();
    cout << Cache.blockSize << " " << Cache.numBlocks << " " << Cache.numSets;
}
