// Q: Given a rotated sorted array. Find the index of the minimum element in the array.
// All the elements are distinct.
#include<bits/stdc++.h>
using namespace std;

// [3, 4, 5, 1, 2]

bool check(vector<int> &arr, int mid){
    if(arr[mid] < arr[0]) return true;
    return false;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        int l = 0, h = n-1;
        while(l <= h) {
            int mid = l + (h-l)/2;
            if(check(a, mid)) {
                h = mid-1;
            }else {
                l = mid+1;
            }
        }
        if(l == n) {
            cout << 0 << endl;
        } else {
            cout << l << endl;
        }
    }
    return 0;
}