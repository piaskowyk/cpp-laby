#ifndef LAB5_NODEBST_H
#define LAB5_NODEBST_H

#include <iostream>
using namespace std;

struct NodeExistException : public std::exception
{
    const char * what () const throw ()
    {
        return "This node already exist in tree";
    }
};

template <class T>
class NodeBST {

    T data;
    NodeBST* left;
    NodeBST* right;

public:
    NodeBST(T _data) : data(_data), left(NULL), right(NULL) {}
    bool contains(T val) const;
    bool insert(T val);
    void print() const;

};

template <class T>
bool NodeBST<T>::contains(T val) const {
    if (val == data) return true;
    NodeBST<T>* next = (val < data) ? left : right;
    return (next != nullptr) ? next->contains(val) : false;
}

template <class T>
bool NodeBST<T>::insert(T val) {
    if (val == data) throw NodeExistException();//return false;
    NodeBST<T>* & next = (val < data) ? left : right;
    if (next == NULL) {
        next = new NodeBST<T>(val);
        return true;
    }
    else return next->insert(val);
}

template <class T>
void NodeBST<T>::print() const {
    if (left != NULL) left->print();
    cout << data << " ";
    if (right != NULL) right->print();
}


#endif //LAB5_NODEBST_H
