#include <stdio.h>
#include <stdlib.h>
        int main () {
        float a;
        float b;
        char cf;
        printf("Write temperature C or F\n");
        scanf("%f%c", &a,&cf);
        if (cf == 'C'){
        	b = ((a * 1.8) + 32);
                	printf("%f\n",b);}

        else if (cf == 'F'){
        	b = ((a - 32) / 1.8);
               		printf("%f\n",b);}
	else{
		printf("Error,trying please\n");
}
}
