#include "../../../../include/structures/storage/list/List.h"

template<class T>
List<T>::List(): head(nullptr), tail(nullptr) {
}

template<class T>
List<T>::~List() {
    const auto *current = this->head;
    while (current != nullptr) {
        const auto *next = current->getNext();
        delete current;
        current = next;
    }
}

template<class T>
void List<T>::add(T info) {
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
T List<T>::get(int ID) {
    auto current = this->head;
    while (current != nullptr) {
        if (current->getNode()->getId() == ID) {
            return current->getNode();
        }
        current = current->getNext();
    }

    return nullptr;
}

template<class T>
void List<T>::remove(T info) {
    auto current = this->head;
    while (current != nullptr) {
        if (current->getNode() == info) {
            if (current->getPrev() != nullptr) {
                current->getPrev()->setNext(current->getNext());
            } else {
                this->head = current->getNext();
            }

            if (current->getNext() != nullptr) {
                current->getNext()->setPrev(current->getPrev());
            } else {
                this->tail = current->getPrev();
            }

            delete current;
            --this->size;
            return;
        }
        current = current->getNext();
    }
}
