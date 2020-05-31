#include <iostream>
#include <string.h>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void FullPermute(char s[],int k, int m)// k代表第几层 m代表从0开始的数组长度
{
    if(k == m)
    {
        for(int i = 0; i <= m; i++)
        {
            cout << s[i] ;
        }
        cout << endl;
    }
    else
    {
        for(int i = k; i <= m; i++)
        {
            swap(s[i], s[k]); // 第i个和这层的第一个交换
            FullPermute(s, k+1, m);
            swap(s[i], s[k]); // 再交换回来 恢复为初始数组
        }
    }
    
}
int main()// 全排列 递归
{
    char s[10];
    cin >> s;
    int m = strlen(s) -1;
    FullPermute(s, 0, m);
    return 0;
}