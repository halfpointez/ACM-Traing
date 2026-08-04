/* #include<bits/stdc++.h>
using namespace std;
const int MAX_N=500'005;
void insert_left(vector<int>& nums, vector<int>& prev, vector<int>& next, int x,
                 int y) {
  int ox_next = next[x];
  int ox_prev = prev[x];
  int oy_prev = prev[y];

  // 断开x原有连接
  if (ox_prev != -1) next[ox_prev] = ox_next;
  if (ox_next != -1) prev[ox_next] = ox_prev;

  // 插入x到y左侧
  prev[y] = x;
  next[x] = y;
  prev[x] = oy_prev;
  if (oy_prev != -1) {  // 只有当y不是头节点时，才更新其原前驱的后继
    next[oy_prev] = x;
  }
}
void insert_right(vector<int>& nums, vector<int>& prev, vector<int>& next,
                  int x, int y) {
  int ox_next = next[x];
  int ox_prev = prev[x];
  int oy_next = next[y];
  int oy_prev = prev[y];

  // 断开x原有连接（判断是否越界）
  if (ox_prev != -1)
    next[ox_prev] = ox_next;  // 用ox_prev代替prev[x]，避免重复计算
  if (ox_next != -1) prev[ox_next] = ox_prev;

  // 插入x到y右侧（判断oy_next是否为-1，避免越界）
  next[y] = x;
  prev[x] = y;
  next[x] = oy_next;
  if (oy_next != -1) {  // 只有当y不是尾节点时，才更新其原后继的前驱
    prev[oy_next] = x;
  }
}

void del(vector<int> &nums,vector <int> &prev,vector <int> &next,int x) {
    nums[x]=-1;
    next[prev[x]]=next[x];
    prev[next[x]]=prev[x];
    next[x]=-1;
    prev[x]=-1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> nums(MAX_N,-1);
    vector<int> prev(MAX_N,-1);
    vector<int> next(MAX_N,-1);
    int N,M;
    cin>>N>>M;

    for(int i=1;i<=N;i++){
        nums[i]=i;
        prev[i]=i-1;
        next[i]=i+1;
    }
    next[0]=nums[1];
    next[N] = -1;
    prev[1] = 0;
    while (M--) {
        int a;
        cin>>a;
        if(a==1){
            int x,y;
            cin>>x>>y;
            if(x==y){
                continue;
            }
            else{
              insert_left(nums, prev, next, x, y);
            } 
        }
        else if(a==2){
            int x,y;
            cin>>x>>y;
            if(x==y){
                continue;
            }
            else
            {
              insert_right(nums, prev, next, x, y);
            } 
        }
        else{
            int x;
            cin>>x;
            if(nums[x]==-1){
                continue;
            }
            else{
              del(nums, prev, next, x);
            } 
        }
    }
    vector<int> result;
    int cur = next[0];  
    while (cur != -1) {
      result.push_back(cur);  
      cur = next[cur];        
    }

    if (result.empty()) {
      cout << "Empty!" << endl;
    } else {
      for (int i = 0; i < result.size(); ++i) {
        if (i > 0) cout << " ";  
        cout << result[i];
      }
      cout << endl;
    }
} */

#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 500005;

// 全局数据结构：修改名称以避免与标准库冲突
vector<int> pre(MAX_N, 0);         // pre[x]：x的前驱节点（原prev）
vector<int> nxt(MAX_N, 0);         // nxt[x]：x的后继节点（原next）
vector<bool> exist(MAX_N, false);  // exist[x]：x是否有效
int head = 0;                      // 链表头节点

// 从原位置移除节点x
void remove_node(int x) {
  int p = pre[x];  // 使用修改后的pre
  int n = nxt[x];  // 使用修改后的nxt
  if (p != 0) {
    nxt[p] = n;  // 更新前驱的后继
  } else {
    head = n;  // 更新头节点
  }
  if (n != 0) {
    pre[n] = p;  // 更新后继的前驱
  }
}

// 将x插入到y的左侧
void insert_left(int x, int y) {
  if (x == y || !exist[x] || !exist[y]) return;
  remove_node(x);

  int y_pre = pre[y];  // y的原前驱
  pre[x] = y_pre;
  nxt[x] = y;
  pre[y] = x;
  if (y_pre != 0) {
    nxt[y_pre] = x;
  } else {
    head = x;  // y是头节点时，x成为新头
  }
}

