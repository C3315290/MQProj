/* Main function of the C program. */

#include <stdio.h>
#include <stdlib.h>

void move(char *str, int N);
int strlen(char *str);

int main()
{
    
char str[] = "pm ol ohk hufaopun jvumpkluaphs av zhf, ol dyval pa pu jpwoly, aoha pz, if zv johunpun aol vykly vm aol slaalyz vm aol hswohila, aoha uva h dvyk jvbsk il thkl vba.";

int i = 0;


while (i < 26) {
    move(str, strlen(str));
    printf("%d: %s\n",i, str);
    i++;
}            
    }
    
void move(char *str, int N) {
int i = 0; // Array index loop counter

    for(i = 0; i < N; i++) {
        if (str[i] != 32 && str[i] >= 97 && str[i] <= 122) {
        if (str[i] == 122) {
            str[i] = 97; 
        }
            else {
                str[i] = str[i] + 1;
            }
    }
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

