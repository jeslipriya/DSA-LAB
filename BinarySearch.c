#include <stdio.h>

int main() {
    int n, key, mid, low = 0, high, i, arr[100], found = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the sorted elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter an element to search: ");
    scanf("%d", &key);

    high = n - 1;

    while(low <= high) {
        mid = (low + high) / 2;
        if(arr[mid] == key) {
            printf("Element found at position %d (index %d)\n", mid + 1, mid);
            found = 1;
            break;
        } else if(arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if(!found) {
        printf("%d is not found in the array!\n", key);
    }

    return 0;
}