// 将x插入到y的右侧
void insert_right(int x, int y) {
  if (x == y || !exist[x] || !exist[y]) return;
  remove_node(x);

  int y_nxt = nxt[y];  // y的原后继
  nxt[x] = y_nxt;
  pre[x] = y;
  nxt[y] = x;
  if (y_nxt != 0) {
    pre[y_nxt] = x;
  }
}

// 删除节点x
void delete_node(int x) {
  if (!exist[x]) return;
  exist[x] = false;

  int p = pre[x];
  int n = nxt[x];
  if (p != 0) {
    nxt[p] = n;
  } else {
    head = n;
  }
  if (n != 0) {
    pre[n] = p;
  }
}

// 初始化链表（1..N依次排列）
void init_list(int N) {
  for (int i = 1; i <= N; ++i) {
    exist[i] = true;
    pre[i] = i - 1;  // 前驱为i-1
    nxt[i] = i + 1;  // 后继为i+1
  }
  pre[1] = 0;  // 第一个节点无前驱
  nxt[N] = 0;  // 最后一个节点无后继
  head = 1;    // 初始头节点为1
}

// 输出链表
void print_list() {
  if (head == 0) {
    cout << "Empty!\n";
    return;
  }
  int cur = head;
  while (cur != 0) {
    cout << cur << " ";
    cur = nxt[cur];  // 沿后继遍历
  }
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;
  cin >> N >> M;
  init_list(N);

  while (M--) {
    int op, x, y;
    cin >> op;
    if (op == 1) {
      cin >> x >> y;
      insert_left(x, y);
    } else if (op == 2) {
      cin >> x >> y;
      insert_right(x, y);
    } else if (op == 3) {
      cin >> x;
      delete_node(x);
    }
  }

  print_list();
  return 0;
}




#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 500005;

// 插入x到y的左侧
void insert_left(vector<int>& prev, vector<int>& next, int x, int y) {
    // 检查x和y是否有效（未被删除）
    if (x == y || (prev[x] == -1 && next[x] == -1) || (prev[y] == -1 && next[y] == -1)) {
        return;
    }

    // 保存x的原前驱和后继
    int ox_prev = prev[x];
    int ox_next = next[x];

    // 断开x与原位置的连接
    if (ox_prev != -1) {
        next[ox_prev] = ox_next;
    }
    if (ox_next != -1) {
        prev[ox_next] = ox_prev;
    }

    // 保存y的原前驱
    int oy_prev = prev[y];

    // 插入x到y的左侧
    prev[x] = oy_prev;
    next[x] = y;
    prev[y] = x;

    // 连接y的原前驱与x
    if (oy_prev != -1) {
        next[oy_prev] = x;
    }
}

// 插入x到y的右侧
void insert_right(vector<int>& prev, vector<int>& next, int x, int y) {
    // 检查x和y是否有效（未被删除）
    if (x == y || (prev[x] == -1 && next[x] == -1) || (prev[y] == -1 && next[y] == -1)) {
        return;
    }

    // 保存x的原前驱和后继
    int ox_prev = prev[x];
    int ox_next = next[x];

    // 断开x与原位置的连接
    if (ox_prev != -1) {
        next[ox_prev] = ox_next;
    }
    if (ox_next != -1) {
        prev[ox_next] = ox_prev;
    }

    // 保存y的原后继
    int oy_next = next[y];

    // 插入x到y的右侧
    prev[x] = y;
    next[x] = oy_next;
    next[y] = x;

    // 连接x与y的原后继
    if (oy_next != -1) {
        prev[oy_next] = x;
    }
}

