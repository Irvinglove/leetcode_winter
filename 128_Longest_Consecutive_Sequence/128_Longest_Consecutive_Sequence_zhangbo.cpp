#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*
 *详解参见https://blog.csdn.net/irving_zhang/article/details/78230960
 */

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> m;
        int max_cnt = 0;
        int len = nums.size();
        for(int i = 0; i < len; i++){
            m.insert({nums[i], 0});
        }
        for(int i = 0; i < len; i++){
            //之前已经找过该值
            if(m.at(nums[i]) == 1){
                continue;
            }
            //向上查找
            int val = nums[i];
            int cnt = 0;
            while(m.find(val) != m.end()){
                cnt++;
                m.at(val) = 1;
                val++;
            }
            //向下查找
            val = nums[i] - 1;
            while(m.find(val) != m.end()){
                cnt++;
                m.at(val) = 1;
                val--;
            }
            if (cnt > max_cnt){
                max_cnt = cnt;
            }

        }
        return max_cnt;
    }
};
int main() {
    Solution sl;
    vector<int> nums = {100, 4, 200, 2, 1, 3};
    std::cout << sl.longestConsecutive(nums) << std::endl;
    return 0;
}
