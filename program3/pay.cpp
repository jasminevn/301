#include "person.cpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

void readData(vector <Person>&e){

ifstream inFile;
inFile.open("input.txt");

Person tmp;
string fname, lname, compname;
float hrs, pay;
int ID;


while(!inFile.eof()){

inFile  >> fname >> lname >> ID >> compname >> hrs >> pay >> ws;
tmp.setFirstName(fname);
tmp.setLastName(lname);
tmp.setEmployeeId(ID);
tmp.setCompanyName(compname);
tmp.setHoursWorked(hrs);
tmp.setPayRate(pay);

e.push_back(tmp);
	
};

inFile.close();

for (int i = 0; i < e.size(); i++){
cout << e[i].getFirstName() << " ";
cout << e[i].getCompanyName() << endl;
};
cout << endl;
};


void getCompanies(vector <string> &c, vector <Person>&e){


for (int i = 0; i < e.size(); i++){
	c.push_back(e[i].getCompanyName());
	//cout << c[i] << endl;
	};

cout<< endl;


sort(c.begin(), c.end());
c.erase(unique(c.begin(), c.end()), c.end());

for(int i =0; i < c.size(); i++){
cout << c[i] << endl;
	};
cout << endl;
};


void printHighestPaid(vector <Person>&e){

float max = 0;
int tmp;

for (int i = 0; i < e.size(); i++){
	if(e[i].totalPay() > max)
		{
		max = e[i].totalPay();
		tmp = i;
		 }
			       }	

cout << "Highest Paid: " << e[tmp].fullName()<< endl;
cout << "Employee ID: " << e[tmp].getEmployeeId() << endl;
cout << "Employer: " << e[tmp].getCompanyName() << endl;
cout << "Total Pay: $" << e[tmp].totalPay() << endl;
};




void separateAndSave(vector <string> &c, vector <Person> &e){

string newname;

for (int i = 0; i < c.size(); i++){
	newname = c[i] + ".txt";
	ofstream newfile;
	newfile.open(newname);
	
	string tmpname = c[i];
	float entiretotal = 0;	

	for (int i = 0; i < e.size(); i++){
		if (tmpname.compare(e[i].getCompanyName()) == 0){

			newfile << e[i].fullName() << " " << e[i].getEmployeeId() << " " <<
			e[i].getCompanyName() << " " << e[i].totalPay() << endl;
			
			entiretotal += e[i].totalPay();
			i++;
			}		
	}
	newfile << "Total Pay: " << entiretotal;
	newfile.close();	
}
 
};



int main(){

vector <Person>employees;
vector <string>companyNames;

readData(employees);
getCompanies(companyNames,employees);
printHighestPaid(employees);
separateAndSave(companyNames, employees);

return 0;
};