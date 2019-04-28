#include <stdio.h>

int main(){
    
    //Marking files for input and output
    FILE *OutputCE, *InputCE;
    FILE *output = fopen("OutputCE", "a");
    FILE *input = fopen("InputCE","r");
    
    //Checking if files is working
    if(output == NULL){
        perror("Output not found");
        return 0;
    }
    if(input == NULL){
        perror("Input not found");
        return 0;
    }
    
    int r;
    
    char String[1024];
    while(!feof(input)){
        
        int i = 0;
        
        fscanf(input,"%d",&r);
        //printf("%d", r);
        
        fgets(String, 200, input);
       
        printf("%s", String);
        
        if(r > 0){
            
            char letter;
            
            for(int p = 0; p < r; p++){
                
                for(int i = 0; String[i] != 0 ;i++){
                    
                    letter = String[i];
                    
                    letter++;
                    
                    
                    //printf("%d\n", letter);
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
                    //printf("%c\n",String[i]);
                }
            }
        }else if(r < 0){
            char letter;
            for(int p = 0; p > r; p--){
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
        }
        fprintf(output,"%d\n",r);
        fprintf(output,"%s\n",String);
    }
    fclose(input);
    fclose(output);
    return 0;
}
