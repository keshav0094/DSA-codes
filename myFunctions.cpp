#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// checks if n is prime or not
bool checkPrime (int n){
    if (n < 2){
        return false;
    }
    for (int i = 2; i*i <= n; i++){
        if (n%i == 0){
            return false;
        }
    }
    return true;
}

// prints all the prime numbers between [2,n]
void printPrime (int n){
    for (int i = 2; i <= n; i++){
        if (checkPrime(i) == true){
            cout << i<< endl;
        }
    }
}

// prints n numbers of the Fibonacci Sequence 
void printFibonacci (int n){
    int first = 0, second = 1, next;
    for (int i = 0; i < n; i++){
        cout << first << ", ";
        next = first + second;
        first = second;
        second = next;
    }
}


// converts decimals to binary
int numToBin (int decNum){
    int pow = 1;
    int ans = 0;
    while (decNum>0){
        int rem = decNum%2;
        decNum /= 2;
        ans += rem*pow;
        pow *= 10;

    }
    return ans;
}

// converts binary to decimals
int binaryToDecimal(int binary){
    int ans = 0;
    int pow = 1;
    while (binary > 0){
        int rem = binary % 2;
        ans += rem * pow;
        binary /= 10;
        pow *= 2;
    }
    return ans;
}

// checks if is a n a power of 2
string isPowerOf2 (int n){
    string ans = "YES";

    if (n <= 1){
        ans = "NO";
    }
    while (n > 1){
        if (n%2 != 0){
            ans = "NO";
            break;
        }
        n /= 2;
    }
    return ans;
}

// checks if is a n a power of 2 using bitwise AND operator
string isPowerOf2UsingBitwise (int n){
    if (n<0){
        return "NO";
    }
    if ((n & (n-1)) == 0){
        return "YES";
    } else {
        return "NO";
    }
}

// reverses n
int reverse(int n){
    int ans = 0;
    while (n != 0) {
        int rem = n % 10;
        ans = ans * 10 + rem;
        n /= 10;
    }
    return ans;
}

int main (){
    vector <int> arr = {1,3,5,7,9};
    int target = 9;

    int st = 0;
    int end = arr.size() - 1;

    //Binary search
    while (st<= end){
        int mid = st + (end-st)/2 ;
        if (target < arr[mid]){
            end = mid-1;
        } else if (target > arr[mid]){
            st = mid+1;
        } else {
            cout << mid;
            break;
        }

    }
    return 0;
}