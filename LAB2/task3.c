#include <stdio.h>
	int main(){
	int a;
	int s;
	int n;
	int k;
	printf("Введите число");
		scanf("%d",&a);
	printf("Введите число");
        	scanf("%d",&n);
	printf("Введите число");
        	scanf("%d",&k);
	for (n=a,s=0; n!=0; n=n/10)
	{k=n%10; s=s+k;}
	printf("%d\n",s);
}
//summa chisel
