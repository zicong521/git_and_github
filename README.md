# git_and_github
# 正则表达式匹配

## 程序主要功能
能实现对有* 和 .的正则表达式匹配
## 程序函数接口
```
bool is_match(char *s , char *p );//判断函数

// 四种情况对应的函数
bool is_match_1(char *s,char *p);//两种符号都不存在

bool is_match_2(char *s,char *p);//只有 '.' 

bool is_match_3(char *s,char *p);// 只有'*' 

void recursion_judge(char *s, char *p ,int *flag);//针对情况三的递归判断函数

bool is_match_4(char *s,char *p);//两种符号都存在
```
## 测试
```
输入 s=aa p=a
输出 0

输入 s=aa p=a*
输出 1

输入 s=abbb p=.*
输出 1

输入 s=aab p=c*a*b
输出 1

输入 s = mississippi p = mis*is*p*.
输出 0

输入 s=sddd p=s*sddd
输出 0 //bug
```


