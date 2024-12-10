/**
 * Stack reversal without using extra space and using recursion
 * Using two recursive functions
 * Stack follow FIFO principle
 * We will be storing all the popped elements from the stack in the stack frame, and keeping them into stack again
   from bottom
 */

/**
 * T.C: O(N*N) // for 2 recursive functions
 * S.C: O(1), since extra space is not used
 */
#include <iostream>
#include <stack>

using namespace std;

class Solution{
public:
    void insertAtBottom(stack<int> &st1, int temp) {
        if (st1.empty()) {
            st1.push(temp);
        }
        else {
            int x = st1.top();
            st1.pop();
            insertAtBottom(st1, temp);
            st1.push(x);
        }
    }
    void Reverse(stack<int> &St){
        if (!St.empty()) {
            int x = St.top();
            St.pop();
            Reverse(St);
            
            insertAtBottom(St, x);
        }
    }
    void printStack(stack<int> s) {
        while (!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    } 
};

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    
    Solution obj;
    cout << "Befire reversal: ";
    obj.printStack(s);
    obj.Reverse(s);
    cout << "After reversal: ";
    obj.printStack(s);
}