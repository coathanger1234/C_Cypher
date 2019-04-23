#include <stdio.h>

int main(){
    char alphabet[26];
    int b = 0;
    char String[1024] = "We Strike At Dawn";
    char choiceSwap;
    char choice;
    char temp;
    
    //Makes an alphabet array
    for(int i = 65; i < 91; i++){
       alphabet[b] = i;
       b++;
    }
    printf("%s", alphabet);
    
    printf("\n");
    printf("Which letter in the alphabet would you like to swap would you like to swap?\n");
    scanf("%s", &choice);
    //printf("%c\n", choiceSwap);
    
    printf("What letter would you like this letter to be swapped with?\n");
    scanf("%s", &choiceSwap);
    if(choice == choiceSwap){
        printf("Please select another letter\n");
    }else{
        for(int i = 0; i < 25; i++){
            if(String[i] == choiceSwap){
                temp = choiceSwap;
                choiceSwap = choice;
                choice = temp;
            }
        }
        for(int i = 0; i < 26; i++){
            printf("%c\n", alphabet[i]);
        }
    }
    
    return 0;
}