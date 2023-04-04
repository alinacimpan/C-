#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <vector>
using namespace std;

template<class T>
class List {
private:
    struct Node {
        T value;
        Node* next;
    };

    Node* head;
    int count;

public:
    List();
    ~List();

    vector<T*> getAll();
    void add(T value);
    void remove(T value);
    bool contains(T value);
    int size();

    void print();


};

template<class T>
inline List<T>::List()
    : head(nullptr),
    count(0)
{}

template<class T>
inline List<T>::~List() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

template<class T>
inline vector<T*> List<T>::getAll() {
    vector<T*> result;
    Node* current = head;
    while (current != nullptr) {
        result.push_back(&current->value);
        current = current->next;
    }
    return result;
}

template<class T>
inline void List<T>::add(T value) {
    if (contains(value)) {
        return;
    }

    Node* n = new Node{ value, head };
    head = n;

    count++;
}

template<class T>
inline void List<T>::remove(T value) {
    Node* current = head;
    Node* prev = nullptr;
    while (current != nullptr) {
        if (current->value == value) {
            if (prev == nullptr) {
                head = current->next;
            }
            else {
                prev->next = current->next;
            }
            delete current;
            count--;
            return;
        }
        prev = current;
        current = current->next;
    }
}

template<class T>
inline bool List<T>::contains(T value) {
    Node* current = head;
    while (current != nullptr) {
        if (current->value == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

template<class T>
inline int List<T>::size() {
    return count;
}

template<class T>
inline void List<T>::print() {
    Node* current = head;
    while (current != nullptr) {
        cout << current->value << " ";
        current = current->next;
    }
}

#endif // LIST_H

