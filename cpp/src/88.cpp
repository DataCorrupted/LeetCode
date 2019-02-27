class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int i=m-1, j=n-1, k=n+m-1;
		while (k != -1){
			if (i == -1) {
				nums1[k] = nums2[j]; j--; 
			} else if (j == -1){
				nums1[k] = nums1[i]; i--; 
			} else {
				if (nums1[i] > nums2[j]){
					nums1[k] = nums1[i]; i--;
				} else {
					nums1[k] = nums2[j]; j--;
				}
			}
			k--;
		}
	}
};

#ifdef DEBUG

REGISTER_TEST(example0){
	vector<int> nums1;
	vector<int> nums2;
	int n=0, m=0;
	vector<int> groundTruth;

	Solution().merge(nums1, m, nums2, n);
	return nums1 == groundTruth;
}
REGISTER_TEST(example1){
	vector<int> nums1({1, 2, 3, 0, 0, 0});
	vector<int> nums2({2, 5, 6});
	int n=3, m=3;
	vector<int> groundTruth({1, 2, 2, 3, 5, 6});

	Solution().merge(nums1, m, nums2, n);
	return nums1 == groundTruth;
}

#endif