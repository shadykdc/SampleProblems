#include <iostream>
#include <vector>

using namespace std;

vector<vector<string>> csv_parser(string input, const char &row_delim, const char &col_delim, const char &q){
    vector<vector<string>> output;
    bool quote = false;
    string one_string;
    vector<string> one_row;
    
    for (char &c : input){
        if (c == q){
            quote = !quote;
        }
        else if (quote || (c != col_delim && c != row_delim)){
            one_string += c;
        }
        else if (c == col_delim){
            one_row.push_back(one_string);
            one_string.clear();
        }
        else if (c == row_delim){ // could've used "else" but I'm being explicit
            one_row.push_back(one_string);
            output.push_back(one_row);
            one_string.clear();
            one_row.clear();
        }
    }
    one_row.push_back(one_string);
    output.push_back(one_row);
    
    return output;
}

int main(){
    
    string in = "foo,bar,name: \"shea,|katie\"|\"yes,no\",fc, a";
    const char &row = '|';
    const char &col = ',';
    const char &q = '"';
    
    vector<vector<string>> output = csv_parser(in, row, col, q);
    
    cout << "[" << endl;
    for (int i = 0; i < output.size(); i++){
        for (int j = 0; j < output[0].size(); j++){
            cout << "[" << output[i][j] << "] ";
        }
        cout << endl;
    }
    cout << "]" << endl;
    
    return 0;
}
