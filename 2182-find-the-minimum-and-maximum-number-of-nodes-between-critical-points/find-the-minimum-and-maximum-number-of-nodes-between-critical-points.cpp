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
        vector<int> criticalPointIdx;
        if(head == NULL || head->next == NULL || head->next->next == NULL){
            return {-1, -1};
        }
        ListNode* temp = head->next;
        ListNode* prev = head;
        int idx = 0;
        while(temp){
            idx++;
            if(temp->next != NULL){
                if(prev->val < temp->val && temp->val > temp->next->val){
                    criticalPointIdx.push_back(idx);
                }
                else if(prev->val > temp->val && temp->val < temp->next->val){
                    criticalPointIdx.push_back(idx);
                }
            }
            prev = temp;
            temp = temp->next;
        }
        // for(auto it : criticalPointIdx){
        //     cout<<it<<" ";
        // }
        int m = criticalPointIdx.size();
        if(m == 0 || m == 1){
            return {-1, -1};
        }
        int maxi = criticalPointIdx[m-1] - criticalPointIdx[0];
        int mini = 1e9;
        for(int i =0; i<m-1; i++){
            mini = min(mini, criticalPointIdx[i+1] - criticalPointIdx[i]);
        }
        if(mini == 1e9) mini = -1;
        return {mini, maxi};
    }
};