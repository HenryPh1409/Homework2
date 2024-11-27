#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &st, int element) {
    if (st.empty()) {
        st.push(element);
    } else {
        int topElement = st.top();
        st.pop();
        insertAtBottom(st, element);
        st.push(topElement);
    }
}

void reverseStack(stack<int> &st) {
    if (!st.empty()) {
        int topElement = st.top();
        st.pop();
        reverseStack(st);
        insertAtBottom(st, topElement);
    }
}

int main() {
    stack<int> st;
    st.push(31);
    st.push(30);
    st.push(29);
    st.push(28);

    cout << "Original stack: ";
    stack<int> temp = st;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    reverseStack(st);

    cout << "Reversed stack: ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}
