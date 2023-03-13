#include<stdio.h>

struct Student
{
    char num[20];
    char name[20];
    double score;
};

void swap(struct Student *p1, struct Student *p2)
{
    struct Student temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

//根据成绩，对包含有n个学生的结构体数组进行排序
void SortStu(struct Student *s, int n)
{
    int i, j;
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-1-i; j++)
        {
            if(s[j].score < s[j+1].score)
                swap(&s[j], &s[j+1]);
        }
    }
}

int main()
{
    
    struct Student s[4] = {{"0221111", "张三", 85}, {"0221112", "李四", 74}, {"0221113", "王五", 90}, {"0221114", "赵六", 80}};
    SortStu(s, 4);
    for(int i=0; i<4; i++)
        printf("%s %s %lf\n", s[i].num, s[i].name, s[i].score);
    return 0;
}