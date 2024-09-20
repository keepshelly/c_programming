#include <stdio.h>
	int main(){
	int g;
	scanf("%d",&g);
	if (g % 400 == 0)
{
	printf("Visokosnyi");
}
	else if(g % 100 == 0){
	printf("Ne visokosnyi");
}
	else if(g % 4 == 0){
	printf("Visokosnyi");
}
}
