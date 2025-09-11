#pragma once
#include <cstring>
#include <vector>
using namespace std;


void print_vec(std::vector<int>& vec);

/*
    https://leetcode.cn/problems/find-all-duplicates-in-an-array/description/
    leetcode类似题目：数组中重复的数据
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        size_t sz = nums.size();
        vector<int> array(sz);
        std::cout << "array[0]="<< array[0] << "\n";
        // std::cout << "array.size()=" << sizeof(array) << "\n";
        // memset(array, 0, sz);
        // std::cout << "array[0]="<< array[0] << "\n";
        vector<int> out;

        for(auto num : nums){
            array[num] += 1;
            if(array[num] == 2)
            {
                out.push_back(num);
            }
        }
        
    
        return out;
    }

};
void get_result()
{
    vector<int> nums = {4,3,2,7,8,2,3,1};
    Solution sol;
    vector<int> res = sol.findDuplicates(nums);
    for(auto r: res)
    {
        std::cout << r << " ";
    }
}

void print_vec(std::vector<int>& vec)
{
    for(auto v: vec)
    {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}