#include<iostream>
using std::cout;

class node
{
  private:
  // int data;
  // node* next;
  // node* prev;
  
  public:
  node() : data(0) , next(nullptr) , prev(nullptr) {}
  node(int val) : data(val) , next(nullptr) , prev(nullptr) {}
  
  int data;
  node* next;
  node* prev;

  // void set_data(int val) { data = val; }
  // int get_data() { return data; }

  // void set_next(node* ptr){ next = ptr; }
  // node* get_next() { return next; }

  // void set_prev(node* ptr) { prev = ptr; }
  // node* get_prev() { return prev; }

};

class doubly_list
{
  private:
  node* head;
  node* tail;
  size_t size;
  public:
  doubly_list() 
  {
    head = tail = nullptr;
    size = 0;
  }
  ~doubly_list() { this->clear(); }

  bool is_empty() const { return head == nullptr; }

  void insert_at_beginning(int val)
  {
    node* newNode = new node(val);
    if( this->is_empty() ) head = tail = newNode;
    else
    {
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
    }
    ++this->size;
  }
  
  void insert_at_end(int val)
  {
    node* newNode = new node(val);
    if( this->is_empty() ) head = tail = newNode;
    else
    {
      tail->next = newNode;
      newNode->prev = tail;
      tail = newNode;
    }
    ++this->size;
  }

  // TODO:
  void insert_at_position(int val , size_t position) // 1-Based 
  {

    if( position < 1 or position > this->size + 1 )
    {
      cout << "Invalid Position\n";
      return;
    }
    else if(position == 1)
    {
      this->insert_at_beginning(val);
      return;
    }
    else if(position == this->size + 1)
    {
      insert_at_end(val);
      return;
    }
    else
    {
      node *prev_node = head;
      for (size_t i = 1; i < position - 1; i++)
      {
        prev_node = prev_node->next;
      }
      node *newNode = new node(val);
      newNode->next = prev_node->next;
      newNode->prev = prev_node;
      prev_node->next->prev = newNode;
      prev_node->next = newNode;
      ++this->size;
    }
  }

  void insert_after_node(int val , node* prev_node) // 1-Based 
  {
    if(prev_node == nullptr)
    {
      cout << "Invalid Pointer\n";
      return;
    }

    if(prev_node->next == nullptr)
    {
      insert_at_end(val);
      return;
    }

    else
    {
      node *newNode = new node(val);
      newNode->next = prev_node->next;
      newNode->prev = prev_node;
      prev_node->next->prev = newNode;
      prev_node->next = newNode;
      ++this->size;
    }
  }

  void delete_from_beginning()
  {
    if(this->is_empty())
    {
      cout << "Invalid, Empty List\n";
      return;
    }
    if(head->next == nullptr)
    {
      delete head;
      head = tail = nullptr;
    }
    else
    {
      head->next->prev = nullptr;
      node* temp = head;
      head = head->next;
      delete temp;
    }
    --this->size;
  }
  
  void delete_from_end()
  {
    if(this->is_empty())
    {
      cout << "Invalid, Empty List\n";
      return;
    }
    else if(head->next == nullptr)
    {
      delete tail;
      head = tail = nullptr;
    }
    else
    {
      tail->prev->next = nullptr;
      node* temp = tail;
      tail = tail->prev;
      delete temp;
    }
    --this->size;
  }

   // TODO:
  void delete_from_position(size_t position) // 1-Based
  {
    if(position < 1 or position > this->size)
    {
      cout << "Invalid Position\n";
      return;
    }
    if(position == 1)
    {
      this->delete_from_beginning();
      return;
    }
    else if(position == this->size)
    {
      this->delete_from_end();
      return;
    }
    else
    {
      node* deleted = head;
      for(size_t i = 1; i < position; ++i)
      {
        deleted = deleted->next;
      }
      deleted->prev->next = deleted->next;
      deleted->next->prev = deleted->prev;
      delete deleted;
      --this->size;
    }
  } 
  
  void delete_node(node* deleted) // 1-Based
  {
    if(deleted == nullptr)
    {
      cout << "Invalid\n";
      return;
    }
    if(deleted->prev == nullptr)
    {
      this->delete_from_beginning();
      return;
    }
    else if(deleted->next == nullptr)
    {
      this->delete_from_end();
      return;
    }
    else
    {
      deleted->prev->next = deleted->next;
      deleted->next->prev = deleted->prev;
      delete deleted;
      --this->size;
    }
  }  

  void Display() const
  {
    if(this->is_empty())
    {
      cout << "List Is Empty\n";
      return;
    }
    node* current = head;
    while (current != nullptr)
    {
      cout << current->data << ' ';
      current = current->next;
    }
    cout << "NULL\n";
  }

  void clear()
  {
    node* current = head;
    while (current != nullptr)
    {
      node* deleted_node = current;
      current = current->next;
      delete deleted_node;
    }
    head = tail = nullptr;
    size = 0;
  }

};

int main()
{

}