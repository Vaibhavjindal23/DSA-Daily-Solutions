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
    ListNode* reverse(ListNode* head){
        if(head == nullptr ||head->next == nullptr){
            return head;
        }
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* after = head;
        while(curr!=nullptr){
            after = curr->next;
            curr->next = prev;
            prev = curr; 
            curr = after;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
       
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast ->next->next;
        }
        ListNode* pass = slow;
        ListNode* reversehead = reverse(pass);
        ListNode* temp = reversehead;
        ListNode* moving = head;
        while(temp!=nullptr){
            if(temp->val != moving->val){
                return false;
            }
            moving = moving->next;
            temp = temp->next;
        }
        return true;
    }
};
