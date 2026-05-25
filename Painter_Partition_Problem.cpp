#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Implement the painter_partition method here
bool isValid (vector<int> boards, int N, int k, long long mid){
    if (N == 0) {
        return true;
    }
    int painter = 1;
    long long board = 0;
    for (int i = 0; i<N; i++){
        if (boards[i] > mid){
            return false;
        }
        if (board + boards[i] <= mid){
            board += boards[i];
        } else {
            painter++;
            board = boards[i];
        }
    }
    if (painter <= k){
        return true;
    } else {
        return false;
    }
}

int painter_partition(vector<int> boards, int k){
    int N = boards.size();
    int ans = -1;
    long long sum = 0;
    int mini = INT_MIN;

    for (int val:boards){
        mini = max(mini, val);
    }

    for (int val:boards){
        sum += val;
    }
    
    long long st = mini;
    long long end = sum;
    
    while (st<=end){
        long long mid = st + (end-st)/2;

        if (isValid(boards, N, k, mid)){
            end = mid-1;
            ans = mid;
        } else {
            st = mid+1;
        }
    }
    return ans;
}

int main() {
    vector<int> boards = {40,30,10,20};
    int k = 2;

    cout << painter_partition(boards, k);
    return 0;
}