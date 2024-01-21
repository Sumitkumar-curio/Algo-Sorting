#include <stdio.h>

// Insertion sort
int main(void) {
    int i, m;
    // Enter the Number of element of Array
    printf("How many Number you want to enter ");
    scanf("%d",&m);
    
    int A[m], j, key;

    printf("Enter %d numbers in series separated by space: ", m);
    for (i = 0; i < m; i++) {
        scanf("%d", &A[i]);

    }
    // Insertion sort logic
    for(j=1;j<m;j++) {
        key =A[j];
        i= j-1;

        while(i>=0 && A[i]>key){
            A[i+1]=A[i];
            i= i-1;
        }

        A[i+1]= key;
     
    }

    printf("The sorted array is:");
          for(i=0;i<m;i++){
            printf("%d ",A[i]);
          }

    return 0;
}
