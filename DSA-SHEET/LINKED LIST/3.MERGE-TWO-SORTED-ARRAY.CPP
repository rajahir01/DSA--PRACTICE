// https://leetcode.com/problems/merge-two-sorted-lists/


// BRUTE FORCE METHOD
// The strategy here uses a temporary dummy node as the start of the result list. The pointer tail always points to the last node in the result list, so appending new nodes is easy. The dummy node gives the tail something to point to initially when the result list is empty. This dummy node is efficient since it is only temporary, and it is allocated in the stack. The loop proceeds, removing one node from either a or b and adding it at the tail. When we are done, the result is in dummy.next.

// L1 and L2 two LL
// Solution Step
// If one of the lists is empty return the other.
// Initialize a node output = NULL, which will the head of the merged list. Compare the first element of both list and create a dummy node temp which stores the smaller value and make output referencing to it.
// If A.val < B.val, create a dummy node temp and set output = temp and A = A.next.
// Else, create a dummy node temp and set output = temp and B= B.next.
// 3. Initialize a pointer curr = output and Iterate till any of the lists reaches its end. Compare the current node’s value of both the list

// If A.val < B.val, create a dummy node temp and set curr.next = temp and B= B.next.
// Else, create a dummy node temp and set curr.next = temp and A= A.next
// Move the curr pointer, curr = curr.next.
// 4. If list A reaches its end in the above loop then append the remaining node of B into the output list (or vice versa).

// 5. Return output.

if(L1==NULL) return L2; //base
if(L2==NULL) return L1;// base
ListNode* OP=NULL;
if(L1.val < L2.val){
  ListNode* temp= ListNode*(L1.val);
  OP=temp;
  L1=L1.next;
}
else
{
  ListNode* temp = ListNode*
}
