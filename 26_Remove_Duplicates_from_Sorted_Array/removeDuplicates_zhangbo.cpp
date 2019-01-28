#include <iostream>
#include <vector>
using namespace std;

/*
 * 说明：
 * 这道数组题相对简单，设置下标i指向最终返回结果，下标j遍历数组。
 * 只要清楚i始终指向不重复数组的下一位即可。
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len == 0 || len == 1) return len;
        int i = 0;
        for(int j = 1; j < len; j++){
            if(nums[i] != nums[j]){
                nums[++i] = nums[j];
            }
        }
        return i + 1;
    }
};

int main() {
    Solution sl;
    vector<int> nums = {1,1,2};
    std::cout << sl.removeDuplicates(nums) << std::endl;
    return 0;
}