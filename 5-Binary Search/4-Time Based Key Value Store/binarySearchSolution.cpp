// Time Complexity: O(log n) Space Complexity: O(n*m)
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> map; //space O(n*m)
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) { //time O(1)
        map[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) { // time O(logn)
        int l = 0;
        int r = map[key].size()-1;

        while (l<=r)
        {
            int m = l + ((r-l)/2);
            auto value = map[key][m];
            if (timestamp < value.first)
            {
                r=m-1;
            } else
            {
                l=m+1;
            }
        }
        return (r>=0)?map[key][r].second:"";
    }
};


int main (){
   TimeMap tm;

   tm.set("alice", "happy", 1);
   string r1 = tm.get("alice", 1);

   cout << r1 << '\n';

   return 0;
}