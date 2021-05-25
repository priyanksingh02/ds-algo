```cpp
enum  state {cover, has_camera, covered};
class Solution {
public:
    int ans = 0;

    int minCameraCover(TreeNode* root) {
        return (check(root) == cover)? ++ans: ans;
    }

    state check(TreeNode* root) {
        if(!root) {
            return covered;
        }
        state l = check(root->left);
        state r = check(root->right);
        if(l == cover || r == cover) {
            ++ans;
            return has_camera;
        }
        if(l == has_camera || r == has_camera) {
            return covered;
        }

        return cover;
    }
};
```
