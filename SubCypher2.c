#include <stdio.h>

int main(){
    char alphabet[1024];
    // = "ABCDEFGHIJKLMNOPQRWSTUVWXYZ"
    char alphabet2[1024] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    int b = 0;
    char String[1024] = "THIS STILL DOESNT WORK";
    char String2[1024];
    char choiceSwap;
    char choice;
    char temp;

    //Makes an alphabet array
    for(int y = 65; y <= 90; y++){
       alphabet[b] = y;
       //printf("%c\n", alphabet[y]);
       b++;
    }

    printf("%s\n", alphabet);
    printf("%s\n",String);
    //printf("\n");

    //printf("\n Please enter the 'key' for the encryption (Use only the letters of the alphabet)\n");
    //printf("An example of how the 'key' should look would be as follows: QWERTYUIOPASDFGHJKLZXCVBNM\n");
    //scanf("%s", alphabet2);

    //printf("%s", alphabet2);

    for(int i = 0; String[i] != 0; i++){
        for(int x = 0; alphabet[x] != 0; x++){
            if(String[i] == alphabet[x]){
                printf("%i:%i   MATCH\n",i,x);
                String2[i] = alphabet2[x];
            }else if(String[i] == 32){
                String2[i] = 32;
            }
        }
    }
    printf("%s\n",String2);

    return 0;
}
