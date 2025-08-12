#include <bits/stdc++.h>
using namespace std;

class Person {
 public:
     int age;
     Person(int age){
         this->age = age;
     }

     Person& add(Person &p){
         this->age += p.age;
         return *this;
     }
};

void test01() {
    Person p1(18);
    cout << p1.age;
}

void test02(){
    Person p1(10);
    Person p2(10);
    p2.add(p1).add(p1).add(p1);
    cout << p2.age;
}


int main() {
    test02();
}