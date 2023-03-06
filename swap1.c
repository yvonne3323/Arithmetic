#include<stdio.h>

struct Stu
{
    char name[20];
    int num;
    double score;
};

void swap1(struct Stu *p1, struct Stu *p2)
{
    struct Stu temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}


//根据结构体学生成绩排序
void sort(struct Stu *p, int n)
{
    int i, j;
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-1-i; j++)
        {
            if(p[j].score < p[j+1].score)
            {
                swap1(&p[j], &p[j+1]);
            }
        }
    }
}

int main()
{
    //交换两个结构体
    struct Stu s1 = {"zhangsan", 1, 90.5};
    struct Stu s2 = {"lisi", 2, 80.5};
    printf("%s %s\n", s1.name,s2.name);
    swap1(&s1, &s2);
    printf("%s %s\n", s1.name,s2.name);

    struct Stu s[3] = {{"zhangsan", 1, 90.5}, {"lisi", 2, 70.5}, {"wangwu", 3, 80.5}};

    sort(s, 3);
    int i;
    for(i=0; i<3; i++)
    {
        printf("%s %d %lf\n", s[i].name, s[i].num, s[i].score);
    }
    return 0;
}