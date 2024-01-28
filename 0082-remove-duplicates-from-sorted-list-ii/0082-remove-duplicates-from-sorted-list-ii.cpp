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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return NULL;
        if(head->next == NULL) return head;
        ListNode* prev = NULL;ListNode* current1 = head;ListNode* current2 = head->next;
        while(current1->next!= NULL){
            if(current1->val != current2->val){
                prev = current1;
                current1 = current2;
                if(current2 != NULL) current2 = current2->next;
            }
            else{
                while(current1 != NULL){
                    current2 = current2->next;
                    if(current2 == NULL){
                        if(prev != NULL) prev->next = NULL;
                        else return NULL;
                        return head;
                    }
                    if(current1->val != current2->val){
                        current1 = current2;
                        current2 = current2->next;
                        if(prev != NULL) prev->next = current1;
                        else head = current1;
                        break;
                    }
                }
            }
        }
        return head;
    }
};