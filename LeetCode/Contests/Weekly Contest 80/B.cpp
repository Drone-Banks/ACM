/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

bool in[10005];

class Solution {

public:
    int numComponents(ListNode* head, vector<int>& G) {
        int ans = 0;
        memset(in,0,sizeof(in));
        for(int x : G) in[x] = 1;
        int now = -1;
        
        ListNode* one = head;
        while(one != NULL) {
            if(in[one->val]){
                if(now==-1) now=++ans;
            }
            else now = -1;
            one = one->next;
            // cout << ans << " " << now << endl;
        }
        return ans;
        
    }
};