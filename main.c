#include <stdio.h>
#include <math.h>

void display_menu(){
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Exponentiate\n");
    printf("Please select a command: ");
}

int main(){
    int com = 0;
    float n1, n2;
    display_menu();
    scanf("%d", &com);
    printf("\n");
    while(com < 1 || com > 5){
        printf("Please enter a number between 1 and 5: ");
        scanf("%d", &com);
        printf("\n");
    }
    printf("Enter first number: ");
    scanf("%f", &n1);
    printf("\n");
    printf("Enter second number: ");
    scanf("%f", &n2);
    printf("\n");
    switch(com){
        case 1:
            printf("Result of addition is: %.2f\n", n1+n2);
            break;
        case 2:
            printf("Result of subtraction is: %.2f\n", n1-n2);
            break;
        case 3:
            printf("Result of multiplication is: %.2f\n", n1*n2);
            break;
        case 4:
            printf("Result of division is: %.2f\n", n1/n2);
            break;
        case 5:
            printf("Result of exponentiation is: %.2f\n", powf(n1,n2));
            break;
    }
    return 0;
}