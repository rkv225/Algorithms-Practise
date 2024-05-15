/*
Problem:
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:
MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2

Solution:
need to store the min of the stack in current element before inserting
return min(val, mini) for min value

Time: O(1) for each operation

Link: https://leetcode.com/problems/min-stack/
*/

class node {
public:
    int val;
    int mini;
    node(int v, int m) {
        val = v;
        mini = m;
    }
};
class MinStack {
public:
    stack<node> st;
    MinStack() {}

    void push(int val) {
        int mini;
        if(st.size() == 0)
            mini = val;
        else
            mini = min(st.top().val, st.top().mini);
        st.push(node(val, mini));
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().val;
    }
    
    int getMin() {
        return min(st.top().val, st.top().mini);
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


/*
Solution: using two stack
one stack will be actual stack and other stack will have minimum
now if our min_val top is greater or equal then we add new val then this means we have a new smaller value 
*/

class MinStack {
public:
    stack<int> min_val;
    stack<int> container;
    MinStack() {
        
    }
    
    void push(int val) {
        container.push(val);
        if(min_val.empty() || min_val.top() >= val)
            min_val.push(val);
    }
    
    void pop() {
        int val = container.top();
        container.pop();
        if(val == min_val.top())
            min_val.pop();
    }
    
    int top() {
        if(container.empty())
            return -1;
        return container.top();
    }
    
    int getMin() {
        if(min_val.empty())
            return -1;
        return min_val.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */