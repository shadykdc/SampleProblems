#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class Stack_Min{
private:
    stack <int> s;
    stack <int> s_min;
    int m;
public:
    void push(int v){
        if (s.empty()) m = v;
        s.push(v);
        m = std::min(m, v);
        s_min.push(m);
    }
    void pop(){
        s.pop();
        s_min.pop();
        // implement something for when s is now empty... what should m be?
    }
    int top(){
        if (!s.empty()) return s.top();
        // else, return something else...
    }
    int min(){
        if (!s_min.empty()) return s_min.top();
        // else, return something else...
    }
};

int main(){
    vector<int> v = {3, 4, 5, 1, 2, 3};
    Stack_Min s;
    
    for (int num : v){
        s.push(num);
    }
    
    cout << "min is " << s.min() << endl;
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    cout << "min is " << s.min() << endl;
    
    return 0;
}
