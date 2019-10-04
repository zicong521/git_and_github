#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define MaxCol 1000 //最大字符串长度

bool is_match(char *s , char *p );//判断函数

// 四种情况对应的函数
bool is_match_1(char *s,char *p);//两种符号都不存在

bool is_match_2(char *s,char *p);//只有 '.' 

bool is_match_3(char *s,char *p);// 只有'*' 

void recursion_judge(char *s, char *p ,int *flag);//针对情况三的递归判断函数

bool is_match_4(char *s,char *p);//两种符号都存在

int main(void)
{
    char s[MaxCol],p[MaxCol-1];
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
        if ( strchr(p,'*')==NULL &&
        strchr(p,'.')==NULL)
        {
            return is_match_1(s,p);
        }
        if ( strchr(p,'*')==NULL &&
        strchr(p,'.')!=NULL)
        {
            return is_match_2(s,p);
        }
        if ( strchr(p,'*')!=NULL &&
        strchr(p,'.')==NULL)
        {
            return is_match_3(s,p);
        }
        if ( strchr(p,'*')!=NULL &&
        strchr(p,'.')!=NULL)
        {
            return is_match_4(s,p);
        }
    }
}
bool is_match_1(char *s,char *p)//if neither sign exists
{
    if(strcmp(s,p) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}
bool is_match_2(char *s,char *p)//if only '.' exists
{
    while(strchr(p,'.')!= NULL)
    {
        char *p_index = strchr(p,'.');
        int index=p_index-p;
        p[index]=s[index];
    }
    return is_match_1(s,p);
}
bool is_match_3(char *s,char *p)
{
    int flag = true;
    recursion_judge(s,p,&flag);
    if(flag)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}
void recursion_judge(char *s, char *p ,int *flag)
{
    if(*s == '\0' || *p == '\0')// 边界条件
    {
        if( *s== '\0')
        {
            while(*p != '\0' && *(p+1) == '*')
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
    if(*(p+1) != '*')//如果p的下一位是字符 直接比较
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
    else //
    {
        if (*s == *p || *p == '.')
        {
            recursion_judge(s+1,p,flag);
        }
        else
        {
            recursion_judge(s,p+2,flag);
        }
        
    }
}
bool is_match_4(char *s,char *p)
{
    int flag = true;
    recursion_judge(s,p,&flag);
    if(flag)
    {
        return true;
    }
    else
    {
        return false;
    }
}