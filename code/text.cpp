#include<bits/stdc++.h>
using namespace std;
class Example {
public:
    Example() {

    }
    
    static int A;
    int B;
    
    Example &add(const Example &e) {
        this->B+=e.B;
        return *this;
    }
    ~Example() {

    }
};
int Example::A=100;
int main() {
    Example e1,e2;
    e1.B=10;
    e2.B=10;
    e1.add(e2).add(e2).add(e2);
    cout<<e1.B;
}