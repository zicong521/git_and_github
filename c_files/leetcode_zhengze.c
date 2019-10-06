#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MaxCol 1000 //最大字符串长度
bool isMatch(char *s, char *p);
int main()
{
    char s[MaxCol], p[MaxCol];
    printf("please input the original string s = ");
    gets(s);
    printf("please input the Match Rule string p = ");
    gets(p);
    printf("%d", isMatch(s, p));
}
bool isMatch(char *s, char *p)
{
    int sl = strlen(s);
    int pl = strlen(p);
    bool dp[sl + 1][pl + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = sl; i > -1; --i)
    {
        for (int j = pl; j > -1; --j)
        {
            if (i == sl && j == pl)
            {
                dp[i][j] = true;
                continue;
            }
            if (pl - j > 1 && p[j + 1] == '*')
            {
                dp[i][j] = dp[i][j + 2] || (i < sl && (p[j] == '.' || p[j] == s[i]) && dp[i + 1][j]);
            }
            else
            {
                dp[i][j] = i < sl && (p[j] == '.' || p[j] == s[i]) && dp[i + 1][j + 1];
            }
        }
    }
    return dp[0][0];
}