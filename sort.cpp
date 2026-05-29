#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printArr(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<", ";
    }
    cout << endl;
}

void bubbleSort (int arr[], int n){
    for (int i=0; i<n-1; i++){
        bool isSwap = false;
        for (int j=0; j<n-1; j++){
            if (arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
                bool swapDone = true;
            }
        }
        if (!isSwap){
            return;
        }
    }
}

void selectionSort (int arr[], int n){
    for (int i=0; i<n-1; i++){
        for (int j=i+1; j<n; j++){
            if (arr[i]>arr[j]){
                swap(arr[i], arr[j]);
            }
        }
    }
}

void insertionSort (int arr[], int n){
    for (int i=1; i<n; i++){
        int curr = arr[i];
        int prev = i-1;

        while (prev >=0 && arr[prev]>curr){
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev+1] = curr;
    }
}

int main() {
    int arr[] = {5,7,3,1,8};
    int n = 5;

    insertionSort(arr,n);
    printArr(arr,n);

    return 0;
}