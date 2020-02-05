#include <iostream>
#include <string>
#include "linkedlist.cpp"
#include <fstream>
s
using namespace std;

void readFile(linkedlist & list, string & file) {
	int n;
	ifstream inFile;
	inFile.open(list);
	while(inFile >> n){
		list.addSorted();
		cout << "Inserted" << n << endl;
	cout << " New List" ;
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
	mylist.print()
	mylist.writeInorder(output)
	mylist.writeReversed(output)
	mylist.addToFront(0);
	mylist.addToBack(100);
	mylist.print();
	mylist.~linkedlist();
	mylist.print();

    return 0;
}