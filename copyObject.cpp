#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Employee {
public:
  int *EmployeeId;
  string *Firstname;
  string *Lastname;
  string *Department;
  double *Salary;
  string *Address;

  // Default constructor
  Employee() {}

  // Regular constructor (allocating memory)
  Employee(int id, string fname, string lname, string dept, double salary,
           string addr) {
    EmployeeId = new int(id);
    Firstname = new string(fname);
    Lastname = new string(lname);
    Department = new string(dept);
    Salary = new double(salary);
    Address = new string(addr);
  }

  // Shallow copy constructor
  Employee(const Employee &emp) {
    EmployeeId = emp.EmployeeId;
    Firstname = emp.Firstname;
    Lastname = emp.Lastname;
    Department = emp.Department;
    Salary = emp.Salary;
    Address = emp.Address;
  }

  // Deep copy method
  static Employee DeepCopyEmployee(const Employee &emp) {
    Employee newEmp;
    newEmp.EmployeeId = new int(*emp.EmployeeId);
    newEmp.Firstname = new string(*emp.Firstname);
    newEmp.Lastname = new string(*emp.Lastname);
    newEmp.Department = new string(*emp.Department);
    newEmp.Salary = new double(*emp.Salary);
    newEmp.Address = new string(*emp.Address);
    return newEmp;
  }

  // Destructor
  ~Employee() {
    // Only delete if this object owns the memory
    cout << "Destoring EmployeeId:" << *EmployeeId << endl;
    delete EmployeeId;
    delete Firstname;
    delete Lastname;
    delete Department;
    delete Salary;
    delete Address;
  }

  Employee &operator=(const Employee &emp) {
    if (this != &emp) {
      delete EmployeeId;
      delete Firstname;
      delete Lastname;
      delete Department;
      delete Salary;
      delete Address;
      EmployeeId = new int(*emp.EmployeeId);
      Firstname = new string(*emp.Firstname);
      Lastname = new string(*emp.Lastname);
      Department = new string(*emp.Department);
      Salary = new double(*emp.Salary);
      Address = new string(*emp.Address);
    }

    return *this;
  }
};

int main() {
  Employee emp1{121, "Vishnu", "Nair", "IT", 33333.0, "Powai"};

  // Shallow copy
  Employee emp2 = emp1;

  // Deep copy
  Employee emp3 = Employee::DeepCopyEmployee(emp1);

  cout << "emp1.Firstname points to: " << emp1.Firstname << endl;
  cout << "emp2.Firstname points to: " << emp2.Firstname << endl;
  cout << "emp3.Firstname points to: " << emp3.Firstname << endl;

  cout << "emp3.Firstname: " << *emp3.EmployeeId << endl;

  if (emp1.Firstname == emp2.Firstname)
    cout << "emp1 and emp2 share the same Firstname pointer (Shallow Copy)"
         << endl;
  else
    cout << "emp1 and emp2 do NOT share the same Firstname pointer" << endl;

  if (emp1.Firstname == emp3.Firstname)
    cout << "emp1 and emp3 share the same Firstname pointer" << endl;
  else
    cout << "emp1 and emp3 have different Firstname pointers (Deep Copy)"
         << endl;

  return 0;
}
