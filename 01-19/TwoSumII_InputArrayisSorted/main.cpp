#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i=0,j=numbers.size()-1; i<j;)
        {
            if(numbers[i]+numbers[j] > target)
            {
                --j;
            }
            else if(numbers[i]+numbers[j] < target)
            {
                ++i;
            }
            else if(numbers[i]+numbers[j] == target)
            {
                return {min(i+1, j+1), max(i+1, j+1)};
            }
        }
        return {};
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
