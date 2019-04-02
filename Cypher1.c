#include <stdio.h>

char str1;
char str2;

const char* encryptR(const char* a);
const char* encryptS(const char* a);
const char* decryptR(const char* a);
const char* decryptS(const char* a);


int main()
{ 
    
    printf("Which cypher would you like to use?\n a) Rotation Cypher\n b) Substitution Cypher\n");
    
    scanf("%s", &str1);
    
    if(str1 == 'a'){
    
        printf("Would you like to:\n a) Encrypt message\n b) Decrypt message");
        
        scanf("%s", &str2);
        
        if(str2 == 'a'){
            printf("ENCRYPT R\n");
        }else if(str2 == 'b'){
            printf("DECRYPT R\n");
        }else{
            printf("ERROR");
        }
        
    }else if(str1 == 'b')
    {
    
        printf("Would you like to:\n a) Encrypt message\n b) Decrypt message");
        
        scanf("%s", &str2);
        
        printf("after scan\n");
        if(str2 == 'a'){
            printf("ENCRYPT S\n");
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

/*const char* encryptR(const char* a){
    
}*/
