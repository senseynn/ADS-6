// Copyright 2022 NNTU-CS
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
        T data;
        Node* next;
        explicit Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;

 public:
    TPQueue() : head(nullptr) {}
    ~TPQueue() {
        while (head != nullptr) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
    }

void push(const T& item) {
        Node* nNode = new Node(item);
if (!head || item.prior > head->data.prior) {
            nNode->next = head;
            head = nNode;
        } else {
            Node* current = head;
            while (current->next && current->next->data.prior >= item.prior) {
                current = current->next;
            }
            nNode->next = current->next;
            current->next = nNode;
        }
    }

T pop() {
      Node* temp = head;
      T result = head->data;
      head = head->next;
      delete temp;
      return result;
    }
};

#endif  // INCLUDE_TPQUEUE_H_
