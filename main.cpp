#include <iostream>
#include <vector>
#include "LinearProbing.hpp"

int main() {
    HashTable h = HashTable();
    std::vector<int> v = {35, 154, 120};

    for(int a: v) {
        h.put(a);
    }
    h.print();

    int d = -1;
    int val = -1;
    while (true) {
        std::cout << "\nInsert or remove 0/1: ";
        std::cin >> d;
        std::cout << "Val: ";
        std::cin >> val;
        if (d == 0) {
            h.put(val);
        } else if (d == 1) {
            h.remove(val);
        }
        h.print();
    }
    return 0;
}