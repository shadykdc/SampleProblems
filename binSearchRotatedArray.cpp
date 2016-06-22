#include <iostream>
#include <vector>

using namespace std;

int bin_search(vector<int> input, int x, int left, int right){
    int mid;
    
    while (left < right){
        mid = (left+right)/2;
        if (input[mid] == x) return mid;
        if (input[mid] >= input[left]){
            if (input[left] <= x && x < input[mid]){
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        else {
            if (input[mid] < x && x <= input[right]){
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
    }
    return -1;
}

int main(){
    
    vector<int> array = {2, 3, 4, 5, 6, 7, 8, 9, 0, 1};
    int x = 0;
    
    int position = bin_search(array, x, 0, array.size());
    
    cout << x << " was found at position " << position << "." << endl;
    
    return 0;
}
