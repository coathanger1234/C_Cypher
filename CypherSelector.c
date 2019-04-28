#include <stdio.h>

char str1;
char str2;

void encryptR();
void encryptS();
void decryptR();
void decryptS();


int main()
{
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
        return 0;
    }

    else if(str1 == 'b'){
        printf("Would you like to:\n a) Encrypt message\n b) Decrypt message\n");
        scanf("%s", &str2);
        printf("after scan\n");
        if(str2 == 'a'){
            encryptS();
            return 0;
        }else if(str2 == 'b'){
            decryptS();
            return 0;
        }else{
            printf("ERROR");    
        }
    }else{
        printf("ERROR");       
    }
    return 0;
    }






void encryptS(){
    
   //Opening files, setting var anems to files
    FILE *OutputSE,*InputSE;
    FILE *input = fopen("InputSE", "r");
    FILE *output = fopen("OutputSE", "a");

    //testing files if they can be opened
    if(input == NULL){
        perror("Input not found");

    }
    if(output == NULL){
        perror("Output not found");

    }
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
        //Goes through all char within String and changes all lowercase char to uppercase
        for(int i = 0; String[i] != 0; i++){
            if(String[i] <= 122 && String[i] >= 97){
                String[i] = String[i] - 32;
            }
        //Compares a char in String to all char in alphabet, when a match has been found, it will take the position of the match and add the same char in the position within alphabet2 and add it to String2
            for(int x = 0; alphabet[x] != '\0'; x++){
                if(String[i] == alphabet[x]){
                    String2[i] = alphabet2[x];
        //Checks for spaces, leaves them in
                }else if(String[i] == 32){

                    String2[i] = 32;
                }
            }
        }
        fprintf(output, "%s", alphabet2);
        fprintf(output, "%s\n", String2);
    }
    fclose(input);
    fclose(output);


}




void decryptS(){
    FILE *OutputSE,*InputSE;
    FILE *input = fopen("InputSD", "r");
    FILE *output = fopen("OutputSD", "a");
    
    
     if(input == NULL){
        perror("Input not found");
    }
    if(output == NULL){
        perror("Output not found");
    }
    
    while(!feof(input)){
        
        char key[1024];
        
        fgets(key,200,input);

        char alphabet[1024];
        
        int b = 0;
        
        char String[3072];

        fgets(String,200,input);

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

}
void decryptR(){
        //Marking files for input and output
    FILE *InputDC,*OutputDC;
    FILE *input = fopen("InputCE","r");
    FILE *output = fopen("OutputCD", "a+");
    
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
    }
}
void encryptR(){
    //Marking files for input and output
    FILE *OutputCE, *InputCE;
    FILE *output = fopen("OutputCE", "a");
    FILE *input = fopen("InputCE","r");
    
    //Checking if files is working
    if(output == NULL){
        perror("Output not found");
    }
    if(input == NULL){
        perror("Input not found");
    }
    
    int r;
    
    char String[1024];
    while(!feof(input)){
        
        fscanf(input,"%d",&r);
        //printf("%d", r);
        
        fgets(String, 200, input);
        
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
}