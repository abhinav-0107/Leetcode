void bubblesort(int *nums, int numsSize)
{
    int temp;
    for (int j = 0; j < numsSize - 1; j++)
    {
        for (int i = 0; i < numsSize - 1 - j; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                temp = nums[i + 1];
                nums[i + 1] = nums[i];
                nums[i] = temp;
            }
        }
    }
}
int maxProductDifference(int *nums, int numsSize)
{
    bubblesort(nums, numsSize);
    int maxproduct = (nums[numsSize - 1] * nums[numsSize - 2]) - (nums[0] * nums[1]);
    return maxproduct;
}