#include <stdio.h>
#include <ctype.h>
#define SIZE 100

int stack[SIZE];
int top = -1;

void push(int value){
    if(top == SIZE-1){
        printf("Stack Overflow!");
    }

    else{
        stack[++top] = value;
    }
}

int pop(){
    if(top<0){
        printf("Stack Underflow!");
    }
    else{
        return (stack[top--]);
    }
}

int evaluatePostfix(const char *expression){
    for(int i=0; expression[i] != '\0'; i++){
        char ch = expression[i];

        if(isdigit(ch)){
            push(ch - '0');
        }

        else{
            int op1 = pop();
            int op2 = pop();

            switch (ch){
                case '+':
                    push(op1 + op2);
                    break;

                case '-':
                    push(op1 - op2);
                    break;

                case '*':
                    push(op1 * op2);
                    break;

                case '/':
                    push(op1 / op2);
                    break;
                
                default:
                    printf("Invalid Operator");
                    break;
            }
        }
    }

    return pop();
}

int main(){
    char postfix[SIZE];

    printf("Enter the postfix expression: ");
    scanf("%s", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result = %d", result);

    return 0;
}