#include <stdio.h>

int main()
{
    FILE *Input,*Output;
    FILE *input = fopen("Input","r");
    FILE *output = fopen("Output", "a+");
    
    int r;
    char String[1024];
    printf("%s\n",String);
    printf("Rotations: \n");
    scanf("%d", &r);
    //printf("%d\n", r);
    if(r > 0){
        char letter;
        //printf("%d",r);
        for(int p = 0; p < r; p++){
            for(int i = 0; String[i] != 0 ;i++){
                letter = String[i];
                letter++;
                
                
                /*if(String[i] > 64 && String[i] < 123){
                    if(String[i] < 91||String[i] > 96){
                        letter++; 
                    }
                }else{
                    continue;
                }*/
                
                switch(letter){
                    case 64:
                        String[i] = 90;
                        break;
                    case 91:
                        String[i] = 65;
                        break;
                    case 96:
                        String[i] = 122;
                        break;
                    case 122:
                        String[i] = 97;
                        break;
                    case 33:
                        String[i] = 32;
                        break;
                    default:
                        String[i] = letter;
                        break;
                }
                
                //printf("%c", letter);
                //printf("%c\n",String[i]);
            }
            //printf("%c", letter);
        }
        for(int i = 0; String[i] != 0; i++){
            printf("%c", String[i]);
        }
        
        
        //DOESNT WORK, FIX NEG. NUMBERS
    }if(r < 0){
        char letter;
        //printf("%d",r);
        for(int p = 0; p < r; p--){
            for(int i = 0; String[i] != 0 ;i++){
                letter = String[i];
                letter--;
                
                
                /*if(String[i] > 64 && String[i] < 123){
                    if(String[i] < 91||String[i] > 96){
                        letter++; 
                    }
                }else{
                    continue;
                }*/
                
                switch(letter){
                    case 64:
                        String[i] = 90;
                        break;
                    case 91:
                        String[i] = 65;
                        break;
                    case 96:
                        String[i] = 122;
                        break;
                    case 122:
                        String[i] = 97; 
                        break;
                    case 33:
                        String[i] = 32;
                        break;
                    default:
                        String[i] = letter;
                        break;
                }
                
                //printf("%c", letter);
                //printf("%c\n",String[i]);
            }
            //printf("%c", letter);
        }
        for(int i = 0; String[i] != 0; i++){
            printf("%c", String[i]);
        }
    }


    return 0;
}
