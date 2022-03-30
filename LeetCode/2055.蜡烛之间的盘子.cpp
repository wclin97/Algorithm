/*
 * @lc app=leetcode.cn id=2055 lang=cpp
 *
 * [2055] 蜡烛之间的盘子
 */
12313
// @lc code=start
/*class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int> answer;
         for(int i = 0; i < queries.size(); i++){
            int front = queries[i][0];
            int end = queries[i][1];
            while(s[front] == '*'){
                front++;
            }
            while(s[end] == '*'){
                end--;
            }
            answer.push_back(0); 
            
            while(front < end){
                 if(s[front] == '*'){
                    answer[i]++;
                    front++;
                    }else front++;
            }
         }
         return answer;
    }
   
};*/

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        //一道找规律的题目
        const auto n=s.size();
        int prefix[n],deskl[n],deskr[n];
        memset(prefix,0,n),memset(deskl,0,n),memset(deskr,n-1,n);
        int pos=0;
        //需要从左往右遍历填充prefix与deskl
        for(int i=0;i<n;++i){
            if(s[i]=='|'){
                pos=i;
                deskl[i]=pos;
                break;
            }
        }
        for(int i=pos+1;i<n;++i){
            if(s[i]=='|')prefix[i]=prefix[i-1]+i-pos-1,pos=i,deskl[i]=pos;
            else prefix[i]=prefix[i-1],deskl[i]=pos;
        }
        //需要从右往左遍历填充deskr
        pos=n-1;
        for(int i=n-1;i!=-1;--i){
            if(s[i]=='|')pos=i,deskr[i]=pos;
            else deskr[i]=pos;
        }
        vector<int> ans(queries.size(),0);
        for(int i=0;i<ans.size();++i){
            //最终答案为queries点的右边界的最邻近的左桌子的前缀和减去左边界的最邻近的右桌子的前缀和
            ans[i]=prefix[deskl[queries[i][1]]]-prefix[deskr[queries[i][0]]];
            if(ans[i]<0)ans[i]=0;
        }
        return ans;        
    }
};

// @lc code=end

