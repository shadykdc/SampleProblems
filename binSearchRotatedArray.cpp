#include <iostream>
#include <vector>

using namespace std;

int find_transition(vector<int> arr){
    int left = 0;
    int right = arr.size()-1;
    int mid;
    
    if (arr[arr.size()-1] < arr[arr.size()-2] && arr[0] > arr[arr.size()-1]){
        return arr.size()-1;
    }
    if (arr[0] < arr[1] && arr[0] < arr[arr.size()-1]){
        return 0;
    }
    
    while(left < right){
        mid = (left+right)/2;
        if (arr[mid-1] > arr[mid] && arr[mid+1] > arr[mid]){
            return mid;
        }
        if (mid+2 <= arr.size()-1 && arr[mid] > arr[mid+1] && arr[mid+2] > arr[mid+1]){
            return mid+1;
        }
        if (arr[mid] > arr[right]){
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

bool bin_search(vector<int> arr, int target){
    int left = 0;
    int right = arr.size()-1;
    int mid;
    
    if (arr[arr.size()-1] < target){
        right = find_transition(arr)-1;
    }
    else {
        left = find_transition(arr);
    }
    
    while (left < right){
        mid = (left+right)/2;
        if (arr[mid] == target){
            return true;
        }
        if (arr[mid] < target){
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
        
    }
    return false;
}

int main(){
    
    vector<int> arr = {1, 2, 3, 4};
    int target = 3;
    
    int transition_pos = find_transition(arr);
    
    cout << "The transition is at position " << transition_pos << endl;
    
    bool found = bin_search(arr, target);
    
    if (found){
        cout << target << " was found!" << endl;
    }
    else {
        cout << target << " was not found." << endl;
    }
    return 0;
}
