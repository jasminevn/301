// Assignment 7 solution provided by Chary Vielma
//begin linkedlist.h
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>

using namespace std;

struct node {
    int data = 0;
    node * next = nullptr;
};

class linkedlist {
private:
    node * head;
    int count(node * ptr); // RECURSIVE
    int sum(node * ptr); // RECURSIVE
    void removeFront(node * & ptr);
    // try remove back 
    
public:
    linkedlist();
    ~linkedlist();
    void addToFront(int n);
    void addToBack(int n);
    void addSorted(int n);
    double average(); // uses sum and count functions
    void writeInorder(string & file);
    void writeReversed(string & file);
    void writeReversedHelper(ofstream & fileHandle, node * ptr); // RECURSIVE
    void print();
};
#endif // end linkedlist.h