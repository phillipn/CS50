#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    string name=GetString();
 

    for (int i=0, n=strlen(name); i<n; i++) {
        if (i == 0) {
            printf("%c", toupper(name[i]));
        } else if (isspace(name[i])) {
            printf("%c", toupper(name[i+1]));
        }
    }
    printf("\n");
}