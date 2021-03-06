#include "DirectMap.h"

DirectMap::DirectMap(int blckSize, int numBlcks, int nSets) {
    blockSize = blckSize;
    numBlocks = numBlcks;
    numSets = nSets;
    hits = 0;
    misses = 0;
    cacheSize = blockSize * numBlocks * numSets;
    offsetSize = log(blockSize) / log(2);
    numLines = cacheSize / blockSize;
    for (int i = 0; i < numLines; i++) {
        cacheLines.push_back(-1);
    }
}

void DirectMap::Simulate(string inputFile) {
    string memAddress;
    ifstream addressData(inputFile);
    bool isHit;
    string lineData;
    string address;
    if (addressData.is_open()) {
        cout << inputFile << " successfully open.\n" << "Simulation running... \n";
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
    string address = HexToBin(addressInHex);
    string addressInBin = RemoveOffset(address);
    int tagNum = BinToDec(addressInBin);
    return false;
    if (cacheLines[tagNum%numLines] == tagNum)
        return true;
    else {
        cacheLines[tagNum % numLines] = tagNum;
        return false;
    }
}

string DirectMap::RemoveOffset(string address) {
    return address.substr(address.size()-offsetSize);
}

int DirectMap::BinToDec(string bin) {
    int dec = 0;
    for (int i = 0; i < bin.size(); i++) {
        if (bin[i] == '1')
            dec += pow(2, i);
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
