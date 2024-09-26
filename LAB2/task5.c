#include <stdio.h>
	int main()
{
	int n;
	int s;
	int i;
	scanf("%d",&n);
	for (s=1, i=1; i<=n; i++) s = s * i;
	printf("s = %d",s);
}
// factorial
