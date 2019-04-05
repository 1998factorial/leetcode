/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) { //O(n^2)
        vector<int> ret;
        ListNode* cur = head;
        while(cur != nullptr){
            ListNode* n = cur->next;
            while(n != nullptr){
                if(n->val > cur->val)break;
                n = n->next;
            }
            if(!n)ret.push_back(0);
            else ret.push_back(n->val);
            cur = cur->next;
        }
        return ret;
    }
};

//monotonic stack
//stack keep tracks of the indices that we have not yet found the "next_maximal" 
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) { //O(n) solution
        vector<int> ret,stack;
        int n = 0;
        for(ListNode* cur = head; cur; cur = cur->next){
            while(stack.size() && ret[stack.back()] < cur->val){
                ret[stack.back()] = cur->val;
                stack.pop_back(); //solved 
            }
            ret.push_back(cur->val);
            stack.push_back(n);
            n++;
        }
        for(int i : stack)ret[i] = 0; //can not find maximal next for these i
        return ret;
    }
};


