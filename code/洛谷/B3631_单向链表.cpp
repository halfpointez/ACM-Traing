/* #include<bits/stdc++.h>
using namespace std;
struct List
{
    int value;
    int next;
};
List list_arr[1000005];
void insert(int &nums,int x,int y){
    list_arr[nums+1].value=y;
    for(int i=1;i<=nums;i++){
        if(list_arr[i].value==x){
            if(list_arr[i].next==-1){
                list_arr[i].next=nums+1;
                list_arr[nums+1].next=-1;
            }
        else{
            int temp_next=list_arr[i].next;
            list_arr[i].next=nums+1;
            list_arr[nums+1].next=temp_next;
        }
        nums++;
        break;  
        }
    }
}
void print_list(int &nums,int x){
    for(int i=1;i<=nums;i++){
        if(list_arr[i].value==x){
            if(list_arr[i].next==-1){
                cout<<0<<endl;
            }
            else{
                cout<<list_arr[list_arr[i].next].value<<endl;
            }
            
        }
    }
}
void del(int &nums,int x){
    for(int i=1;i<=nums;i++){
        if(list_arr[i].value==x){
            if(list_arr[i].next==-1){
                break;
            }

            list_arr[i].next=list_arr[list_arr[i].next].next;
        }
    }
}
int main(){
    list_arr[1].value=1;
    list_arr[1].next=-1;
    int nums;
    nums=1;
    int q;
    cin>>q;
    while (q--)
    {
        int a;
        cin>>a;
        if(a==1){
            int x,y;
            cin>>x>>y;
            insert(nums,x,y);
        }
        else if(a==2){
            int x;
            cin>>x;
            print_list(nums,x);
        }
        else if(a==3){
            int x;
            cin>>x;
            del(nums,x);
        }
    }
    

} */

#include<bits/stdc++.h>
using namespace std;

struct List {
    int value;
    int next;
};

List list_arr[1000005];
unordered_map<int, int> val_to_idx;  // 记录元素值对应的数组索引

// 插入操作：将y插入到x后面
void insert(int &nums, int x, int y) {
    int x_idx = val_to_idx[x];  // 直接通过哈希表获取x的索引
    int new_idx = nums + 1;
    list_arr[new_idx].value = y;
    // 保存x原来的后继
    int original_next = list_arr[x_idx].next;
    // x的后继改为新节点
    list_arr[x_idx].next = new_idx;
    // 新节点的后继为x原来的后继
    list_arr[new_idx].next = original_next;
    // 记录y的索引
    val_to_idx[y] = new_idx;
    nums++;
}

// 查询操作：输出x后面的元素
void print_list(int x) {
    int x_idx = val_to_idx[x];  // 直接通过哈希表获取x的索引
    int next_idx = list_arr[x_idx].next;
    if (next_idx == -1) {
        cout << 0 << endl;
    } else {
        cout << list_arr[next_idx].value << endl;
    }
}

// 删除操作：删除x后面的元素
void del(int x) {
    int x_idx = val_to_idx[x];  // 直接通过哈希表获取x的索引
    int del_idx = list_arr[x_idx].next;  // 要删除的节点索引
    if (del_idx == -1) return;  // x是最后一个元素，无需删除
    // x的后继改为被删除节点的后继
    list_arr[x_idx].next = list_arr[del_idx].next;
    // 移除被删除节点的索引映射
    val_to_idx.erase(list_arr[del_idx].value);
}

int main() {
    // 初始化：第一个元素为1
    list_arr[1].value = 1;
    list_arr[1].next = -1;
    val_to_idx[1] = 1;  // 记录1的索引
    int nums = 1;
    
    int q;
    cin >> q;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, y;
            cin >> x >> y;
            insert(nums, x, y);
        } else if (op == 2) {
            int x;
            cin >> x;
            print_list(x);
        } else if (op == 3) {
            int x;
            cin >> x;
            del(x);
        }
    }
    return 0;
}