#include <iostream>
#include <vector>

using namespace std;

vector<vector<string>> csv_parser(string input, const char &row_delim, const char &col_delim, const char &q){
    vector<vector<string>> output;
    bool quote = false;
    string str;
    vector<string> one_row;
    
    for (char &c : input){
        cout << "Current char: " << c << "\t\t";
        if (c == q){
            quote = !quote;
            cout << endl;
            continue;
        }
        if (quote){
            str += c;
            cout << "adding to str: " << str;
        }
        else if (c == col_delim){
            cout << "pushing " << str;
            one_row.push_back(str);
            str.clear();
        }
        else if (c == row_delim){
            cout << "pushing a row";
            one_row.push_back(str);
            output.push_back(one_row);
            str.clear();
            one_row.clear();
        }
        else {
            str += c;
            cout << "adding to str: " << str;
        }
        cout << endl;
    }
    
    return output;
}

int main(){
    
    string in = "foo,bar,name: \"shea,|katie\"|\"yes,no\",,";
    const char &row = '|';
    const char &col = ',';
    const char &q = '"';
    
    vector<vector<string>> output;
    
    output = csv_parser(in, row, col, q);
    
    cout << output[0][0] << ", " << output[0][1] << ", " << output[0][2] << endl;
    cout << output[1][0] << ", " << output[1][1] << ", " << output[1][2] << endl;
    
    return 0;
}
