#include <cstdlib>
#include <stdexcept>
#include <iostream>
using namespace std;

typedef unsigned int nodedata;

struct Node
{
  const nodedata     cargo;
  const unsigned int key;
  Node*              link;
  Node(const nodedata mycargo, const unsigned int akey) :
    cargo(mycargo), key(akey), link(NULL) { }
  ~Node() { }
};

class LinkedList
{
public:
  LinkedList();
  ~LinkedList();
  unsigned int insert(nodedata);
  unsigned int append(nodedata);
  unsigned int insertafterkey(nodedata, unsigned int key);
  void remove(unsigned int);
  nodedata getnode();
  nodedata getnodebykey(unsigned int key);
private:
  Node*        head;
  unsigned int count;
  unsigned int key;
};

LinkedList::LinkedList() : head(NULL), count(0), key(0) { }

LinkedList::~LinkedList()
{
  if (head==NULL && key==0) return;
  while (head)
    {
    Node* node = head;
    head = node->link;
    count--;
    delete node;
    if (count == 0) break; // possibly corrupted list
    }
  if ((count==0 && head !=NULL) || (head==NULL && count != 0))
    {
    const char* errormsg = "Warning: inconsistent list";
    cout << errormsg << endl;
    }
}

unsigned int LinkedList::insert(nodedata cargo)
{
  unsigned int nodekey = key;
  Node* newNode = new Node(cargo, nodekey);
  newNode->link = head;
  head = newNode;
  key++;
  count++;
  return nodekey;
}

nodedata LinkedList::getnode()
{
  if (head==NULL)
    {
    const char* errormsg = "Warning: accessing empty list";
    throw std::runtime_error(errormsg);
    }
  Node* node = head;
  head = node->link;
  const nodedata cargo = node->cargo;
  count--;
  delete node;
  return cargo;
}
  

nodedata LinkedList::getnodebykey(unsigned int akey)
{
  if (head==NULL)
    {
    const char* errormsg = "Warning: accessing empty list";
    throw std::runtime_error(errormsg);
    }
  Node* node = head;
  Node** previous = &head; // bug
  while (node->key != akey)
    {
    previous = &(node->link);
    node = node->link;
    }
  *previous = node->link;
  nodedata cargo = node->cargo;
  delete node;
  return cargo;
}


void LinkedList::remove(unsigned int akey)
{
  nodedata cargo = getnodebykey(akey);
}


int main(int argc, char* argv[])
{
  const unsigned int listSize = atoi(argv[1]);

  LinkedList ll;

  unsigned int keys[listSize];

  for (unsigned int k=0; k<=listSize; k++)
    keys[k] = ll.insert(2*k+1);

  nodedata thisnode = ll.getnodebykey(3);
  
  unsigned int finished = 0;

  return 0;
}
