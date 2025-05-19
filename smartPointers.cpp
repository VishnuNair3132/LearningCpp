#include <iostream>
#include <memory>
#include <utility>
using namespace std;
int total;
unique_ptr<int> add(unique_ptr<int> a, shared_ptr<int> b) {

  total = *a + *b;
  return a;
}

int substract(const unique_ptr<int> &a, const shared_ptr<int> &b) {
  return *a - *b;
}

class Person {
public:
  int Id;
  string firstName;
  string lastName;
  string address;

  Person(int Id, string firstName, string lastName, string address) {
    this->Id = Id;
    this->lastName = lastName;
    this->firstName = firstName;
    this->address = address;
  }
  ~Person() { cout << "Destory Person" << endl; }
};

void printPerson(const Person &personPtr) {

  cout << "Person Id is: " << personPtr.Id << endl;
  cout << "Person Name is: " << personPtr.firstName << endl;
  cout << "Person LastName is: " << personPtr.lastName << endl;
  cout << "Person Address is: " << personPtr.address << endl;
}

int main() {
  unique_ptr<int> unique = make_unique<int>(10);
  unique_ptr<int> unique2 = make_unique<int>(34);

  shared_ptr<int> SharedPointer1 = make_shared<int>(300);
  shared_ptr<int> sharedPointer2;

  sharedPointer2 = SharedPointer1;

  cout << *unique << endl;

  cout << *SharedPointer1 << endl;

  cout << *sharedPointer2 << endl;

  unique_ptr<int> result = add(std::move(unique), SharedPointer1);

  cout << total << endl;

  int substractResult = substract(unique2, sharedPointer2);

  cout << *(result) << endl;
  cout << substractResult << endl;

  weak_ptr<int> weak_Ptr = sharedPointer2;

  cout << &weak_Ptr << endl;

  if (auto value = weak_Ptr.lock()) {
    cout << *value << endl;
  }

  unique_ptr<Person> personPtr =
      make_unique<Person>(1, "Vishnu", "Nair", "313/2, Sagar Darshan Society");

  printPerson(*personPtr);

  cout << weak_Ptr.use_count() << endl;
  cout << sharedPointer2.use_count() << endl;
  return 0;
}
