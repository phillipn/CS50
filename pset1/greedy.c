#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void){
    int change = 0;
    int count = 0;

    
do {
    printf("How much change is owed?\n");
    change = round(GetFloat()*100);
} while (change<0);

while (change >= 25) {
    count += 1;
    change = change - 25;
}
while (change >= 10) {
    count += 1;
    change = change - 10;
}
while (change >= 5) {
    count += 1;
    change = change - 5;
}
while (change >= 1) {
    count += 1;
    change = change - 1;
}

  printf("%d\n", count);  
}