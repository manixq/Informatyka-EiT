//AL: 9.75/10

//10pkt (cykliczna)
#include <iostream>
using namespace std;

class osoba
{

  osoba* nast;
  osoba* pop;
  string imie;
public:

  osoba():nast(NULL),pop(NULL){
    imie="";
  }
  osoba(string i):nast(NULL),pop(NULL),imie(i){}

  friend class lista;
};

class lista
{
  osoba* first;
public:
  lista():first(NULL){}
  ~lista()//destruktor
  {
    osoba* ptr;
    ptr= first;
    if(first == NULL) //AL: po co tak udziwniać. Lepiej napisać if (first != NULL)
      {}
    else
      {
      
	while(ptr->nast != first)
	  {
	    ptr = ptr->nast;
	    cout << ptr->pop->imie<<endl;
	    delete ptr->pop;
	  }
	cout << ptr->imie<<endl;
	delete ptr;
	
      }
  }
  
  void usuwanie(string im)//funkcja usuwajaca imie z bazy
  {
    osoba* ptr;
    ptr=first;
    if(first == NULL)
      {
	cout << "brak listy"<<endl;
      }
    else if(first->imie == im)
      {
	first->pop->nast = first->nast;
	first->nast->pop = first->pop;
	first = first->nast;
	delete ptr;
	//AL: należy również sprawdzić czy usuwany element jest jedynu=ym elementem listy. Wtedy first = NULL;
      }
    else
      {
	while((ptr->nast->imie != im) && (ptr->nast != first))
	  {
	    ptr = ptr->nast;
	  }
	if((ptr->nast == first) && (ptr->nast->imie != im))
	  {
	    cout << "brak takiej osoby w bazie"<<endl;
	  }
	else
	  {
	    osoba* dilit;
	    dilit = ptr->nast;
	    ptr->nast->nast->pop = ptr;
	    ptr->nast= ptr->nast->nast;
	    delete dilit;
	  }
	
      }
  }

  void add(string im)//funkcja dodajaca
  {
    osoba* nowa = new osoba(im);

    if(first==NULL)
      {
	first=nowa;
	first->nast=first;
	first->pop=first;
      }
    else if(first->imie >= im)
      {
	nowa->nast = first;
	nowa->pop = first->pop;
	first->pop->nast = nowa;
	first->pop = nowa; 
	//	if(first->nast == first)
	//	  first->nast = nowa;
	first=nowa;
      }
    else
      {
	osoba* ptr;
	ptr = first;
	while((im >= ptr->nast->imie) && (ptr->nast != first))
	  {
	    ptr = ptr->nast;
	  }
	if(ptr->nast == first)
	  {
	    nowa->nast = first;
	    nowa->pop = first->pop;
	    first->pop->nast = nowa;
	    first->pop = nowa;
	    
	  }
	else
	  {
	    nowa->nast = ptr->nast;
	    nowa->pop = ptr;
	    ptr->nast->pop = nowa;
	    ptr->nast = nowa;
	  }
      }
  }

  void wyswietl()//funkcja wyswietlajaca
  {
    osoba* ptr;
    ptr= first;
    if(first == NULL)
      cout << "brak listy"<<endl;
    else
      {
	cout << first->imie<<endl;
	while(ptr->nast != first)
	  {
	    cout << ptr->nast->imie << endl;
	    ptr = ptr->nast;
	  }
      }
  }
};

int main()
{
  lista baza;
  baza.usuwanie("Ania");
  baza.wyswietl();
  baza.add("Jolanta");
  baza.add("Heniek");
  baza.add("Ania");
  baza.add("Maciek");
  baza.wyswietl();
 
  cout << endl<<endl;


}
