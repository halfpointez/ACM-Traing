    #include<bits/stdc++.h>
    using namespace std;
    using i_64 = unsigned long long;
    const i_64 MAX_N = 100'005'0;
    i_64 l=0, r=0, sta[MAX_N];

    void push(i_64 x) {
        sta[r++] = x;
    }

    void pop() {
        if( r-l == 0) {
        cout << "Empty" << endl;
        }
        else{
            r--;
        }
    }

    void query() {
        if( r - l == 0) {
        cout << "Anguei!" << endl;
        }
        else {
            cout << sta[r - 1] << endl;
        }
    }

    void size() {
        cout << r - l << endl;
    }

    int main() {
        ios::sync_with_stdio(0);
        cin.tie(nullptr);
        int T;
        cin >> T;
        while (T--) {
            int t;
            cin>>t;
            l = 0, r = 0;
            while (t--) { 
            string a;
            cin >> a;
            if (a == "push") {
                i_64 b;
                cin >> b;
                push(b);
            } else if (a == "query") {
                query();
            } else if (a == "size") {
                size();
            }
            else if (a=="pop") {
                pop();
            }
            }
        }
        
    
        
    }