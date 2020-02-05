#include "person.cpp"
#include <iostream>
#include <fstream>
using namespace std;

int readData(Person a[], int n){

ifstream inFile;
inFile.open("input.txt");

string fn, ln;
float r, hrs;
int newcnt = 0;

for(int i = 0; i < n; i++){
	if (inFile >> fn >> ln >> r >> hrs >> ws){
		a[i].setFirstName(fn);
		a[i].setLastName(ln);
		a[i].setPayRate(r);
		a[i].setHoursWorked(hrs);

		newcnt +=1;
	}
	else
		break;
};

return newcnt;
inFile.close();
};


void writeData(Person a[], int n){

ofstream newfile;
newfile.open("output.txt");

for (int i = 0; i < n; i++){
	newfile << a[i].fullName() << " " << a[i].totalPay() << endl;
};

newfile.close();

};


int main(){

int size = 20;
Person employees[size];

int newcnt2 = readData(employees, size);
writeData(employees, newcnt2);

return 0;
};
