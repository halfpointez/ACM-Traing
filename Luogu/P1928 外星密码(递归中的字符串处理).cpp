#include <bits/stdc++.h>
using namespace std;
string cursion() {
  char c;
  string s="";
  int k;
  string sub_str="";
  while (cin >> c) {
    if (c == '[') {
      cin >> k;
      sub_str = cursion();
      while (k--) {
       s+=sub_str;
      }
    } else if (c == ']') {
      return s;
    } else {
      s += c;
    }
    }   
    return s;
}
int main() {
    cout<<cursion();
    return 0;
}