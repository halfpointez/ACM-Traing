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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummyHead = new ListNode(0);
    ListNode* l3 = dummyHead;

    int add = 0;
    int sum;
    while (l1 != nullptr || l2 != nullptr || add > 0) {
      sum = add;
      if (l1 != nullptr) {
        sum += l1->val;
        l1 = l1->next;
      }
      if (l2 != nullptr) {
        sum += l2->val;
        l2 = l2->next;
      }
      ListNode* a = new ListNode(sum % 10);
      l3->next = a;
      l3 = a;
      add = sum / 10;
    }
    ListNode* result = dummyHead->next;
    delete dummyHead;
    return result;
  }
};