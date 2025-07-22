#include<bits/stdc++.h>
using namespace std;    
int main(){
    string s;
    int maxodd = 0, maxeven = 0, minodd = 100, mineven = 0;
    int alpha[26] = {0};
    int ans;
    cin >> s;
    for(char c : s) {
        int ord=(int)('c') - 97;
        alpha[ord]++;
    }
    for(int i = 0; i < 26; i++) {
        if(alpha[i] % 2 == 0) {
            maxeven = max(maxeven, alpha[i]);
            mineven = min(mineven, alpha[i]);
        } else {
            maxodd = max(maxodd, alpha[i]);
            minodd = min(minodd, alpha[i]);
        }
    }
    int maxa = maxeven - minodd;
    int maxb=maxodd - mineven;
    ans=max(maxa, maxb);
    cout<<ans<<endl;
    return 0;
}