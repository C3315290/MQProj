/* Main function of the C program. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void demove(char *str, int N);
void enmove(char *encryptstr, int N);
void returnword(char *str, char *word, int wordnumber, int N);
void initword(char *word);
int nowords(char *str, int N);
int containspunc(char *word, int K);
void initfind(char *find);
void initendsub(char *ensub);
void initdesub(char *desub);
void upperstr(char *str);
void upperenstr(char *encryptstr);
void encryptsub(char *alphabet, char *subkey, char *ensub, char *str);
void decryptsub(char *alphabet, char *subkey, char *desub, char *str);


int main(){
    
char str[100000];   //string used for encryption/decryption 
char encryptstr[100000]; //string used for encryption of rotation cipher
int j = 1;
int k = 1;
int l = 1;
int o = 1;
int largestwordpos = 1; //variable used for longest word position in string str.
int largestwordlength = 1; //variable used for longest word length in string str.
char word[100]; //string used for storing longest word in str
char find[1000]; //string used to store words read from dictionary file.
int cipherresult = 0; //integer used to store rotation cipher movements in decrypt without key mode
int ciphermove; //integer used to store rotation cipher movements in encrypt and decrypt rotation movement key
char c; //menu selection character
char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //used in functions encryptsub and decryptsub to compare substitution keys with
char subkey[26]; //entered in terminal for decryption and encryption of substitution ciphers
char ensub[100000]; //used to store encrypted substitution ciphers
char desub[100000]; //used to store decrypted substitution ciphers


//MENU
printf("Please select an option: \n");
printf("a) Encrypt ceaser cypher, enter a key.\n");
printf("b) Decrypt ceaser cypher without key\n");
printf("c) Decrypt ceaser cypher given key\n");
printf("d) Encrypt Substitution with key provided\n");
printf("e) Decrypt Substitution with key provided\n");
printf("Selection: ");
scanf("%c", &c); //scans selection and stores in char c


//function init ensures word and find strings are filled with '/0''before being used.
initword(word);
initfind(find);

FILE *dict;
dict = fopen("words.txt", "r"); // this file contains words to be used for spell checking.
if (dict == NULL) {
    perror("Can't open file");//return error if not file
}

FILE *subdecrypted;
subdecrypted = fopen("subdecrypted.txt", "w"); // open file for writing - decrypted substitution ciphers go here.
if (subdecrypted == NULL) {
    perror("Can't open file");//return error if not file
}
FILE *subencrypted;
subencrypted = fopen("subencrypted.txt", "w"); // open file for writing - encrypted substitution ciphers go here.
if (subencrypted == NULL) {
    perror("Can't open file");//return error if not file
}
FILE *rotdecrypted;
rotdecrypted = fopen("rotdecrypted.txt", "w"); // open file for writing - decrypted rotation ciphers go here.
if (rotdecrypted == NULL) {
    perror("Can't open file");//return error if not file
}
FILE *rotencrypted;
rotencrypted = fopen("rotencrypted.txt", "w"); // open file for writing - encrypted rotation ciphers go here.
if (rotencrypted == NULL) {
    perror("Can't open file");//return error if not file
}
FILE *rotencryptf;
rotencryptf = fopen("rotcipherencrypt.txt", "r"); // open file for reading - rotation ciphers to be encrypted go here.
if (rotencryptf == NULL) {
    perror("Can't open file");//return error if not file
}
FILE *rotdecryptf;
rotdecryptf  = fopen("rotcipherdecrypt.txt", "r"); // open file for reading - rotation ciphers to be decrypted go here.
if (rotdecryptf == NULL) {
    perror("Can't open file");//return error if not file
}
FILE *subencryptf;
subencryptf = fopen("subcipherencrypt.txt", "r");  // open file for reading - substitution ciphers to be encrypted go here.
if (subencryptf == NULL) {
    perror("Can't open file");//return error if not file
}
FILE *subdecryptf;
subdecryptf  = fopen("subcipherdecrypt.txt", "r"); // open file for reading - substitution ciphers to be decrypted go here.
if (subdecryptf == NULL) {
    perror("Can't open file"); //return error if not file
}

switch (c) {      
    case 'a': //a) Encrypt ceaser cypher, enter a key
        printf("Enter Cypher Movement Integer:");
        scanf("%d", &ciphermove); //recieve cipher key to use
                while(fscanf(rotencryptf, "%[^\n]", encryptstr) != EOF){ //scan file until new line or EOF
                    upperenstr(encryptstr); //convert contents to upper case
                    while (o <= ciphermove) { //while loop to use enmove function certain many of times.
                        enmove(encryptstr, strlen(encryptstr)); //enmove will move all characters by 1
                        o++;
                    }     
                }
        printf("Encrypted text with movement of %d: %s\n", ciphermove, encryptstr); //display completed encryption
        fprintf(rotencrypted, "%s", encryptstr); //print to file
        break;
    
    case 'b': //b) Decrypt ceaser cypher without key
        
        while(fscanf(rotdecryptf, "%[^\n]", str) != EOF){ //scan file until new line or EOF
            upperenstr(str); //convert str to uppercase
            while (l <= nowords(str, strlen(str))) { //while loop comparing number of words in str with 'l'
                returnword(str, word, l, strlen(str)); //grabs lth word in str
                if (strlen(word) > largestwordlength && containspunc(word, strlen(word)) == 0) { //decerns whether lth words is higher than previous word
                    largestwordlength = strlen(word); // if above is true, update variables to current word
                    largestwordpos = l;    
                }
            l++;
            }
        }
        
        //largest word is assumed to the most complex word, avoiding false positive cipher solutions. ('if' turns into 'he' with cipher key -1 or 25)
        
        returnword(str, word, largestwordpos, strlen(str)); //make word equal to largest word calculated from above.
        printf("Word used for spell checking: %s\n", word); //print word that will be used for spell checking
        
        while (j < 26) { //move all letters in word 26 times
            demove(word, strlen(word));
            rewind(dict); //rewind dictionary file if somehow it has been scanned already.
            while(fscanf(dict, "%s", find) != EOF){ //scan dictionary file one word at a time
                if(strcmp(find, word) == 0){ //use <string.h> function strcmp to compate two strings, returns 0 if 'find' is equal to 'word'.
        		  cipherresult = j; //stores cipher result 
        		  printf("Word Found: %s\n", find); //indicate print if word found
        	   }
            }
            j++;
        }
        printf("Cipher Movement: %d\n", abs(cipherresult - 26)); //an offset of -26 required because loops only going forward.
        
        //now that we know cipher key, use this to move entire string, str
        
        while (k < 26) {
            demove(str, strlen(str));
            if (k == cipherresult) { //loop until cipher key
                printf("Decrypted: %s\n", str); //print solution
                fprintf(rotdecrypted, "%s", str); //write solution to file
            }
            k++;
        }
        break;
    case 'c': //c) Decrypt ceaser cypher given key
    
        printf("Enter Cypher Movement Integer:");
        scanf("%d", &ciphermove);
        
        while(fscanf(rotdecryptf, "%[^\n]", str) != EOF){ //scan file until new line or EOF
            upperenstr(str); //convert to uppercase
            while (k < 26) {
                demove(str, strlen(str)); //move str 
                if (k == abs(ciphermove - 26)) { //move str until entered cipher key is reached.
                    printf("Decrypted: %s\n", str); //print decrypted string
                    fprintf(rotdecrypted, "%s", str); //print to file
                }
                k++;
            }
        }
        break;
    case 'd': //d) Encrypt Substitution with key provided
    
        printf("Enter substitution key (Eg QWERTYUIOPASDFGHJKLZXCVBNM):");
        scanf("%s", subkey); //store entered key in subkey
        
        while(fscanf(subencryptf, "%[^\n]", str) != EOF){ //scan file until new line or EOF
            upperenstr(str); //convert to uppercase
            encryptsub(alphabet, subkey, ensub, str); //encrypt
        }
        
        printf("Encrypted: %s\n", ensub); //print encrypted string
        fprintf(subencrypted, "%s", ensub); //print encrypted string to file
        
        break;
    
    case 'e': //e) Decrypt Substitution with key provided
        printf("Eneter substitution key (Eg QWERTYUIOPASDFGHJKLZXCVBNM):");
        scanf("%s", subkey); //store entered key in subkey      
        
        while(fscanf(subdecryptf, "%[^\n]", str) != EOF){ //scan file until new line or EOF
            upperenstr(str); //convert to uppercase
            decryptsub(alphabet, subkey, desub, str); //decrypt function
        } 
        
        printf("Decrypted: %s\n", desub); //print decrypted string
        fprintf(subdecrypted, "%s", desub); //print decrypted string to file
        
        break;
    
    default: printf("Unknown option %c\nPlease enter a, b, c, d or e\n",c); // if selection not in case-switch
}
}

// ------------------------------FUNCTIONS--------------------------------------------
//rotation encryption move for length of str
void demove(char *str, int N) {
int i = 0; 
    for(i = 0; i < N; i++) {
        if (str[i] != 32 && str[i] >= 65 && str[i] <= 90) { //loop back through capital characters if capital 'Z' is reached. Z = 90 A = 65
        if (str[i] == 90) {   //Z = 90
            str[i] = 65;      // A = 65
        }
            else {
                str[i] = str[i] +1; //move character by 1
            }
    }
}
return;
}
//rotation encryption move for length of encryptstr
void enmove(char *encryptstr, int N) {
int i = 0;
    for(i = 0; i < N; i++) {
        if ((encryptstr[i] >= 65 && encryptstr[i] <= 90)) { //loop back through capital characters if capital 'Z' is reached. 
            if (encryptstr[i] == 90) {  //Z = 90
                encryptstr[i] = 65;     // A = 65
            }
            else {
                encryptstr[i] = encryptstr[i] + 1; //move character by 1
            }
        }
    }
return;
}
    
//function to return lth word. longest word of str string.
void returnword(char *str, char *word, int n, int N) {
    int count = 0;
    int count2 = 0;
    int spaces = 0;
    if (n == 1){ // if first word is longest, there is no spaces to count, first space indicates end of first word.
        while (str[count] != ' ') { //copy str string to word string until space.
        word[count] = str[count];        
        count++;
        }
   }
   if (n > 1) {
       while (count < N) {
            while (spaces >= n-1 && spaces < n && count < N) { //compares amount of spaces to enable copy of str string to word string
            word[count2] = str[count]; 
            count++;
            count2++;
                    if (str[count] == ' ') { //if space increment space
                    spaces++;
                        if (spaces == n) { //if space = n end string for word string
                               word[count2] = '\0';
                        }
                    }
            }
            if (str[count] == ' ') { //when not copying string increment spaces untill required spaces is reached.
                    spaces++;
            }
            count++;
        }
    }
    return;
}

//initialises string 'word' with \0 characters, ensures when writing to string that '\0' is definitely present to ensure no garbage data is used
void initword(char *word) {
    int i = 0;
    while (word[i] != '\0') {
        word[i] = '\0';
        i++;
    }
} 
//initialises string 'ensub' with \0 characters, ensures when writing to string that '\0' is definitely present to ensure no garbage data is used
void initendsub(char *ensub){
      int i = 0;
    while (ensub[i] != '\0') {
        ensub[i] = '\0';
        i++;
    }  
}
//initialises string 'desub' with \0 characters, ensures when writing to string that '\0' is definitely present to ensure no garbage data is used
void initdesub(char *desub){
    int i = 0;
    while (desub[i] != '\0') {
        desub[i] = '\0';
        i++;
    }  
}

//initialises string 'find' with \0 characters, ensures when writing to string that '\0' is definitely present to ensure no garbage data is used
void initfind(char *find) {
    int i = 0;
    while (find[i] != '\0') {
        find[i] = '\0';
        i++;
    }
}

//This function converts all characters to uppercase in string 'encryptstr'
void upperenstr(char *encryptstr) {
    int i = 0;
    while (encryptstr[i] != '\0') { 
        encryptstr[i] = (toupper(encryptstr[i])); 
        i++;
    }
}  
//This function converts all charaters to uppercase in string 'str'
void upperstr(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        str[i] = (toupper(str[i]));
        i++;
    }
}  
  
//this function counts how many words are in string 'str' using the amount of spaces present in string.
int nowords(char *str, int N) {
    int j = 0;
    int words = 0;
    for (j = 0; j < N; j++) {
        if (str[j] == ' ') {
            words++;   
        }
    }
return words + 1; //+1 counts the first word in string.
}
    
//this function identifies whether there are any punctuation present in string 'word', return 1 or 0, 1 indicating punctuation present.
int containspunc(char *word, int K) {
    int j = 0;
    int r = 0;
    while (j <= K) {
        if ((word[j] >= 33 && word[j] <= 64) || (word[j] >= 91 && word[j] <= 96) || (word[j] >= 123 && word[j] <= 126)) {
        // punctuation and special character ascii codes are between 33-64, 91-96 and 123-126
        r = 1;
        }
    j++;
    }
return r;
}
     
/*
This function accepts strings alphabet, subkey, desub and str and compares characters in str, subkey and alphabet
and in turn encrypts the result into string ensub.

*/   
void encryptsub(char *alphabet, char *subkey, char *ensub, char *str) {
    int n = 0;
    int m = 0;
    int found = 0;
    for (m = 0; m < strlen(str); m++) { //loops through str for its entire length to perform the next loop on each character
        found = 0; // found is used for deducing special characters and spaces. reset to 0 so it may be used again.
            for (n = 0; n <= 26; n++) { //loops through each charater in str, checking which postion it matches in alphabet and then replaces with same position in subkey string. 
                if (str[m] == alphabet[n]) {
                      ensub[m] = subkey[n];
                      found = 1; //set to 1 if character was found.
                }
            }
        if (found == 0) { //if letter not found in subkey it is assumed characters is not a letter. does not need to be encrypted
        ensub[m] = str[m];
        }
    }
}

/*
This function accepts strings alphabet, subkey, desub and str and compares characters in str, subkey and alphabet
and in turn decrypts the result into string desub.
*/

void decryptsub(char *alphabet, char *subkey, char *desub, char *str) {
    int n = 0;
    int m = 0;
    int found = 0;
    for (m = 0; m < strlen(str); m++) { //loops through str for its entire length to perform the next loop on each character
        found = 0; // found is used for deducing special characters and spaces. reset to 0 so it may be used again.
            for (n = 0; n <= 26; n++) { //loops through each charater in str, checking which postion it matches in subkey and then replaces with same position in alphabet string. 
                if (str[m] == subkey[n]) {
                      desub[m] = alphabet[n];
                      found = 1; //set to 1 if character was found.
                }
            }
        if (found == 0) { //if letter not found in subkey it is assumed characters is not a letter. does not need to be decrypted
        desub[m] = str[m];
        }
    }
}
