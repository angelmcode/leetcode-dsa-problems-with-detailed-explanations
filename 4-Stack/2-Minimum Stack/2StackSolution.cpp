// Time Complexity: O(1)  Space Complexity: O(n)
#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
   stack<int> ST; // space O(n)
   stack<int> minST; // space O(n)
public:
   
    MinStack() {
        
    }
    
    void push(int val) { // time and space O(1)
        ST.push(val);
        val = min(val, minST.empty() ? val : minST.top());
        minST.push(val);
    }
    
    void pop() { // time and space O(1)
        ST.pop();
        minST.pop();
    }
    
    int top() { // time and space O(1)
        return ST.top();
    }
    
    int getMin() { // time and space O(1)
        return minST.top();
    }
};


int main (){
   MinStack minStack;
   
   minStack.push(1);
   minStack.push(2);
   minStack.push(0);
   cout << minStack.getMin() << '\n';
   minStack.pop();
   cout << minStack.top() << '\n';
   cout << minStack.getMin() << '\n';
   return 0;
}