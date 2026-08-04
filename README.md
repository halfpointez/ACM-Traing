# ACM-Halfpoint

个人算法竞赛刷题归档与模板库。

## 目录结构

```
ACM-Halfpoint/
├── CF/                 # Codeforces 训练
│   ├── Round-1850/
│   ├── Round-1873/
│   ├── Round-1915/
│   ├── Round-1926/
│   ├── Round-1950/
│   ├── Round-1971/
│   ├── Round-1985/
│   ├── Round-1999/
│   ├── Round-2009/
│   ├── Round-2044/
│   ├── Round-2065/
│   ├── Round-2094/
│   ├── Round-2148/
│   ├── Round-2167/
│   ├── Round-2185/
│   ├── Round-2218/
│   └── Round-274545/
├── Luogu/              # 洛谷题目
├── LeetCode/           # LeetCode 题目
├── 板子/               # 算法模板 & 知识点整理
├── 笔记/               # 做题笔记 & 学习记录
├── 摸鱼/               # 课外阅读
└── misc/               # 未分类代码
```

## 代码注解规范

每个 `.cpp` 文件头部建议标注元数据，方便 grep 检索：

```cpp
// @tag: dp, knapsack
// @diff: 1600
// @status: AC
// @note: 01背包变种，注意long long溢出
```

### 常见标签

| 标签 | 含义 |
|------|------|
| `dp` | 动态规划 |
| `greedy` | 贪心 |
| `graph` | 图论 |
| `tree` | 树 |
| `dsu` | 并查集 |
| `seg-tree` | 线段树 |
| `bit` | 树状数组 |
| `binary-search` | 二分 |
| `math` | 数学/数论 |
| `string` | 字符串 |
| `constructive` | 构造 |

### 检索示例

```bash
# 搜索所有 DP 题
rg "@tag:.*dp" CF/

# 搜索特定难度的题
rg "@diff: 1600" CF/

# 搜索所有 WA 过的题
rg "@status:.*WA" CF/
```

## 平台

- **Codeforces**: 按比赛轮次（Round）分文件夹
- **洛谷**: 按题号 `Pxxxx` / `Bxxxx` 命名
- **LeetCode**: 题号 + 题目名
