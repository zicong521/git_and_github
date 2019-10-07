#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
// p为空 s为空 返回1
//p为空 s不空 返回0
//s为空 p为 x*y* 这样的结构返回1
//s为空 p为其他不为空 返回0

bool isMatch(char *s, char *p);
int main()
{
    char s[] = "aa";
    char p[] = "a*";

    printf("%d", isMatch(s, p));
}
bool isMatch(char *s, char *p)
{
     int len_s = strlen(s);
    int len_p = strlen(p);
    if ( len_p == 0)
    {
        if (len_s== 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool flag = (len_s != 0) && (*s == *p || *p == '.');

    if (len_p >= 2 && *(p+1) == '*')
    { 
        return isMatch(s, p+2) || (flag && isMatch(s+1, p)); //调用次数问题
    }
    else
    {
        if(flag)
        {
            return isMatch(s+1, p+1);
        }
        else
        {
            return false;
        }
    }
}