//
// Created by mleko on 5/21/19.
//

#ifndef LAB5_LINKLIST_H
#define LAB5_LINKLIST_H

#include <iostream>

using namespace std;

struct EmptyListException : public std::exception
{
    const char * what () const throw ()
    {
        return "List is empty";
    }
};

template <class T>
struct Node {
    Node<T>* next;
    T val;
};

template <class T>
class LinkList {
    Node<T>* start;
public:
    LinkList<T>() : start(nullptr) {}
    ~LinkList();
    void add(T item);
    bool delLast();
    template <class U>
    friend std::ostream& operator<<( std::ostream&out, const LinkList<U>&list );

private:
    LinkList<T>(const LinkList<T>&);
    LinkList<T>& operator=(const LinkList<T>&);
};

template<class T>
LinkList<T>::~LinkList() {
    while (delLast()){}
}

template<class T>
void LinkList<T>::add(T item) {
    if(start == nullptr) {
        start = new Node<T>{nullptr, item};
        return;
    }

    Node<T>* prev = start;
    Node<T>* ptr = start->next;
    while (ptr != nullptr) {
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = new Node<T>{nullptr, item};
}

template<class T>
bool LinkList<T>::delLast() {
    if(start == nullptr) {
        throw EmptyListException();
    }

    Node<T>* prev = start;
    Node<T>* ptr = start->next;

    while (ptr != nullptr) {
        prev = ptr;
        ptr = ptr->next;
    }
    cout << prev->val << endl;
    free(prev->next);
    prev->next = nullptr;
    return true;
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const LinkList<T> &list) {
    if(list.start == nullptr){
        return out;
    }
    Node<T>* ptr = list.start;
    while (ptr != nullptr){
        out << ptr->val << "->";
        ptr = ptr->next;
    }
    return out;
}

#endif //LAB5_LINKLIST_H
