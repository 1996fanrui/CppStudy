/*
 * printf scanf
 * 格式化输入输出
 */

#include <stdio.h>

/*
 * 读写 int 和 float
 */
void example1()
{
	int i;
	float f;

	printf("Enter integer: ");
	scanf("%d", &i);
	printf("%d\n", i);

	printf("Enter float: ");
	scanf("%f", &f);
	printf("%f\n", f);
}

/*
 * 读写无符号整数 p80
 */
void example2()
{
	unsigned int u;

	printf("Enter unsigned interger(base 10): ");
	scanf("%u", &u);
	printf("%u\n", u);

	printf("Enter unsigned interger(base 8): ");
	scanf("%o", &u);
	printf("%o\n", u);

	printf("Enter unsigned interger(base 16): ");
	scanf("%x", &u);
	printf("%x\n", u);
}

/*
 * 读写短整数、长整数 p80
 */
void example3()
{
	short int s;
	long int l;

	printf("Enter short int: ");
	scanf("%hd", &s);
	printf("%hd\n", s);

	printf("Enter long int: ");
	scanf("%ld", &l);
	printf("%ld\n", l);
}

/*
 * 读写double p83
 */
void example4()
{
	double d;

	printf("Enter double: ");
	scanf("%lf", &d);
	printf("%f", d);
}

/*
 * 读写字符 p86
 */
void example5()
{
	char ch;
	
	printf("Enter char: ");
	scanf("%c", &ch);
	printf("%c", ch);
}

int main()
{
	//example1();
	//example2();
	//example3();
	//example4();
	example5();

	return 0;
}
