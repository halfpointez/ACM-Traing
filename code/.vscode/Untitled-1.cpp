#include<bits/stdc++.h>
using namespace std;
class example{
    public:
     int age;
    example(){
        cout << "wucan"<<endl;
    }
    example(int a){
        cout << "ucan" << endl;
        age = a;

    }
    example(const example &e){
        cout << "copy"<<endl;
    }
    ~example(){
        cout << "xigou";
    }
    int getage(){
        return age;
    }
    private:
       

};
int main(){
    example (p1) (10);
    example p2 = example (p1);

}