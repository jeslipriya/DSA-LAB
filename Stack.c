#include <stdio.h>
#include <stdlib.h>
#define MAX 5

static int stack[MAX];
int top = -1;

void push(int x){
    stack[++top] = x;
}

int pop(){
    return (stack[top--]);
}

void view(){
    int i;
    if(top<0){
        printf("Stack Underflow!");
    }

    else{
        printf("\nTop ->");
        for(i=top; i>=0; i--){
            printf("%4d", stack[i]);
        }
        printf("\n");
    }
}

int main(){
    int ch=0, val;

    while (ch != 4)
    {
        printf("---STACK OPERATIONS---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. View\n");
        printf("4. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch){
            case 1:
                if(top == MAX-1){
                    printf("Stack Overflow!");
                    break;
                }
                else{
                    printf("Enter stack Element: ");
                    scanf("%d", &val);
                    push(val);
                    break;
                }
                

            case 2:
                if(top<0){
                    printf("Stack Underflow!");
                    break;
                }

                else{
                    val = pop();
                    printf("Poped element: %d", val);
                    break;
                }

            case 3:
                view();
                break;

            case 4:
                printf("Exiting the program!");
                exit(0);

            default:
                printf("Enter the valid choice");
                break;            
        }
    }
    
    return 0;
}