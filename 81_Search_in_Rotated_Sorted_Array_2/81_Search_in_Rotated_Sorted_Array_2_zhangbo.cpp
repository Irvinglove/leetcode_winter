#include <iostream>
#include <vector>
using namespace std;

/*
 *详解参见https://blog.csdn.net/irving_zhang/article/details/78207143
 */

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int len = nums.size();
        int l = 0;
        int r = len - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                return true;
            }
            if (nums[l] < nums[mid]) {
                if (nums[l] <= target && target <= nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else if (nums[l] > nums[mid]) {
                if (nums[mid] <= target && target <= nums[r]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }else{
                l++;
            };
        }
        return false;
    }
};


int main() {
    vector<int> nums = {2,5,6,0,0,1,2};
    Solution sl;
    std::cout << sl.search(nums, 3) << std::endl;
    return 0;
}
