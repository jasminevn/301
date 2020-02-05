// Assignment 7 solution provided by Chary Vielma
#include <fstream>
#include <iostream>
#include <string>
#include "linkedlist.cpp"

using namespace std;

void readFile(linkedlist & list, string & file) {
    int n;
    ifstream data;
    data.open(file);
    while(data >> n) {
        list.addSorted(n);
        cout << "Inserted " << n << endl;
        cout << "New list: ";
        list.print();
        cout << '\n';
    }
}

int main() {
    string filename = "input.txt";
    string output = "output.txt";
    linkedlist mylist;
    readFile(mylist, filename);
    cout << "Average: " << mylist.average() << endl;
    mylist.print();
    mylist.writeInorder(output);
    mylist.writeReversed(output);
    mylist.addToFront(0);
    mylist.addToBack(100);
    mylist.print();
    mylist.~linkedlist();
    mylist.print();
    return 0;
}
