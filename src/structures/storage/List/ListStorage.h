#ifndef LISTSTORAGE_H
#define LISTSTORAGE_H

#include <iostream>

#include "ListNode.h"
#include "../Storage.h"

using namespace std;

template<class T>
class ListStorage final : public Storage<T> {
public:
    ListStorage(ListNode<T> *head, ListNode<T> *tail, int size);

    ~ListStorage() override;

    void add(T info) override;
    T get(int ID) override;

private:
    ListNode<T> *head;
    ListNode<T> *tail;
    int size;
};


#endif //LISTSTORAGE_H
