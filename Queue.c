#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

void insert(int value){
    if(front == SIZE-1){
        printf("Queue is full!\n");
    }

    else{
        rear++;
        queue[rear] = value;
        printf("Inserted Successfully!\n");
    }
}

void delete(){
    if(front == rear){
        printf("Queue is Empty!\n");
    }
    else{
        front++;
        printf("Deleted element: %d\n", queue[front]);
    }
}

void display(){
    if(front == rear){
        printf("Queue is Empty!\n");
    }
    else{
        printf("Queue Elements: \n");
        for(int i=front+1; i<=rear; i++){
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main(){
    int choice, val;

    while(1){

        printf("---QUEUE OPERATIONS---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
    
        printf("Enter your choice: ");
        scanf("%d", &choice);
    
        switch (choice){
            case 1:
                printf("Enter a value to insert: ");
                scanf("%d", &val);
                insert(val);
                break;
    
            case 2:
                delete();
                break;
    
            case 3:
                display();
                break;
    
            case 4:
                printf("Exiting the program!");
                exit(0);
            
            default:
                break;
        }
    }


    return 0;
}