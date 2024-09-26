#include <stdio.h>
	int main()
{
	int n1;
	int n2;
	int i = n1;
	printf("Введите два числа\n");
	scanf("%d%d",&n1,&n2);
	for (i=n1; !(n1 % i ==0 && n2 % i ==0); i--);
			int nod = i;
		printf("%ls",&nod);
}
// NOD
