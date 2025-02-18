#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000
#define MAX_WORDS  200

int main() {
    char text[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt 12313 54534 34 634";
    char *words[MAX_WORDS];
    int wordCount = 0;
    char *token = strtok(text, " ,.-\n");
    while (token != NULL) {
        words[wordCount++] = token;
        token = strtok(NULL, " ,.-\n");
    }
    for (int i = wordCount - 1; i >= 0; i--) {
        printf("%s ", words[i]);
    }
    printf("\n");

    return 0;
}