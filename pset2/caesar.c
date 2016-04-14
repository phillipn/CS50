#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <cs50.h>
#include <math.h>
#include <stddef.h>

int main(int argc, string argv[]) {
    if (argc != 2) {
        printf("Need valid number!\n");
        return 1;
    } else {
        string text;
        text = GetString();
        int key = atoi(argv[1]);
 
        for (int i = 0, n=strlen(text); i<n; i++) {
            if (isupper(text[i])) {
                if ((text[i] + (key%26)) >= 91) {
                    text[i] = text[i] + (key % 26) - 26;
                    printf("%c", text[i]);
                } else {
                    printf("%c", text[i] + key%26);
                }
            } else if (islower(text[i])) {
                if ((text[i] + (key%26)) >= 123) {
                    text[i] = text[i] + (key % 26) - 26;
                    printf("%c", text[i]);
                } else {
                    printf("%c", text[i] + key%26);
                }
            } else {
                printf("%c", text[i]);
            }
        }
       printf("\n");
    }
 }