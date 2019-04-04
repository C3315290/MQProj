/* Main function of the C program. */

#include <stdio.h>
#include <stdlib.h>

int main()
{


float data[] = {1.2, 8.4, 10.8, -0.4, -8.234, 3.1};
float maximum = -1e30;
int maxindex;
int i;

    for (i = 0; i < 6; i++) {
        
        if (data[i] > maximum) {
        maximum = data[i];
        maxindex = i;
    
        }
        
        
    }
printf("The maximum value was %f, found at index %d", maximum, maxindex);
printf("The maximum value was %f, found at index %d", maximum, maxindex);
printf("The maximum value was %f, found at index %d", maximum, maxindex);
}
