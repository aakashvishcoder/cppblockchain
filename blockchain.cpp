#include <iostream>
#include <ctime>
#include <string>
using namespace std;

struct Block {
    int index;
    string data;
    string previousHash;
    string currHash;
    long timestamp;
    int nonce;
    Block* next;

    Block(int idx, string data, string preHash)
    : index(idx), data(data), previousHash(preHash), nonce(0), next(nullptr) {
        timestamp = time(nullptr);
        hash = calculateHash();
    }
    
};