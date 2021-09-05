class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        if(nums.size() <= 1)
            return 0;
        
        
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int mid = low + (high-low)/2;
        
        while( low <= high){
            
                mid = low + (high-low)/2;
            if( mid>0 and mid<n-1){
                    
                if( nums[mid]>nums[mid-1] and nums[mid]>nums[mid+1])
                    return mid;
                else if( nums[mid+1] > nums[mid]){
                    low = mid+1;
                }else if( nums[mid-1] > nums[mid]){
                    high = mid-1;
                }
                
            }else if (mid == 0){
                if(nums[mid] > nums[mid+1])
                    return mid;
                else
                    return mid+1;
            }else if( mid == n-1){
                if(nums[mid]>nums[mid-1])
                    return mid;
                else
                    return mid-1;
            }
            
        }
        
        return mid;
        
    }
};