#include <iostream>
#include <string>
#include <cmath>

using namespace std;

struct Node {
    string myWord;
    Node* next;
};

class myHashTable {
    Node** table;
    unsigned int k;
    unsigned int allWords;

    int hash_function(string myWord);

public:
    myHashTable(unsigned int size);

    void insertWord(string myWord);
    void tableSlots(); // prints contents of the slots
    void slotLength(); // prints the slot length
    void standardDevivation(); // prints the standard deviation
};

