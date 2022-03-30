/*
 * @lc app=leetcode.cn id=2049 lang=cpp
 *
 * [2049] 统计最高分的节点数目
 */

// @lc code=start
class Solution
{
public:
    int countHighestScoreNodes(vector<int> &parents)
    {
        //用数组存储二叉树
        int maxscore = -1;
        int maxnum = 0;
        int n = parents.size();
        int tree[n] = {-1};
        tree[1] = 0;
        //数组建树
        for (int i = 0; i < n; i++)
        {
            int flag = 0;
            for (int j = 1; j < n; j++)
            {
                if (parents[j] = i && flag == 0)
                {
                    tree[2 * i] = j;
                    flag++;
                }
                if (parents[j] = i && flag == 1)
                {
                    tree[2 * i + 1 ] = j;
                }
            }
        }
        //a0为父亲节点大小a1a2为两个儿子节点大小
        int a[3] = 1;
        for(int i = 0; i < n; i++){
            while(i / 2){
                tree[]
            }
        }

    }
};
// @lc code=end
