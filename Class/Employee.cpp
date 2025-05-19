#include "Employee.h"
#include <string>
using namespace std;

Employee::Employee(const int &employeeId, const string &firstName,
                   const string &lastName, const string &department,
                   const float &salary, const char &gender, const string &dob) {
  this->employeeId = employeeId;
  this->firstName = firstName;
  this->lastName = lastName;
  this->department = department;
  this->salary = salary;
  this->gender = gender;
  this->dob = dob;
}

Employee::Employee() {}

// getter

string Employee::getDepartment() const { return department; }
string Employee::getFirstname() const { return firstName; }
string Employee::getLastname() const { return lastName; }
float Employee::getSalary() const { return salary; }
int Employee::getEmployeeId() const { return employeeId; }
char Employee::getGender() const { return gender; }
string Employee::getDob() const { return dob; }

// setter
void Employee::setEmployeeId(int employeeId) { this->employeeId = employeeId; }

void Employee::setFirstName(string firstName) { this->firstName = firstName; }
void Employee::setLastName(string lastName) { this->lastName = lastName; }
void Employee::setDepartment(string department) {
  this->department = department;
}
void Employee::setGender(char gender) { this->gender = gender; }
void Employee::setDob(string dob) { this->dob = dob; }
void Employee::setSalary(float salary) { this->salary = salary; }
