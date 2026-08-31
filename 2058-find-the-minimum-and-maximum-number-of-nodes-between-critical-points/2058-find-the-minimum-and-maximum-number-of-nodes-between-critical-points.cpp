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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head->next->next==nullptr)
        return {-1,-1};
        int mini=INT_MAX;
        int maxi;

        int prev=head->val;
        head=head->next;
        int first=-1;
        int last=-1;
        int i=1;
        while(head->next)
        {
            if((head->val>prev && head->val>head->next->val) ||
            (head->val<prev && head->val<head->next->val))
            {
                if(last==-1)
                {
                    last=i;
                    first=i;
                }
                else
                {
                    mini=min(mini,i-last);
                    maxi=i-first;
                    last=i;
                }
            }
            prev=head->val;
            head=head->next;
            i++;
        }
        if(mini==INT_MAX)
        return {-1,-1};
        else
        return {mini,maxi};
    }
};