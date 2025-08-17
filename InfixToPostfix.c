#include <stdio.h>
#include <ctype.h>
#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char operator){
    if(top == SIZE-1){
        printf("Stack Overflow!");
    }
    else{
        stack[++top] = operator;
    }
}

char pop(){
    if(top<0){
        printf("Stack Underflow!");
        return '\0';
    }
    else{
        return (stack[top--]);
    }
}

int priority(char op){
    if(op == '('){
        return 0;
    }
    else if (op == '+' || op == '-'){
        return 1;
    }
    else if (op == '*' || op == '/'){
        return 2;
    }
    else{
        // printf("Invalid Operator");
        return -1;
    }   
}

int main(){
    char infix[20], postfix[20], ch;
    int i;

    printf("Enter the Infix Expression: ");
    scanf("%s", infix);

    for(i=0; infix[i] != '\0'; i++){
        if(isalnum(infix[i])){
            printf("%c", infix[i]);
        }
        else if (infix[i] == '('){
            push('(');
        }
        else if(infix[i] == ')'){
            while((ch = pop()) != '('){
                printf("%c", ch);
            }
        }
        else{
            while (priority(stack[top]) >= priority(infix[i])){
                printf("%c", pop());
            }
            push(infix[i]);
        }
    }

    while(top != -1){
        printf("%c", pop());
    }

    return 0;
}