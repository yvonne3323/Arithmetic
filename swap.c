// 用指针交换两个学生的交换
#include <stdio.h>

struct Stu
{
    char num[20];//学号
    char name[20];//姓名
    double score;//成绩
};

void swap(struct Stu *p1, struct Stu *p2)
{
    struct Stu temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main()
{
    struct Stu s1 = {"0221111", "张三", 85};
    struct Stu s2 = {"0221112", "李四", 74};
    printf("交换前：\n");
    printf("第一个学生：学号：%s 姓名：%s 成绩：%lf\n", s1.num, s1.name, s1.score);
    printf("第二个学生：学号：%s 姓名：%s 成绩：%lf\n", s2.num, s2.name, s2.score);
    swap(&s1, &s2);
    printf("交换后：\n");
    printf("第一个学生：学号：%s 姓名：%s 成绩：%lf\n", s1.num, s1.name, s1.score);
    printf("第二个学生：学号：%s 姓名：%s 成绩：%lf\n", s2.num, s2.name, s2.score);
    return 0;
}
