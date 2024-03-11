/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    // To track parent node of each node in the tree
    /**
     * Definition for a binary tree node.
     * struct TreeNode {
     *     int val;
     *     TreeNode *left;
     *     TreeNode *right;
     *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
     * };
     */
    class Solution
    {
    public:
        int burnTheTree(TreeNode *root, TreeNode *target, map<TreeNode *, TreeNode *> &nodeToParent)
        {
            int time = 0;
            queue<TreeNode *> q;
            map<TreeNode *, bool> vis;
            q.push(target);
            vis[target] = true;
            while (!q.empty())
            {
                int s = q.size();
                bool flag = false;
                for (int i = 0; i < s; i++)
                {
                    TreeNode *temp = q.front();
                    q.pop();
                    if (temp->left && !vis[temp->left])
                    {
                        q.push(temp->left);
                        vis[temp->left] = true;
                        cout << temp->left->val << " " << vis[temp->left] << " ";
                        flag = true;
                    }
                    if (temp->right && !vis[temp->right])
                    {
                        q.push(temp->right);
                        vis[temp->right] = true;
                        cout << temp->right->val << " " << vis[temp->right] << " ";
                        flag = true;
                    }
                    if (nodeToParent[temp] && !vis[nodeToParent[temp]])
                    {
                        q.push(nodeToParent[temp]);
                        vis[nodeToParent[temp]] = true;
                        cout << nodeToParent[temp]->val << " " << vis[nodeToParent[temp]] << " ";
                        flag = true;
                    }
                }
                if (flag)
                {
                    time++;
                }
                cout << "TIME : " << time << endl;
            }
            return time;
        }
        TreeNode *createMapping(TreeNode *root, map<TreeNode *, TreeNode *> &nodeToParent, int start)
        {
            TreeNode *res = NULL;
            queue<TreeNode *> q;
            q.push(root);
            nodeToParent[root] = NULL;
            while (!q.empty())
            {
                TreeNode *topEle = q.front();
                q.pop();
                if (topEle->val == start)
                {
                    res = topEle;
                }
                if (topEle->left)
                {
                    nodeToParent[topEle->left] = topEle;
                    q.push(topEle->left);
                }
                if (topEle->right)
                {
                    nodeToParent[topEle->right] = topEle;
                    q.push(topEle->right);
                }
            }
            return res;
        }
        int amountOfTime(TreeNode *root, int start)
        {
            map<TreeNode *, TreeNode *> m;
            TreeNode *target = createMapping(root, m, start);
            int ans = burnTheTree(root, target, m);
            return ans;
        }
    };
};