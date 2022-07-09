// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

// BRUTE FORCE METHOD
// NTH NODE FROM THE END
//1 > Calculate the total length for the linked list.
//2 > Determine the count of the node which is going to be nth from the end.
//3 > Parse through the linked list and delete the node by setting it's previous node's next to current node's next.

 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
 if(n==0) return head;
   ListNode* dummy = head;
   int len=0;
   while(dummy->next!=0)
   {
     len++;
     dummy=dummy->next; // counting the length of LL
   }
   
   int nth = len-n+ 1;  // node to deleted from the end
        // cout<<"len"<<len<<endl;
        // cout<<"nth"<<nth<<endl;
   if(nth==len){ // means have to delete head
     ListNode* node= head;
     head=head->next;
     delete(node);
     
   }
   
   
   
   ListNode* t=head;
    int count=1;
     while(count<nth  && len!=nth){
       t=t->next;
         count++;
     }
        if(len!=nth){
   ListNode* node= t->next;
   t->next=t->next->next;
   delete(node);
        }
        
        
        return head;
        
        
    }
};


// TC - O(2N)




// OPTIMIZED APPROACH
// TWO POINTER

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* start= new ListNode();
        start->next=head;
        ListNode* fast= start;
        ListNode* slow= start;
        for(int i=1;i<=n;i++){  // traversing till nth position
            fast=fast->next;
        } // fast took n steps
        
        while(fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;
        
        
        return start->next;  // bcoz head pointing to start->next
        
        
        
        
    }
};


// TC- O(1)
// SC- O(1)
