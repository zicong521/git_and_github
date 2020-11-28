// 判断合法的C整型常量
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"
bool pre_process(char * str);
bool ten_judge(char const * str);
bool eight_judge(char const *str);
bool sixteen_judge(char const *str);
void last_process(char *str);
int main()
{
    
    char c;
    char str[20];
    while((c = getchar()) != EOF)
    {
        
        for(int i = 0;i<20 && c != '\n';i++)
        {
            str[i] = c;
            c =getchar();
            if(c == '\n')
            str[i+1] = '\0';
        }
        bool t = pre_process(str);
        if(t)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    printf("End\n");
}
bool pre_process(char * str)
{
    // 处理前缀和后缀
    if(str[0] == '+' || str[0] == '-') // 有符号10进制
    {
        strcpy(str, str + 1);
        last_process(str);
        return ten_judge(str);
    }
     if(str[0] == '0' && (str[1] == 'x' || str[1] == 'X')) // 16
    {
        strcpy(str, str + 2);
        last_process(str);
        return sixteen_judge(str);
        
    }
    if(str[0] == '0')// 8
    {
        last_process(str);
        return eight_judge(str);
    }
    if(str[0] >= '1' && str[0] <= '9') // 无符号10进制
    {
        last_process(str);
        return ten_judge(str);
    }
    else
    {
        return false;
    }
    
}
bool ten_judge(char const * str)
{
    bool flag = true;
    if((str[0] >= '1' && str[0] <= '9') == 0)
    return flag = false;
    for(int i = 0;str[i] != '\0' ;i++)
    {
        if((str[i] >= '0' && str[i] <= '9') == 0)
        return flag = false;
    }
    return flag = true;
}
bool eight_judge(char const *str)
{
    bool flag = true;
    if(str[0] != '0')
    return flag = false;
     for(int i = 1;str[i] != '\0' ;i++)
    {
        if((str[i] >= '0' && str[i] <= '7') == 0)
        return flag = false;
    }
    return flag = true;
}
bool sixteen_judge(char const *str)
{
    bool flag = true;
     for(int i = 0;str[i] != '\0' ;i++)
    {
        if(( (str[i] >= '0' && str[i] <= '9') ||
            (str[i] >= 'a' && str[i] <= 'f')  ||
            (str[i] >= 'A' && str[i] <= 'F')
        ) == 0)
        return flag = false;
    }
    return flag = true;
}
void last_process(char *str)
{
    char *pt = strchr(str, 'l');
    if(pt != NULL)
    strcpy(pt, pt + 1);
    pt = strchr(str, 'L');
    if(pt != NULL)
    strcpy(pt, pt + 1);
    pt = strchr(str, 'u');
    if(pt != NULL)
    strcpy(pt, pt + 1);
    pt = strchr(str, 'U');
    if(pt != NULL)
    strcpy(pt, pt + 1);
}