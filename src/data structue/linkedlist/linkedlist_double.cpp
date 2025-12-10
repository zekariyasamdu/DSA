#include <iostream>
using namespace std;

class LinkedList {
private:
  class Node {
  public:
    int value;
    Node *next;
    Node *prev;
    Node(int _value) : value(_value), next(nullptr), prev(nullptr) {}
  };
  Node *head;
  Node *tail;
  int length;

public:
  LinkedList() : head(nullptr), tail(nullptr), length(0) {};
  void insert_at_head(int value) {
    Node *newNode = new Node(value);
    if (head == nullptr) {
      head = newNode;
      tail = newNode;
      length++;
      return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    length++;
  }

  void insert_at_tail(int value) {
    if (tail == nullptr) {
      insert_at_head(value);
      return;
    }
    Node *newNode = new Node(value);
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
    length++;
  }

  void insert_at_index(int value, int index) {
    if (index < 0 || index > length) {
      cout << "Index out of bound!" << endl;
      return;
    }
    if (index == 0) {
      insert_at_head(value);
      return;
    }

    Node *newNode = new Node(value);
    Node *cur = head;
    for (int i = 0; i < index; i++) {
      cur = cur->next;
    }
    newNode->prev = cur->prev;
    newNode->next = cur;

    cur->prev->next = newNode;
    cur->prev = newNode;
    length++;
  }

  void remove_head() {
    if (head == nullptr) {
      cout << "Linked List already empty";
      return;
    }
    Node *tmp = head->next;
    delete head;
    head = tmp;
    if (head != nullptr)
      head->prev = nullptr;
    else
      tail = nullptr;
    length--;
  }

  void remove_tail() {
    if (head == nullptr) {
      cout << "Linked List already empty";
      return;
    }
    Node *cur = tail;
    if (cur->prev == nullptr) {
      delete head;
      head = nullptr;
      tail = nullptr;
      length--;
      return;
    }
    tail = cur->prev;
    cur->prev->next = nullptr;
    delete cur;
    length--;
  }

  void remove_at_index(int index) {
    if (index < 0 || index >= length) {
      cout << "Index out of bound!" << endl;
      return;
    }
    if (index == 0) {
      remove_head();
      return;
    }

    if (index == length - 1) {
      remove_tail();
      return;
    }

    Node *cur = head;
    for (int i = 0; i < index; i++) {
      cur = cur->next;
    }
    cur->prev->next = cur->next;
    cur->next->prev = cur->prev;
    delete cur;
    length--;
  }

  int get(int index) {
    if (index >= length || index < 0) {
      cout << "Index out of bound" << endl;
      return 0;
    }
    Node *cur = head;
    for (int i = 0; i < index; i++) {
      cur = cur->next;
    }
    return cur->value;
  }

  void set(int index, int value) {
    if (index >= length || index < 0) {
      cout << "Index out of bound" << endl;
      return;
    }
    Node *cur = head;
    for (int i = 0; i < index; i++) {
      cur = cur->next;
    }
    cur->value = value;
  }

  int size() { return length; }

  bool isEmpty() { return length == 0; }

  void clear() {
    if (length == 0) {
      cout << "is empty!";
      return;
    }
    Node *cur = head;
    Node *prev = nullptr;
    for (int i = 0; i < length; i++) {
      prev = cur;
      cur = prev->next;
      delete prev;
    }
    head = nullptr;
    tail = nullptr;
    length = 0;
  }

  void print() {
    if (!head) {
      cout << "List is empty\n";
      return;
    }
    Node *cur = head;
    cout << "null <- ";
    while (cur) {
      cout << cur->value << " -> ";
      cur = cur->next;
    }
    cout << "null\n";
  }
};

int main() { return 0; }
