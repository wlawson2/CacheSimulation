#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "DirectMap.h"
#include "SetAssociative.h"
#include "FullyAssociative.h"
using namespace std;

int main() {
    
    string fileName="gcc.trace";
    string filePath = "C:/Users/wdlaw/Downloads/";
    cout << fileName << " successfully open.\n" << "Simulation running... \n";
    FullyAssociative fa(64, 64, 1, true);
    fa.Simulate(filePath+fileName);
    cout << (double)fa.hits / (fa.hits + fa.misses);


    /*
    FullyAssociative fa1(4, 4, 1, false);
    FullyAssociative fa2(4, 4, 1, true);
    FullyAssociative fa3(4, 64, 1, false);
    FullyAssociative fa4(4, 64, 1, true);
    FullyAssociative fa5(4, 256, 1, false);
    FullyAssociative fa6(4, 256, 1, true);
    FullyAssociative fa7(64, 4, 1, false);
    FullyAssociative fa8(64, 4, 1, true);
    FullyAssociative fa9(256, 4, 1, false);
    FullyAssociative fa10(256, 4, 1, true);
    FullyAssociative fa11(64, 64, 1, false);
    FullyAssociative fa12(64, 64, 1, false);
    cout << endl << endl << endl;
    
    cout << "Fully Associative, gcc.trace" << endl;
    cout << " Sets | Blocks / Set | Bytes / Block | Cache Size | Replacement| Hit Rate \n";
    fa1.Simulate(filePath + fileName);
    cout << "   " << fa1.numSets << "  |       " << fa1.numBlocks << "      |       " << fa1.blockSize << "       |     " << fa1.cacheSize << "     |     " << fa1.replace << "   |    " << (double)fa1.hits / (fa1.hits + fa1.misses) << endl;
   
    fa2.Simulate(filePath + fileName);
    cout << "   " << fa2.numSets << "  |       " << fa2.numBlocks << "      |       " << fa2.blockSize << "       |     " << fa2.cacheSize << "     |     " << fa2.replace << "   |    " << (double)fa2.hits / (fa2.hits + fa2.misses) << endl;
    fa3.Simulate(filePath + fileName);
    cout << "   " << fa3.numSets << "  |      " << fa3.numBlocks << "      |       " << fa3.blockSize << "       |     " << fa3.cacheSize << "    |     " << fa3.replace << "   |    " << (double)fa3.hits / (fa3.hits + fa3.misses) << endl;
    fa4.Simulate(filePath + fileName);
    cout << "   " << fa4.numSets << "  |      " << fa4.numBlocks << "      |       " << fa4.blockSize << "       |    " << fa4.cacheSize << "     |     " << fa4.replace << "   |    " << (double)fa4.hits / (fa4.hits + fa4.misses) << endl;
    fa5.Simulate(filePath + fileName);
    cout << "   " << fa5.numSets << "  |      " << fa5.numBlocks << "     |       " << fa5.blockSize << "       |     " << fa5.cacheSize << "   |     " << fa5.replace << "   |    " << (double)fa5.hits / (fa5.hits + fa5.misses) << endl;
    fa6.Simulate(filePath + fileName); 
    cout << "   " << fa6.numSets << "  |      " << fa6.numBlocks << "     |       " << fa6.blockSize << "       |     " << fa6.cacheSize << "   |     " << fa6.replace << "   |    " << (double)fa6.hits / (fa6.hits + fa6.misses) << endl;
    fa7.Simulate(filePath + fileName);
    cout << "   " << fa7.numSets << "  |       " << fa7.numBlocks << "      |       " << fa7.blockSize << "       |     " << fa7.cacheSize << "    |     " << fa7.replace << "   |    " << (double)fa7.hits / (fa7.hits + fa7.misses) << endl;
    fa8.Simulate(filePath + fileName);
    cout << "   " << fa8.numSets << "  |       " << fa8.numBlocks << "      |       " << fa8.blockSize << "       |     " << fa8.cacheSize << "    |     " << fa8.replace << "   |    " << (double)fa8.hits / (fa8.hits + fa8.misses) << endl;
    fa9.Simulate(filePath + fileName);
    cout << "   " << fa9.numSets << "  |       " << fa9.numBlocks << "      |      " << fa9.blockSize << "     |     " << fa9.cacheSize << "    |     " << fa9.replace << "   |    " << (double)fa9.hits / (fa9.hits + fa9.misses) << endl;
    fa10.Simulate(filePath + fileName);
    cout << "   " << fa10.numSets << "  |       " << fa10.numBlocks << "      |      " << fa10.blockSize << "      |    " << fa10.cacheSize << "    |     " << fa10.replace << "   |    " << (double)fa10.hits / (fa10.hits + fa10.misses) << endl;
    fa11.Simulate(filePath + fileName);
    cout << "   " << fa11.numSets << "  |      " << fa11.numBlocks << "      |       " << fa11.blockSize << "       |   " << fa11.cacheSize << "    |     " << fa11.replace << "   |    " << (double)fa11.hits / (fa11.hits + fa11.misses) << endl;
    fa12.Simulate(filePath + fileName);
    cout << "   " << fa12.numSets << "  |      " << fa12.numBlocks << "      |       " << fa12.blockSize << "       |   " << fa12.cacheSize << "    |     " << fa12.replace << "   |    " << (double)fa12.hits / (fa12.hits + fa12.misses) << endl;


    cout << endl << endl << endl;


    SetAssociative sa1(4, 4, 4, true);
    SetAssociative sa2(4, 4, 4, false);
    SetAssociative sa3(4, 4, 16, true);
    SetAssociative sa4(4, 4, 16, false);
    SetAssociative sa5(4, 16, 4, true);
    SetAssociative sa6(4, 16, 4, false);
    SetAssociative sa7(4, 64, 4, true);
    SetAssociative sa8(4, 64, 4, false);
    SetAssociative sa9(16, 4, 4, true);
    SetAssociative sa10(16, 4, 4, false);
    SetAssociative sa11(64, 4, 4, true);
    SetAssociative sa12(64, 4, 4, false);
    SetAssociative sa13(16, 16, 16, true);
    SetAssociative sa14(16, 16, 16, false);
    SetAssociative sa15(64, 64, 64, true);
    SetAssociative sa16(64, 64, 64, false);

    cout << "Set Associative, gcc.trace" << endl;
    cout << " Sets | Blocks / Set | Bytes / Block | Cache Size | Replacement | Hit Rate \n";
    sa1.Simulate(filePath + fileName);
    cout << "   " << sa1.numSets << "  |       " << sa1.numBlocks << "      |       " << sa1.blockSize << "       |     " << sa1.cacheSize << "     |     "  << sa1.replace  << "   |    " << (double)sa1.hits / (sa1.hits + sa1.misses) << endl;
    sa2.Simulate(filePath + fileName);
    cout << "   " << sa2.numSets << "  |       " << sa2.numBlocks << "      |       " << sa2.blockSize << "       |     " << sa2.cacheSize << "     |     " << sa2.replace << "   |    " << (double)sa2.hits / (sa2.hits + sa2.misses) << endl;
    sa3.Simulate(filePath + fileName);
    cout << "   " << sa3.numSets << " |       " << sa3.numBlocks << "      |       " << sa3.blockSize << "       |     " << sa3.cacheSize << "    |     " << sa3.replace << "   |    " << (double)sa3.hits / (sa3.hits + sa3.misses) << endl;
    sa4.Simulate(filePath + fileName);
    cout << "   " << sa4.numSets << " |       " << sa4.numBlocks << "      |       " << sa4.blockSize << "       |    " << sa4.cacheSize << "    |     " << sa4.replace << "   |    " << (double)sa4.hits / (sa4.hits + sa4.misses) << endl;
    sa5.Simulate(filePath + fileName);
    cout << "   " << sa5.numSets << "  |       " << sa5.numBlocks << "     |      " << sa5.blockSize << "       |     " << sa5.cacheSize << "    |     " << sa5.replace << "   |    " << (double)sa5.hits / (sa5.hits + sa5.misses) << endl;
    sa6.Simulate(filePath + fileName);
    cout << "   " << sa6.numSets << "  |       " << sa6.numBlocks << "    |      " << sa6.blockSize << "       |     " << sa6.cacheSize << "    |     " << sa6.replace << "   |    " << (double)sa6.hits / (sa6.hits + sa6.misses) << endl;
    sa7.Simulate(filePath + fileName);
    cout << "   " << sa7.numSets << "  |       " << sa7.numBlocks << "     |      " << sa7.blockSize << "       |   " << sa7.cacheSize << "    |     " << sa7.replace << "   |    " << (double)sa7.hits / (sa7.hits + sa7.misses) << endl;
    sa8.Simulate(filePath + fileName);
    cout << "   " << sa8.numSets << "  |       " << sa8.numBlocks << "     |      " << sa8.blockSize << "       |   " << sa8.cacheSize << "    |     " << sa8.replace << "   |    " << (double)sa8.hits / (sa8.hits + sa8.misses) << endl;
    sa9.Simulate(filePath + fileName);
    cout << "   " << sa9.numSets << "  |       " << sa9.numBlocks << "      |      " << sa9.blockSize << "       |     " << sa9.cacheSize << "    |     " << sa9.replace << "   |    " << (double)sa9.hits / (sa9.hits + sa9.misses) << endl;
    sa10.Simulate(filePath + fileName);
    cout << "   " << sa10.numSets << "  |       " << sa10.numBlocks << "      |      " << sa10.blockSize << "       |    " << sa10.cacheSize << "    |     " << sa10.replace << "   |    " << (double)sa10.hits / (sa10.hits + sa10.misses) << endl;
    sa11.Simulate(filePath + fileName);
    cout << "   " << sa11.numSets << "  |       " << sa11.numBlocks << "      |      " << sa11.blockSize << "       |   " << sa11.cacheSize << "    |     " << sa11.replace << "   |    " << (double)sa11.hits / (sa11.hits + sa11.misses) << endl;
    sa12.Simulate(filePath + fileName);
    cout << "   " << sa12.numSets << "  |       " << sa12.numBlocks << "      |      " << sa12.blockSize << "       |   " << sa12.cacheSize << "    |     " << sa12.replace << "   |    " << (double)sa12.hits / (sa12.hits + sa12.misses) << endl;
    sa13.Simulate(filePath + fileName);
    cout << "   " << sa13.numSets << " |       " << sa13.numBlocks << "     |      " << sa13.blockSize << "       |   " << sa13.cacheSize << "    |     " << sa13.replace << "   |    " << (double)sa13.hits / (sa13.hits + sa13.misses) << endl;
    sa14.Simulate(filePath + fileName);
    cout << "   " << sa14.numSets << " |       " << sa14.numBlocks << "     |      " << sa14.blockSize << "       |   " << sa14.cacheSize << "    |     " << sa14.replace << "   |    " << (double)sa14.hits / (sa14.hits + sa14.misses) << endl;
    sa15.Simulate(filePath + fileName);
    cout << "   " << sa15.numSets << " |       " << sa15.numBlocks << "     |      " << sa15.blockSize << "       |  " << sa15.cacheSize << "   |     " << sa15.replace << "   |    " << (double)sa15.hits / (sa15.hits + sa15.misses) << endl;
    sa16.Simulate(filePath + fileName);
    cout << "   " << sa16.numSets << " |       " << sa16.numBlocks << "     |      " << sa16.blockSize << "       |  " << sa16.cacheSize << "   |     " << sa16.replace << "   |    " << (double)sa16.hits / (sa16.hits + sa16.misses) << endl;

    cout << endl << endl << endl;


    DirectMap dm1(4, 1, 4);
    DirectMap dm2(4, 1, 16);
    DirectMap dm3(4, 1, 64);
    DirectMap dm4(4, 1, 256);
    DirectMap dm5(16, 1, 4);
    DirectMap dm6(16, 1, 16);
    DirectMap dm7(16, 1, 64);
    DirectMap dm8(16, 1, 256);
    DirectMap dm9(64, 1, 4);
    DirectMap dm10(64, 1, 16);
    DirectMap dm11(64, 1, 64);
    DirectMap dm12(64, 1, 256);
    
    cout << "Direct mapped, gcc.trace" << endl;
    cout << " Sets | Blocks / Set | Bytes / Block | Cache Size | Replacement | Hit Rate \n";
    dm1.Simulate(filePath + fileName);
    cout << "   " << dm1.numSets << "  |       " << dm1.numBlocks << "      |       " << dm1.blockSize  << "       |     "  << dm1.cacheSize << "     |     None    | " << (double)dm1.hits / (dm1.hits + dm1.misses) << endl;
    dm2.Simulate(filePath + fileName);
    cout << "   " << dm2.numSets << " |       " << dm2.numBlocks << "      |       " << dm2.blockSize << "       |     " << dm2.cacheSize << "     |     None    | " << (double)dm2.hits / (dm2.hits + dm2.misses) << endl;
    dm3.Simulate(filePath + fileName);
    cout << "   " << dm3.numSets << " |       " << dm3.numBlocks << "      |       " << dm3.blockSize << "       |     " << dm3.cacheSize << "    |     None    | " << (double)dm3.hits / (dm3.hits + dm3.misses) << endl;
    dm4.Simulate(filePath + fileName);
    cout << "  " << dm4.numSets << " |       " << dm4.numBlocks << "      |       " << dm4.blockSize << "       |    " << dm4.cacheSize << "    |     None    | " << (double)dm4.hits / (dm4.hits + dm4.misses) << endl;
    dm5.Simulate(filePath + fileName);
    cout << "   " << dm5.numSets << "  |       " << dm5.numBlocks << "      |      " << dm5.blockSize << "       |     " << dm5.cacheSize << "     |     None    | " << (double)dm5.hits / (dm5.hits + dm5.misses) << endl;
    dm6.Simulate(filePath + fileName);
    cout << "   " << dm6.numSets << " |       " << dm6.numBlocks << "      |      " << dm6.blockSize << "       |     " << dm6.cacheSize << "    |     None    | " << (double)dm6.hits / (dm6.hits + dm6.misses) << endl;
    dm7.Simulate(filePath + fileName);
    cout << "   " << dm7.numSets << " |       " << dm7.numBlocks << "      |      " << dm7.blockSize << "       |    " << dm7.cacheSize << "    |     None    | " << (double)dm7.hits / (dm7.hits + dm7.misses) << endl;
    dm8.Simulate(filePath + fileName);
    cout << "  " << dm8.numSets << " |       " << dm8.numBlocks << "      |      " << dm8.blockSize << "       |    " << dm8.cacheSize << "    |     None    | " << (double)dm8.hits / (dm8.hits + dm8.misses) << endl;
    dm9.Simulate(filePath + fileName);
    cout << "   " << dm9.numSets << "  |       " << dm9.numBlocks << "      |      " << dm9.blockSize << "       |     " << dm9.cacheSize << "    |     None    | " << (double)dm9.hits / (dm9.hits + dm9.misses) << endl;
    dm10.Simulate(filePath + fileName);
    cout << "   " << dm10.numSets << " |       " << dm10.numBlocks << "      |      " << dm10.blockSize << "       |    " << dm10.cacheSize << "    |     None    | " << (double)dm10.hits / (dm10.hits + dm10.misses) << endl;
    dm11.Simulate(filePath + fileName);
    cout << "   " << dm11.numSets << " |       " << dm11.numBlocks << "      |      " << dm11.blockSize << "       |    " << dm11.cacheSize << "    |     None    | " << (double)dm11.hits / (dm11.hits + dm11.misses) << endl;
    dm12.Simulate(filePath + fileName);
    cout << "  " << dm12.numSets << " |       " << dm12.numBlocks << "      |      " << dm12.blockSize << "       |    " << dm12.cacheSize << "   |     None    | " << (double)dm12.hits / (dm12.hits + dm12.misses) << endl;
    */
}