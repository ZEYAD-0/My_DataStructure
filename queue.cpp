#include <iostream>
#include <stdexcept>
using std::cout;
using std::cerr;


class node
{
private:
  int data;
  node *next;

public:

  void set_data(int val){ data = val; }
  void set_next(node* address){ next = address; }

  node* get_next() const { return next; }
  int get_data() const { return data; }
  int& get_data() { return data; } // returns reference

  node() : data(0) , next(nullptr){}
  
  node(int val, node *address = nullptr) : data(val) , next(address){}

  ~node(){} // not needed here
};


class queue
{
private:
  node* head;
  node* tail;
  size_t Size;

public:
  // queue(){ head = tail = nullptr; }
  queue() : head(nullptr) , tail(nullptr) , Size(0) {}

  bool empty() const { return head == nullptr; }

  void push(int val)
  {
    node* newNode = new node(val);
    if(empty())
    {
      head = tail = newNode;
    }
    else
    {
      tail->set_next( newNode );
      tail = newNode;
    }
    ++Size;
  }

  int pop()
  {
    if( !empty() )
    {
      node* delptr = head;
      if( tail == head ) tail = tail->get_next();
      head = head->get_next();
      int deleted = delptr->get_data();
      delete delptr;
      --Size;
      return deleted;
    }
    throw std::out_of_range("Cannot pop from an empty list");
  }

  void Display() const
  {
    node* current = head;
    while( current != nullptr )
    {
      cout << current->get_data() << '\t';
      current = current->get_next();
    }
    cout << "NULL";
    cout << '\n';
  }

  int front() const // Read only
  {
    if(head == nullptr) throw std::out_of_range("empty list");
    return head->get_data();
  }

  int& front() 
  {
    if(head == nullptr) throw std::out_of_range("empty list");
    return head->get_data();
  }

  int back() const // Read only
  {
    if(tail == nullptr) throw std::out_of_range("empty list");
    return tail->get_data();
  }

  int& back() 
  {
    if(tail == nullptr) throw std::out_of_range("empty list");
    return tail->get_data();
  }

  size_t size() const { return Size; }

  bool found(int key) const
  {
    node* current = head;
    while (current != nullptr)
    {
      if(current->get_data() == key) return true;
      current = current->get_next();
    }
    return false;
  }

  void clear()
  {
    while(!empty())
    {
      this->pop();
    }
  }
  
  void swap( queue& other )
  {
    std::swap(this->head , other.head);
    std::swap(this->tail , other.tail);
    std::swap(this->Size , other.Size);
  }

  ~queue()
  {
    this->clear();
  }

};


int main()
{
  // queue q;
  // q.push(5);
  // cout << q.front() << '\n';
  // q.push(4);
  // cout << q.front() << '\n';
  // q.Display();
  // cout << q.back() << '\n';
  // q.clear();
  // q.Display();
  queue q1, q2;
  q1.push(5);
  q1.push(10);
  
  q2.push(20);
  q2.push(30);

  q1.Display();
  q2.Display();

  // Swap the contents of q1 and q2
  q1.swap(q2);

  // Now, q1 contains 20, 30 and q2 contains 5, 10
  q1.Display();
  q2.Display();

}
