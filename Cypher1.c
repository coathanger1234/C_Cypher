#include <stdio.h>

char str;

const char* encryptR(const char* a);
const char* encryptS(const char* a);
const char* decryptR(const char* a);
const char* decryptS(const char* a);


int main()
{
    
    printf("Which cypher would you like to use?\n a) Rotation Cypher\n b) Substitution Cypher\n");
    
    scanf("%c", &str);
    
    if(str == 'a'){
    
        printf("Would you like to:\n a) Encrypt message\n b) Decrypt message");
        
    }else if(str == 'b'){
    
        printf("Would you like to:\n a) Encrypt message\n b) Decrypt message");
        
    }else{
        printf("ERROR");
        
    }
    return 0;
}

/*const char* encryptR(const char* a){
    
}*/
