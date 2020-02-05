#include "person.cpp"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void readData(vector <Person> &e){

ifstream inFile;
inFile.open("input.txt");

string fn, ln;
float r, hrs;
int i =0;

while(inFile >> fn >> ln >> r >> hrs >> ws){
	//cout << fn;
	e.emplace_back(fn, ln, r, hrs);	
	//cout << e[i].getFirstName() << endl;
	//i++;
	}
	

inFile.close();
};


void writeData(vector <Person> &e){

ofstream newfile;
newfile.open("output.txt");
int i =0;

for (int i = 0; i < e.size(); i++){
	newfile << e.at(i).fullName() <<" "<< e.at(i).totalPay() << endl;
};

newfile.close();

};


int main(){

//int size = 20;
//Person employees[size];

//create vector
vector <Person>employees;


readData(employees);
writeData(employees);

return 0;
};
