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
    
        printf("A");
        
    }else if(str == 'b'){
    
        printf("B");
        
    }else{
        printf("ERROR");
        
    }
    return 0;
}
