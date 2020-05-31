#include <iostream>
using namespace std;
int main()
{
    int n[10]; //存放9个初始状态
    for (int i = 1; i <= 9; i++)
        cin >> n[i];
    int num[9]; //9种操作的次数
    for (num[0] = 0; num[0] < 4; ++num[0])
        for (num[1] = 0; num[1] < 4; ++num[1])
            for (num[2] = 0; num[2] < 4; ++num[2])
                for (num[3] = 0; num[3] < 4; ++num[3])
                    for (num[4] = 0; num[4] < 4; ++num[4])
                        for (num[5] = 0; num[5] < 4; ++num[5])
                            for (num[6] = 0; num[6] < 4; ++num[6])
                                for (num[7] = 0; num[7] < 4; ++num[7])
                                    for (num[8] = 0; num[8] < 4; ++num[8])
                                    {
                                        int temp;
                                        temp = (n[1] + num[0] +num[1] + num[3])%4;
                                        temp += (n[2] + num[0] +num[1] + num[2] + num[4])%4;
                                        temp += (n[3] + num[1] +num[2] + num[5])%4;
                                        temp += (n[4] + num[0] +num[3] + num[4]+ num[6])%4;
                                        temp += (n[5] + num[0] +num[2] + num[4]+ num[6]+ num[8])%4;
                                        temp += (n[6] + num[2] +num[4] + num[5]+ num[8])%4;
                                        temp += (n[7] + num[3] +num[6] + num[7])%4;
                                        temp += (n[8] + num[4] +num[6] + num[7]+ num[8])%4;
                                        temp += (n[9] + num[5] +num[7] + num[8])%4;
                                        if(temp == 0)
                                        {
                                            for(int i = 0;i<9;++i)
                                            while (num[i]--)
                                            {
                                                cout<<i+1<<" ";
                                            }
                                            
                                            return 0;
                                        }
                                    }

    return 0;
}
