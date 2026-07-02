class Solution {
public:
    int search(vector<int>& nums, int target) {
        //since we know array is sorted we can apply binary search thats the first hint 
        int low=0;
        int high=nums.size()-1;
        
        while(high>=low){
            int mid=low+(high-low)/2; //instead of (low+high)/2 to avoid tle
            if(nums[mid]==target)return mid;
            if(target<nums[mid]){
                high=mid-1;
            }
            else low=mid+1;

        }
        return -1;
    }
    
}; 