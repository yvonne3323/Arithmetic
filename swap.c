// 用指针交换两个学生的交换
#include <stdio.h>

struct Stu
{
    int num;
    char name[20];
    double score;
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
    struct Stu stu1 = {0221111, "张三", 85};
    struct Stu stu2 = {0222222, "李四", 90};
    // 交换前
    printf("交换前：\n");
    printf("第一个学生：学号：%d 姓名：%s 成绩：%lf\n", stu1.num, stu1.name, stu1.score);
    printf("第二个学生：学号：%d 姓名：%s 成绩：%lf\n", stu2.num, stu2.name, stu2.score);
    // 交换
    swap(&stu1, &stu2);
    // 交换后
    printf("交换后：\n");
    printf("第一个学生：学号：%d 姓名：%s 成绩：%lf\n", stu1.num, stu1.name, stu1.score);
    printf("第二个学生：学号：%d 姓名：%s 成绩：%lf\n", stu2.num, stu2.name, stu2.score);
}
