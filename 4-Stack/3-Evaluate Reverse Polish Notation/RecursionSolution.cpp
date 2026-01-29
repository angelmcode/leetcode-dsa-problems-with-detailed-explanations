// Time Complexity: O(n)  Space Complexity: O(n)
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
   int eval(vector<string>& tokens){
      string token = tokens.back();
      tokens.pop_back();

      if (token != "+" && token != "-" && token != "*" && token != "/")
      {
         return stoi(token);
      }

      int numberB = eval(tokens);
      int numberA = eval(tokens); 

      if (token == "+") return numberA + numberB;
      else if (token == "-") return numberA - numberB;
      else if (token == "*") return numberA * numberB;
      else return numberA / numberB;
   }

   int evalRPN(vector<string>& tokens) {
      return eval(tokens);
   }
};


int main (){
   Solution s;

   vector<string> tokens = {"1","2","+","3","*","4","-"};
   
   int result = s.evalRPN(tokens);
   cout << result << '\n';
   return 0;
}