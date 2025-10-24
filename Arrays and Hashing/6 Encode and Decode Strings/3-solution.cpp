// Time complexity: O(n), Space complexity: O(n + s)

#include <iostream> // needed to input output operations
#include <vector> // needed to use vector
#include <string> // needed to use substr ans stoi

using namespace std;

class Solution {
public:

// 10,1#01234567891a
    static string encode(vector<string>& strs) {
      if (strs.empty()) return "";  
      
      string result = ""; // space: O(n + s)
      for(string &s : strs){ // time: O(n)
         result += to_string(s.size()) + ",";
      }
      result += "#";
      for(string &s : strs){ // time: O(s)
         result += s;
      }
      return result;
    }

    static vector<string> decode(string s) {
      if (s.empty()) return {};  
      vector<int> sizes; // space: O(n)
      int i = 0; 
      int j = 0; 
    
      while (s[j] != '#') // time: O(n)
      {      
         if(s[j] == ',')
         {
            int value = stoi(s.substr(i,j-i));
            sizes.push_back(value);
            j++;
            i=j;
         } else
         {
            j++;
         }
         
      }
      i++;
      j=0;
      vector<string> result; // space: O(s)
      while (i<s.size()) // time: O(s)
      {
         string element = s.substr(i,sizes[j]);
         result.push_back(element);
         i+=sizes[j];
         j++;
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