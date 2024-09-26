/*#include <stdio.h>
	int main()
{
	int a = 5;
	while(a>0){
		a--;
	}
	for (int i = 0; i < 5; i++){
		printf("hello ");
	}
}*/
#include <stdio.h>
	int main(){
	int i = 0;
	int s = 1;
	int n;
	printf("Введите число\n");
	scanf("%d",&n);
	for (s=1, i=0; i<=n; i++){
		s = s * 2;
		printf("%d ",s);
}
}
//stepen dvoiki
