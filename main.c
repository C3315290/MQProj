/* Main function of the C program. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void move(char *str, int N);
void returnword(char *str, char *word, int wordnumber, int N);
void init(char *word);  //sets entire word string to '\0' ensures when function returnword is run, only a word returns.
int nowords(char *str, int N);
int containspecial(;


int main()
{
    
char str[] = "pc tktg-vgdlxcv cjbqtg du rdbeatm pcs gxvxs gjath eajh wpgs-id-rdet-lxiw gtvjapixdch pgt cdl qtxcv atvxhapits ugdb hipit id hipit. ztn utstgpa gtvjapixdch ltgt udgbjapits qn iwt usp, uir, pcs iwt rehr. tprw du iwtht utstgpa pvtcrxth htgkth p hetrxuxr bxhhxdc. dct tmpbeat: aplh hedchdgts qn iwt duuxrt du iwt upxg stqi rdaatrixdc egprixrth egtktci pc pvtcrn ugdb ejgedhtujaan wpgphhxcv raxtcih xc htgxdjh stqi. iwt upxg eprzpvxcv pcs apqtaxcv pri bpzth rtgipxc iwpi egditrixdc ugdb bxhatpsxcv eprzpvxcv du vddsh xh vjpgpcitts id tprw qjntg du vddsh rpggxts xc hbpaa hwdeh ph ltaa ph xc apgvt hjetgbpgztih. egdsjrih dc iwt bpgzti bjhi gtktpa iwt cpbth du paa xcvgtsxtcih dc iwt apqta. apcvjpvt bjhi qt xc ratpg pcs egtrxht itgbh iwpi rpc qt jcstghidds qn tktgndct. iwxh egprixrt xh ktgn rgjrxpa udg iwt axkth du bpcn etdeat. xi xh egjstci iwpi lt gtrpaa iwpi iwt usp hetrxuxrpaan gtfjxgth iwpi paa vddsh pgt ejgt, hput, pcs lwdathdbt. iwt usp hipith iwpi paa vddsh qt egdsjrts jcstg wxvwan hpcxipgn rdcsxixdch. sgjvh bjhi qt rdbeatitan hput pcs bjhi pahd qt tuutrixkt udg iwtxg hipits ejgedht. iwxh edaxrn peeaxth id rdhbtixrh iwpi bjhi qt qdiw hput pcs ejgt. xcsxkxsjpah pgt duitc idipaan jcpeegtrxpixkt du iwt usp'h vgtpi stsxrpixdc.";
int i = 0;
int k = 0;
int l = 1;
int largestwordpos = 1;
int largestwordlength = 1;
char word[100];
char find[1000];
int cipherresult = 0;


init(word);
init(find);

FILE *input;
input = fopen("words.txt", "r");

while (l <= nowords(str, strlen(str))) {
    returnword(str, word, l, strlen(str));
    
    if (strlen(word) > largestwordlength) {
        largestwordpos = l;    
    }

l++;
}

returnword(str, word, largestwordpos, strlen(str));

while (i < 26) {
    move(word, strlen(word));
rewind(input);
while(fscanf(input, "%s", find) != EOF)
{
	if(strcmp(find, word) == 0)
	{
		cipherresult = i;
	}
}
    i++;
}

printf("Results: %d\n", cipherresult);

while (k < 26) {
    move(str, strlen(str));
    if (k == cipherresult) {
        printf("Decrypted: %s\n", str);
    }
     k++;
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
    
void returnword(char *str, char *word, int n, int N) 
{
    int count = 0;
    int count2 = 0;
int spaces = 0;
    if (n == 1)
   {
        while (str[count] != ' ') 
        {
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

void init(char *word) {
    int i = 0;

    while (word[i] != '\0') {
                word[i] = '\0';
                i++;
                }
    }  
    int nowords(char *str, int N) {
        int j = 0;
        int words = 0;
        for (j = 0; j < N; j++) {
        if (str[j] == ' ') {
        words++;   
                    ;
        }
}
        return words + 1;
    }