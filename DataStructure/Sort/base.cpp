#include "stdio.h"
#include "stdlib.h"

#define MAX_LENGTH 10

typedef struct {
    int r[MAX_LENGTH + 1];
    int length;
}SqList;
// 一个交换函数 交换表中i和j下标的值
void swap( SqList *L, int i, int j)
{
    int temp = L->r[i];
    L->r[i] = L->r[j];
    L->r[j] = temp;
}
int main()
{
    return 0;
}

