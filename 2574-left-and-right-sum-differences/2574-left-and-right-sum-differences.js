/**
 * @param {number[]} nums
 * @return {number[]}
 */
var leftRigthDifference = function(nums) {
    let size = nums.length;
    let ans = new Array(size);
    let leftsum = new Array(size);
    let rightsum = new Array(size);
    leftsum[0] = 0;
    rightsum[size-1] = 0; 
    for(let i = 1 ; i < ans.length ; i++){
        leftsum[i] = leftsum[i-1] + nums[i-1];
        console.log(leftsum[i]);
    }
    for(let i = ans.length-2 ; i>=0 ; i--){
        rightsum[i] = rightsum[i+1] + nums[i+1];
    }
    for(let i = 0 ; i < nums.length ; i++){
        ans[i] = Math.abs(leftsum[i] - rightsum[i]); 
    }
    return ans;
};