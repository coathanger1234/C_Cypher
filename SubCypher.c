#include <stdio.h>

int main(){
    char alphabet[25];
    int b = 0;
    char String[1024] = "We Strike At Dawn";
    char choiceSwap;
    char choice;
    char temp;
    for(int i = 65; i <= 90; i++){
       alphabet[b] = i;
       b++;
    }
    printf("\n");
    printf("Which letter in the alphabet would you like to swap would you like to swap?\n");
    scanf("%s", &choiceSwap);
    //printf("%c\n", choiceSwap);
    
    printf("What letter would you like this letter to be swapped with?\n");
    scanf("%s", &choice);
    if(choice == choiceSwap){
        printf("Please select another letter");
    }else{
        for(int i = 0; i < 25; i++){
            if(String[i] == choiceSwap){
                temp = choiceSwap;
                choiceSwap = choice;
                choice = temp;
            }
        }
        for(int i = 0; i < 25; i++){
            printf("%c", alphabet[i]);
        }
    }
    
    return 0;
}