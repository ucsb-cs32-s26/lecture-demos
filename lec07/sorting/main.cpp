#include "sorting.h"
#include<string>
#include<iostream>
void printArray(std::string msg, int a[], int n)  {
    std::cout << msg <<" ";
    for(int i=0; i<n; i++) {
        std::cout<<a[i]<<" ";
    }
    std::cout<<"\n";
}

int main() {
    int arr1[]{7,3,8,1,2};
    int n1 = 5;

    printArray("before\t", arr1, n1);
    selectionSort(arr1, n1);
    printArray("after\t", arr1, n1);

    int arr2[]{7,3,8,1,2};
    int n2 = 5;

    printArray("before\t", arr2, n2);
    insertionSort(arr2, n2);
    printArray("after\t", arr2, n2);

    
    return 0;
}