#include <bits/stdc++.h>
using namespace std;

int findFromArray(int x, vector<int> &arr){
    int low = 0, high = arr.size()-1;
    while(low <= high) {
        int mid = low + (high-low)/2;
        if(arr[mid] == x) return mid;
        if(arr[mid] > x){
            high = mid-1;
        } else {
            low = mid+1;
        }
    }
    return -1;
}

int main() {
    vector<int> arr{1, 3, 4, 10, 12, 15};
    // task is to find an element x is present in the above array or not.
    cout << "index of 10 is: " << findFromArray(10, arr) << "\n";
    cout << "index of 1 is: " << findFromArray(1, arr) << "\n";
    cout << "index of 15 is: " << findFromArray(15, arr) << "\n";
    cout << "index of 7 is: " << findFromArray(7, arr) << "\n";
    return 0;
}