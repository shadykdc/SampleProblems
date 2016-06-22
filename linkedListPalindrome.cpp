#include <iostream>
#include <stack>

using namespace std;

struct Node{
    char data;
    Node *next;
    Node(char _c){
        data = _c;
        next = NULL;
    }
};

bool palindrome (Node *root){
    Node *current = root;
    stack<char> s;
    
    while (current != NULL){
        s.push(current->data);
        current = current->next;
    }
    current = root;
    while(current != NULL){
        if (current->data != s.top()){
            return false;
        }
        s.pop();
        current = current->next;
    }
    
    return true;
}

int main(){
    
    Node *a1 = new Node('a');
    Node *b1 = new Node('b');
    Node *c = new Node('c');
    Node *b2 = new Node('b');
    Node *a2 = new Node('a');
    Node *x = new Node('x');
    a1->next = b1;
    b1->next = c;
    c->next = b2;
    b2->next = a2;
    a2->next = x;
    
    /* Is the above linked list a palindrome? */
    
    bool pal = palindrome(a1);
    
    if (pal){
        cout << ":)" << endl;
    }
    else {
        cout << ":(" << endl;
    }
    
    // should probably delete the nodes/ dynamically allocated memory
    
    return 0;
}
