
#include <stdio.h>
//Basically does what the Sub Cypher does, but reverses the alphabet
int main(){
    
    FILE *OutputSE,*InputSE;
    FILE *input = fopen("InputSD", "r");
    FILE *output = fopen("OutputSD", "a");
    
    
     if(input == NULL){
        perror("Input not found");
        return 0;
    }
    if(output == NULL){
        perror("Output not found");
        return 0;
    }
    
    while(!feof(input)){
        
        char key[1024];
        
        fgets(key,200,input);
        
        printf("%s", key);

        char alphabet[1024];
        
        int b = 0;
        
        char String[3072];

        fgets(String,200,input);
        
        printf("%s", String);

        char String2[3072];
        
        for(int y = 65; y <= 90; y++){
           alphabet[b] = y;
           b++;
        }
        for(int i = 0; String[i] != 0; i++){
            if(String[i] <= 122 && String[i] >= 97){
                String[i] = String[i] - 32;
            }
            for(int x = 0; alphabet[x] != '\0'; x++){
                if(String[i] == key[x]){
                    String2[i] = alphabet[x];

                }else if(String[i] == 32){

                    String2[i] = 32;
                }
            }
        }
        fprintf(output, "%s", key);
        fprintf(output, "%s\n", String2);

        
    }
    fclose(input);
    fclose(output);

    return 0;
}