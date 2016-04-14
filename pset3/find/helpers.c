/*
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>

#include "helpers.h"

/*
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    int end = n-1;
    int begin = 0;

    while (end >= begin)
    {
        int middle = (begin + end) / 2;
        if (values[middle] == value) {
            return true;
        } else if (values[middle] > value) {
            end = middle-1;
        } else {
            begin = middle+1;
        }
    }

    return false;
}
/*
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    bool iterate;
    do
    {
        iterate = false;
        for (int i = 0; i < n-1; i++)
        {
            if (values[i] > values[i+1]) {
                int temp = values[i];
                values[i] = values[i+1];
                values[i+1] = temp;
                iterate = true;
            }
        }
    } while (iterate);
    return;
}
