//begin linkedlist.h
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>

using namespace std;

struct node {
    int data;
    node * next = nullptr;
};

class linkedlist {
private:
    node * head;
    int count(node *ptr); // RECURSIVE
    int sum(node *ptr); // RECURSIVE

public:
    linkedlist();
    ~linkedlist(); // RECURSIVE
    void addToFront(int n);
    double average(); // uses sum and count functions
    void writeInorder(string & file);
    void writeReversed(string & file);
};
#endif // end linkedlist.h