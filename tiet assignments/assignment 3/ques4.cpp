#include <iostream>
#include <stack>
using namespace std;

int prec(char c) {
    if(c=='^') return 3;
    if(c=='*' || c=='/') return 2;
    if(c=='+' || c=='-') return 1;
    return -1;
}

int main() {
    string infix;
    cout << "Enter infix: ";
    cin >> infix;

    stack<char> st;
    string post = "";

    for(int i=0; i<infix.length(); i++) {
        char c = infix[i];
        if(isalnum(c)) {
            post += c;
        }
        else if(c=='(') {
            st.push(c);
        }
        else if(c==')') {
            while(!st.empty() && st.top()!='(') {
                post += st.top();
                st.pop();
            }
            if(!st.empty()) st.pop();
        }
        else {
            while(!st.empty() && prec(st.top()) >= prec(c)) {
                post += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty()) {
        post += st.top();
        st.pop();
    }
    cout << "Postfix: " << post;
}
