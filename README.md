# git_and_github
# 正则表达式匹配

## 开发环境 
VScode 
gcc
mingw64
## 程序主要功能
能实现对有* 和 .的正则表达式匹配
## 程序函数接口
```
bool is_match(char *s , char *p );//判断函数

// 四种情况对应的函数
bool is_match_1(char *s,char *p);//判断子函数


void recursion_judge(char *s, char *p ,int *flag);//针对情况三的递归判断函数 
# 对于s = sssff p=s*ssff 会出bug 
void recursion_judge_reverse(char *s, char *p ,int *flag);//倒置递归判断函数
# 对于 s = ssff p=ssff* 会出bug    
#将两个函数输出结合起来 只要有一个输出为1 就判断为true 
#实现了无bug
void reverse(char *s);//字符串翻转函数 配合倒置递归函数使用 
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
输出 1

输入 s=fdsa p=s*f*.*ds*s.
输出 1


```


