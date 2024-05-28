#include <stdio.h>
#include <math.h>
#include <pthread.h>
#include <malloc.h>

struct threadArgs{
    float n1, n2;
    int op_id;
};

void display_menu(){
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Exponentiate\n");
    printf("6. Display All\n");
    printf("Please select a command: ");
}

void print_operation(float n1, float n2, int op_id){
    if(op_id == 1)
        printf("Result of addition is: %.2f\n", n1+n2);
    else if(op_id == 2)
        printf("Result of subtraction is: %.2f\n", n1-n2);
    else if(op_id == 3)
        printf("Result of multiplication is: %.2f\n", n1*n2);
    else if(op_id == 4)
        printf("Result of division is: %.2f\n", n1/n2);
    else if(op_id == 5)
        printf("Result of exponentiation is: %.2f\n", pow(n1,n2));
}

void* print_withThreads(void* args){
    struct threadArgs *currArgs = (struct threadArgs*)args;
    print_operation(currArgs->n1, currArgs->n2, currArgs->op_id);
    free(args);
    return NULL;
}

int main(int argc, char *argv[]){
    pthread_t t[5];
    int com = 0;
    float n1, n2;
    display_menu();
    scanf("%d", &com);
    printf("\n");
    while(com < 1 || com > 6){
        printf("Please enter a number between 1 and 6: ");
        scanf("%d", &com);
        printf("\n");
    }
    printf("Enter first number: ");
    scanf("%f", &n1);
    printf("\n");
    printf("Enter second number: ");
    scanf("%f", &n2);
    printf("\n");
    if(com >= 1 && com <= 5)
        print_operation(n1, n2, com);
    else {
        for(int i = 0; i < 5; i++) {
            struct threadArgs *args = malloc(sizeof(struct threadArgs));
            args->n1 = n1;
            args->n2 = n2;
            args->op_id = i + 1;
            pthread_create(&t[i], NULL, print_withThreads, (void *) args);
        }
        for(int i = 0; i < 5; i++) {
            pthread_join(t[i], NULL);
        }
    }
    return 0;
}
