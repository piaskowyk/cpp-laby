#include <iostream>
#include <stdio.h>
#include <string.h>

#include "NodeBST.h"
#include "TreeBST.h"

using namespace std;

template <class T>
bool rowne(T a, T b, T c) {
    return (a == b) && (b == c);
}

template <>
bool rowne<const char*>(const char* a, const char* b, const char* c ) {
    return strcmp(a, b) && strcmp(b, c);
}

int main() {
    cout << "Start" << endl;

    TreeBST<int> treeBstInt;
    treeBstInt.insert(2);
    treeBstInt.insert(1);
    treeBstInt.insert(3);
    if(treeBstInt.contains(2)) {
        cout << "Zawiera" << endl;
    }
    treeBstInt.insert(3);

    return 0;
}