/*
** Given an integer, output the english version of the number.
** So 123 would be one hundred twenty three.
*/

#include <iostream>
#include <cmath>

using namespace std;

string ones[20] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
    "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    
string tens[10] = {"", "", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    
string hundreds[10] = {"", "", "", "thousand", "", "", "million", "", "", "billion"};


/* This function handles numbers 1 - 999 */
void three_digits(int &num, string &output){
    for (int i = 9; i > 0; i--){
        int hun = num/(i*100);
        if (hun > 0){
            output += ones[hun] + " hundred ";
            num = num - (i*100);
            break;
        }
    }
    for (int i = 9; i >= 2; i--){
        int ten = num/(i*10);
        if (ten > 0){
            output += tens[i] + " ";
            num = num - (i*10);
            break;
        }
    }
    
    if (num != 0){
        output += ones[num] + " ";
        num = 0;
    }
    return;
}

/* This function handles numbers -999,999,999,999 to 999,999,999,999 */
string convert(int num){
    string output;
    
    if (num < 0){
        num *= -1;
        output += "negative ";
    }
    
    if (num == 0){
        return "zero";
    }
    
    while (num != 0){
        for (int i = 9; i >= 2; i--){
            if (hundreds[i].empty()){
                continue;
            }
            int hun = num/pow(10,i);
            if (hun > 0){
                three_digits(hun, output);
                output += hundreds[i] + " ";
                num = num - (((int)(num/pow(10,i)))*pow(10,i));
            }
        }
        if (!output.empty() && output != "negative " && num != 0){
            output += "and ";
        }
        three_digits(num, output);
    }
    
    return output;
}

/* main function */
int main(){
    
    int num = -0;
    
    string output = convert(num);
    
    cout << num << " is said " << output << endl;
    
    return 0;
}
