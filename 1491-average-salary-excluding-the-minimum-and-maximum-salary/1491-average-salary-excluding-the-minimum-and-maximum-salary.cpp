class Solution {
public:
    double average(vector<int>& salary) {
        int n=salary.size();
        int mini=*min_element(salary.begin(),salary.end());
        int maxi=*max_element(salary.begin(),salary.end());
        double sum=accumulate(salary.begin(),salary.end(),0)-mini-maxi;
        return sum/(n-2);
    }
};