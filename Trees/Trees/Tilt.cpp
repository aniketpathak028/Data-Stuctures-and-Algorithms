
 struct TreeNode {
  int val;
  TreeNode *left;
 TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    long long int tiltSum= 0;
    long long int findSum(TreeNode* root, long long int &sum){
        if(!root) return 0;
        
        long long int leftSum = findSum(root->left, sum);
        long long int rightSum = findSum(root->right, sum);
        sum += root->val + leftSum + rightSum;
        return sum;  
    }
    void tilt(TreeNode* root){
        if(!root) return;
        
        long long int left = findSum(root->left, left);
        long long int right = findSum(root->right, right);
        long long int currTilt = abs(left-right);
        tiltSum+= currTilt;
        tilt(root->left);
        tilt(root->right);
    }
    long long int  findTilt(TreeNode* root) {
        tilt(root);
        return tiltSum;
    }
};