// Linked List Node
#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <iostream>
using namespace std;
template <typename T>
class Node{
public:
    T data;
    Node *link;
    Node(T element){
        data = element;
        link = 0; }
};


template <typename T>
class LinkedList
{
protected:
    Node<T> *first;
    int current_size;
public:
    LinkedList(){
        first = 0;
        current_size = 0; };
    int GetSize() { return current_size; };
    void Insert(T element); 
    virtual bool Delete(T &element); 
    void Print();	
};

template <typename T>
void LinkedList<T>::Insert(T element){ 
    Node<T> *newnode = new Node<T>(element);
    newnode->link = first;
    first = newnode;
    current_size++;
}

template <typename T>
bool LinkedList<T>::Delete(T &element){
    
    if(first == 0) return false;
    Node<T> *current = first, *previous = 0;
    while(1){    
        if(current->link == 0)    
        {
            if(previous) previous->link = current->link;
            else first = first->link;
            break;
        }
        previous = current;
        current = current->link;
    }
    element = current->data;
    delete current;
    current_size--;
    return true;
}

template <typename T>
void LinkedList<T>::Print() {
    Node<T> *current = first;
    if(!current_size)
        return;
    for(int i = 1; i <= current_size; i++) {
        cout << '[' << i << '|' << current->data << ']';
        if(i != current_size)
            cout << "->";
        current = current->link;
    }
    cout << "\n";
}

#endif 
