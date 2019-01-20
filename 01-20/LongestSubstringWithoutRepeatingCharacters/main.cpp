#include <iostream>
#include <set>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)
        {
            return 0;
        }
        string temp;
        temp.push_back(s[0]);
        set<int> v;
        int pos;
        for (int i=1; i<s.size(); ++i)
        {
            pos = temp.find(s[i]);
            if(pos!=temp.npos){
                v.insert(temp.size());
                temp = temp.substr(pos+1,-1);
            }
            temp += s[i];
        }
        v.insert(temp.size());
        set<int>::iterator it = v.end();
        --it;
        return *it;
    }
};

int main()
{
    Solution s;
    string que("");
    cout << s.lengthOfLongestSubstring(que);
    return 0;
}
