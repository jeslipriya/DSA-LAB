#include <stdio.h>

int main(){
    int arr[50], n, i, search, found=0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    printf("Enter the elements: ");
    for(i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }

    printf("Enter a number to be searched: ");
    scanf("%d", &search);

    for(i=0;i<n;i++){
        if(search == arr[i]){
            printf("%d found at position %d", search, i+1);
            found = 1;
        }
    }

    if(!found){
        printf("%d is not found in the array!", search);
    }

    return 0;
}