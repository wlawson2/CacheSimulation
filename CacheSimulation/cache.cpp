#include "cache.h"

void cache::GetUserDetails() {
    numSets = GetUserInput("Enter the number of sets in the cache (a positive power of 2) :");
    numBlocks = GetUserInput("Enter the number of blocks in each set (a positive power of 2) :");
    blockSize = GetUserInput("Enter the number of bytes in a block (a positive power of 2, must be at least 4 :");
}

int cache::GetUserInput(string outputMessage) {
    bool valid = false;
    int input;
    while (!valid) {
        cout << outputMessage;
        cin >> input;
        valid = true;
        if (!valid)
            cout << "Invalid input" << endl;
        else
            cout << "Input accepted" << endl;
    }
    return input;
}