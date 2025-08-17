#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int main(){
    int i, arr[SIZE], n, choice, element, pos;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    do{
        printf("---ARRAY OPERATIONS---\n");
        printf("1. Display Array\n");
        printf("2. Insert ELements\n");
        printf("3. Delete Elements\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                printf("Array: ");
                for(i=0; i<n; i++){
                    printf("%d", arr[i]);
                    printf("\n");
                }
                break;

            case 2:
                if(n == SIZE){
                    printf("Array is full!\n");
                    break;
                }
                else{
                    printf("Enter the element to insert: ");
                    scanf("%d", &element);

                    printf("Enter the position to insert: ");
                    scanf("%d", &pos);

                    if(pos<0|| pos>n){
                        printf("Invalid position!\n");
                    }
                    else{
                        for(i=n; i>pos; i--){
                            arr[i] = arr[i-1];
                        }

                        arr[pos] = element;
                        n++;
                        printf("Successfully Inserted!\n");
                    }
                }
                break;

            case 3:
                if(n==0){
                    printf("Array is empty!\n");
                    break;
                }
                else{
                    printf("Enter the position to delete (0 to %d): ", n-1);
                    scanf("%d", &pos);

                    if(pos<0 || pos>n){
                        printf("Invalid position!\n");
                    }
                    else{
                        for(i=pos; i<n; i++){
                            arr[i] = arr[i+1];
                        }
                        n--;
                        printf("Successfully deleted!\n");
                    }
                }
                break;
                
            case 4:
                printf("Exiting the program!\n");
                exit(0);
            
            default:
                printf("Invalid choice\n");
                break;
        }
    } while(choice != 4);

    return 0;
}
