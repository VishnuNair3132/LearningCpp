#pragma once
#include <string>
using namespace std;
class Student {
public:
  // Constructor
  Student(const int studentId, const string &first_name,
          const string &last_name, const string &Department,
          const string &address);

  // Getters (const-correct)
  int getStudentId() const;
  string getFirst_name() const;
  string getLast_name() const;
  string getDepartment() const;
  string getAddress() const;

  // Setters
  void setStudentId(int id);
  void setFirst_name(const string &name);
  void setLast_name(const string &name);
  void setDepartment(const string &dept);
  void setAddress(const string &addr);

private:
  // Member variables (private for encapsulation)
  int studentId;
  string first_name;
  string last_name;
  string Department;
  string address;
};
