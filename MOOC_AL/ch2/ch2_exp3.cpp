#include <iostream>
#include <cmath>
using namespace std;
int N; // N行
int NQueenPos[100];
void NQueen(int k) // 默认 0 —— k-1行都被摆好了
{
    if (k == N) //所有的皇后都被摆好了
    {
        for (int i = 0; i < N; i++)
        {
            cout << NQueenPos[i] + 1 << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < N; i++)
    {
        int j;
        for (j = 0; j < k; j++)
        {
            if (NQueenPos[j] == i || abs(NQueenPos[j] - i) == abs(k - j))
            {
                break;
            }
        }
        if (j == k)
        {
            NQueenPos[k] = i;
            NQueen(k + 1);
        }
    }
}
int main()
{
    cin >> N;
    NQueen(0);
    return 0;
}