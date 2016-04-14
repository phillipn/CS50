/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */

#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef uint8_t BYTE;


int main(void)
{

    FILE* camera = fopen("card.raw", "r");
    FILE* temp;
    bool isJpeg(BYTE* p);

    if (camera == NULL) {
        printf("Could not open\n");
        return 1;
    }

    BYTE* buffer = malloc(512);
    
    if (buffer==NULL) {
        printf("Issues with code");
        return 2;
    }
    
    int counter= 0;
    char* filename = malloc(sizeof(char)*8);
    
    bool fileopened = false;
    
    while(fread(buffer, sizeof(buffer), 1, camera) == 1) {
        if (isJpeg(buffer)) {
            sprintf(filename, "%03d.jpg", counter);
            counter++;
            
            if(fileopened) {
                fclose(temp);
                temp = fopen(filename, "w");
                fwrite(buffer, sizeof(buffer), 1, temp);
            } else {
                temp = fopen(filename, "w");
                fwrite(buffer, sizeof(buffer), 1, temp);
                fileopened = true;   
            }
            
        } else if (fileopened) {
            fwrite(buffer, sizeof(buffer), 1, temp);  
        }
    }
        
        if (temp) {
            fclose(temp);
        }
            fclose(camera);
            free(filename);
            free(buffer);
            return 0;
    }
    
bool isJpeg(BYTE* p) {
    return (p[0]==0xff && p[1]==0xd8 && p[2]==0xff && (p[3] == 0xe0 ||p[3] == 0xe1));
}
    
    
