// in an array, lower bound of x is defined as min(i) or first element where arr[i] >= x 
// and upper bound is defined as min(i) or first element where arr[i] > i.

#include <bits/stdc++.h>
using namespace std;

int checkForUpperbound(int arr[], int mid, int x){
    if(arr[mid] > x) return 1;
    return 0;
}

int checkForLowerbound(int arr[], int mid, int x){
    if(arr[mid] >= x) return 1;
    return 0;
}

int lowerBound(int arr[], int x, int N){
    int low = 0, high = N-1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(checkForLowerbound(arr, mid, x)) {
            high = mid-1;
        } else {
            low = mid+1;
        }
    }
    return low;
}

int upperBound(int arr[], int x, int N){
    int low = 0, high = N-1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(checkForUpperbound(arr, mid, x)) {
            high = mid-1;
        } else {
            low = mid+1;
        }
    }
    return low;
}

int main() {
    int arr[] = {2, 3, 3, 7, 9, 13, 13, 13, 15, 17, 17, 17, 17, 18};
    int N = sizeof(arr)/sizeof(arr[0]);
    cout << "lower bound of 10 is: " << lowerBound(arr, 10, N) << endl;
    cout << "lower bound of 13 is: " << lowerBound(arr, 13, N) << endl;
    cout << "lower bound of 2 is: " << lowerBound(arr, 2, N) << endl;
    cout << "lower bound of 18 is: " << lowerBound(arr, 18, N) << endl;
    cout << "lower bound of 1 is: " << lowerBound(arr, 1, N) << endl;
    cout << "lower bound of 19 is: " << lowerBound(arr, 19, N) << endl;

    cout << "upper bound of 10 is: " << upperBound(arr, 10, N) << endl;
    cout << "upper bound of 13 is: " << upperBound(arr, 13, N) << endl;
    cout << "upper bound of 2 is: " << upperBound(arr, 2, N) << endl;
    cout << "upper bound of 18 is: " << upperBound(arr, 18, N) << endl;
    cout << "upper bound of 1 is: " << upperBound(arr, 1, N) << endl;
    cout << "upper bound of 19 is: " << upperBound(arr, 19, N) << endl;
    return 0;
}