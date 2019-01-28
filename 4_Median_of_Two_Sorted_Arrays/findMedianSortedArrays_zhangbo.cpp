#include <iostream>
#include <stdlib.h>
#include <vector>
#include <limits.h>
using namespace std;

/*
 * 说明：
 * 解题过程参照https://blog.csdn.net/irving_zhang/article/details/78230375
 */

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int l = (m + n + 1) / 2;
        int r = (m + n + 2) / 2;
        return (find_k(nums1, 0, nums2, 0, l) + find_k(nums1, 0, nums2, 0, r)) / 2.0;
    }
    double find_k(vector<int>& nums1, int start1, vector<int>& nums2, int start2, int k){
        if (start1 > nums1.size() - 1) return nums2[start2 + k - 1];
        if (start2 > nums2.size() - 1) return nums1[start1 + k - 1];
        int m = nums1.size();
        int n = nums2.size();
        if (m == 0) return nums2[k - 1];
        if (n == 0) return nums1[k - 1];
        if (k == 1) return min(nums1[start1], nums2[start2]);

        int aMid = INT_MAX, bMid = INT_MAX;
        if (start1 + k/2 - 1 < nums1.size()) aMid = nums1[start1 + k/2 - 1];
        if (start2 + k/2 - 1 < nums2.size()) bMid = nums2[start2 + k/2 - 1];

        if (aMid < bMid)
            return find_k(nums1, start1 + k/2, nums2, start2,       k - k/2);// Check: aRight + bLeft
        else
            return find_k(nums1, start1,       nums2, start2 + k/2, k - k/2);// Check: bRight + aLeft
    }
};

int main() {
    vector<int> nums1 = {1,3};
    vector<int> nums2 = {};
    Solution sl;
    std::cout << sl.findMedianSortedArrays(nums1, nums2) << std::endl;
    return 0;
}