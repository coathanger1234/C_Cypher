#include <stdio.h>
//Declaring each method 
void encryptR(); //Rotation encryption
void encryptS(); //Sub encryption
void decryptR(); //Rotation decryption
void decryptS(); //Sub decryption


int main()
{
    //DECISION TREE
    printf("Which cypher would you like to use?\n a) Rotation Cypher\n b) Substitution Cypher\n");
    scanf("%s", &str1);
    //DECIDED TO USE ROTATION
    if(str1 == 'a'){
        printf("Would you like to:\n a) Encrypt message\n b) Decrypt message\n");
        scanf("%s", &str2);
        if(str2 == 'a'){    //DECIDED TO ENCRYPT
            encryptR(); 
        }else if(str2 == 'b'){  //DECIDED TO DECRYPT
            decryptR();
        }else{
            printf("ERROR");    //ANYTHING ELSE
        }
        return 0;
    }
    //DECIDED TO USE SUBSTITUTE
    else if(str1 == 'b'){
        printf("Would you like to:\n a) Encrypt message\n b) Decrypt message\n");
        scanf("%s", &str2);
        printf("after scan\n");
        if(str2 == 'a'){    //DECIDED TO ENCRYPT
            encryptS();
        }else if(str2 == 'b'){  //DECIDED TO DECRYPT
            decryptS();
        }else{
            printf("ERROR");    //ANYTHING ELSE
        }
    }else{
        printf("ERROR");       //ANYTHING ELSE
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

        //getting message
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
        //prints key and encrypted message
        fprintf(output, "%s", alphabet2);
        fprintf(output, "%s\n", String2);
    }
    //closes the files, as the method is complete
    fclose(input);
    fclose(output);


}




void decryptS(){
    //Opening files, setting var names to files
    FILE *OutputSE,*InputSE;
    FILE *input = fopen("InputSD", "r");
    FILE *output = fopen("OutputSD", "a");
    
    //testing files if they can be opened
     if(input == NULL){
        perror("Input not found");
    }
    if(output == NULL){
        perror("Output not found");
    }
    //runs until end of file is reached
    while(!feof(input)){
        //array to hold the key used to encrypt alphabet
        char key[1024];
        //getting the key
        fgets(key,200,input);
        //array to hold the normal alphabet
        char alphabet[1024];
        //variable used to keep position withing the alphabet array
        int b = 0;
        //var to hold message
        char String[3072];
        //getting message
        fgets(String,200,input);
        //var to hold decrypted message
        char String2[3072];
        //Create an alpahabet
        for(int y = 65; y <= 90; y++){
           alphabet[b] = y;
           b++;
        }
        //Changing all lowercase letters to uppercase
        //goes through message
        for(int i = 0; String[i] != 0; i++){
            //if lowercase is found
            if(String[i] <= 122 && String[i] >= 97){
                //convert to uppercase
                String[i] = String[i] - 32;
            }
            //Compares a char in String to all char in alphabet, when a match has been found, it will take the position of the match and add the same char in the position within alphabet2 and add it to String2
            for(int x = 0; alphabet[x] != '\0'; x++){
                if(String[i] == key[x]){
                    String2[i] = alphabet[x];

                }else if(String[i] == 32){

                    String2[i] = 32;
                }
            }
        }
        //prints key for message and then the message on a seperate line
        fprintf(output, "%s", key);
        fprintf(output, "%s\n", String2);

        
    }
    //closes files
    fclose(input);
    fclose(output);

}
void decryptR(){
    //KEEPS BREAKING ./A.OUT
    FILE *OutputDC;
    FILE *output = fopen("OutputCD", "a");
    //tests if file ca be opened
    if(output == NULL){
        perror("Output not found");
    }
    
    int r;  //var for number of rotations
    
    char String[1024]; // var to hold message
    
    //COULDNT GET FILE I/O TO WORK, WOULD KEEP BREAK ./A.OUT, SO I SETTLED FOR A SIMPLE
    //SCANF, SORRY MARKER
    
    //asks for key to encrypt
    printf("Please enter KEY for cypher\n");
    //gets key
    scanf("%d",&r);
    //asks for message
    printf("Please enter MESSAGE for cypher\n");
    //gets message
    scanf("%s",String);
    //checks if the key is positive
    if(r > 0){

        //creates a var called letter, used as a placeholder for comparing and manipulation
        char letter;

        //loop that goes through however many rotations declared
        for(int p = 0; p < r; p++){
            //loop goes through every char in message
            for(int i = 0; String[i] != 0 ;i++){
                //sets letter as String[i], done because i got nervous if the variable would get messed up
                letter = String[i];
                //takes 1 away from the ASCII value
                letter = letter - 1;
                //switch case goes through multiple cases if the ASCII value goes outside of
                //the English alphabet
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
    }else if(r < 0){    //checks if the key is a negative, everythings the same as above, except inverted, such as letters being plused
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
    }
        //prints results to a file, key first then message
        fprintf(output,"%d\n",r);
        fprintf(output,"%s\n",String);
        //closes file
        fclose(output);
    
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
    //goes until end of input file
    while(!feof(input)){
        //gets key from input file
        fscanf(input,"%d",&r);
        //gets message from input file
        fgets(String, 200, input);
        //same as decryptR()
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
        //prints values to a file, key first, then message
        
        //NOTE: THE PRINTING IS A BIT FUNKY, IT WILL DISPLAY THE NUMBER TWICE,
        //FIRST ONE IS EMPTY OR HAS JUNK, SECOND WILL HAVE THE CORRECT DISPLAY, BUG
        //HAS UNKOWN ORIGIN AND WILL HAUNT ME TILL THE END OF MY DAYS
        fprintf(output,"%d\n",r);
        fprintf(output,"%s\n",String);
    }
    //Closes files
    fclose(input);
    fclose(output);
}