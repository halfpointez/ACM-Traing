#include<bits/stdc++.h>
using namespace std;
using i_64 = long long;
const i_64 MAX_N= 1000000;
i_64 l = 0, r = 0, que[MAX_N]; 

void push(i_64 x) {
    que[r++] = x;
}

void pop() {
    if(r==l) {
      cout << "ERR_CANNOT_POP" << endl;
    }
    else {
        l++;
    }
}

void query() {
    if(r==l) {
      cout << "ERR_CANNOT_QUERY" << endl;
    }
    else {
        cout << que[l] << endl;
    }
}

void size() {
    cout << r-l << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int a;
        cin >> a;
        if( a==1) {
            int x;
            cin>>x;
            push(x);
        }
        else if ( a==2) {
            pop();
        }
        else if ( a==3) {
            query();
        }
        else if ( a==4) {
            size();
        }
    }
    
}