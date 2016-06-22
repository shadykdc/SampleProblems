/*
[9 2 9 9] -> [9 3 0 0]
[9 9] -> [1 0 0]
*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> add_one(int arr[], int length){
    vector<int> output;
    bool adding = true;
    
    for (int i = length-1; i > -1; i--){
        int current_num = arr[i];
        if(adding && current_num == 9){
            output.insert(output.begin(),0);
            if (i == 0){
                output.insert(output.begin(),1);
            }
        }
        else if(adding){
            output.insert(output.begin(),arr[i]+1);
            adding = false;
        }
        else {
            output.insert(output.begin(),arr[i]);
        }
    }
    
    return output;
}

int main(){

    int arr[4] = {1, 2, 3, 4};
    
    vector<int> output = add_one(arr, 4);
    
    for (int i = 0; i < output.size(); i++){
        cout << output[i] << " ";
    }
    
    return 0;
}
