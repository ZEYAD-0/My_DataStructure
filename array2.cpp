#include <iostream>
using namespace std;

class Array
{
private:
  int size;
  int length;
  int *items;

public:
  Array(int arrsize)
  {
    size = arrsize;
    length = 0;
    items = new int[arrsize];
  }
  void Fill()
  {
    int no_of_items;
    cout << "How many items you want to fill ? \n";
    cin >> no_of_items;
    if (no_of_items > size)
    {
      cout << "You cannot exceed the array size \n";
      return;
    }
    else
    {
      for (int i = 0; i < no_of_items; i++)
      {
        cout << "Enter item no " << i << endl;
        cin >> items[i];
        length++;
      }
    }
  }
  void Display()
  {
    cout << "Display Array content \n";
    for (int i = 0; i < length; i++)
    {
      cout << items[i] << '\t';
    }
    cout << endl;
  }
  int getSize()
  {
    return size;
  }
  int getLength()
  {
    return length;
  }

  int Search(int key)
  {
    int index = -1;
    for (int i = 0; i < length; i++)
    {
      if (items[i] == key)
      {
        index = i;
        break;
      }
    }
    return index;
  }

  void Append(int newitem)
  {
    if (length < size)
    {
      items[length] = newitem;
      length++;
    }
    else
      cout << "Array is full \n";
  }

  void insert(int index , int val)
  { 
    if(index < 0 || index >= size )
    {
      cout << "WRONG INDEX\n";
      return;
    }
    if(size > length)
    {
      for(int i = length; i > index; --i)
      {
        items[i] = items[i - 1];
      }
      items[index] = val;
      length++;
    }
    else cout << "NO Space\n";
  }
  void Delete(int index)
  {
    if(index < 0 || index >= length)
    {
      cout << "INDEX OUT Of RANGE\n";
      return;
    }

    for(int i = index; i < length - 1; ++i)
    {
      items[i] = items[i + 1];
    }
    length--;

    /* OR

    int* newarr = new int[size];
    for(int i = 0; i < length - 1; ++i)
    {
      if(i >= index)
      {
        newarr[i] = items[i + 1];
      }
      else newarr[i] = items[i];
    }
    length = length - 1;
    delete[] items;
    items = newarr;
    */
  }

  void enlarge(int newsize) // which is better??
  {
    if(newsize <= size)
    {
      cout << "New Size must be bigger than current size";
      return;
    }

    size = newsize;
    int* old = items;
    items = new int[newsize];
    for(int i = 0; i < length; ++i)
    {
      items[i] = old[i];
    }
    delete[] old;
    old = nullptr;

    /* --------------------------------- */

    /* OR */
  //   size = newsize;
  //   int* newarr = new int[newsize];
  //   for(int i = 0; i < length; ++i)
  //   {
  //     newarr[i] = items[i];
  //   }
  //   delete[] items;
  //   items = newarr;
  //   newarr = nullptr;
  }
  void merge(Array other)
  {
    int newSize = this->getSize() + other.getSize(); // size or getsize better??
    size = newSize;
    int* old = items;
    items = new int[size];
    for(int i = 0; i < this->length; ++i)
    {
      items[i] = old[i];
    }

    delete[] old;
    old = nullptr;
    for(int i = 0; i < other.length; ++i)
    {
      items[i + this->length] = other.items[i];
    }

    length = this->getLength() + other.getLength();
  }
};

int main()
{
  Array myarr(5);
  myarr.Fill();
  myarr.Display();
  cout << "size: " << myarr.getSize() << '\t' << "length: " << myarr.getLength() << endl;
  
  Array arr2(3);
  arr2.Fill();
  myarr.merge(arr2);

  myarr.Display();
  cout << "size: " << myarr.getSize() << '\t' << "length: " << myarr.getLength() << endl;

  // myarr.enlarge(6);
  // myarr.Append(5);
  // cout << "size: " << myarr.getSize() << '\t' << "length: " << myarr.getLength() << endl;
  // myarr.Display();

  // cout << "insert" << endl;
  // myarr.insert(1 , 9);
  // myarr.Display();

  // cout << "size: " << myarr.getSize() << '\t' << "length: " << myarr.getLength() << endl;
  // cout << "delete" << endl;

  // myarr.Delete(4);

  // myarr.Display();
  // cout << "size: " << myarr.getSize() << '\t' << "length: " << myarr.getLength() << endl;

}