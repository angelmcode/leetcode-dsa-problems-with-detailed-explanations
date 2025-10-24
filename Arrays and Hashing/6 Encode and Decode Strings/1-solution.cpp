// Time complexity: O(n), Space complexity: O(n + s)

#include <iostream> // needed to input output operations
#include <vector> // needed to use vector
#include <string> // needed to use substr ans stoi

using namespace std;

class Solution {
public:

// string expected: 10#01234567891#a
    static string encode(vector<string>& strs) {
      string result = ""; // space: O(n + s)

      for(string &s : strs){ // Time: O(n)
         result += to_string(s.size()) + "#" + s;
      }
      return result;
    }

    static vector<string> decode(string s) {
      vector<string> result; // Space: O(n+s)
      
      int i=0;

      for (int j = 0; j < s.size(); j++) //Time: O(n)
      {
         if (s[j]=='#')
         {
            int length = stoi(s.substr(i,j-i));
            result.push_back(s.substr(j+1, length));
            i = j + length +1;
            j=i;
         }
      } 
      return result;
    }
};

int main(){

   // vector<string> strs = {"neet","code","love","you"};
   vector<string> strs = {"0123456789","a"};
   cout << Solution::encode(strs) << '\n';

   string s = Solution::encode(strs);

   vector<string> result = Solution::decode(s);
   for (string &r: result)
   {
      cout << r << '\n';
   }
   
}