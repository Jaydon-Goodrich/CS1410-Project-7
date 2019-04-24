#include <iostream>
#include "employee.h"
#include <iomanip>
#include <stdexcept>
#include <string>

using namespace std;
double WEEKHOUR = 40;
double FEDTAX = .2;
double STATETAX = .075;
double BENEFITS = .0524;
double HALF = 2;

// Employee parent class func defs
Employee::Employee(int empNum, string name, string address, string phone){
   this->empNum = empNum;
   this->name = name;
   this->address = address;
   this->phone = phone;
}
void Employee::readData(ifstream& fileData){
   string data;
   //int empNum;
   if (getline(fileData, data)){
      empNum = stoi(data);
   }
   else {
      throw std::runtime_error("Error");
   }
   getline(fileData, name);
   getline(fileData, address);
   getline(fileData, phone);
   
}
int Employee::getEmpNum() const{
   return empNum;
}
const std::string& Employee::getName() const{
   return name;
}
const std::string& Employee::getAddress() const{
   return address;
}
const std::string& Employee::getPhone() const{
   return phone;
}
void Employee::setName(const std::string& name){
   this->name = name;
}
void Employee::setAddress(const std::string& address){
   this->address = address;
}
void Employee::setPhone(const std::string& phone){
   this->phone = phone;
}
void Employee::write(ofstream& fileData){
   fileData << empNum << endl;
   fileData << name << endl;
   fileData << address << endl;
   fileData << phone << endl;
}

void Employee::printCheck() const{
   cout << "....................UVU Computer Science" << endl;
   cout << "Dept................................." << endl;
   cout << endl;
   cout << endl;
}
// HourlyEmployee class func def

double HourlyEmployee::getHourlyWage() const{
   return hourlyWage;
}
double HourlyEmployee::getHoursWorked() const{
   return hoursWorked;
}
void HourlyEmployee::setHourlyWage(double wage){
   hourlyWage = wage;
}
void HourlyEmployee::setHoursWorked(double hours){
   hoursWorked = hours;
}
double HourlyEmployee::calcPay() const{
   double grossPay;
   double otwage;
   double netPay;
   double othours;
   grossPay = hoursWorked * hourlyWage;
   if (hoursWorked > WEEKHOUR){
      otwage = hourlyWage + (hourlyWage/HALF);
      othours = hoursWorked - WEEKHOUR;
      grossPay = ((hoursWorked - othours) * hourlyWage) + (othours * otwage);
   }
   netPay = grossPay - ((grossPay * FEDTAX)+(grossPay * STATETAX));
   return netPay;
}
void HourlyEmployee::printCheck() const{
   cout << std::fixed;
   cout << std::setprecision(HALF);
   
   Employee::printCheck();
   
   cout << "Pay to the order of " << this->getName() << "....................................$" << HourlyEmployee::calcPay() << endl;
   cout << endl;
   cout << endl;
   cout << "United Community Credit Union" << endl;
   cout << ".............................................................................." << endl;
   cout << endl;
   cout << endl;
   cout << endl;
   cout << endl;
   cout << endl;
   cout << endl;
   cout << "Hours worked: " << hourlyWage << endl;
   cout << "Hourly wage: " << hoursWorked << endl;
   cout << endl;
   cout << endl;
}
void HourlyEmployee::write(ofstream& fileData){
   Employee::write(fileData);
   fileData << hourlyWage << endl;
   fileData << hoursWorked << endl;
}
HourlyEmployee* HourlyEmployee::read(ifstream& fileData){
   HourlyEmployee* emp = nullptr;
   try{
      emp = new HourlyEmployee();
      emp->readData(fileData);
   }
   catch(runtime_error &error){
      delete emp;
      emp = nullptr;
   }
   
   return emp;
}
void HourlyEmployee::readData(ifstream& fileData){
   string data;
   //double hoursWorked;
   //double hourlyWage;
   Employee::readData(fileData);
   if (getline(fileData, data)){
      hourlyWage = stod(data);
   }
   else {
      throw std::runtime_error("Error");
   }
   if (getline(fileData, data)){
      hoursWorked = stod(data);
   }
   else {
      throw std::runtime_error("Error");
   }
}

   /*string data;
   int empNum;
   double hoursWorked;
   double hourlyWage;
   if (getline(fileData, data)){
      empNum = stoi(data);
   }
   else {
      throw std::runtime_error("Error");
   }
         
   getline(fileData, name);
   getline(fileData, address);
   getline(fileData, phone);
   if (getline(fileData, data)){
      hourlyWage = stod(data);
   }
   else {
      throw std::runtime_error("Error");
   }
   if (getline(fileData, data)){
      hoursWorked = stod(data);
   }
   else {
      throw std::runtime_error("Error");
   }
   Employee person(empNum,name,address,phone,hourlyWage,hoursWorked);
   
   return person;
   */

// SalariedEmployee class func def start

void SalariedEmployee::readData(ifstream& fileData){
   string data;
   //double salary;
   Employee::readData(fileData);
   if (getline(fileData, data)){
      salary = stod(data);
   }
   else {
      throw std::runtime_error("Error");
   }
}

double SalariedEmployee::getSalary() const{
   return salary;
}
void SalariedEmployee::setSalary(double salary){
   this->salary = salary;
}
void SalariedEmployee::write(ofstream& fileData){
   Employee::write(fileData);
   fileData << salary << endl;
}
double SalariedEmployee::calcPay() const{
   double grossSal;
   double TakeOut;
   TakeOut = (salary *FEDTAX) + (salary *STATETAX) + (salary*BENEFITS);
   grossSal = salary - TakeOut;
   return grossSal;
}
void SalariedEmployee::printCheck() const{
   
   Employee::printCheck();
   cout << "Pay to the order of " << this->getName() << "....................................$" << SalariedEmployee::calcPay() << endl;
   cout << endl;
   cout << endl;
   cout << "United Community Credit Union" << endl;
   cout << ".............................................................................." << endl;
   cout << endl;
   cout << endl;
   cout << endl;
   cout << endl;
   cout << endl;
   cout << "Salary: " << salary << endl;
} 
SalariedEmployee* SalariedEmployee::read(ifstream& inFile)
{
   SalariedEmployee* emp = nullptr;
   try{
      emp = new SalariedEmployee();
      emp->readData(inFile);
   }
   catch(runtime_error &error){
      delete emp;
      emp = nullptr;
   }
   
   return emp;
}
