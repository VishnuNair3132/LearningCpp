#pragma once

#include <string>
using namespace std;
class Employee {

private:
  int employeeId;
  string firstName;
  string lastName;
  string department;
  float salary;
  char gender;
  string dob;

public:
  Employee(const int &employeeId, const string &firstName,
           const string &lastName, const string &department,
           const float &salary, const char &gender, const string &dob);

  Employee();

  int getEmployeeId() const;
  string getFirstname() const;
  string getLastname() const;
  string getDepartment() const;
  float getSalary() const;
  char getGender() const;
  string getDob() const;

  // setters
  void setEmployeeId(const int Id);
  void setFirstName(const string firstName);
  void setLastName(const string lastName);
  void setDepartment(const string department);
  void setSalary(const float salary);
  void setGender(const char gender);
  void setDob(const string Dob);
};
