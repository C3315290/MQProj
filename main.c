/* Main function of the C program. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void demove(char *str, int N);
void enmove(char *encyptstr, int N);
void returnword(char *str, char *word, int wordnumber, int N);
void initword(char *word);  //sets entire word string to '\0' ensures when function returnword is run, only a word returns.
int nowords(char *str, int N);
int containspunc(char *word, int K);
void initfind(char *find);
void upperstr(char *str);
void upperenstr(char *encyptstr);


int main()
{
    
char str[100000];
char encyptstr[100000];
int j = 1;
int k = 1;
int l = 1;
int o = 1;
int largestwordpos = 1;
int largestwordlength = 1;
char word[100];
char find[1000];
int cipherresult = 0;
int ciphermove;
char c;


printf("Please select an option: \n");
printf("a) Encrypt ceaser cypher, place test to be encrypted in Cipher.txt, enter a key.\n");
printf("b) Decrypt ceaser cypher without key\n");
printf("c) Decrypt ceaser cypher given Key\n");
printf("Selection: ");
scanf("%c", &c);

initword(word);
initfind(find);

FILE *dict;
dict = fopen("words.txt", "r");
FILE *output;
output = fopen("decrypted.txt", "w");
FILE *encryptf;
encryptf = fopen("cipherencrypt.txt", "r");
FILE *decryptf;
decryptf  = fopen("cipherdecrypt.txt", "r");

switch (c) {
 
case 'a':
printf("Enter Cypher Movement Integer:");
scanf("%d", &ciphermove);
rewind(encryptf) ;
        while(fscanf(encryptf, "%[^\n]", encyptstr) != EOF){
            upperenstr(encyptstr);
            while (o <= ciphermove) {
                enmove(encyptstr, strlen(encyptstr)); 
                o++;
            }     
        }
printf("Encrypted text with movement of %d: %s\n", ciphermove, encyptstr);  
break;

case 'b':

while(fscanf(decryptf, "%[^\n]", str) != EOF){
    upperenstr(str);
    while (l <= nowords(str, strlen(str))) {
        returnword(str, word, l, strlen(str));
        if (strlen(word) > largestwordlength && containspunc(word, strlen(word)) == 0) {
            largestwordlength = strlen(word);
            largestwordpos = l;    
        }
    l++;
    }
}
returnword(str, word, largestwordpos, strlen(str));
printf("Word used for spell checking: %s\n", word);

while (j < 26) {
    demove(word, strlen(word));
    rewind(dict);
    while(fscanf(dict, "%s", find) != EOF){
        if(strcmp(find, word) == 0){
		  cipherresult = j;
		  printf("Word Found: %s\n", find);
	   }
    }
    j++;
}
printf("Cipher Movement: %d\n", abs(cipherresult - 26));

while (k < 26) {
    demove(str, strlen(str));
    if (k == cipherresult) {
        printf("Decrypted: %s\n", str);
        fprintf(output, "%s", str);
    }
    k++;
}
break;
case 'c':

printf("Enter Cypher Movement Integer:");
scanf("%d", &ciphermove);

while(fscanf(decryptf, "%[^\n]", str) != EOF){
    upperenstr(str);
    while (k < 26) {
        demove(str, strlen(str));
        if (k == abs(ciphermove - 26)) {
            printf("Decrypted: %s\n", str);
            fprintf(output, "%s", str);
        }
        k++;
    }
}

break;
default: printf("Unknown option %c\nPlease enter a or b\n",c);
}
}

// ------------------------------FUNCTIONS--------------------------------------------
void demove(char *str, int N) {
int i = 0; // Array index loop counter
    for(i = 0; i < N; i++) {
        if (str[i] != 32 && str[i] >= 65 && str[i] <= 90) {
        if (str[i] == 90) {
            str[i] = 65; 
        }
            else {
                str[i] = str[i] +1;
            }
    }
}
return;
}

void enmove(char *encyptstr, int N) {
int i = 0; // Array index loop counter
    for(i = 0; i < N; i++) {
        if ((encyptstr[i] >= 65 && encyptstr[i] <= 90)) {
            if (encyptstr[i] == 90) {
                encyptstr[i] = 65; 
            }
            else {
                encyptstr[i] = encyptstr[i] + 1;
            }
        }
    }
return;
}
    
    
void returnword(char *str, char *word, int n, int N) {
    int count = 0;
    int count2 = 0;
    int spaces = 0;
    if (n == 1){
        while (str[count] != ' ') {
        word[count] = str[count];       
        count++;
        }
    word[count] = '\0';
    word[count + 1] = '\0';
   }
    
   if (n > 1) {
       while (count < N) {
            while (spaces >= n-1 && spaces < n && count < N) {
            word[count2] = str[count]; 
            count++;
            count2++;
                    if (str[count] == ' ') {
                    spaces++;
                        if (spaces == n) {
                               word[count2] = '\0';
                        }
                    }
            }
            if (str[count] == ' ') {
                    spaces++;
            }
            count++;
        }
    }
    return;
}

void initword(char *word) {
    int i = 0;
    while (word[i] != '\0') {
        word[i] = '\0';
        i++;
    }
}      
    
void upperenstr(char *encyptstr) {
    int i = 0;
    while (encyptstr[i] != '\0') {
        encyptstr[i] = (toupper(encyptstr[i]));
        i++;
    }
}  

void upperstr(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        str[i] = (toupper(str[i]));
        i++;
    }
}  

void initfind(char *find) {
    int i = 0;
    while (find[i] != '\0') {
        find[i] = '\0';
        i++;
    }
}
  
int nowords(char *str, int N) {
    int j = 0;
    int words = 0;
    for (j = 0; j < N; j++) {
        if (str[j] == ' ') {
            words++;   
        }
    }
return words + 1;
}
    
    
int containspunc(char *word, int K) {
    int j = 0;
    int r = 0;
    while (j <= K) {
        if ((word[j] >= 33 && word[j] <= 64) || (word[j] >= 91 && word[j] <= 96) || (word[j] >= 123 && word[j] <= 126)) {
        r = 1;
        }
    j++;
    }
return r;
}
           