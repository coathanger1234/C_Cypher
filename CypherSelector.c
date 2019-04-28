#include <stdio.h>

char str1;
char str2;

void encryptR();
void encryptS();
void decryptR();
//void decryptS();


int main()
{
    printf("Which cypher would you like to use?\n a) Rotation Cypher\n b) Substitution Cypher\n");
    scanf("%s", &str1);
    if(str1 == 'a'){
        printf("Would you like to:\n a) Encrypt message\n b) Decrypt message\n");
        scanf("%s", &str2);
        if(str2 == 'a'){
            encryptR(); 
        }else if(str2 == 'b'){
            decryptR();
        }else{
            printf("ERROR");
        }
        return 0;
    }

    else if(str1 == 'b'){
        printf("Would you like to:\n a) Encrypt message\n b) Decrypt message\n");
        scanf("%s", &str2);
        printf("after scan\n");
        if(str2 == 'a'){
            encryptS();
            return 0;
        }else if(str2 == 'b'){
            printf("DECRYPT S\n");
            return 0;
        }else{
            printf("ERROR");    
        }
    }else{
        printf("ERROR");       
    }
    return 0;
    }

void encryptR(){    

}






void encryptS(){
    
   FILE *OutputSE;
    FILE *output = fopen("OutputSE", "a");
char alphabet[1024];
    // = "ABCDEFGHIJKLMNOPQRWSTUVWXYZ"
    char alphabet2[1024] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    int b = 0;
    char String[1024];
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
    
    printf("Please enter a message");
    
    scanf("%[^\n]%*c",String);
    printf("%s\n", alphabet);
    printf("%s\n",String);
    //printf("\n");

    //printf("\n Please enter the 'key' for the encryption (Use only the letters of the alphabet)\n");
    //printf("An example of how the 'key' should look would be as follows: QWERTYUIOPASDFGHJKLZXCVBNM\n");
    //scanf("%s", alphabet2);

    //printf("%s", alphabet2);

    for(int i = 0; String[i] != 0; i++){
        if(String[i] <= 122 && String[i] >= 97){
            String[i] = String[i] - 32;
            //printf("%c", String[i]);
        }
        
        for(int x = 0; alphabet[x] != 0; x++){
            if(String[i] == alphabet[x]){
                //printf("%i:%i   MATCH\n",i,x);
                String2[i] = alphabet2[x];
            }else if(String[i] == 32){
                String2[i] = 32;
            }
        }
       //printf("%s\n",String);
    }

    printf("%s\n",String2);
    fprintf(output,"%s\n",String2);
    fclose(output);


}




void decryptR(){
    char word[] = "b";
    int i = 0;
    printf("%c\n", word[i]);
}
//void decryptS(){
//    String word[] = "a";
//}