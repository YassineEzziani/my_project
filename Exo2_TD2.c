//Question 1
#include <stdbool.h>

void swap_int(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

bool is_sorted_ascending(int A[], int n) {
    if (n <= 1) {
        return true;
    }
    for (int i = 1; i < n; i++) {
        if (A[i] < A[i - 1]) {
            return false;
        }
    }
    return true;
} 

void copy_array(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

//Question 2

int selection_sort(int A[],int n){
    for (int i = 0; i < n - 2 ; i++)
    {
        int min = i;
        for (int j = i + 1 ; j < n - 1 ; j++)
        {
            if (A[j]<A[min])
                min = j ;
        }
        swap_int(A[i],A[min]);
    }
    return A;
}
//Worst case complexity: O(n^2)

//Question 3

int insertion_sort(int A[],int n){
    for (int i = 1 ; i < n - 1 ; i++)
    {
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key )
        {
            A[j+1] = A[j];
            j = j - 1;
        }
        A[j+1] = key;
    }
}