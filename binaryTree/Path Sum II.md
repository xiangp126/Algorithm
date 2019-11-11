## Path Sum II
### Illustrate
<https://leetcode.com/problems/path-sum-ii/>

Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.


Example:

```
Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
```

Return:

```
[
   [5,4,11,2],
   [5,8,4,5]
]
```

### Code - _with C++_

- vector::pop_back

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ret;
        vector<int> path;
        dfs(root, sum, path, ret);
        return ret;
    }
    
    void dfs(TreeNode *root, int gap, vector<int> &path,
             vector<vector<int>> &ret) {
        if (root == NULL) {
            return;
        }
        
        path.push_back(root->val);
        
        if (root->left == NULL && root->right == NULL && root->val == gap) {
            ret.push_back(path);
        }
        
        dfs(root->left, gap - root->val, path, ret);
        dfs(root->right, gap - root->val, path, ret);
        
        path.pop_back();
    }
};
```

### Code - _with Java_
```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> ret = new ArrayList<>();
        List<Integer> path = new ArrayList<>();
        dfs(root, sum, path, ret);
        return ret;
    }

    public void dfs(TreeNode root, int gap, List<Integer> path,
                    List<List<Integer>> ret) {
        if (root == null) {
            return;
        }

        path.add(root.val);

        if (root.left == null && root.right == null && root.val == gap) {
            // ret.add(path);
            // for java, you should new an ArrayList copying path
            ret.add(new ArrayList<>(path));
        }

        dfs(root.left, gap - root.val, path, ret);
        dfs(root.right, gap - root.val, path, ret);

        path.remove(path.size() - 1);
    }
}
```