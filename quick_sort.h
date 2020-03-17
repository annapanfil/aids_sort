#include <algorithm>
#include <iostream>
using namespace std;

char a;

int partition(int* tab, int left, int right)
{
  int piv = tab[int((left+right)/2)]; //element, z którym porównujemy
  int i = left;                      //przesuwa się w prawo, szuka elementów większych
  int j = right;                     //przesuwa się w lewo, szuka elementów mniejszych
  // cout<<left<<" piv: "<<piv<<" "<<right<<endl;
  // cin>>a;
  while(i<j)
  {
    while(tab[i]<piv)
      i++;
    while(tab[j]>piv)
      j--;
    if(i<j)
      {
        swap(tab[i], tab[j]);
        j--;
        i++;

        // cout<<"swapped ";
        // for (int i=0; i<5; i++)
        // cout<<tab[i]<<" ";
        // cout<<endl;
      }
  }
  //po prawej od piv są elementy większe od niego, po lewej - mniejsze
  return j;
}


void quick(int* tab, int left, int right)
{
  if (left < right)
  {
    //podziel tablicę na mniejsze części i posortuj je
    int cut = partition(tab, left, right);
    // for (int i=0; i<=5; i++)
    //   cout<<tab[i]<<" ";
    // cout<<"cut in "<<cut<<endl;
    // cin>>a;
    quick(tab, left, cut);
    quick(tab, cut + 1, right);
  }
}

//Quicksort
void quickSort(int* tab, int n)
{
  quick(tab, 0, n-1);
}
