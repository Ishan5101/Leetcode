class Solution {
public:
    int partition(vector<int>& nums, int l, int r) {

        int pivot = nums[r];

        int left = l;
        int right = r - 1;

        while (left <= right) {

            while (left <= right && nums[left] <= pivot)
                left++;

            while (left <= right && nums[right] > pivot)
                right--;

            if (left < right)
                swap(nums[left], nums[right]);
        }

        swap(nums[left], nums[r]);

        return left;
    }

    int quickSelect(vector<int>& nums, int l, int r, int k) {

        int p = partition(nums, l, r);

        if (p == k)
            return nums[p];

        if (p < k)
            return quickSelect(nums, p + 1, r, k);

        return quickSelect(nums, l, p - 1, k);
    }

    int findKthLargest(vector<int>& nums, int k) {

        int target = nums.size() - k;

        return quickSelect(nums, 0, nums.size() - 1, target);
    }
};