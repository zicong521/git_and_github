#include <iostream>
#include <string.h>
using namespace std;

void swap1(char s[], int k ,int i)
{
    int temp = s[i];
    for(int j = i; j > k; j--)
    {
        s[j] = s[j-1];
    }
    s[k] = temp;
}
void swap2(char s[], int k ,int i)
{
    int temp = s[k];
    for (int j=k; j < i ; j++)
    {
        s[j] = s[j+1];
    }
    s[i] = temp;
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
            swap1(s, k, i); // 第i个放到这一行的最前面
            FullPermute(s, k+1, m);
            swap2(s, k, i); // 再交换回来 恢复为初始数组
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