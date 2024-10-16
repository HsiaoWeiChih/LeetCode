#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int size = nums.size();
        map<int, int> m;
        
        for(int i = 0; i < size; i++){
            m[nums[i]]++;
        }
        size = ceil(size/2.0);
        for(auto x: m){
            if(x.second >= size){
                return x.first;
            }
        }
        return 0;
    }
};

int main()
{
    vector<int> v = {1,2,3,1,1};
    Solution test;
    cout << test.majorityElement(v);
    return 0;
}