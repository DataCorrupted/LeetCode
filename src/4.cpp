// http://www.cnblogs.com/grandyang/p/4465932.html
class Solution {
public:

    int findKth(vector<int> nums1, vector<int> nums2, int k){
        int size1 = nums1.size(), size2 = nums2.size();
        if (size1 > size2) { return findKth(nums2, nums1, k); }
        if (nums1.size() == 0) { return nums2[k-1]; }
        if (k == 1){ return min(nums1[0], nums2[0]); }
        
        int i = min(k/2, size1), j = min(k/2, size2);
        if (nums1[i-1] < nums2[j-1]){
            return findKth(vector<int>(nums1.begin() + i, nums1.end()), nums2, k-i);
        } else {
            return findKth(nums1, vector<int>(nums2.begin() + j, nums2.end()), k-j);
        }
        //return 0;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int total_size = nums1.size() + nums2.size();
        if (total_size & 0x1 == 1){
            return findKth(nums1, nums2, total_size / 2 + 1);
        } else {
            return 
                (findKth(nums1, nums2, total_size / 2) 
                 + findKth(nums1, nums2, total_size / 2 + 1)) / 2.0;
        }
    }
};