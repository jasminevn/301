#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

//struct
struct PERSON{

char Name[20];
float Balance;
};

//store into array
void storeArray(PERSON a[], int size){

ifstream inFile;
inFile.open("data.txt");

string fname, lname, fullname;
float num;

for(int i = 0; i < size; i++){
   inFile >> fname >> lname;
   fullname = fname + " " + lname;
   strcpy(a[i].Name, fullname.c_str());
   inFile >> a[i].Balance;
   inFile >> ws;
			     };

inFile.close();
};


//Display records
void Display(PERSON a[], int size){

string equals;
cout << "Name" << "        " << "Balance" << endl;
equals.assign(25, '-');
cout << equals;
cout << endl;

for (int i = 0; i < size; i++){
   cout << a[i].Name << "   " << a[i].Balance << endl;
 			      };

cout << endl;
};


//display name of customer with max balance
void FindRichest(PERSON a[], int size){

string richest;
float max = 0;
int tmp;

for (int i = 0; i < size; i++){
	if(a[i].Balance > max)
		{
		max = a[i].Balance;
		tmp = i;
		 }
			       }	

cout << "The customer with the maximum balance is " << a[tmp].Name << endl;
};


//deposit money in account
void Deposit(char *CustName, PERSON a[], int size){

float amount=0;
int place;

for (int i = 0; i < size; i++){
	if (strcmp(CustName, a[i].Name) == 0){
		place = i;
			}		

}
cout << CustName << ", how much would you like to deposit? ";
cin >> amount;
cout << endl;

a[place].Balance += amount;
cout << "Now your new balance is " << a[place].Balance;

};

//copy array in same file
void NewCopy(string filename, PERSON a[], int size){

ofstream newfile;
newfile.open(filename);

for (int i = 0; i < size; i ++){
newfile << a[i].Name << "   " << a[i].Balance << endl;
};

newfile.close();

};



//main
int main(){

ifstream inFile;
inFile.open("data.txt");

int N = 0;
string s;
string fname, lname, fullname;
char name[20];

//count the number of records
while(!inFile.eof()){
	getline(inFile, s);
	N+=1;
		  };

inFile.close();

//create array
PERSON P[N];

storeArray(P, N);
Display(P,N);
FindRichest(P,N);

cout << "Enter your full name to deposit money: ";
cin >> fname >> lname;

fullname = fname+ " " + lname;
strcpy(name, fullname.c_str());

Deposit(name, P, N);
NewCopy("data.txt", P, N);

//inFile.close();
return 0;
};



