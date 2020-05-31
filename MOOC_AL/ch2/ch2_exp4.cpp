#include <iostream>

#include <stdlib.h>
using namespace std;
double exp()// 代表对一个逆波兰表达式做处理
{
    char s[10];
    cin >> s;// 流里面的内容都是用空格隔开的 
    switch (s[0])
    {
    case '+':
        return exp() + exp();
        break;
    case '-':
        return exp() - exp();
        break;
    case '*':
        return exp() * exp();
        break;
    case '/':
        return exp() / exp();
        break;
    default:
        return atof(s);
        break;
    }

}
int main()
{
    cout<<exp()<<endl;
    return 0;
}