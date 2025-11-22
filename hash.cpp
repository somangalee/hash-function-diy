#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

#include "hash.h"

using namespace std;

// Creates hash table and makes all slots empty
myHashTable::myHashTable(unsigned int size) {
    k = size;
    allWords = 0;

    table = new Node*[k];

    for (int i = 0; i < k; i++) {
        table[i] = nullptr;
    }
}

// takes a word, transforms all characters to lowercase, adds their ASCII values
int myHashTable::hash_function(string myWord) {
    unsigned int tracker = 0;
    string lower_case = myWord; // creates copy of the word

    for (char c : lower_case) {
        if (c >= 'A' && c <= 'Z') {
            c = c + 32; // converts uppercase characters to lowercase by adding 32. This is because lowercase characters are exactly 32 more than their uppercase counterparts.
        }
        tracker = tracker * 31 + (unsigned char)c; 
    }
    return tracker % k;
}

// Selects which slot words should go into, creates new nodes and adds the node to the slot and updates word counter. 
void myHashTable::insertWord(string myWord) {
    unsigned int slot = hash_function(myWord);

    Node* newNode = new Node;
    newNode->myWord = myWord;
    newNode->next = nullptr;

    if(table[slot] == nullptr) {
        table[slot] = newNode;
    } else {
        newNode->next = table[slot];
        table[slot] = newNode;
    }

    allWords++;
}

// Prints the contents of the first 5 slots.
void myHashTable::tableSlots() {
    for (int i = 0; i < 5 && i < k; i++) {
        cout << "Slot " << i << ": ";

        Node* currentWord = table[i];
        
        while (currentWord != nullptr) {
            cout << currentWord->myWord << " ";
            currentWord = currentWord->next;
        }
        cout << endl;
    }
}

// Prints the slot lengths 
void myHashTable::slotLength() {
    for (int i = 0; i < 100 && i < k; i++) {
        int count = 0;
        Node* current = table[i];

        while (current != nullptr) {
            count++;
            current = current->next;
        }
        cout << "Slot " << i << ": " << count << endl; // Prints the amount of words in each slot
    }
}

// calculates the standard deviation 
void myHashTable::standardDevivation() {
    double mean = (double)allWords/k;

    double sumSquaredDiff = 0.0;
        for (int i = 0; i < k; i++) {
            int slotLength = 0;
            Node* current = table[i];

            while (current != nullptr) {
                slotLength++;
                current = current->next;
            }
            double differences = slotLength - mean;
            sumSquaredDiff += differences * differences;
        }
    double finalStandardDev = sqrt(sumSquaredDiff/k);

    cout << setprecision(4) << finalStandardDev << endl;
}








