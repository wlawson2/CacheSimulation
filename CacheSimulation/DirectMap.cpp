#include "DirectMap.h"

DirectMap::DirectMap(int blckSize, int numBlcks, int nSets) {
    //set the caches values based on the parameters given in the constructor
    blockSize = blckSize;
    numBlocks = numBlcks;
    numSets = nSets;
    hits = 0;
    misses = 0;
    //Calculate the cache information based on the given parameters
    cacheSize = blockSize * numBlocks * numSets;
    offsetSize = log(blockSize) / log(2);
    numLines = cacheSize / blockSize;
    //create the cache with the each line containing -1 initially
    for (int i = 0; i < numLines; i++)
        cacheLines.push_back(-1);

}

//Function called to run the simulation on the cache and the addresses given in the parameter file
void DirectMap::Simulate(string inputFile) {
    string memAddress;
    ifstream addressData(inputFile);
    bool isHit;
    string lineData;
    string address;
    if (addressData.is_open()) {
        //loops through each address in the file and calculates hits and misses.
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

bool DirectMap::checkHit(string addressInHex) {
    //use helper functions to calculate the index that the address would be
    string address = HexToBin(addressInHex);
    string addressInBin = RemoveOffset(address);
    int tagNum = BinToDec(addressInBin);
    int index = tagNum % numLines;
    //check the index to see if the address was a hit or not
    if (cacheLines.at(index) == tagNum) {
        return true;
    }
    else {
        cacheLines[tagNum % numLines] = tagNum;
        return false;
    }
}

//removes offset from address since it is not necessary for checking the cache.
string DirectMap::RemoveOffset(string address) {
    return address.substr(0,address.size()-offsetSize);
}

// Conversion functions to ease handling of addresses in binary
int DirectMap::BinToDec(string bin) {
    int dec = 0;
    for (int i = 0; i < bin.size(); i++) {
        if (bin[i] == '1')
            dec += pow(2, bin.size()-i-1);
    }
    return dec;
}

string DirectMap::HexToBin(string hex) {
    string bin;
    for (int i=0; i<hex.size(); i++) {
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
