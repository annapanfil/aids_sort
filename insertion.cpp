#include "generator.h"
#include <iostream>
#include <chrono>
#include <fstream>

using namespace std;

void insertion(int tab[], int n)
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
}


int main()
{
  int n=1000;
  char shape;
  int numbers[10000];
  fstream file;

  cin>>shape;
  file.open("insertion.txt", ios::out);
  do
  {
    // if(shape!='q')
    // {
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

    //   cout <<n<<" elements, " << chrono::duration_cast<chrono::microseconds>(end - start).count()
  	// << " μs" << endl;
    file<<chrono::duration_cast<chrono::microseconds>(end - start).count()<<endl;
    n+=200;
    // }
  }while (shape !='q' && n<=10000);
  file.close();
  return 0;
}
