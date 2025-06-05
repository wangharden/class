#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<set>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x)
    :val(x),next(nullptr)
    {}
};

class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int j=nums.size();
        for (int i = 0; i < j; i++)
        {
            int result=target-nums[i];
            for(int a=i+1;a<j;a++){
                if (nums[a]=result)
                {
                    return {i,a}   ;
                }
                
            }
        }
        return {};
        
    }
};

class Solution2 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> mp;
        for(string& str:strs){
            string key = str;   // 复制索引
            sort(key.begin(),key.end()); //sort的用法
            mp[key].emplace_back(str); // 在尾部构建元素的语法
        }
        vector<vector<string>> ans;
        for(auto it=mp.begin();it!=mp.end();++it){
            ans.emplace_back(it->second); //给ans数组构建元素的方法
        }
        return ans;
    }
};

class Solution3 {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> num_set;
        for(const auto it:nums){
            num_set.insert(it);
        }
        int longestcount=0;
        for(const auto it:num_set){
            if (!num_set.count(it-1)) //查找set中某个数的语法
            {
                int current=it;
                int currentcount=1;
    
            
            while (num_set.count(current+1)) //不能用if，因为if只会判断一次
            {
                current+=1;
                currentcount+=1;
            }
            longestcount=max(longestcount,currentcount);
            
        }
    }
    return longestcount;
}
};


class solution4{
public:void moveZeros(vector<int>& nums){
    int n=nums.size(),left=0,right=0;
    while(right<n){
        if(nums[right]){
            swap(nums[left],nums[right]);
            left++;
        }
        right++;
    }
}
};
class Solution5 {
public:
    int maxArea(vector<int>& height) {
        int l=0,r=height.size()-1;
        int ans=0;
        while(l<r){
            int area=min(height[l],height[r])*(r-l);
            ans=max(ans,area);
            if (height[l]<height[r])
            {
                l++;
            }
            else{
                --r;
            }
        }
        return ans;
    }

};

class Solution6 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*> visted;
        ListNode* temp=headA;
        while (temp!=nullptr)
        {
            visted.emplace(temp);
            temp=temp->next;
        }
        temp=headB;
        while (temp!=nullptr)
        {
            if(visted.count(temp)){
                return temp;
            }
            temp=temp->next;
        }
        return nullptr;
        
    }
};

class Solution7 {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode* Newhead = reverseList(head->next);
        head->next->next=head;
        head->next=nullptr;
        return Newhead;
    }
};

class Solution8 {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow =head;
        ListNode *qucick =head;
        while(qucick->next!=nullptr && qucick!=nullptr){
            slow=slow->next;
            qucick=qucick->next->next;
        }
        slow=rotate(slow);
        ListNode* pre=slow;
        bool ans=1;
        while (ans && slow->next!=nullptr)
        {
            if (slow->val!=head->val)
            {
                return ans=0;
            }
            slow=slow->next;
            head=head->next;
        }
        pre=rotate(pre);
        return ans;
        
    }
    ListNode* rotate(ListNode* head){
        ListNode* temp=nullptr;
        ListNode* cur=head;
        while(cur){
            ListNode* next=cur->next;
            cur->next=temp;
            temp=cur;
            cur=next;
        }
        return temp;
        
    }

};

class Solution9 {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==nullptr){
            return list2;
        }
        else if (list2==nullptr)
        {
            return list1;
        }
        else if (list1->val<list2->val)
        {
            list1->next=mergeTwoLists(list1->next,list2);
            return list1;
        }
        else if (list1->val>list2->val){
            list2->next=mergeTwoLists(list1,list2->next);
            return list2;
        }
        
    }
};

