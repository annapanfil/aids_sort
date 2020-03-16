void heapify(int* tab, int parent, int heapsize)
  {
    //uporządkuj rodzica i jego potomków
    int l = 2*parent+1, r = 2*parent+2, largest;

    if(l<heapsize && tab[l]>tab[parent])
      largest = l;
    else
      largest = parent;
    if(r<heapsize && tab[r]>tab[largest])
      largest = r;

    if (largest!=parent)
    {
      swap(tab[largest], tab[parent]);
      heapify(tab, largest, heapsize); //uporządkuj niższe gałęzie
    }

  }

void build_heap(int* tab, int n)
  //uporządkuj całe drzewo, zaczynając od dołu
  {
    for(int i=n/2-1; i>=0; i--)
      heapify(tab, i, n);
  }

void heap(int* tab, int heapsize)
{
  build_heap(tab, heapsize);

  for(int i=heapsize-1; i>0; i--)
  {
    swap(tab[0], tab[i]);       //zamień największy (pierwszy) element z ostatnim
    heapsize--;                 //oddzielaj posortowane od nieposortowanych
    heapify(tab, 0, heapsize);  //uporządkuj pozostałe drzewo
  }
}
