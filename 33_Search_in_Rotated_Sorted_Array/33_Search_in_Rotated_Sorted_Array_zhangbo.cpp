#include <iostream>
#include <vector>
using namespace std;

/*
 *详解参见https://blog.csdn.net/irving_zhang/article/details/78192831
 */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        int l = 0;
        int r = len - 1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[l] <= nums[mid]){
                if(nums[l] <= target && target <= nums[mid]){
                    r = mid - 1;
                }else{
                    l = mid + 1;
                }
            }else {
                if (nums[mid] <= target && target <= nums[r]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main() {
    vector<int> nums = {3,1};
    Solution sl;
    std::cout <<sl.search(nums, 1) << std::endl;
    return 0;
}
