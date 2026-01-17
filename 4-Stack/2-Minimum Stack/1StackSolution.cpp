// Time Complexity: O(1)  Space Complexity: O(n)
#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
   stack<long> ST; // space O(n)
   long m; // space O(1)
public:
   
    MinStack() {
        
    }
    
    void push(int val) { // time and space O(1)
      if (ST.empty())
      {
         ST.push(0);
         m = val;
      } else {
         ST.push(val - m);
         if(val < m) m = val; 
      }
      
    }
    
    void pop() { // time and space O(1)
      long value = ST.top();
      ST.pop();

      if(value < 0) m = m - value;
    }
    
    int top() { // time and space O(1)
      long value = ST.top();
      return value > 0 ? (int)(value + m) : (int)m;
    }
    
    int getMin() { // time and space O(1)
        return m;
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