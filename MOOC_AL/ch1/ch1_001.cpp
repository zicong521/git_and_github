#include <iostream>
#include <cstring>
using namespace std;

char oribits[40] ;
char aimbits[40] ;

void flip_bits(char str[], int i)
{
    if(str[i] == '0')
        str[i] = '1';
    else
        str[i] = '0';
}
bool judge_bool(int i, char str[])
{
    return (str[i] == aimbits[i]);
}
int caculate(int n, char str[])
{
    int count = 0;
    for(int i=1;i<n;++i)
    {
        if(judge_bool(i-1, str))
        {
            ;
        }
        else 
        {
            flip_bits(str, i-1);
            flip_bits(str, i);
            if(i<n-1)
            flip_bits(str, i+1);
            count++;
        }
        
    }
    if(str[n-1]!=aimbits[n-1])
    count = -1;
    return count;
}
int main()
{
   cin >> oribits >> aimbits;
   int count_1, count_2;
   int n = strlen(oribits);
   char temp[40] ;
   strcpy(temp, oribits);

   //第一种情况 
   flip_bits(temp, 0);
   flip_bits(temp, 1);
   count_1 = caculate(n, temp);
   if(count_1!=-1)
   count_1 += 1;
   else
   count_1 = -1;
   //第二种情况

   count_2 = caculate(n, oribits);
   if( count_2 == -1 && count_1 == -1)
   {
       cout << "impossible"<<endl;;
   }
   else
   {
       if((count_1>count_2?count_2:count_1) == -1)
       cout<<(count_1>count_2?count_1:count_2)<<endl;
       else
       cout<< (count_1>count_2?count_2:count_1)<<endl;
   }
   return 0;
}
/*

*/