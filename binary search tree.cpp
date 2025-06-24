#include <iostream>
using std::cout;

class node
{
  private:
  public:
  int data;
  node* left;
  node* right;

  node() : data(0) , left(nullptr) , right(nullptr) {}
  node(int val) : data(val) , left(nullptr) , right(nullptr) {}

};


class BST
{
  private:
  node* root;
  size_t size;
  public:
  BST() : root(nullptr) , size(0) {}
  ~BST() { clear(); }
  bool empty() const
  {
    return this->root == nullptr;
  }


  node* insert_recursive_helper(node* subRoot , int val)
  {
    if(subRoot == nullptr)
    {
      subRoot = new node(val);
      ++size;
      return subRoot;
    }
    else
    {
      if(val < subRoot->data)
      {
        subRoot->left = insert_recursive_helper(subRoot->left , val);
      }
      
      else if(val > subRoot->data) // Greater
      {
        subRoot->right = insert_recursive_helper(subRoot->right , val);
      }

      else /* Equal */
      {
        cout << "Repeated Value\n";
        return subRoot;
      }
    }
    return subRoot;
  }

  void insert_recursive(int val)
  {
    this->root = insert_recursive_helper(this->root , val);
  }

  node* insert_iterative(int val)
  {
    if(this->empty())
    {
      this->root = new node(val);
      ++this->size;
      return this->root;
    }

    node *current = this->root;
    node *parent = nullptr;
    while (current != nullptr)
    {
      parent = current;
      if (val < current->data) // smaller
      {
        current = current->left;
      }

      else if (val > current->data) // greater
      {
        current = current->right;
      }

      else // equal
      {
        cout << "Repeated Value\n";
        return parent;
      }
    }

    node *newNode = new node(val);
    if (val < parent->data)
    {
      parent->left = newNode;
    }
    else // only  >
    {
      parent->right = newNode;
    }

    ++this->size;

    return newNode;
  }

  void pre_order_helper(node* subRoot) const // Root => Left => Right
  {
    if( subRoot == nullptr )
    {
      return;
    }
    cout << subRoot->data << ' ';
    pre_order_helper(subRoot->left);
    pre_order_helper(subRoot->right);
  }
  void pre_order() const
  {
    if( this->root == nullptr )
    {
      cout << "Tree Is Empty\n";
      return;
    }
    pre_order_helper( this->root );
    cout << '\n';
  }

  void in_order_helper(node* subRoot) const // Left => Root => Right
  {
    if( subRoot == nullptr )
    {
      return;
    }
    in_order_helper(subRoot->left);
    cout << subRoot->data << ' ';
    in_order_helper(subRoot->right);
  }
  void in_order() const
  {
    if( this->root == nullptr )
    {
      cout << "Tree Is Empty\n";
      return;
    }
    in_order_helper( this->root );
    cout << '\n';
  }

  void post_order_helper(node* subRoot) const // Left => Right => Root
  {
    if( subRoot == nullptr )
    {
      return;
    }
    post_order_helper(subRoot->left);
    post_order_helper(subRoot->right);
    cout << subRoot->data << ' ';
  }
  void post_order() const
  {
    if( this->root == nullptr )
    {
      cout << "Tree Is Empty\n";
      return;
    }
    post_order_helper( this->root );
    cout << '\n';
  }


  node* find_helper(node* subRoot , int key) const
  {
    if( subRoot == nullptr ) return nullptr;
    else if( key == subRoot->data ) return subRoot;
    else if( key < subRoot->data )
    {
      return find_helper(subRoot->left , key);
    }
    else
    { 
      return find_helper(subRoot->right , key);
    }
  }

  bool find(int key) const
  {
    if( this->empty() )
    {
      cout << "Empty\n";
      return false;
    }
    return (find_helper(this->root , key) != nullptr);
  }


  node* find_min_helper(node* subRoot) const
  {
    if(subRoot->left == nullptr)
    {
      return subRoot;
    }
    return find_min_helper(subRoot->left);
  }

  node* find_min() const
  {
    if( this->empty() )
    {
      cout << "Empty\n";
      return nullptr;
    }
    return find_min_helper(this->root);
  }

  node* find_max_helper(node* subRoot) const
  {
    if(subRoot->right == nullptr)
    {
      return subRoot;
    }
    return find_max_helper(subRoot->right);
  }

  node* find_max() const
  {
    if( this->empty() )
    {
      cout << "Empty\n";
      return nullptr;
    }
    return find_max_helper(this->root);
  }

  node* Delete_helper(node* subRoot, int val)
  {
    if(subRoot == nullptr)
    {
      cout << "Invalid\n";
      return nullptr;
    }
    if(val < subRoot->data)
    {
      // cout << "node " << subRoot->data << " wants to delete " << val << '\n';
      // cout << "go left\n";
      subRoot->left = Delete_helper(subRoot->left , val);
    }
    else if(val > subRoot->data)
    {
      // cout << "node " << subRoot->data << " wants to delete " << val << '\n';
      // cout << "go right\n";
      subRoot->right = Delete_helper(subRoot->right , val);
    }
    else
    {
      // cout << "found\n";
      if(subRoot->left == nullptr and subRoot->right == nullptr) // leaf node
      {
        // cout << "leaf delete\n";
        delete subRoot;
        --this->size;
        return nullptr;
      }
      else if(subRoot->left != nullptr and subRoot->right == nullptr) // one child at left
      {
        subRoot->data = subRoot->left->data;
        subRoot->left = Delete_helper(subRoot->left , subRoot->left->data);
      }
      else if(subRoot->left == nullptr and subRoot->right != nullptr) // one child at right
      {
        subRoot->data = subRoot->right->data;
        subRoot->right = Delete_helper(subRoot->right , subRoot->right->data);
      }
      else // two children
      {
        // cout << "two children delete\n";
        node* greater_left = find_max_helper(subRoot->left);
        /*
         * OR  node* least_right = find_min_helper(subRoot->right);
         */
        subRoot->data = greater_left->data;
        subRoot->left = Delete_helper(subRoot->left , greater_left->data);
      }
    }
    return subRoot;
  }

  void Delete(int value)
  {
    this->root = Delete_helper(this->root , value); // this.root = is for one node case
  }

  void clear_helper(node* root)
  {
    if(root == nullptr) return;
    clear_helper(root->left);
    clear_helper(root->right);
    delete root;
  }

  void clear()
  {
    this->clear_helper(this->root);
    this->root = nullptr;
    this->size = 0;
  }

};


int main()
{
  BST tree;
  tree.insert_recursive(100);
  tree.insert_recursive(150);
  tree.insert_recursive(50);
}