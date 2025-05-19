#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

#include "Class/Employee.h"
#include "Class/Student.h"

using namespace std;
class Person {
public:
  int Age;
  string first_name;
  string last_name;
  bool isRegisted = 0;
};

void printf() { cout << "Hellow" << endl; };
int add(int a, int *b, int *c) { return a + (*b) + *c; }

int *substractByPointers(int *a, int *b, int *d) {
  int *c = (int *)malloc(sizeof(int));
  *c = *a - *b - *d;
  return c;
}

void printStatement() { cout << "PSG is going to win tonight" << endl; }

void printProducer(void (*p)()) { p(); }

int multiply(int a, int b) { return a * b; }

int main() {
  int a = 22;

  int *b = &a;

  int c = 54;
  int total = add(a, b, &c);
  cout << "Result of the addition" << total << endl;

  int *result = substractByPointers(&a, b, &c);

  cout << "Result of the substraction" << *result << endl;
  /*
    Person p1;
    cout << "Enter person details\n";
    cout << "enter age:";
    cin >> p1.Age;
    cout << "enter FirstName: ";
    cin >> p1.first_name;
    cout << "enter LastName: ";
    cin >> p1.last_name;
    cout << "Enter If Registered or Not: ";
    cin >> p1.isRegisted;

    cout << "Age: " << p1.Age << endl;
    cout << "FirstName: " << p1.first_name << endl;
    cout << "LastName: " << p1.last_name << endl;
    cout << "isRegisted: " << p1.isRegisted << endl;
  */
  vector<int> nums = {2, 3, 4, 5, 3, 2, 2, 55, 6, 5, 3, 2};

  long arr[4] = {3, 2, 4, 3};

  char characterArr[6] = {'a', 'a', 'b', 'd', 'z', 'r'};

  std::cout << (characterArr) << endl;

  cout << (characterArr + 1) << endl;

  Student student1(1, " Vishnu", "Nair", "CSE", "Mumbai");

  cout << student1.getFirst_name() << endl;
  cout << student1.getLast_name() << endl;
  cout << student1.getAddress() << endl;
  cout << student1.getDepartment() << endl;
  cout << student1.getStudentId() << endl;

  /*int evenCount = 0;
  int oldCount = 0;

  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] % 2 == 0) {
      evenCount++;
    } else {
      oldCount++;
    }
  }

  cout << "Count of Even Number is" << evenCount << endl;
  cout << "Count of Odd Number is " << oldCount << endl;
*/

  int (*p)(int, int) = &multiply;

  int multiplyTotal = p(4, 5);

  cout << "Result Of Multiplication is: " << multiplyTotal << endl;

  printProducer(printStatement);

  Employee *emp = new Employee();
  emp->setFirstName("Vishnu");
  emp->setLastName("Nair");
  emp->setGender('M');
  emp->setDepartment("IT");
  emp->setDob("2003-06-02");
  emp->setSalary(12000.0);
  emp->setEmployeeId(2);

  cout << "EmployeeId: " << emp->getEmployeeId() << endl;
  cout << "Employee Name: " << emp->getFirstname() << endl;
  cout << "Employee LastName: " << (*emp).getLastname() << endl;
  cout << "Employee Department: " << (*emp).getDepartment() << endl;
  cout << "Employee Gender: " << emp->getGender() << endl;
  cout << "Employee Salary: " << emp->getSalary() << endl;
  cout << "Employee Dob: " << emp->getDob() << endl;

  cout << "Size Of Employee is: " << sizeof(*emp) << endl;

  printf();
  delete emp;

  return 0;
}
