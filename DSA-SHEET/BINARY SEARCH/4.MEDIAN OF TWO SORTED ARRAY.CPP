// https://leetcode.com/problems/median-of-two-sorted-arrays


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
                if(nums2.size()<nums1.size())
        {
            return findMedianSortedArrays(nums2,nums1);
        }
        int n1=nums1.size();
        int n2=nums2.size();
        int low=0;
        int high=n1;
        while(low<=high)
        {
            int cut1=(low+high)/2;
            //a b c d
            //e f g h i j
            //total= 10 elements we need to divide array into two halves i.e 5 each
            //a b | c d and now we meed 5-2=3 more elements req on each half so 2nd cut will be at e f g | h i j
            int cut2=(n1+n2+1)/2-cut1;
            //elements at left of cut point
            int l1=cut1==0?INT_MIN:nums1[cut1-1];
            int l2=cut2==0?INT_MIN:nums2[cut2-1];
            //elements after (right) cut point
            int r1=cut1==n1?INT_MAX:nums1[cut1];
            int r2= cut2==n2?INT_MAX:nums2[cut2];
            if(l1<=r2 && l2<=r1)
            {
                if((n1+n2)%2==0)
                {
                    return ((max(l1,l2) + min(r1,r2))*1.0/2.0);
                }
                else
                {
                    return max(l1,l2);
                }
            }
            //suppose we have an element on left side which greater than right side element , invalid case move the parition before the current position to keep left side elements smaller than right side elements, meaning decrases cut1-1,bringing cut towards left side thus making l1 smaller than r2
            else if(l1>r2)
            {
                high=cut1-1;
            }
            //if l2 >r1 then we know we need to bring any element from right side to left and remove l2 to right right means increase the cut1+1, thus making l2<=r2
            else
            {
                low=cut1+1;
            }
        }
        return 0.0;
    }
                        
};
