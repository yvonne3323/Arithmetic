//打印一个字符串的全部子序列
//循环做法
#include <stdio.h>

void printSub(char *str, int i, char *res, int j)
{
    if (str[i] == '\0')
    {
        res[j] = '\0';
        printf("%s\n", res);
        return;
    }
    printSub(str, i + 1, res, j);
    res[j] = str[i];
    printSub(str, i + 1, res, j + 1);
}

int main()
{
    char str[] = "ab c";
    char res[10];
    printSub(str, 0, res, 0);
    return 0;
}


