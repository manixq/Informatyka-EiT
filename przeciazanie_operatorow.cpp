//AL: brak operatorów + i -, 2/3

#include <iostream>

using namespace std;

class complex{

  double re, im;

public:
  
  
  complex(double r=0.0 ,double i=0.0):
    re(r),im(r)
  {}

  friend ostream &operator<<(ostream&, complex&);
  friend istream &operator>>(istream&, complex&);
  friend complex operator*(complex, complex);
  friend complex operator/(complex, complex);
    
};

ostream &operator<<(ostream &out, complex &a){
  out << a.re;
  out << a.im;
  return out;}

istream &operator>>(istream &in, complex &a){
  in >> a.re;
  in >> a.im;
  return in;}

complex operator*(complex a, complex b)
{

  return complex(a.re*b.re-a.im*b.im, a.re*b.im+a.im*b.re);}
complex operator/(complex a, complex b)
{
  return complex((a.re*b.re+a.im*b.im)/(b.re*b.re+b.im*b.im), (-a.re*b.im+a.re*b.re)/(b.re*b.re+b.im*b.im));}

int main()
{
  complex a1;
}
