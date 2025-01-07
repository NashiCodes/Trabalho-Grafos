#include "ListStorage.h"

template<class T>
ListStorage<T>::ListStorage(): head(nullptr), tail(nullptr), size(0) {
}

template<class T>
ListStorage<T>::~ListStorage() {
    const auto *current = this->head;
    while (current != nullptr) {
        const auto *next = current->getNext();
        delete current;
        current = next;
    }

    delete this;
}

template<class T>
void ListStorage<T>::add(T *info) {
    auto *node = new ListNode<T>(info);
    node->setNext(nullptr);
    node->setPrev(nullptr);


    if (this->size == 0) {
        this->head = node;
    } else {
        this->tail->setNext(node);
        node->setPrev(this->tail);
    }

    this->tail = node;
    ++this->size;
}

template<class T>
T* ListStorage<T>::get(int ID) {
    auto current = this->head;
    while (current != nullptr) {
        if (current->getNode()->getId() == ID) {
            return current->getNode();
        }
        current = current->getNext();
    }

    return nullptr;
}
