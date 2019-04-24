#include <iostream>
#include "employee.h"
#include <fstream>
#include <stdexcept>
#include <vector>
using namespace std;

int main(){
   
   int userIn = 0;
   string fileName;   
   cout << "This program has two options:" << endl;
   cout << "1 - Create a data file, or" << endl;
   cout << "2 - Read data from a file and print paychecks." << endl;
   cout << "Please enter (1) to create a file or (2) to print checks:";
   cin >> userIn;
   cout << endl;
   cout << endl;
   
   
   if(userIn == 1){
      
      cout << "Please enter a file name: " << endl;
      cin >> fileName;
      cout << endl;
      
      ofstream empFile;
      empFile.open(fileName);
      
      HourlyEmployee potter(1, "H. Potter", "Privet Drive", "201-9090", 40.00, 12.00);
      SalariedEmployee dumbledore(2, "A. Dumbledore", "Hogwarts", "803-1230", 1200.00);
      HourlyEmployee weasley(3, "R. Weasley", "The Burrow", "892-2000", 40.00, 10.00);
      SalariedEmployee hagrid(4, "R. Hagrid", "Hogwarts", "910-8765", 1000);
      
      potter.write(empFile);
      dumbledore.write(empFile);
      weasley.write(empFile);
      hagrid.write(empFile);
      
      empFile.close();
      
      cout << "Data file created ... you can now run option 2." << endl;
      cout << endl;
      cout << endl;
   }
   else if (userIn == 2){
      cout << "Please enter a file name:" << endl;
      cin >> fileName;
      ifstream myFile;
      myFile.open(fileName);
      if (myFile.fail()){
         cout << "Couldn't open file for input";
         exit(-1);
      }
      
      
      //while (!myFile.eof()){
         //myFile >> fileName;
      if (myFile.good()){
         try {
            vector<Employee*> emps;
            ifstream fileData(fileName);
            emps.push_back(HourlyEmployee::read(fileData));
            emps.push_back(SalariedEmployee::read(fileData));
            emps.push_back(HourlyEmployee::read(fileData));
            emps.push_back(SalariedEmployee::read(fileData));
            for (Employee*e:emps){
               if(e!=nullptr){
                  e->printCheck();
               }
            } 
            /*HourlyEmployee newPotter = HourlyEmployee::read(myFile);
            SalariedEmployee newDumbledore = SalariedEmployee::read(myFile);
            HourlyEmployee newWeasley = HourlyEmployee::read(myFile);
            SalariedEmployee newHagrid = SalariedEmployee::read(myFile);
            
            newPotter.printCheck();
            newDumbledore.printCheck();
            newWeasley.printCheck();
            newHagrid.printCheck(); */
            }
            catch (const runtime_error& error)
            {
            //cout << error.what();
            exit(-1);
            }
         }
         
      else if (myFile.bad()){
         cout << "Couldn't open file for input1" << endl;
         exit(-1);
      }
   //}
   }
   
}
