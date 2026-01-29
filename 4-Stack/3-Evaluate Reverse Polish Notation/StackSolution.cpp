// Time Complexity: O(n) Space Complexity: O(n)
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
      stack<int> numbers; // space O(n)

      for(string& s: tokens){ // time O(n)
         int number1;
         int number2;
         int result;
         
         if (s == "+")
         {
            number2 = numbers.top();
            numbers.pop();
            number1 = numbers.top();
            numbers.pop();
            result = number1 + number2;
            numbers.push(result);
         } else if (s == "-")
         {
            number2 = numbers.top();
            numbers.pop();
            number1 = numbers.top();
            numbers.pop();
            result = number1 - number2;
            numbers.push(result);
         } else if (s == "*")
         {
            number2 = numbers.top();
            numbers.pop();
            number1 = numbers.top();
            numbers.pop();
            result = number1 * number2;
            numbers.push(result);
         } else if (s == "/")
         {
            number2 = numbers.top();
            numbers.pop();
            number1 = numbers.top();
            numbers.pop();
            if(number2 == 0){
               result=number1;
            } else {
               result = number1 / number2;
            }
            numbers.push(result);
         } else {
            numbers.push(stoi(s));
         }
      }
      return numbers.top();
    }
};


int main (){
   Solution s;

   vector<string> tokens = {"1","2","+","3","*","4","-"};
   
   int result = s.evalRPN(tokens);
   cout << result << '\n';
   return 0;
}