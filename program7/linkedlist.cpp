#include "linkedlist.h"

linkedlist::linkedlist() {

head = nullptr;

}

linkedlist::~linkedlist() {
    while(head!= nullptr){
		removeFront(head);
}
}

int linkedlist::count() {
 	if(ptr == nullptr){
	return;
}
	return count(ptr->next) + 1;
  // RECURSIVE
}

void linkedlist::addToFront(int n) {
	if(head == nullptr){
	head = new node;
	head ->data = n;
return;
}
	node *tmp = new node;
	tmp->data = n;
	tmp->next = head;
	head = tmp;
}

double linkedlist::average() {
    // uses sum and count functions
	return(sum(head) / double(count(head));
}

int linkedlist::sum() {
    // RECURSIVE
if(ptr == nullptr){
	return 0;
}
	return sum(ptr->next) + ptr->data;
}

void linkedlist::writeInorder(string & file) {
	if(head == nullptr){
	return;
	}
	ofstream data;
	data.open(file, ofstream::app);
	note * tmp = head;
	while(tmp !=nullptr){
	data << tmp ->data << " " ;
	tmp = tmp->next;
}
	data << endl;
	data.close();

}

void linkedlist::writeReversed(string & file) {
    // RECURSIVE
if (head == nullptr){
	return;
}	
	ofstream data;
	data.open(file, ofstream:spp);
	
}