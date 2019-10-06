#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define MaxCol 1000 //最大字符串长度

bool is_match(char *s , char *p );//判断函数

bool is_match_1(char *s,char *p);// 判断子函数

void recursion_judge(char *s, char *p ,int *flag);// 递归判断函数
void recursion_judge_reverse(char *s, char *p ,int *flag);//倒置递归判断函数

void reverse(char *s);//字符串翻转函数 
                               
int main(void)
{
    char s[MaxCol],p[MaxCol];
    printf("please input the original string s = ");
    gets(s);
    printf("please input the Match Rule string p = ");
    gets(p);
    if(is_match(s,p))
    {
        printf("%d\n",true); 
    }
    else
    {
        printf("%d\n",false);
    }
    system("pause");
    return 0;
    
}
bool is_match(char *s , char *p )
{
    if (s== NULL && p==NULL)
    {
        return true;
    }
    else if (s== NULL || p==NULL)
    {
        return false;
    }    
    else
    {
            return is_match_1(s,p);
    }
}

bool is_match_1(char *s,char *p)//其他情况
{
    int flag1 = true,flag2 = true;
    recursion_judge(s,p,&flag1);
     //这里加一个字符串逆转函数 
    reverse(s),reverse(p);
    recursion_judge_reverse(s,p,&flag2);
    if(flag1 || flag2)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}
void recursion_judge_reverse(char *s, char *p ,int *flag)//倒置字符串 迭代判断函数  *flag 是标签
{
    if(*s == '\0' || *p == '\0')// 边界条件
    {
        if( *s== '\0')
        {
            while(*p =='*')
            {
                p +=2;
            }
            if (*p == '\0')
            {
                *flag = true;
                return;
            }
            else
            {
                *flag = false;
                return;
            }
        }
        else
        {
            *flag = false;
            return ;
        }
        
    }
    if( *p != '*')// 倒过来 第一位如果不是* 直接匹配
    {
        if (*s == *p || *p == '.')
        {
            recursion_judge_reverse(s+1,p+1,flag);
        }
        else 
        {
            *flag = false;
            return ;
        }
    }
    else //第一位是* 
    {
        if (*(p+1) == *s  || *(p+1) == '.')
        {
            recursion_judge_reverse(s+1,p,flag);
        }
        else
        {
            recursion_judge_reverse(s,p+2,flag);
        }
        
    }
}
void recursion_judge(char *s, char *p ,int *flag)//正置判断
{
    if(*s == '\0' || *p == '\0')// 边界条件
    {
        if( *s == '\0')
        {
            while(*(p+1) =='*')
            {
                p +=2;
            }
            if (*p == '\0')
            {
                *flag = true;
                return;
            }
            else
            {
                *flag = false;
                return;
            }
        }
        else
        {
            *flag = false;
            return ;
        }
        
    }
    if( *(p+1) != '*')//  第二位如果不是* 直接匹配
    {
        if (*s == *p || *p == '.')
        {
            recursion_judge(s+1,p+1,flag);
        }
        else 
        {
            *flag = false;
            return ;
        }
    }
    else //第二位是* 
    {
        if (*p == *s  || *p == '.')
        {
            recursion_judge(s+1,p,flag);
        }
        else
        {
            recursion_judge(s,p+2,flag);
        }
    }
}
void reverse(char *s)//注意字符串是以字符数组的形式存储的
{
    int len_str=0;
    char temp;
    for (int i=0;s[i] != '\0'; i++)
    {
        len_str++;
    }
    for(int i=0 ;i < len_str/2 ;i++)
    {
        temp=s[len_str- i-1];
        s[len_str- i-1]=s[i];
        s[i]=temp;
    }
}