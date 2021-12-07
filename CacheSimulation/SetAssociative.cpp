#include "SetAssociative.h"

SetAssociative::SetAssociative(int blckSize, int numBlcks, int nSets, bool rep) {
    blockSize = blckSize;
    fifo = rep;
    if (fifo)
        replace = "FIFO";
    else
        replace = "LRU ";
    numBlocks = numBlcks;
    numSets = nSets;
    hits = 0;
    misses = 0;
    cacheSize = blockSize * numBlocks * numSets;
    offsetSize = log(blockSize) / log(2);
    numLines = cacheSize / blockSize;
    deque <int> q;
    for (int i = 0; i < nSets; i++)
        cacheLines.push_back(q);
}

string SetAssociative::GetTag(string address) {
    int setNS = log(numSets) / log(2);
    return address.substr(0, address.size()-setNS);
}

string SetAssociative::GetSet(string address) {
    int setNS = log(numSets) / log(2);
    return address.substr(address.size() - setNS, address.size());
}

void SetAssociative::Simulate(string inputFile) {
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

bool SetAssociative::checkHit(string addressInHex) {
    string address = HexToBin(addressInHex);
    string addressInBin = RemoveOffset(address);
    string tag = GetTag(addressInBin);
    string set = GetSet(addressInBin);
    int tagNum = BinToDec(tag);
    int setN = BinToDec(set);
    bool hit = false;
    int index;
    for (int i = 0; i < cacheLines[setN].size(); i++) {
        if (cacheLines[setN].at(i) == tagNum) {
            hit = true;
            index = i;
        }
    }
    if (!fifo && hit) {
        cacheLines[setN].erase(cacheLines[setN].begin() + index);
        cacheLines[setN].push_back(tagNum);
    }
    if (!hit) {
        cacheLines[setN].push_back(tagNum);
        if (cacheLines[setN].size() > numBlocks) {
            cacheLines[setN].pop_front();
        }
    }
    return hit;
}

string SetAssociative::RemoveOffset(string address) {
    return address.substr(0,address.size() - offsetSize);
}

int SetAssociative::BinToDec(string bin) {
    int dec = 0;
    for (int i = 0; i < bin.size(); i++) {
        if (bin[i] == '1')
            dec += pow(2, bin.size()-i-1);
    }
    return dec;
}

string SetAssociative::HexToBin(string hex) {
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
