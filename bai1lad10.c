#include <stdio.h>
#include <stdlib.h>

// ========== MERGE SORT ==========
void merge(int a[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; ++i) L[i] = a[l + i];
    for (int j = 0; j < n2; ++j) R[j] = a[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
        a[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];

    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int m = (l + r)/2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

// ========== RADIX SORT ==========
int getMax(int a[], int n) {
    int mx = a[0];
    for(int i = 1; i < n; i++)
        if(a[i] > mx) mx = a[i];
    return mx;
}

void countingSort(int a[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    for(int i = 0; i < n; i++)
        count[(a[i] / exp) % 10]++;

    for(int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for(int i = n - 1; i >= 0; i--) {
        output[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }

    for(int i = 0; i < n; i++)
        a[i] = output[i];
}

void radixSort(int a[], int n) {
    int m = getMax(a, n);
    for(int exp = 1; m/exp > 0; exp *= 10)
        countingSort(a, n, exp);
}

// =====================================
int main() {
    int a[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(a)/sizeof(a[0]);

    // ch?n cái nào b?n test
    // mergeSort(a, 0, n - 1);
    radixSort(a, n);

    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}

