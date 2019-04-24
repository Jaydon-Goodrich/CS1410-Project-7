//This is mine own work. Jaydon Goodrich CS 1410
/* Using inheritence to create 2 child classes off of the parent employee class. The 2 child classs will be for salaried
and houlry employees.*/
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class Employee{
public:
    virtual ~Employee() = default;
    int getEmpNum() const;
    const std::string& getName() const;
    const std::string& getAddress() const;
    const std::string& getPhone() const;
    void setName(const std::string& name);
    void setAddress(const std::string& address);
    void setPhone(const std::string& phone);
    virtual void write(ofstream& fileData) = 0;
    virtual double calcPay() const = 0;
    virtual void printCheck() const = 0;
    
protected:
    Employee() = default;
    virtual void readData(ifstream& fileData);
    Employee(int num, std::string name, std::string address, std::string phone);
    
private:
    int empNum;
    std::string name;
    std::string address;
    std::string phone;
    
};

class HourlyEmployee : public Employee{
public:
    HourlyEmployee(int empNum, std::string name, std::string address, std::string phone, double hourlyWage, double hoursWorked)
    : Employee(empNum, name, address, phone){
        this->hourlyWage = hourlyWage;
        this->hoursWorked = hoursWorked;
    }
    
    double getHourlyWage() const;
    double getHoursWorked() const;
    void setHourlyWage(double wage);
    void setHoursWorked(double hours);
    double calcPay() const override;
    void printCheck() const override;
    static HourlyEmployee* read(ifstream& fileData);
    void write(ofstream& fileData) override;
    
    
protected:
    HourlyEmployee() = default;
    void readData(ifstream& fileData) override;
    
private:
    double hourlyWage;
    double hoursWorked;
};

class SalariedEmployee : public Employee{
public:
    SalariedEmployee(int empNum, string name, string address, string phone, double salary)
    : Employee(empNum, name, address, phone){
         this-> salary = salary;
    }
    double getSalary() const;
    void setSalary(double salary);
    void write(ofstream& fileData) override;
    double calcPay() const override;
    void printCheck() const override;
    static SalariedEmployee* read(ifstream& fileData);
    
protected:
    SalariedEmployee() = default;
    void readData(ifstream& fileData) override;
    
private:
    double salary;
    
};
