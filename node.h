#ifndef NODE_H
#define NODE_H
#pragma once
template <typename T>
class List;

template <class T>
class Node {
private:
    T info;
    Node<T>* next;
public:
    Node(T info, Node<T>* next) : info(info), next(next){}
    Node(T info) : info(info){ next= nullptr;}
    friend class List<T>;
};

#endif //NODE_H
