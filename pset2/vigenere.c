#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[]) {
    string text;

    if (argc != 2) {
        printf("I will only accept one command-line argument!\n");
        return 1;
    } 
    string key = argv[1];
    for (int k=0; k<strlen(key); k++) {
        if (key[k]>='0' && key[k]<='9') {
            printf("No numbers in the key!\n");
            return 1;
        }
    }
        text = GetString();
        int n=strlen(text);
        int shift; 
        for (int i=0, j=0; i<n; i++, j++) {
            if (j >= strlen(key)) {
                j=0;
            } 
            if (!isalpha(text[i])) {
                j=j-1;
            }
            if (text[i]>='a' && text[i]<='z') {
                if (islower(key[j])){
                    shift= key[j]-97;
                } else if (isupper(key[j])){
                    shift= key[j]-65;
                }
                    if (text[i] + shift > 'z') {
                        printf("%c", text[i]+shift-26);
                    } else { 
                        printf("%c", text[i]+shift);
                    }
            } else if (text[i]>='A' && text[i]<='Z') {
                if (islower(key[j])){
                    shift= key[j]-97;
                } else if (isupper(key[j])){
                    shift= key[j]-65;
                }
                    if (text[i] + shift > 'Z') {
                        printf("%c", text[i]+shift-26);
                    } else { 
                        printf("%c", text[i]+shift);
                    }
            } else {
                printf("%c", text[i]);
            }
        }
        printf("\n");
}