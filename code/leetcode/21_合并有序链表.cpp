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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head;
        if(list1 == nullptr || list2 == nullptr) { 
            return ( (list1 == nullptr) ? list2 : list1); 
        }
        else {
            head = ((list1->val<=list2->val)? list1 : list2);
            ListNode* current1=list1;
            ListNode* current2=list2;
            ListNode* pre=head;
            if(pre==list1) {
                current1=list1->next;
            }
            else {
                current2=list2->next;
            }

            while(current1!=nullptr&&current2!=nullptr) {
                if(current1->val<=current2->val) {
                    pre->next=current1;
                    current1=current1->next;
                    pre=pre->next;
                }
                else if(current1->val>current2->val) {
                    pre->next=current2;
                    current2=current2->next;
                    pre=pre->next;
                }
            }
            pre->next=((current1==nullptr) ? current2:current1);
            return head;
        }
       
    }
};