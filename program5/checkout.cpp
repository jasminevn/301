//Jasmine Nguyen

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "person.cpp"
#include "book.cpp"

using namespace std;

void printMenu() {
	cout << "---------Library Book Rental System---------" << endl;
	cout << "1. Book checkout" << endl;
	cout << "3.View all available books" << endl;
	cout << "4. View all outstanding rentals" << endl;
	cout << "5. View outstanding rentals for a cardholder" << endl;
	cout << "7. Close library card" << endl;
	cout << "8. Exit system" << endl;
	cout << "Please enter a choice: " ;
}

//store persons.txt in cardholder vector
void readPerson(vector<Person *> & c){

Person *ptr;
int cID;
string fn, ln;
bool a;
int cardno;

ifstream inFile;
inFile.open("persons.txt");

while(inFile >> cID >> a >> fn >> ln >> ws){
	ptr = new Person(cID, a, fn, ln);
	}
c.push_back(ptr);

inFile.close();

};

//stores books.txt to book vector
void readBooks(vector<Book *> &b){
Book *ptr;
int bID;
string t, auth, cat;
int bookid;

ifstream inFile;
inFile.open("books.txt");

while(inFile >> bID >> t >> auth >> cat >> ws){
	ptr = new Book(bID, t, auth, cat);
}
b.push_back(ptr);

inFile.close();

};

//store ptr to book ptr
void readRentals(vector<Book *> &b, vector<Person *> & c){

Person *ptr;
Book *bookptr;
int bookid, cardid;

ifstream inFile;
inFile.open("rentals.txt");

for(int i = 0; i < c.size(); i++){	
	ptr = c.at(i);
}

for(int i = 0; i < b.size(); i++){
	bookptr = b.at(i);
}

while(inFile >> bookid >> cardid >> ws){
bookptr->setPersonPtr(ptr);
bookptr->getAuthor();
bookptr->getId();
bookptr->getCategory();
bookptr->getTitle();
}

inFile.close();

};

//option 1
void bookCheckout(vector<Book *> & b, vector<Person *> & c){

Person *ptr;
int cID, bID;
string fn, ln, t, auth, cat;
bool a;
int cardno, bookid;


cout << "Please enter the card ID: ";
cin >> cardno;
for(int i = 0; i < c.size(); i++){
	if(cardno == c.at(i)->getId()){
	cout << "Cardholder: " << c.at(i)->fullName() << endl;
		}
	else
	cout << "Card ID not found" << endl;	
	};


cout << "Pleaser enter the book ID: " ;
cin >> bookid;
	
for(int i = 0; i < b.size(); i++){
	if(bookid == b.at(i)->getId()){
	cout << "Title: " << b.at(i)->getTitle() << endl;
	}
	else	
	cout << "Book ID not found" << endl;
}

};


void bookReturns(vector<Book *> & b){
int bID;

cout << " Please enter the bookID to return: ";	
cin >> bID;

for(int i = 0; i < b.size(); i++){
	if(bID == b.getTitle()){
	cout << "Title: " << b.at(i)->getTitle() << endl;
	cout << "Return Completed" << endl;
	}
	else
	cout << "Book ID not found" << endl;
}

};
	
/*
void readRentals(vector<Book *> & myBooks, vector<Person *> myCardholders){
	return;
}

void openCard(vector<Person *> & myCardholders, int nextID){
	return;
}

Book * searchBook(vector<Book *> myBooks, int id){
	return nullptr;
}
*/

int main()
{
	vector<Book *> books;
	vector<Person *> cardholders;
	readPerson(cardholders);
	readBooks(books);
	readRentals(books,cardholders);
	int choice;
	do
	{
		printMenu();
		cin >> choice;
		switch(choice)
		{	
			case 1:
				bookCheckout(books, cardholders);
				break;
			
			case 2:
				bookReturns(books);
				break;
/*
			case 3:
				break;

			case 4:
				break;
	
			case 5:
				break;

			case 6:
				break;

			case 7:
				break;

			case 8:
				break;
*/
			default:
				cout << "Invalid entry" << endl;
				break;
		}
		cout << endl;
	} while(choice != 8);
		return 0;
}


