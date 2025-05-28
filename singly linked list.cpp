#include <iostream>
using namespace std;

class node
{
public:
  int data;
  node* next;
  node(int val)
  {
    data = val;
    next = nullptr;
  }
};

class linkedList
{
public:
  node* head;
  linkedList()
  {
    head = nullptr;
  }
  ~linkedList()
  {
    node* current = head;
    
    while(current != nullptr)
    {
      node* temp = current;
      current = current->next;
      delete temp;
    }
    head = nullptr;
  }
  void insert_big(int val)
  {
    if(is_empty())
    {
      head = new node(val);
    }
    else
    {
      node* newnode = new node(val);
      newnode->next = head;
      head = newnode;
    }
    cout << "** Insert at beginning DONE **" << endl;
  }

  void insert_end(int val)
  {
    node* newnode = new node(val);
    if(is_empty())
    {
      head = newnode;
    }
    else
    {
      node* current = head;
      while(current->next != nullptr) // stops at last node
      {
        current = current->next;
      }
      current->next = newnode;
      // newnode->next = nullptr; // not needed cuz it is NULL by constructor
    }
    cout << "** Insert at End DONE **" << endl;
  }

  void insert_pos(int val , int position)
  {
    /* Extra */
    // if( position > this->count() || position < 1 )
    // {
    //   cout << "Invalid Pos\n";
    //   return;
    // }

    
    if(position < 1)
    {
      cout << "Invalid, pos should be >= 1\n";
      return;
    }
    
    if(position == 1)
    {
      this->insert_big(val);
      return;
    }
    
    /*
    - traverse to node just before position => we on tail and no pos exit
    - node before.next = new node
    */
    
    node* current = head; // we are on first node
    // insertion at end handled in for loop (end not after end)
    for(int i = 1; i < position - 1 && current != nullptr; ++i)
    {
      current = current->next;
    }
    if(current == nullptr)
    {
      cout << "Invalid Pos\n";
      return;
    }
    node* newnode = new node(val);
    newnode->next = current->next;
    current->next = newnode;
    cout << "value : " << val << " inserted at position " << position << endl;
  }

  void Delete_beg()
  {
    if(this->is_empty())
    {
      cout << "List Is Empty\n";
      return;
    }
    node* temp = head;
    head = head->next;
    delete temp;
    temp = nullptr; // not important cuz temp is a local variable will be destroyed after function call
    cout << "** First Node Deleted **\n";
  }

  void Delete_end()
  {
    if(this->is_empty())
    {
      cout << "List Is Empty\n";
      return;
    }
    if(this->head->next == nullptr) // only one node
    {
      delete head;
      head = nullptr;
      return;
    }
    node* current = head;
    while(current->next->next != nullptr) // stops at before last node
    {
      current = current->next;
    }
    delete current->next;
    current->next = nullptr;
    cout << "** Last Node Deleted **\n";
  }

  void Delete_pos(int position)
  {
    if(position < 1)
    {
      cout << "Invalid, Position Should be >= 1\n";
      return;
    }
    if(this->is_empty())
    {
      cout << "List Is Empty\n";
      return;
    }

    if(position == 1)
    {
      cout << "Deleted Done at pos 1\n";
      this->Delete_beg();
      return;
    }
    node* current = head;
    for(int i = 1; i < position - 1 && current != nullptr; ++i)
    {
      current = current->next;
    }
    if(current == nullptr || current->next == nullptr)
    {
      cout << "Position is Out of Range\n";
      return;
    }
    else
    {
      node* temp = current->next;
      current->next = current->next->next;
      delete temp;
      cout << "** Node at Pos ** " << position << " Deleted\n";
    }
  }

  bool is_empty()
  {
    return (head == nullptr);
  }

  void display() // اوعى تعمل الكارثة
  {
    cout << "** Display **" << endl;
    node* current = head;
    
    while(current != nullptr)
    {
      cout << "data : " << current->data << '\n';
      current = current->next;
    }
    cout << "NULL\n";
  }

  int count()
  {
    node* current = head;
    int nodes = 0;
    while(current != nullptr)
    {
      nodes++;
      current = current->next;
    }
    return nodes;
  }

  bool is_found(int key)
  {
    node* current = head;
    while(current != nullptr)
    {
      if(current->data == key)
      {
        return true;
      }
      current = current->next; 
    }
    return false;
  }
};

int main()
{
  linkedList list1;

  cout << "there is " << list1.count() << " node\n\n";

  list1.insert_big(5);

  cout << "there is " << list1.count() << " node\n\n";
  
  list1.display();
  
  list1.insert_big(6);

  cout << "there is " << list1.count() << " node\n\n";
  
  list1.display();
  
  list1.insert_end(7);
  
  cout << "there is " << list1.count() << " node\n\n";
  
  list1.display();

  list1.insert_end(8);
  
  cout << "there is " << list1.count() << " node\n\n";
  
  list1.display();
  
  list1.insert_pos(3 , 5);
  
  cout << "there is " << list1.count() << " node\n\n";
  
  list1.display();
  cout << "---------------------------\n\n";

  // list1.Delete_beg();
  
  // cout << "there is " << list1.count() << " node\n\n";
  
  // list1.display();


  // list1.Delete_end();
  
  // cout << "there is " << list1.count() << " node\n\n";
  
  // list1.display();

  list1.Delete_pos(3);
  
  cout << "there is " << list1.count() << " node\n\n";
  
  list1.display();

}