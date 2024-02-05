//Problem - 10 
        /*Write a program to demonstrate the merge sort and display the result for each intermediate
        step for the following initial array of elements.
        Input: arr = {8, 17, 18, 9, 10, 2, 5, 12} */

#include <stdio.h>

void Merge(int Arr[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    int ArrL[n1];
    int ArrR[n2];

    // Copy data to temporary arrays ArrL[] and ArrR[]
    for (int i = 0; i < n1; i++)
        ArrL[i] = Arr[p + i];
    for (int j = 0; j < n2; j++)
        ArrR[j] = Arr[q + 1 + j];

    // Merge the two arrays back into Arr[]
    int i = 0, j = 0, k = p;
    while (i < n1 && j < n2) {
        if (ArrL[i] <= ArrR[j]) {
            Arr[k] = ArrL[i];
            i++;
        } else {
            Arr[k] = ArrR[j];
            j++;
        }
        k++;
    }

    
    while (i < n1) {
        Arr[k] = ArrL[i];
        i++;
        k++;
    }


    while (j < n2) {
        Arr[k] = ArrR[j];
        j++;
        k++;
    }
}

void MergeSort(int Arr[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        MergeSort(Arr, p, q);
        MergeSort(Arr, q + 1, r);
        Merge(Arr, p, q, r);
    }
}

void ViewArr(int Arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", Arr[i]);
    }
    printf("\n");
}

int main(void) {
    int Arr[] = {8, 17, 18, 9, 10, 2, 5, 12};
    int size = sizeof(Arr) / sizeof(Arr[0]);

    printf("Original array: ");
    ViewArr(Arr, size);

    MergeSort(Arr, 0, size - 1);

    printf("Sorted array: ");
    ViewArr(Arr, size);

    return 0;
}
