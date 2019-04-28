#include <stdio.h>

int main()
{
    //Marking files for input and output
    FILE *InputDC,*OutputDC;
    FILE *input = fopen("InputDC","r");
    FILE *output = fopen("OutputDC", "a+");*/
    
    if(input == NULL){
        perror("Input not found");
    }
    if(output == NULL){
        perror("Output not found");
    }
    
    int r;  //var for number of rotations
    
    char String[1024];
    
    while(!feof(input)){

    fscanf(input,"%d",&r);
    
    fgets(String, 200, input);
    
    if(r > 0){

        
        char letter;

        
        for(int p = 0; p < r; p++){
            
            for(int i = 0; String[i] != 0 ;i++){
                
                letter = String[i];
                
                letter = letter - 1;
                
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
                    case 31:
                        String[i] = 32;
                        break;
                    default:
                        String[i] = letter;
                        break;
                }
            }
        }
        for(int i = 0; String[i] != 0; i++){
            printf("%c\n", String[i]);
        }
    }else if(r < 0){
        char letter;
        for(int p = 0; p > r; p--){
            for(int i = 0; String[i] != 0 ;i++){
                letter = String[i];
                letter++;
                
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
            }
        }
        fprintf(output,"%d\n",r);
        fprintf(output,"%d\n",r);
    }
    fclose(output);
    fclose(input);
    return 0;
}
