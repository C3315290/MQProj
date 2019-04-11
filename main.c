/* Main function of the C program. */

#include <stdio.h>
#include <stdlib.h>


int len(char *str);
void move(char *str, int N);
int threewords(char *str, int N);

int main()
{
    
char str[] = "pm ol ohk hufaopun jvumpkluaphs av zhf, ol dyval pa pu jpwoly, aoha pz, if zv johunpun aol vykly vm aol slaalyz vm aol hswohila, aoha uva h dvyk jvbsk il thkl vba.";

int i = 0;


printf("%d\n", threewords(str, len(str)));

// FILE *input;
FILE *output;

// input = fopen("words.txt", "r");
output = fopen("ciph.txt", "w");

fprintf(output, "%s", str);

while (i < 26) {
    move(str, len(str));
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
return;
}

int len(char *str) {
    int i = 0;
    while (str[i] != 0) {
    
     i++;
 }
     return i;
    }
    

int threewords(char *str, int N) {
int i1 = 0; // Array index loop counter
int i2 = 0;
int i3 = 0;
int firstspace = 0;
//int secondspace = 0;
//int thirdspace = 0;
int spaces = 0;

    for(i1 = 0; spaces < 1; i1++) {
       if (str[i1] == ' ' && spaces == 0) {
       firstspace = i1;
        spaces++;
        }
    }
  //  for(i2 = 0; spaces < 2; i2++) {
   //     if (str[i2] == ' ' && spaces == 0) {
   //     secondspace = i2;
   //     spaces++;
   //     }
//}
  //  for(i3 = 0; spaces < 3; i3++) {
    //    if (str[i3] == ' ' && spaces == 0) {
    //    thirdspace = i3;
    //    spaces++;
    //    }
  //  }
return firstspace;
}
