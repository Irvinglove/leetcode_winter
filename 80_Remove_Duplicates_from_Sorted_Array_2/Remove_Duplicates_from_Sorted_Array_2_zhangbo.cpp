#include <iostream>
#include <vector>
using namespace std;

/*
 *详解参见https://blog.csdn.net/irving_zhang/article/details/78184077
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        int count = 1;
        if (len == 0 || len == 1) return len;
        int i = 0;
        for(int j = 1; j < len; j++){
            if(nums[j] == nums[j - 1]){
                if(count < 2){
                    i++;
                    nums[i] = nums[j];
                    count++;
                }
            }else{
                i++;
                nums[i] = nums[j];
                count = 1;
            }


        }
        return i + 1;
    }
};

int main() {
    vector<int> nums = {1,1,2,2,2,3,3,3,4};
    Solution sl;
    std::cout << sl.removeDuplicates(nums) << std::endl;
    return 0;
}
