//双色汉诺塔问题
//把最后一个圆盘n移动到B塔座上之后，就要考虑如何把C塔座上的n-2个圆盘移动到A上，
//然后再把C上的圆盘n-1移动到B上，再把A上的n-2个移动到B上。
//从这个思路来看，我们每次递归时移动到一起的圆盘都是相邻的，也就是说是颜色不一样的
#include<stdio.h>

void Hannoi(int,char,char,char,int*);
int num[3];//num[3]为ABC最上方的圆盘编号 
int main()
{
/*
我们为了验证前面的想法，加上一个记录数组，用来记录每挪动
一次后ABC三个塔座最上方的圆盘编号。如果塔座上没有圆盘，
则记录为0。
*/
	int n;
	scanf("%d",&n);
	num[0]=1;
	num[1]=0;
	num[2]=0;
	Hannoi(n,'A','B','C',num);
	return 0;
} 
void Move(int i,char M,char N)
{   //把第i层塔从M位置移动到N位置
	printf("%d:%c-->%c\n",i,M,N);
}
/*
1、在递归函数里加判断。添加的地方为每次调用Move函数之
后，即每输出一次挪动记录之后。
2、因为相同颜色的圆盘的序号都为奇数或者都为偶数，则两个
颜色相同的圆盘序号相加必为偶数，而两个颜色不同的圆盘序号
数相加必为奇数。
3、所以只需要判断圆盘本身的序号数加上要移动到的塔座最上
方的圆盘序号是否为偶数即可。如果为偶数，就说明此解法错
误，输出false。此判断还有一个特殊情况就是如果要移动到的塔
座上没有圆盘，就不用输出false，这是个特例。
*/
void Hannoi(int n,char A,char B,char C,int* num)
{
	if(n==1)
	{
		Move(1,A,B);
		if((num[A-'A']+num[B-'A'])%2==0&&num[B-'A']!=0){
			printf("false\n");
		}
		
		else{
			printf("true\n");
		}
		
		num[A-'A']=0;
		num[B-'A']=1;
		return;
	}
	n--;
	Hannoi(n,A,C,B,num);
	Move(n+1,A,B);
	if((num[A-'A']+num[B-'A'])%2==0&&num[B-'A']!=0){
		printf("false\n");
	}
	else{
		printf("true\n");
	}
	num[A-'A']=0;
	num[B-'A']=n+1;
	Hannoi(n,C,B,A,num);
}
