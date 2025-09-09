#include <iostream>
#include <stack>
using namespace std;

int main() {
    string exp;
    cout << "Enter postfix: ";
    cin >> exp;

    stack<int> st;
    for(int i=0; i<exp.length(); i++) {
        char c = exp[i];
        if(isdigit(c)) {
            st.push(c - '0');
        } else {
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();
            int res = 0;
            if(c=='+') res = val1 + val2;
            else if(c=='-') res = val1 - val2;
            else if(c=='*') res = val1 * val2;
            else if(c=='/') res = val1 / val2;
            st.push(res);
        }
    }
    cout << "Result: " << st.top();
}
