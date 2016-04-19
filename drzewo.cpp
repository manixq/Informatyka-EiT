//AL: 8/9

#include <iostream>
using namespace std;

class node
{
  node* right;
  node* left;
  int value;
public:
  node():right(NULL),left(NULL),value(0){}
  node(int val):right(NULL),left(NULL),value(val){}
  friend class tree;
};
class tree
{
  node* root;
public:
  tree():root(NULL){}
  void dodaj(int val)
  {
    if(root)
      {
	node* current=root;
	while(current)
	  {
	    if(current->value <=  val) //AL: >
	      {
		if(current->left)
		  current = current->left;
		else
		  {
		    current->left = new node(val);
		    return;//inaczej sie zapetli, bo current nigdy nie bedzie null
		  }		
	      }
	    else
	      {
		if(current->right)
		  current = current->right;
		else
		  {
		    current->right = new node(val);
		    return;
		  }		  
	      }
	  }
      }
    else
      root = new node(val);
  }
  node* szukaj(int val)
  {
    if(root)
      {	
	node* current = root;
	while(current)
	  {
	    if(current->value <= val)
	      if(current->value == val)
		{
		  return current;
		}
	      else
		current = current->left;
	    else
	      current = current->right;	      
	  }
	return current;
      }
    else
      return root;
  }
  void inorder(node* ptr)
  {
    if(ptr)
      {
	inorder(ptr->right);
	cout << ptr->value << endl;
	inorder(ptr->left);
      }
  }
  void wyswietl()
  {
    inorder(root);   
  }
  void inorder_delete(node* ptr) //AL: usuwanie MUSI bazować na postorder. Inaczej następuje odczyt danych z usuniętych elementów.
  {
    if(ptr)
      {
	inorder_delete(ptr->right);
	cout <<"usuwam" << ptr->value<<endl;
	delete ptr;
	inorder_delete(ptr->left);
      }
  }
  ~tree()
  {
    inorder_delete(root);
  }
};


int main()
{
  tree drzewko;
  drzewko.dodaj(5);
  drzewko.dodaj(6);
  drzewko.dodaj(3);
  drzewko.dodaj(2);
  drzewko.dodaj(8);
  drzewko.dodaj(11);
  drzewko.dodaj(3);
  drzewko.dodaj(10);
  drzewko.dodaj(4);
  drzewko.wyswietl();
  cout << drzewko.szukaj(9)<<endl;
  cout << drzewko.szukaj(11)<<endl;
  cout << drzewko.szukaj(5)<<endl;
}
