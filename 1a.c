#include <stdio.h>

int main() {
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    if(n < 2) {
        printf("Need at least two elements");
        return 0;
    }

    int arr[n];
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int smallest = arr[0], second = arr[1];

    if(smallest > second) {
        int temp = smallest;
        smallest = second;
        second = temp;
    }

    for(i = 2; i < n; i++) {
        if(arr[i] < smallest) {
            second = smallest;
            smallest = arr[i];
        }
        else if(arr[i] < second && arr[i] != smallest) {
            second = arr[i];
        }
    }

    printf("Second smallest element = %d", second);

    return 0;
}