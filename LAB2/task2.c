#include <stdio.h>
	int main(){
	int a;
	int n;
	printf("Введите число:");
	scanf("%d",&a);
	for (n=2; n<a; n++)
     		{ if (a%n==0) break;}
	if (n==a) puts("Good");
}
//prostoe chislo
