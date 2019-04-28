#include <stdio.h>

int main(){
    //Opening files, setting var anems to files
    FILE *OutputSE,*InputSE;
    FILE *input = fopen("InputSE", "r");
    FILE *output = fopen("OutputSE", "a");

    //testing files if they can be opened
    if(input == NULL){
        perror("Input not found");
        return 0;
    }
    if(output == NULL){
        perror("Output not found");
        return 0;
    }






    //Actual section that does the encryption
    //runs until end of file reached
    while(!feof(input)){
        //variable to hold the normal alphabet
        char alphabet[1024];

        //Asigns the Encryption key to this variable

        char alphabet2[1024];


        fgets(alphabet2,200,input);





        int b = 0;
        //Assigns the message to be encrypted to a var
        
        char String[3072];

        fgets(String,200,input);

        char String2[3072];










        //Makes an alphabet array
        for(int y = 65; y <= 90; y++){
           alphabet[b] = y;
           b++;
        }
        //Checks if all char is uppercase
        for(int i = 0; String[i] != 0; i++){
            if(String[i] <= 122 && String[i] >= 97){
                String[i] = String[i] - 32;
            }
        //changes char depending on position in alphabet[]
            for(int x = 0; alphabet[x] != '\0'; x++){
                if(String[i] == alphabet[x]){
                    String2[i] = alphabet2[x];

                }else if(String[i] == 32){

                    String2[i] = 32;
                }
            }
        }
        fprintf(output, "%s", alphabet2);
        fprintf(output, "%s\n", String2);
    }
    return 0;
}