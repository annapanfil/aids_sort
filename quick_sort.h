#include <algorithm>
#include <iostream>
using namespace std;

int partition(int* tab, int left, int right)
{
  //RÓŻNE MOŻLIWOŚCI WYBORU PIVOTA
  // int choice = int((left+right)/2);
  int choice = right;
  // int choice = rand()%(right-left + 1) + left;

  int piv = tab[choice]; //element, z którym porównujemy


  int i = left;                      //przesuwa się w prawo, szuka elementów większych
  int j = right;                     //przesuwa się w lewo, szuka elementów mniejszych
  while(true)
  {
    while(tab[i]<piv)
      i++;
    while(tab[j]>piv)
      j--;
    if(i<j)
      {
        swap(tab[i], tab[j]);
        i++;
        j--;
      }
    else
      return j;
      //po prawej od piv są elementy większe od niego, po lewej - mniejsze
  }
}


void quick(int* tab, int left, int right)
{
  if (left < right)
  {
    //podziel tablicę na mniejsze części i posortuj je
    int cut = partition(tab, left, right);
    quick(tab, left, cut-1);
    quick(tab, cut+1, right);
  }
}

//Quicksort
void quickSort(int* tab, int n)
{
  quick(tab, 0, n-1);
}
