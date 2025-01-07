#ifndef LISTSTORAGE_H
#define LISTSTORAGE_H

#include <iostream>

#include "ListNode.h"

using namespace std;

template<class T>
class List final {
public:
    List();
    ~List();
    void add(T info);
    T get(int ID);

    int getSize() const { return this->size; }

private:
    int size = 0;
    ListNode<T> *head;
    ListNode<T> *tail;
};


#endif //LISTSTORAGE_H
