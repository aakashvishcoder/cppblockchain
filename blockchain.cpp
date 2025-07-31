#include <iostream>
#include <ctime>
#include <string>
#include "picosha2.h"
using namespace std;

struct Block {
    int index;
    time_t timestamp;
    string data;
    string previousHash="0";
    string currHash;
    int nonce;
    int difficulty;
    Block* next;

    Block(int idx, std::string data, std::string prevHash, int diff)
    : index(idx),
      timestamp(time(nullptr)),  
      data(data),
      previousHash(prevHash),
      nonce(0),
      difficulty(diff),
      next(nullptr) {
        currHash = calculateHash();  
    }

    string calculateHash() {
        string input = ""+to_string(index)+to_string(timestamp)+data+previousHash+to_string(nonce);
        return picosha2::hash256_hex_string(input);
    }

    void mineBlock() {
        string target(difficulty,'0');
        while (currHash.substr(0,difficulty) != target) {
            nonce++;
            currHash = calculateHash();
        }
        cout << "Block " << index << " mined: " << currHash << " (difficulty: " << difficulty << ")" << endl;
    }
};

class BlockChain {
    Block* head;
    public:
        BlockChain(int difficulty) {
            head = new Block(0,"Genesis Block","",difficulty);
            head->mineBlock();
        }
        void addBlock(string text, int difficulty) {
            Block* temp = head;
            while(temp->next) {
                temp=temp->next;
            }
            Block* newBlock = new Block(temp->index+1,text,temp->currHash, difficulty);
            newBlock->mineBlock();
            temp->next = newBlock;
        }
        void printChain() {
            Block* temp = head;
            while(temp) {
                cout << "Index : " << temp->index << endl;
                cout << "Timestamp : " << temp->timestamp << endl;
                cout << "Data : " << temp->data << endl;
                cout << "Previous Hash : " << temp->previousHash << endl;
                cout << "Current Hash : " << temp->currHash << endl;
                cout << "Nonce : " << temp->nonce << endl;
                cout << "Difficulty: " << temp->difficulty << endl;
                temp=temp->next;
            }
        }
        bool validateChain() {
            Block* temp = head;
            while (temp && temp->next) {
                Block* next = temp->next;

                if (temp->currHash != temp->calculateHash()) {
                    cout << "Invalid hash at block " << temp->index << endl;
                    return 0;
                }

                if (next->previousHash != temp->currHash) {
                    cout << "Broken chain at block " << next->index << endl;
                    return 0;
                }

                if (temp->currHash.substr(0, temp->difficulty) != string(temp->difficulty, '0')) {
                    cout << "Block " << temp->index << " fails the difficulty check!" << endl;
                    return 0;
                }

                temp = temp->next;  
            }

            if (temp) {
                if (temp->currHash != temp->calculateHash()) return 0;
                if (temp->currHash.substr(0, temp->difficulty) != string(temp->difficulty, '0')) return 0;
            }

            return 1;
        }
};

int main() {
    // example code
    BlockChain* chain = new BlockChain(3);
    cout << "Hello !" << endl;
    chain->addBlock("Block1",4);
    chain->addBlock("Block2",5);
    chain->addBlock("Block3",4);
    chain->addBlock("Block4",5);
    chain->printChain();
    cout << chain->validateChain() << endl;
    return 0;
};