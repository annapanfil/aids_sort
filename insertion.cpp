#include "generator.h"
#include <iostream>
#include <chrono>

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
  const int n=10000;
  char shape;
  int numbers[n];

  do
  {
    cin>>shape;

    if(shape!='q')
    {
      mgenerate(numbers, n, shape);

      /*cout<<"generated: ";
      for (int i=0; i<n; i++)
          cout << numbers[i] <<" ";
      cout<<endl;*/

      auto start = chrono::steady_clock::now();
      insertion(numbers, n);
      auto end = chrono::steady_clock::now();

      /*cout<<"sorted: ";
      for (int i=0; i<n; i++)
          cout << numbers[i] <<" ";
      cout<<endl;*/

      cout << "Elapsed time: " << chrono::duration_cast<chrono::milliseconds>(end - start).count()
  	<< " ms" << endl;
    }
  }while (shape !='q');
  return 0;
}
