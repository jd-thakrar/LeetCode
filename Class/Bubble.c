#include<stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int n;
    printf("Enter the no. of elemnet: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elemnets: ");

    for(int i = 0; i<n ;i++){
        scanf("%d", &arr[i]);
    }

    printf("Array before the sorting: ");
    for(int i = 0;i<n;i++){
        printf("%d ", arr[i]);
    }

    for(int i = 0; i <n; i++){
        for(int j = 0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }

    printf("\nArray after the sorting: ");
    for(int i = 0;i<n;i++){
        printf("%d ", arr[i]);
    }

    return 0;
}