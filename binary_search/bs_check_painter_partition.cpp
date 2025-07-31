// Given an array arr[] and k, where the array represents the boards and 
// each element of the given array represents the length of each board. k numbers 
// of painters are available to paint these boards. Consider that each unit 
// of a board takes 1 unit of time to paint. The task is to find the minimum time 
// to get this job done by painting all the boards under the constraint that any 
// painter will only paint the continuous sections of boards. say board [2, 3, 4] 
// or only board [1] or nothing but not board [2, 4, 5].

#include<bits/stdc++.h>
using namespace std;

int arr[100100];
int n, k;

int check(int mid){
    // in mid time, can these k painters accomplish the task of painting the wall or not. if yes 1, else 0.
    int no_of_painters = 1;
    int time_taken_by_painter = 0;
    for(int i=0;i<n;i++) {
        if(arr[i] > mid) return 0;
        if(time_taken_by_painter+arr[i] > mid){
            no_of_painters++;
            time_taken_by_painter = arr[i];
        } else{
            time_taken_by_painter+=arr[i];
        }
    }
    return no_of_painters <= k;
}

int main(){
    cin >> n >> k; // n is number of walls, k is no of painters
    int sum = 0;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        sum += arr[i];
    }
    int l = 0, h = sum;
    while(l <= h) {
        int mid = l + (h-l)/2;
        if(check(mid) == 1) {
            h = mid-1;
        } else {
            l = mid+1;
        }
    }
    cout << l << endl;
    return 0;
}

// test case: 
// 6
// 2
// 1 3 8 7 2 5

// error notes. 

// 1) debugging is taking so much time. i understand that this is due to lack of practice. 
// 2) i declared int n, k again inside the main function though i declared it in global place. 
// here the check function is not taking n and k scanned values. instead they are getitng as 0 each. 
// its because, we scanned variables declared inside main but we are using global variables inside check.