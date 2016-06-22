#include <iostream>
#include <cmath>

using namespace std;

int max_subarray(int arr[], int length){
    int big = arr[0];
    int biggest = arr[0];
    
    for (int i = 1; i < length; i++){
        big = max(arr[i], (big+arr[i]));
        biggest = max(big, biggest);
    }
    
    return biggest;
}

int main(){
    
    int arr[10] = {3, -100, 7, 9, -4, 2, 5, 1, 0, -6};
    int max = max_subarray(arr, 10);
    cout << "Max sub array sum is " << max << endl;
    
    return 0;
}
