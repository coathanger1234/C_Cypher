#include <stdio.h>

char str1;
char str2;

void encryptR();
//void encryptS();
void decryptR();
//void decryptS();


int main()
{
    FILE *Input, *Output; 
    FILE *input = fopen("Input","r");
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
    }
}

    /*else if(str1 == 'b'){
        printf("Would you like to:\n a) Encrypt message\n b) Decrypt message");
        scanf("%s", &str2);
        printf("after scan\n");
        if(str2 == 'a'){
            printf("ENCRYPT S\n"){
        }else if(str2 == 'b'){
            printf("DECRYPT S\n");
        }else{
            printf("ERROR");    
        }
    }else{
        printf("ERROR");       
    }
    return 0;
}
*/
void encryptR(){    
    FILE *Input, *Output;
    FILE *input = fopen("Input","r");
    FILE *output = fopen("Output", "a+");
    
    int moveAmount = 0;
    
    printf("By how much do you wish to move the letters:\n");
    
    scanf("%d", &moveAmount);
    
    //printf("%d",moveAmount);
    
    char string[1024];
    
    if(input == NULL){ 
        perror("fopen()");
        return;
    }else{
        while(!feof(input)){
            fscanf(input, "%c", string);
            
            printf("%c %d\n", string[0], string[0]);
            if(string[0] == '\n'){
                fprintf(output, "%c", string);
            }
        }
    }
    
}
//void encryptS(){
//    String word[] = "a";
//}
void decryptR(){
    char word[] = "b";
    int i = 0;
    printf("%c\n", word[i]);
}
//void decryptS(){
//    String word[] = "a";
//}