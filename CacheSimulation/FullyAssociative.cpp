#include "FullyAssociative.h"

FullyAssociative::FullyAssociative(int blckSize, int numBlcks, int nSets, bool rep) {
    //set the caches values based on the parameters given in the constructor
    blockSize = blckSize;
    numBlocks = numBlcks;
    numSets = nSets;
    lru = rep;
    if (!lru)
        replace = "FIFO";
    else
        replace = "LRU ";
    hits = 0;
    misses = 0;
    //Calculate the cache information based on the given parameters
    cacheSize = blockSize * numBlocks * numSets;
    offsetSize = log(blockSize) / log(2);
    numLines = cacheSize / blockSize;

}

void FullyAssociative::Simulate(string inputFile) {
    string memAddress;
    ifstream addressData(inputFile);
    bool isHit;
    string lineData;
    string address;
    if (addressData.is_open()) {
        while (getline(addressData, lineData)) {
            string temp1 = lineData.substr(lineData.find(' ') + 1);
            string temp2 = temp1.substr(0, temp1.find(' '));
            address = temp2.substr(temp2.find('x') + 1);
            isHit = checkHit(address);
            if (isHit)
                hits++;
            else
                misses++;
        }
    }

}

bool FullyAssociative::checkHit(string addressInHex) {
    //remove unnecessary parts of given address and convert to deimal
    bool hit = false;
    int index;
    string address = HexToBin(addressInHex);
    string addressInBin = RemoveOffset(address);
    int tagNum = BinToDec(addressInBin);
    int front;
    if (fifo.empty())
        front = -1;
    else
        front=fifo.front();

    //iterates through cache to check if the address is in the cache
    for (int i = 0; i < fifo.size(); i++) {
        if (fifo.at(i) == tagNum) {
            hit = true;
            index = i;
        }
    }
    //moves address into back of the deque if the replacement method is least recently used
    if (lru) {
        fifo.push_back(tagNum);
        if (fifo.size() > numLines) {
            if (hit)
                fifo.erase(fifo.begin() + index);
            else
                fifo.pop_front();
        }
    }
    //Inserts address into deque if it is a miss.
    else {
        if (!hit) {
            fifo.push_back(tagNum);
            if (fifo.size() > numLines) {
                fifo.pop_front();
            }
        }
    }
    return hit;
}

//removes offset from address since it is not necessary for checking the cache.
string FullyAssociative::RemoveOffset(string address) {
    return address.substr(0,address.size() - offsetSize);
}

// Conversion functions to ease handling of addresses in binary
int FullyAssociative::BinToDec(string bin) {
    int dec = 0;
    for (int i = 0; i < bin.size(); i++) {
        if (bin[i] == '1')
            dec += pow(2, bin.size()-i-1);
    }
    return dec;
}

string FullyAssociative::HexToBin(string hex) {
    string bin;
    for (int i = 0; i < hex.size(); i++) {
        switch (hex[i]) {
        case '0':
            bin += "0000";
            break;
        case '1':
            bin += "0001";
            break;
        case '2':
            bin += "0010";
            break;
        case '3':
            bin += "0011";
            break;
        case '4':
            bin += "0100";
            break;
        case '5':
            bin += "0101";
            break;
        case '6':
            bin += "0110";
            break;
        case '7':
            bin += "0111";
            break;
        case '8':
            bin += "1000";
            break;
        case '9':
            bin += "1001";
            break;
        case 'A':
        case 'a':
            bin += "1010";
            break;
        case 'B':
        case 'b':
            bin += "1011";
            break;
        case 'C':
        case 'c':
            bin += "1100";
            break;
        case 'D':
        case 'd':
            bin += "1101";
            break;
        case 'E':
        case 'e':
            bin += "1110";
            break;
        case 'F':
        case 'f':
            bin += "1111";
            break;
        default:
            cout << "\nInvalid hexadecimal digit ";
        }
    }
    return bin;
}
