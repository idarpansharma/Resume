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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode*temp= head;
         ListNode*back= NULL;
          ListNode*curr= head;
          ListNode*ins= head;
          int count=0;
          while(ins!=NULL){
            count++;
            ins=ins->next;
          }
          k=k%count;
          
          while(temp!=NULL && k!=0){
            if(temp->next==NULL){
                temp->next=curr;
                back->next=NULL;
                head=temp;
                curr=temp;
                k--;


            }
            back=temp;
            temp=temp->next;



          }
          return curr;

    }
};