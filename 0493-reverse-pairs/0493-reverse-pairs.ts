function reversePairs(nums: number[]): number {
function mergeSort(nums: number[], start: number, end: number): number {
        if (start >= end) return 0;
        
        const mid = start + Math.floor((end - start) / 2);
        let count = mergeSort(nums, start, mid) + mergeSort(nums, mid + 1, end);
        
        // Count the reverse pairs
        let j = mid + 1;
        for (let i = start; i <= mid; i++) {
            while (j <= end && nums[i] > 2 * nums[j]) {
                j++;
            }
            count += j - (mid + 1);
        }
        
        // Merge the two halves
        let temp = [];
        let left = start, right = mid + 1;
        while (left <= mid && right <= end) {
            if (nums[left] <= nums[right]) {
                temp.push(nums[left++]);
            } else {
                temp.push(nums[right++]);
            }
        }
        while (left <= mid) {
            temp.push(nums[left++]);
        }
        while (right <= end) {
            temp.push(nums[right++]);
        }
        for (let i = start; i <= end; i++) {
            nums[i] = temp[i - start];
        }
        
        return count;
    }
    
    return mergeSort(nums, 0, nums.length - 1);
};