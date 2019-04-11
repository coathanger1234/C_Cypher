#include <stdio.h>

int main()
{
    char String[1024] ="ZZZZZZZZZZZZZZ";
    printf("%s\n",String);
    for(int i = 0; String[i] != 0 ;i++){
        char letter = String[i];
        letter =+ 2;
        
        
        /*if(String[i] > 64 && String[i] < 123){
            if(String[i] < 91||String[i] > 96){
                letter++; 
            }
        }else{
            continue;
        }*/
        
        switch(letter){
            case 64:
                letter = 90;
                break;
            case 91:
                letter = 65;
                break;
            case 96:
                letter = 122;
                break;
            case 122:
                letter = 97;
                break;
            case 33:
                letter = 32;
                break;
            default:
                break;
        }
        printf("%c", letter);
        //printf("%c\n",String[i]);
    }
    return 0;
}
