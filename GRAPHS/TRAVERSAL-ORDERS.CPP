// THERE ARE 4 TRAVERSAL ORDER WHICH ARE
// PRE ORDER
void preorder(node* node)
{
  if(node!=NULL)
  {
    cout<<node->data;
    preorder(node->left);
     preorder(node->right);
  }
}



void inorder(node* node)
{
  if(node!=NULL)
  {
    inorder(node->left);
    cout<<node->data;
     inorder(node->right);
  }
}




void postorder(node* node)
{
  if(node!=NULL)
  {
    postorder(node->left);
     postorder(node->right);
    cout<<node->data;
  }
}

