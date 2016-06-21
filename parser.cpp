#include <iostream>
#include <vector>

using namespace std;

vector<vector<string>> csv_parser(string input, const char &row_delim, const char &col_delim, const char &q){
    vector<vector<string>> output;
    bool quote = false;
    string str;
    vector<string> one_row;
    
    for (char &c : input){
        if (c == q){
            quote = !quote;
            continue;
        }
        if (quote){
            str += c;
        }
        else if (c == col_delim){
            one_row.push_back(str);
            str.clear();
        }
        else if (c == row_delim){
            one_row.push_back(str);
            output.push_back(one_row);
            str.clear();
            one_row.clear();
        }
        else {
            str += c;
        }
    }
    one_row.push_back(str);
    output.push_back(one_row);
    
    return output;
}

int main(){
    
    string in = "foo,bar,name: \"shea,|katie\"|\"yes,no\",fc, a";
    const char &row = '|';
    const char &col = ',';
    const char &q = '"';
    
    vector<vector<string>> output;
    
    output = csv_parser(in, row, col, q);
    
    cout << "[";
    for (int i = 0; i < output.size(); i++){
        for (int j = 0; j < output[0].size(); j++){
            cout << "[" << output[i][j] << "] ";
        }
    }
    cout << "]" << endl;
    
    return 0;
}
