#include <iostream>
#include <cstring>

#include "LinkList.h"

using namespace std;

template <class T>
T min(T a, T b, T c) {
    if(a <= b && a <= c) return a;
    else if(b <= a && b <= c) return b;
    else return c;
}

template <>
const char* min<const char*>(const char* a, const char* b, const char* c ) {
    if(strcmp(a, b) > 0 && strcmp(a, c) > 0) return a;
    else if(strcmp(b, a) > 0 && strcmp(b, c) > 0) return b;
    else return c;
}

int main() {
    cout << "Start" << endl;

    cout << "min val:" << min("aaa", "bbb", "c") << endl;

    LinkList<int> linkList;
    linkList.add(1);
    linkList.add(2);
    linkList.add(3);

    linkList.delLast();
    linkList.delLast();

    cout << linkList << endl;

    cout<<"koniec"<<endl;

    return 0;
}