/* 表达式求值
*  表达式由项或 + - 组成
*   项由因子或 * / 组成
*   因子由 （表达式） 或者是 整数
*
*/
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int factor_value();
int term_value();
int expression_value();


int main()
{
    cout << expression_value() << endl;
    return 0;
}

int expression_value()//求一个表达式的值
{
    int result = term_value();
    while(true)
    {
        char op = cin.peek();
        if(op == '+' || op == '-')
        {
            cin.get();
            int value = term_value();
            if(op == '+')
            {
                result += value;
            }
            else
            {
                result -= value;
            }
            
        }
        else
        {
            break;
        }
        
    }
    return result;
}
int term_value()
{
    int result = factor_value();
    while(true)
    {
        char op = cin.peek();
        if(op == '*' || op == '/')
        {
            cin.get();
            int value = factor_value();
            if(op == '*')
            {
                result *= value;
            }
            else
            {
                result /= value;
            }
            
        }
        else
        {
            break;
        }
        
    }
    return result;
}
int factor_value()
{
    int result = 0;
    char op = cin.peek();
    if (op == '(')
    {
        cin.get();
        result = expression_value();
        cin.get();
    }
    else // 处理一个字符数字
    {
        while(isdigit(op))
        {
            cin.get();// 这里cin.get 和 cin.peek的顺序很关键 
            result = 10*result + op - '0';
            op = cin.peek();
        }
    }
    return result;
}