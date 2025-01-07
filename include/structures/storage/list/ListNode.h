#ifndef LISTNODE_H
#define LISTNODE_H

template<class T>
class ListNode {
    T info;
    ListNode *next;
    ListNode *prev;

public:
    explicit ListNode(T info) {
        this->info = info;
        this->next = nullptr;
        this->prev = nullptr;
    }

    [[nodiscard]] T getNode() const { return this->info; }
    [[nodiscard]] ListNode *getNext() const { return this->next; }
    [[nodiscard]] ListNode *getPrev() const { return this->prev; }
    void setNext(ListNode *next) { this->next = next; }
    void setPrev(ListNode *prev) { this->prev = prev; }
};


#endif //LISTNODE_H
