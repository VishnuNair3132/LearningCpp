#include "Student.h"
#include <string>
using namespace std;

Student::Student(int studentId, const string &first_name,
                 const string &last_name, const string &Department,
                 const string &Address) {
  this->studentId = studentId;
  this->first_name = first_name;
  this->last_name = last_name;
  this->Department = Department;
  this->address = Address;
}

// getters

int Student::getStudentId() const { return studentId; }

string Student::getFirst_name() const { return first_name; };

string Student::getLast_name() const { return last_name; };

string Student::getDepartment() const { return Department; };

string Student::getAddress() const { return address; };

// setter
void Student::setStudentId(int id) { this->studentId = id; }

void Student::setFirst_name(const string &first_name) {
  this->first_name = first_name;
}

void Student::setLast_name(const string &last_name) {
  this->last_name = last_name;
}

void Student::setDepartment(const string &Department) {
  this->Department = Department;
}

void Student::setAddress(const string &Address) { this->address = Address; }
