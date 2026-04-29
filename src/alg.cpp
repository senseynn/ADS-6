// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

struct SYM {
    char ch;
    int prior;
};

template<typename T>
class TPQueue {
 private:
    struct Node {
        T info;
        Node* link;
        explicit Node(const T& value) : info(value), link(nullptr) {}
    };

    Node* first;

 public:
    TPQueue() : first(nullptr) {}
    ~TPQueue() {
        while (first) {
            Node* tmp = first;
            first = first->link;
            delete tmp;
        }
    }

    void push(const T& item) {
        Node* node = new Node(item);
        if (!first || item.prior > first->info.prior) {
            node->link = first;
            first = node;
        } else {
            Node* ptr = first;
            while (ptr->link && ptr->link->info.prior >= item.prior)
                ptr = ptr->link;
            node->link = ptr->link;
            ptr->link = node;
        }
    }

    T pop() {
        Node* tmp = first;
        T res = first->info;
        first = first->link;
        delete tmp;
        return res;
    }
};

#endif  // INCLUDE_TPQUEUE_H_
