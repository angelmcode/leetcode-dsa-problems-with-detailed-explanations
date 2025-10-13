// time complexity: O(n * k)  sapce complexity: O(n * k)

#include <iostream> // needed to use input output operations
#include <vector> // needed to use the dynamic array
#include <unordered_map> // neede to use the hash map
using namespace std; // needed to not write std:: everytime

class Solution {
public:
    static vector<vector<string>> groupAnagrams(vector<string>& strs) {

      unordered_map< string, vector<string> > group; // space: O(n * k)

      for (int i = 0; i < strs.size(); i++) // space: O(n * k)
      {
         vector<int> checker(26,0);
         string element = strs[i]; 
         string key = "";

         for (char e : element)
         {
            checker[e-'a']++;
         }
         
         for (int c : checker)
         {
            key = key + "," + to_string(c);
         }
         
         group[key].push_back(element);

      }

      vector<vector<string>> result; // space: O(n * k)

      for (auto &g : group) 
      {
         result.push_back(g.second);
      }
       
      return result;
    }   
};

int main() {

   vector<string> strs {"ab","cd"};

   vector<vector<string>> result = Solution::groupAnagrams(strs);

   for (const auto &row : result) {
        std::cout << '[';
        for (int i = 0; i < row.size(); ++i) {
            std::cout << row[i];
            if (i + 1 < row.size()) std::cout << ", ";
        }
        std::cout << "]\n";
    }
    return 0;
}