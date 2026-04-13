#include <iostream>
#include <string>

using namespace std;

// write a function to print the contents of your array
//   bonus (+5% to your grade for this lab)! try to implement your function so that it can accept
//     many types of data (int, char, string, etc.)
//  Replace the ... with proper parameters
template <typename flexibleType> // ???
void printArray(flexibleType array[], int size) {
    for(int i = 0; i < size; i++){
        cout << array[i] << " ";
    }
}

// Implement a sequential search algorithm
// your function should search for a target value (target)
//    within the indices of "start" to "end"
// return true if target exists in the array within this range,
//    return false otherwise
bool seqSearch(string target, string arr[], int start, int end) {
    for(int i = start; i <= end; i++){
        if(target == arr[i]){
            return true;
        }
    }
    return false;
}

// Implement an iterative binary search 
// Return true if target exists in the array with size n,
//    return false otherwise 
bool binSearch(float target, float arr[], int n) {
    int left = 0;
    int right = n - 1;
    
    while(left <= right){
        int mid = left + (right-left)/2;
        if(arr[mid] == target){
            return true;
        } else if(arr[mid] > target){
            right = mid - 1;
        } else{
            left = mid + 1;
        }
    }
    return false;
}

// Implement a recursive binary search 
// Return true if target exists in the array with size n
//   return false otherwise
bool binSearchR(char target, char charray[], int n) {
    // base case
    if(n <= 0){
        return false;
    }
    int mid = n / 2;
    if(charray[mid] == target){
        return true;
    }

    //general case
    if(charray[mid] < target){
        return binSearchR(target, charray + mid + 1, n - mid - 1);
    } else{
        return binSearchR(target, charray, mid);
    }
}

// Implement Exponential Search
//    Reuse your iterative binSearch(...) on a narrowed window
//    Assumes the array is sorted in ascending order
// Step 1: Handle edge cases (empty array) and quickly check the first element.
// Step 2: Grow a “bound”: start at 1, then repeatedly double it
//         while you are still inside the array and the current value is less than the target.
// Step 3: Define a search window:
//         - The left edge is halfway back from the current bound.
//         - The right edge is the smaller of (current bound) and (last valid index).
// Step 4: Run your existing binSearch on just that window and return its result.
//         You may pass a pointer to the start of the window and its length,
//         or copy that window to a temporary buffer if you prefer.
bool expSearch(float target, float arr[], int n) {
    if(n <= 0){
        return false;
    }
    if(arr[0] == target || arr[n - 1] == target){
        return true;
    }
    int bound = 1;
    while(bound < n && arr[bound] < target){
        bound = bound * 2;
    }
    int left = bound / 2;
    int right;
    if(bound < n){
        right = bound;
    } else{
        right = n - 1;
    }

    return binSearch(target, arr + left, right - left + 1);
}
