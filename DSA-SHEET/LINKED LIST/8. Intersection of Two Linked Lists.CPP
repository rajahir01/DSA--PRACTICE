// https://leetcode.com/problems/intersection-of-two-linked-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // BRUTE FORCE METHOD
//         if(headA==NULL || headB==NULL){
//             return NULL;
//         }
//         ListNode* tempA=headA;
//         while(tempA!=NULL){
//             ListNode* tempB=headB;
//             while(tempB!=NULL){
//                 if(tempA==tempB){
//                     return tempA;
//                 }
//                 tempB=tempB->next;
//             }
//             tempA=tempA->next;
//         }
//         return NULL;
        
        
        
        // OPTIMIZED APPROACH USING TWO POINTER METHOD
        
                if(headA==NULL || headB==NULL){
                return NULL;}
                    ListNode* a=headA;
                    ListNode* b=headB;
                    
                    while(a!=b){
                        a=a==NULL? headB:a->next;
                        b=b==NULL? headA:b->next;
                    }
         return a;
        //TC- O(2M)
        //SC- O(1)
        
        
        
    }
};
