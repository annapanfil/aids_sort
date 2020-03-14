#include "generator.h"
#include <iostream>

using namespace std;

int* insertion(int tab[], int n)
{
  int temp, j;

  for (int i=1; i<n;i++)
  {
    temp = tab[i];
    j=i-1;
    while (j>=0 && tab[j]>temp)
    {
      tab[j+1]=tab[j];
      j--;
    }
    tab[j+1]=temp;
  }
  return tab;
}


int main()
{
  const int n=9;
  char shape;
  int numbers[n];

  cin>>shape;

  mgenerate(numbers, n, shape);

  cout<<"generated: ";
  for (int i=0; i<n; i++)
      cout << numbers[i] <<" ";
  cout<<endl;

  insertion(numbers, n);

  cout<<"sorted: ";
  for (int i=0; i<n; i++)
      cout << numbers[i] <<" ";
  cout<<endl;

  return 0;
}
