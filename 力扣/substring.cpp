#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>


using namespace std;

//560.和为K的子数组串。
//思路就是按顺序计算前n个的和，将和存入map中，每增加一个新增的元素，就查找有无current_sum-k，有的话增加符合的数量，最后在map中增加current_sum的计数
class Solution1{
    public:
        int subarraySum(vector<int>& nums,int k){
            unordered_map<int,int> prefix_count;
            prefix_count[0]=1; //初始化数组
            int count=0;
            int current_sum=0;

            for(int num:nums){
                //求和  
                current_sum+=num;
                if(prefix_count.find(current_sum-k)!=prefix_count.end()){
                    count+=prefix_count[current_sum-k];
                }
                prefix_count[current_sum]++;

            }
            return count;

        }

        vector<vector<int>> findAllSubArray(vector<int>& nums,int k){
            unordered_map<int ,vector<int>> prefix_map;
            prefix_map[0]={-1};
            int current_sum=0;
            vector<vector<int>> result;

            for (size_t i = 0; i < nums.size(); i++)
            {
                current_sum+=nums[i];
                int target=current_sum-k;

                if(prefix_map.find(target)!=prefix_map.end()){
                    for (int start:prefix_map[target])
                    {
                        vector<int> subarray(nums.begin()+start+1,nums.begin()+i+1);
                        result.push_back(subarray);
                    }
                    
                }
                prefix_map[current_sum].push_back(i);
            }
            return result;
            
        }
};


// 力扣第三题，无重复字符的最长子串
// 思路：用一个哈希表来记录每个字符的索引，当遇到重复字符时，更新左指针的位置为重复字符的下一个位置。
// 本题出现的错误：对于map的operator[]不熟悉，该错做用于通过key访问或者插入对应的value
class solution2{
    public:
        int lengthofLongestSubstring(string s){
            unordered_map<char,int> char_index;
            int max_length=0; //最长子串长度
            int left=0; //左指针
            // 遍历字符串
            for(size_t right=0; right<s.size();right++){
                // 如果字符已经在哈希表中，更新左指针的位置为重复字符的下一个位置
                if(char_index.find(s[right])!=char_index.end() && char_index[s[right]]>=left){
                    left=char_index[s[right]]+1;       
                }
                // 更新字符的索引
                char_index[s[right]]=right;
                // 计算当前子串的长度
                max_length=max(max_length,static_cast<int>(right-left+1));
            }
            return max_length;
        }

};


// 力扣56 合并区间
// 思路：先按照区间的左端点进行排序，然后遍历区间，如果当前区间的左端点小于等于前一个区间的右端点，则说明它们有重叠，将它们合并；否则，将当前区间加入结果数组中。
class Solution3{
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals){
            if (intervals.empty()) return {};
            // 按照区间的左端点进行排序
            sort(intervals.begin(), intervals.end(),
                 [](const vector<int>& a, const vector<int>& b) {
                     return a[0] < b[0];
                 });
            vector<vector<int>> merged;
            merged.push_back(intervals[0]); // 添加第一个区间
            // 遍历区间
            for(size_t i=1;i<intervals.size();i++){
                // 如果当前区间的左端点小于等于前一个区间的右端点，则说明它们有重叠，将它们合并
                if(intervals[i][0]<=merged.back()[1]){
                    merged.back()[1]= max(merged.back()[1], intervals[i][1]);
                }else{
                    // 否则，将当前区间加入结果数组中
                    merged.push_back(intervals[i]);
                }
            }
            return merged;
        }
};