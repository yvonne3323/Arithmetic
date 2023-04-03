//打印一个字符串的全部排列

#include <stdio.h>

void printPer(char *str, int i)
{
    if (str[i] == '\0')
    {
        printf("%s\n", str);
        return;
    }
    for (int j = i; str[j] != '\0'; j++)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        printPer(str, i + 1);
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main()
{
    char str[] = "abc";
    printPer(str, 0);
    return 0;
}
