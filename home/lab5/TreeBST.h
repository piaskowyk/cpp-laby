#ifndef LAB5_TREEBST_H
#define LAB5_TREEBST_H

#include <iostream>
using namespace std;
#include "NodeBST.h"

template <class T>
class TreeBST {

    NodeBST<T>* root;

public:
    TreeBST<T>() : root(NULL) {}
    bool contains(T val) const { return (root != NULL) ? root->contains(val) : false; }
    bool insert(T val);
    void print() const;

private:
    TreeBST<T>(const TreeBST<T>&);
    TreeBST<T>& operator=(const TreeBST<T>&);
};

template <class T>
bool TreeBST<T>::insert(T val) {
    if (root == NULL) {
        root = new NodeBST<T>(val);
        return true;
    }
    else return root->insert(val);
}

template <class T>
void TreeBST<T>::print() const {
    cout << "tree: [";
    if (root == NULL) cout << "empty" << endl;
    else root->print();
    cout << "]" << endl;
}

#endif //LAB5_TREEBST_H
