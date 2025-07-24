/**
 * GFG
 */

/*
    Monotonic Stack Explanation:
    ----------------------------
    A **monotonic stack** is a stack that maintains its elements in either
    strictly increasing or strictly decreasing order.

    In this problem, we use a **monotonic decreasing stack** to find the
    **Next Greater Element (NGE)** for each element in the array:
    
    - As we traverse from right to left, we maintain a stack such that:
        - The stack always contains elements **greater** than the current element.
        - This ensures the **top of the stack** is always the **next greater** element.
    
    Algorithm Steps:
    ----------------
    1. Traverse the array from right to left.
    2. While the stack is not empty and the top is ≤ current element, pop it.
    3. If stack is empty, no greater element → store -1.
       Else, the top of stack is the next greater element → store it.
    4. Push the current element onto the stack.
    
    Time Complexity: O(n)
    Space Complexity: O(n) — for the stack and output array
*/

class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        stack<int> st;                   // Stack to maintain decreasing elements
        int n = arr.size();
        vector<int> nge(n);             // Result array to store Next Greater Elements
        
        for (int i = n - 1; i >= 0; i--) {
            // Pop all elements ≤ arr[i] since they can't be the NGE
            while (!st.empty() && st.top() <= arr[i]) {
                st.pop();
            }

            // If stack is empty, no greater element on right
            if (st.empty()) {
                nge[i] = -1;
            } else {
                nge[i] = st.top();      // Top of stack is the next greater element
            }

            // Push current element to stack for future comparisons
            st.push(arr[i]);
        }

        return nge;
    }
};
