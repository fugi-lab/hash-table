#include <iostream>
#include <vector>
#include <string>
#include "Primes.hpp"
#include "Entry.hpp"

// A hash table of integers 
class HashTable {
    public:
        HashTable() {
            // Initialize the table and set all indexes to empty entries.
            hashTable.resize(17);
            for (int i = 0; i < size; i++) {
                hashTable[i] = Entry();
            }
        }

        void remove() {

        }

        void put(int a) {
            int index = hashFunc(a);
            // First check if the index is empty or full
            if (hashTable[index].getStatus() == 0 || hashTable[index].getStatus() == 2) {
                hashTable[index] = Entry(a);
            } else {
                if (hashTable[index].getVal() == a) return;
                // std::cout << "Collision: " << a << " with " << hashTable[index].getVal() << std::endl;
                int i = index;
                while (hashTable[i].getStatus() == 1) {
                    i++;
                }
                hashTable[i] = Entry(a);
            }
            curSize++;
            loadFactor = curSize / size;
            if (loadFactor > 0.5) {
                rehash();
            }
        }

        // Rehash everytime the loadfactor goes beyond 0.5
        void rehash() {
            // std::cout << "Rehashing " << std::endl;
            // save the old hash table
            std::vector<Entry> oldHashTable = hashTable;
            // Resize the hash table
            // and empty everything in it
            size = nextPrime(size*2); 
            hashTable.resize(size);
            loadFactor = 0;
            curSize = 0;
            for (auto& entry: hashTable) {
                entry = Entry();
            }
            // Copy the old hash table to the new one
            for (auto oldEntry: oldHashTable) {
                if (oldEntry.getStatus() == 1) 
                    put(oldEntry.getVal());
            }
        }

        void remove(int val) {
            int index = hashFunc(val);
            int i = index;
            while ((hashTable[i].getStatus() == 1 || hashTable[i].getStatus() == 2) && hashTable[i].getVal() != val) {
                i++;
            }
            // std::cout << i << " " << hashTable[i].getVal() << std::endl;
            if (hashTable[i].getVal() == val)
                hashTable[i].setStatus(2);
        }

        void print() {
            for(auto entry: hashTable) {
                if (entry.getStatus() != 1) {
                    std::cout << " * ";
                } else {
                    std::cout << entry.getVal() << " ";
                }
            }
        }
    private:
        std::vector<Entry> hashTable;
        int size = 17; // Max size that that hash table can carry
        int curSize = 0; // The current number of elements in the hash table
        float loadFactor = 0; // size divided by curSize

        int hashFunc(int val) {
            return val%size;
        }
};