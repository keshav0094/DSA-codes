#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isValid(vector<int> stalls, int k, int mid){
    int cow = 1;
    int lastCowPos = stalls[0];

    for (int i=1; i<stalls.size(); i++){
        if (stalls[i]-lastCowPos >= mid){
            lastCowPos = stalls[i];
            cow++ ;
        }
        if (cow==k){
            return true;
        }
    }
    return false;
}

int aggressiveCows(vector<int>& stalls, int k){
    sort(stalls.begin() , stalls.end());

    int st = 1;
    int end = stalls[stalls.size()-1] - stalls[0];
    int ans = -1;

    while(st<=end){
        int mid = st + (end-st)/2;

        if (isValid(stalls, k, mid)){
            ans = mid;
            st = mid+1;
        } else{
            end = mid-1;
        }
    }
    return ans;
}

int main() {
    vector<int> stalls = {1, 2, 4, 8, 9};
    int k = 3;

    cout << aggressiveCows(stalls, k);
    return 0;
}