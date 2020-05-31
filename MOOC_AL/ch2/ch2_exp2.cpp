#include <iostream>
using namespace std;

void Hanoi(int n, char x, char y, char z)
{
    if (n == 1)
    {
        cout<< x <<"->"<< z <<endl;
        return;
    }
    //第一步 将 n-1 个从A -> B
    Hanoi(n-1,x, z, y);
    //第二步 将 1 个从A -> C
    cout<< x <<"->"<< z <<endl;
    //第三步 将n-1个从B -> C
    Hanoi(n-1, y, x, z);

}
int main()
{
    int n;
    cin >> n;
    Hanoi(n, 'A', 'B', 'C');
    return 0;
}