#include <iostream>
#include <vector>
using namespace std;

bool isValid (const vector<int>& arr , int mid, int m, int n){
    int stu = 1;
    int pg = 0;

    for (int i = 0; i<n; i++){
        if (arr[i] > mid){
            return false;
        }
        if (pg + arr[i] <= mid){
            pg += arr[i];
        } else {
            stu++;
            pg = arr[i];
        }
    }
    if (stu <= m){
        return true;
    } else {
        return false;
    }
}

int allocateBooks(const vector<int>& arr, int n, int m) {
    if (m > n) {
        return -1;
    }
    int sum = 0;
    for (int i = 0; i<n; i++){
        sum += arr[i];
    }
    int st = 0;
    int end = sum;
    int ans = -1;

    while (st <= end){
        int mid = st + (end-st)/2;
        if (isValid(arr, mid, m, n)){
            ans = mid;
            end = mid-1;
        } else {
            st = mid+1;
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {15,17,20};
    int n = 3, m = 2;
    
    cout << allocateBooks(arr, n, m) << endl;
    return 0;
}