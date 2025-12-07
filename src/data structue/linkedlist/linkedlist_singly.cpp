#include <iostream>
using namespace std;

class LinkedList {
private:
  class Node {
  public:
    int value;
    Node *next;
    Node(int val) {
      value = val;
      next = nullptr;
    }
  };
  Node *head;
  Node *tail;
  int length;

public:
  LinkedList() : head(nullptr), tail(nullptr), length(0) {}

  void insert_at_head(int value) {
    Node *new_val = new Node(value);
    if (head == nullptr) {
      head = new_val;
      tail = new_val;
      length++;
      return;
    }
    new_val->next = head;
    head = new_val;
    length++;
  }

  void insert_at_tail(int value) {
    Node *new_val = new Node(value);
    if (head == nullptr) {
      head = new_val;
      tail = new_val;
      length++;
      return;
    }
    tail->next = new_val;
    tail = new_val;
    length++;
  }

  void insert_at_index(int index, int value) {
    if (index > length || index < 0) {
      cout << "Index out of bound" << endl;
      return;
    }
    Node *new_val = new Node(value);
    Node *cur = head;
    Node *prev = nullptr;
    for (int i = 0; i < index; i++) {
      prev = cur;
      cur = prev->next;
    }
    if (prev == nullptr) {
      insert_at_head(value);
      return;
    }
    prev->next = new_val;
    new_val->next = cur;
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
    length--;
    if (head == nullptr) {
      tail = nullptr;
    }
  }

  void remove_tail() {
    if (head == nullptr) {
      cout << "Linked List already empty";
      return;
    }
    Node *cur = head;
    Node *prev = nullptr;
    for (int i = 0; i < length - 1; i++) {
      prev = cur;
      cur = prev->next;
    }
    if (prev == nullptr) {
      delete head;
      head = nullptr;
      tail = nullptr;
      length--;
      return;
    }
    prev->next = nullptr;
    delete cur;
    tail = prev;
    length--;
  }

  void remove_at_index(int index) {
    if (index >= length || index < 0) {
      cout << "Index out of bound" << endl;
      return;
    }
    if (index == 0) {
      remove_head();
      return;
    }
    Node *cur = head;
    Node *prev = nullptr;
    for (int i = 0; i < index; i++) {
      prev = cur;
      cur = prev->next;
    }
    Node *tmp = cur->next;
    delete cur;
    prev->next = tmp;
    if (tmp == nullptr) {
      tail = prev;
    }
    length--;
  }

  int get(int index) {
    if (index >= length || index < 0) {
      cout << "Index out of bound" << endl;
      return 0;
    }
    Node *cur = head;
    Node *prev = nullptr;
    for (int i = 0; i < index; i++) {
      prev = cur;
      cur = prev->next;
    }
    return cur->value;
  }

  void set(int index, int value) {
    if (index >= length || index < 0) {
      cout << "Index out of bound" << endl;
      return;
    }
    Node *cur = head;
    Node *prev = nullptr;
    for (int i = 0; i < index; i++) {
      prev = cur;
      cur = prev->next;
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
    Node *cur = head;
    for (int i = 0; i < length; i++) {
      cout << cur->value << " -> ";
      cur = cur->next;
    }
    cout << "null" << "\n";
  }
};

int main() {
  LinkedList ll = LinkedList();
  ll.insert_at_head(10);
  ll.insert_at_tail(90);
  ll.print();
  return 0;
}
