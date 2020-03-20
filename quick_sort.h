#include <algorithm>
#include <iostream>
using namespace std;

int quick(int* tab, int left, int right)
{
  //RÓŻNE MOŻLIWOŚCI WYBORU PIVOTA
  int choice = int((left+right)/2);
  // int choice = right;
  // int choice = rand()%(right-left + 1) + left;

  int piv = tab[choice]; //element, z którym porównujemy

  int i = left;                      //przesuwa się w prawo, szuka elementów większych
  int j = right;                     //przesuwa się w lewo, szuka elementów mniejszych

  do
  {
    while(tab[i]<piv)  i++;
    while(tab[j]>piv)  j--;

    if(i<=j)
      {
        swap(tab[i], tab[j]);
        i++;
        j--;
      }
    }while(i<=j);
    if(left<j) quick(tab,left,j);
    if(right>i) quick(tab,i,right);
}

//Quicksort
void quickSort(int* tab, int n)
{
  quick(tab, 0, n-1);
}
