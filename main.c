/* Main function of the C program. */

#include <stdio.h>
#include <stdlib.h>

void move(char *str, int N);

int strlen(char *str);

int main()
{
    
    
    
char str[] = "jvumpkluaphs";
int i = 0;
while (i < 26) {
    move(str, strlen(str));
    printf("%s\n", str);
    i++;
}            
    printf("%s\n", str);
    }

void move(char *str, int N) {
int i = 0; // Array index loop counter
    for(i = 0; i < N; i++)
        if (str[i] != 122) 
        {
            str[i] = str[i] + 1; // Use array syntax
         }
        else 
        {
            str[i] = 97;
        }
        
return; // Optional
}


int strlen(char *str) {
    int i = 0;
    while (str[i] != 0) {
    
     i++;
 }
     return i;
    }

