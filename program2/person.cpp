#include "person.h"
#include <iostream>
#include <string>
using namespace std;

Person::Person(){

lastName = " ";
firstName = " ";
payRate = 0;
hoursWorked = 0;

};

void Person::setLastName(string lName){
	lastName = lName;
};

string Person::getLastName(){
	return lastName;
};

void Person::setFirstName(string fName){
	firstName = fName;
};

string Person::getFirstName(){
	return firstName;
}

void Person::setPayRate(float rate){
	payRate = rate;
};

float Person::getPayRate(){
	return payRate;
};
void Person::setHoursWorked(float hours){
	hoursWorked = hours;
};

float Person::getHoursWorked(){
	return hoursWorked;
};

float Person::totalPay(){
	return payRate*hoursWorked;
	
};

string Person::fullName(){
	return firstName + " " + lastName;
	
};