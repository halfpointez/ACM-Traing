#include<iostream>
using namespace std;
class Person {
public:
    static int m_a;
    static void func() {
        cout << "static func used" << endl;
    }
};
int Person::m_a;
int main()
{
    Person p;
    p.func();
    Person::func();
}