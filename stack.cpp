#include<iostream>
using std::cout;
using std::cerr;
using std::nothrow;


class node
{
private:
  int data;
  node *next;

public:
  void set_data(int val) { this->data = val; }
  void set_next(node* ptr) { this->next = ptr; }

  int get_data() const { return data; } 
  int& get_data() { return data; } // returns reference

  node* get_next() const { return next; }


  node()
  {
    set_data(0); set_next(nullptr);
  }

  node(int val , node* ptr = nullptr)
  {
    set_data(val); set_next(ptr);
  }

  ~node(){} // not needed here
};

class stack
{
private:
  node* top;

public:
  
  stack()
  {
    top = nullptr;
  }

  bool is_empty() const
  {
    return this->top == nullptr;
  }


  bool is_full()
  {
    node* ptr = new (nothrow) node;
    if( ptr == nullptr ) 
    {
      cerr << "Can't allocate Now \n"; // Not necessary Full Heap
      return true;
    }
    delete ptr;
    return false;
  }

  void push(int val) 
  {
    node* newNode = new node(val);
    if( this->is_empty() )
    {
      top = newNode;
    }
    else
    {
      newNode->set_next( this->top );
      this->top = newNode;
    }
  }


  void pop()
  {
    if(!this->is_empty())
    {
      node *delptr = top;
      top = top->get_next();
      delete delptr;
    }
  }

  void clear()
  {
    while (!this->is_empty())
    {
      this->pop();
    }
  }

  void display() const
  {
    if( this->is_empty() )
    {
      cout << "Empty!!\n\n";
      return;
    }
    cout << "** DISPLAY!! ** \n";
    node* current = this->top;
    while( current != nullptr )
    {
      cout << current->get_data() << '\n';
      current = current->get_next();
    }
    cout << "NULL\n\n";
  }

  int count() const
  {
    int counter = 0;
    node* current = this->top;
    while (current != nullptr)
    {
      counter++;
      current = current->get_next();
    }
    return counter;
  }

  bool found(int key) const
  {
    node* current = this->top;
    while (current != nullptr)
    {
      if( current->get_data() == key ) return true;
      current = current->get_next();
    }
    return false;
  }

  int Top() const // Read - Only
  {
    if (this->is_empty())
    {
      throw std::runtime_error("Stack is empty! No top element.");
    }
    return this->top->get_data();
  }

  int& Top() // Modify
  {
    if (this->is_empty())
    {
      throw std::runtime_error("Stack is empty! No top element.");
    }
    return this->top->get_data();
  }

  ~stack()
  {
    while (!this->is_empty())
    {
      this->pop();
    }
  }
};


int main()
{
  stack st;
  st.push(5);
  st.push(6);
  st.push(7);
  st.clear();
  st.display();
  cout << st.Top() << '\n';
  st.Top() = 6;
  cout << st.Top() << '\n';
  // st.pop();
  // st.display();
  // cout << st.count() << '\n';
  // for(int i = 10; i <= 12; ++i)
  // {
  //   st.push(i);
  //   st.display();
  // }
  // cout << st.count() << '\n';
  // st.pop();
  // st.display();
  // cout << st.count() << '\n';
  // cout << " ---------------------- \n";
  // cout << st.Top() << '\n';
  // cout << st.found(113) << '\n';
}