// 删除节点x
void del(vector<int>& prev, vector<int>& next, int x) {
    // 检查x是否已被删除
    if (prev[x] == -1 && next[x] == -1) {
        return;
    }

    // 保存x的前驱和后继
    int p = prev[x];
    int n = next[x];

    // 断开x与前后节点的连接
    if (p != -1) {
        next[p] = n;
    }
    if (n != -1) {
        prev[n] = p;
    }

    // 标记x为已删除（前后均置为-1）
    prev[x] = -1;
    next[x] = -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 初始化prev和next数组，-1表示空
    vector<int> prev(MAX_N, -1);
    vector<int> next(MAX_N, -1);

    int N, M;
    cin >> N >> M;

    // 初始化双向链表（1~N依次排列）
    for (int i = 1; i <= N; ++i) {
        prev[i] = i - 1;  // 前驱为i-1（1的前驱是0，作为虚拟头节点）
        next[i] = i + 1;  // 后继为i+1
    }
    next[N] = -1;       // 最后一个节点的后继为空
    next[0] = 1;        // 虚拟头节点0的后继指向第一个节点1

    while (M--) {
        int op, x, y;
        cin >> op;
        if (op == 1) {
            cin >> x >> y;
            insert_left(prev, next, x, y);
        } else if (op == 2) {
            cin >> x >> y;
            insert_right(prev, next, x, y);
        } else if (op == 3) {
            cin >> x;
            del(prev, next, x);
        }
    }

    // 遍历输出结果
    int cur = next[0];  // 从虚拟头节点的后继开始遍历
    if (cur == -1) {
        cout << "Empty!\n";
    } else {
        while (cur != -1) {
            cout << cur << " ";
            cur = next[cur];
        }
        cout << "\n";
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 500005;

// 插入x到y的左侧
void insert_left(vector<int>& prev, vector<int>& next, int x, int y) {
  // 检查x和y是否有效（未被删除）
  if (x == y || (prev[x] == -1 && next[x] == -1) ||
      (prev[y] == -1 && next[y] == -1)) {
    return;
  }

  // 保存x的原前驱和后继
  int ox_prev = prev[x];
  int ox_next = next[x];

  // 断开x与原位置的连接
  if (ox_prev != -1) {
    next[ox_prev] = ox_next;
  }
  if (ox_next != -1) {
    prev[ox_next] = ox_prev;
  }

  // 保存y的原前驱
  int oy_prev = prev[y];

  // 插入x到y的左侧
  prev[x] = oy_prev;
  next[x] = y;
  prev[y] = x;

  // 连接y的原前驱与x
  if (oy_prev != -1) {
    next[oy_prev] = x;
  }
}

// 插入x到y的右侧
void insert_right(vector<int>& prev, vector<int>& next, int x, int y) {
  // 检查x和y是否有效（未被删除）
  if (x == y || (prev[x] == -1 && next[x] == -1) ||
      (prev[y] == -1 && next[y] == -1)) {
    return;
  }

  // 保存x的原前驱和后继
  int ox_prev = prev[x];
  int ox_next = next[x];

  // 断开x与原位置的连接
  if (ox_prev != -1) {
    next[ox_prev] = ox_next;
  }
  if (ox_next != -1) {
    prev[ox_next] = ox_prev;
  }

  // 保存y的原后继
  int oy_next = next[y];

  // 插入x到y的右侧
  prev[x] = y;
  next[x] = oy_next;
  next[y] = x;

  // 连接x与y的原后继
  if (oy_next != -1) {
    prev[oy_next] = x;
  }
}

// 删除节点x
void del(vector<int>& prev, vector<int>& next, int x) {
  // 检查x是否已被删除
  if (prev[x] == -1 && next[x] == -1) {
    return;
  }

  // 保存x的前驱和后继
  int p = prev[x];
  int n = next[x];

  // 断开x与前后节点的连接
  if (p != -1) {
    next[p] = n;
  }
  if (n != -1) {
    prev[n] = p;
  }

  // 标记x为已删除（前后均置为-1）
  prev[x] = -1;
  next[x] = -1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // 初始化prev和next数组，-1表示空
  vector<int> prev(MAX_N, -1);
  vector<int> next(MAX_N, -1);

  int N, M;
  cin >> N >> M;

  // 初始化双向链表（1~N依次排列）
  for (int i = 1; i <= N; ++i) {
    prev[i] = i - 1;  // 前驱为i-1（1的前驱是0，作为虚拟头节点）
    next[i] = i + 1;  // 后继为i+1
  }
  next[N] = -1;  // 最后一个节点的后继为空
  next[0] = 1;   // 虚拟头节点0的后继指向第一个节点1

  while (M--) {
    int op, x, y;
    cin >> op;
    if (op == 1) {
      cin >> x >> y;
      insert_left(prev, next, x, y);
    } else if (op == 2) {
      cin >> x >> y;
      insert_right(prev, next, x, y);
    } else if (op == 3) {
      cin >> x;
      del(prev, next, x);
    }
  }

  // 遍历输出结果
  int cur = next[0];  // 从虚拟头节点的后继开始遍历
  if (cur == -1) {
    cout << "Empty!\n";
  } else {
    while (cur != -1) {
      cout << cur << " ";
      cur = next[cur];
    }
    cout << "\n";
  }

  return 0;
}

修复越界访问
去除冗余的nums数组 
直接遍历输出，避免中间向量
明确虚拟节点0的作用，避免依赖nums[1]
