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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *odd_ptr=NULL;
        ListNode *even_ptr=NULL;
        ListNode *head2=NULL;
        ListNode *head1=NULL;
        int count=0;
        while(head!=NULL){
            count++;
            if(count%2==1){
                if(head1==NULL){
                    head1=head;
                    odd_ptr=head;
                }
                else{
                    odd_ptr->next=head;
                    odd_ptr=head;
                }
            }
            else{
                if(head2==NULL){
                    head2=head;
                    even_ptr=head;
                }
                else{
                    even_ptr->next=head;
                    even_ptr=head;
                } 
            }
            head=head->next;
            
        }
        
        if(head1==NULL) return NULL;
        odd_ptr->next=head2;
        if(head2!=NULL) even_ptr->next=NULL;
        return head1;
        
    }
};