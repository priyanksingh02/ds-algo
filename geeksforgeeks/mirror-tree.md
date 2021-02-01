```cpp
/* Should convert tree to its mirror */
void mirror(Node* node) 
{
  if(!node) return ;
  mirror(node->left);
  mirror(node->right);
  swap(node->left, node->right);
}

```
