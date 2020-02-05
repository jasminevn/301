// Assignment 7 solution provided by Chary Vielma
#include "linkedlist.h"

linkedlist::linkedlist() {
    head = nullptr;
}

linkedlist::~linkedlist() {
    while(head != nullptr) {
        removeFront(head);
    }
}

void linkedlist::removeFront(node * & ptr) { 
// pass ptr by reference because we are changing what it points to permanently
    if(ptr == nullptr) {
        return;
    }
    node * temp = ptr;
    ptr = temp->next;
    delete temp;
}

int linkedlist::count(node * ptr) {
    if(ptr == nullptr) {
        return 0;
    }
    return count(ptr->next) + 1;
}

void linkedlist::addToFront(int n) {
    if(head == nullptr) {
        head = new node;
        head->data = n;
        return;
    }
    node * temp = new node;
    temp->data = n;
    temp->next = head;
    head = temp;
}

void linkedlist::addToBack(int n) {
    if(head == nullptr) {
        addToFront(n);
        return;
    }
    
    node * temp = head; // must make copy of head or else I will permanently 
                                     //change what head points to by accident when I try to advance the pointer
    while(temp->next != nullptr) {
        temp = temp->next;
    }
    
    node * toInsert = new node;
    toInsert->data = n;
    temp->next = toInsert;
}

void linkedlist::addSorted(int n) {
    if(head == nullptr || head->data >= n) {
        addToFront(n);
        return;
    }
    
    node * current = head;
    while(current->next != nullptr && current->next->data < n) {
        current = current->next;
    }
    
    node * temp = new node;
    temp->data = n;
    temp->next = current->next;
    current->next = temp;
}

double linkedlist::average() {
    return (sum(head) / double(count(head)));
}

int linkedlist::sum(node * ptr) {
    if(ptr == nullptr) {
        return 0;
    }
    return sum(ptr->next) + ptr->data;
}

void linkedlist::writeInorder(string & file) {
    if (head == nullptr) {
        return;
    }
    ofstream data;
    data.open(file, ofstream::app);
    node * temp = head;    
    while(temp != nullptr) {
        data << temp->data << " ";
        temp = temp->next;
    }
    data << '\n';
    data.close();
}

void linkedlist::writeReversed(string & file) {
    if (head == nullptr) {
        return;
    }
    ofstream data;
    data.open(file, ofstream::app); // app used to make sure I don't overwrite file contents
    writeReversedHelper(data, head);
    data << '\n';
    data.close();
}

void linkedlist::writeReversedHelper(ofstream & fileHandle, node * ptr) {
    if(ptr != nullptr) {
        writeReversedHelper(fileHandle, ptr->next);
        fileHandle << ptr->data << " ";        
    }
}

void linkedlist::print() {
    node * temp = head;
    if(head == nullptr) {
        cout << "List empty!";
    }
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << '\n';
}