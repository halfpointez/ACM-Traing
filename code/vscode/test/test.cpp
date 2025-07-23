#include<bits/stdc++.h>
using namespace std;
int main(){
    int T; // 总数据次数
    cin>>T;

    while (T--)
    {
        int n;//阶数
        vector<int> f(n);
        for (int i = 0; i < n;i++){
            cin >> f[i];
        }
            int jvzheng[n][n]={0};

            for (int i = 0; i < n;i++){
                vector<int> m;//用于判断每一行所需要的前置值是否满足

                    for (int k = 0; k < f[i];k++){
                        m.push_back(k);
                    }

                for (int j = 0; j < n;j++){
                    if()


                }
            }//对每一行进行检索

            for (int i = 0; i < n;i++){
                for (int j = 0; j < n;j++){

                }
            }//对每一列进行检索
    }
    
    
}