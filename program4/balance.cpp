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


PERSON * readData(int n){

//create array
PERSON *P= new PERSON[n];

ifstream inFile;
inFile.open("data.txt");

string fname, lname, fullname;
float num;

for(int i = 0; i < n; i++){
   inFile >> fname >> lname;
   fullname = fname.substr(0,8) + " " + lname.substr(0,9);
   strcpy(P[i].Name, fullname.c_str());
   inFile >> P[i].Balance;
   inFile >> ws;
			     };

inFile.close();

//return pointer
return P;
};


//store into array
void storeArray(PERSON a[], int size){

ifstream inFile;
inFile.open("data.txt");

string fname, lname, fullname;
float num;

for(int i = 0; i < size; i++){
   inFile >> fname >> lname;
   fullname = fname.substr(0,8) + " " + lname.substr(0,9);
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
void Deposit(char *CustName, PERSON a[], int size, float amount){

int place;


for (int i = 0; i < size; i++){
	if (strcmp(CustName, a[i].Name) == 0){
		place = i;
			}	
}


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
N = N-1;

inFile.close();

PERSON * P = readData(N);
storeArray(P, N);
Display(P,N);
FindRichest(P,N);

cout << "Enter your full name to deposit money: ";
cin >> fname >> lname;

fullname = fname+ " " + lname;
strcpy(name, fullname.c_str());

float amt;

cout << fullname << ", how much would you like to deposit? ";
cin >> amt;
cout << endl;

Deposit(name, P, N, amt);
NewCopy("data.txt", P, N);

//inFile.close();
return 0;
};



