// Time Complexity: O(n) for getmin all other O(1)  Space Complexity: O(n)
#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

class MinStack {
private:
   unordered_map<int,int> MP; //space O(n)
   stack<int> ST; //space O(n)
public:
   
    MinStack() {
    }
    
    void push(int val) { //time and space O(1)
        ST.push(val);
        MP[val]++;
    }
    
    void pop() { //time and space O(1)
        if (MP[ST.top()] > 1)
        {
         MP[ST.top()]--;
        } else {
         MP.erase(ST.top());
        }

        ST.pop();
    }
    
    int top() { //time and space O(1)
        return ST.top();
    }
    
    int getMin() { //time O(n) and space O(1)
      int m = __INT_MAX__;
        for (auto &n : MP)
        {
         m = min(m, n.first);
        }
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