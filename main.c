/* Main function of the C program. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int len(char *str);
void move(char *str, int N);
void returnword(char *str, char *word, int wordnumber, int N);

int main()
{
    
char str[] = "pm ol ohk hufaopun jvumpkluaphs av zhf, ol dyval pa pu jpwoly, aoha pz, if zv johunpun aol vykly vm aol slaalyz vm aol hswohila, aoha uva h dvyk jvbsk il thkl vba.";
int i = 0;
char word3[10];

returnword(str, word3, 4, len(str));

printf("%s\n", word3);


// FILE *input;
FILE *output;

// input = fopen("words.txt", "r");
output = fopen("ciph.txt", "w");

fprintf(output, "%s", str);

//prints all permutations
while (i < 26) {
    move(word3, len(word3));
    printf("%d: %s\n",i, word3);
    
    i++;
}          

  
    }
// ------------------------------FUNCTIONS--------------------------------------------
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
int len(char *str) { //function finds length of string
    int i = 0;
    while (str[i] != 0) {
     i++;
 }
     return i;
    }
    
void returnword(char *str, char *word, int n, int N) 
{
    int count = 0;
    int count2 = 0;
     //   int count2 = 0;
int spaces = 0;
    if (n == 1)
   {
        while (str[count] != ' ') 
        {
        word[count] = str[count];       
        count++;
        }
    word[count] = '\0';
    }
    
    
    
    
   if (n > 1) {
       while (count < N) {
            while (spaces >= n-1 && spaces < n && count < N) {
            word[count2] = str[count]; 
            count++;
            count2++;
                    if (str[count] == ' ') {
                    spaces++;
                    if (spaces == n + 1) {
                            word[count2 + 1] = '\0';
                    }
                }
            }
                if (str[count] == ' ') {
                    spaces++;
                }
            count++;
            }

    }
}
