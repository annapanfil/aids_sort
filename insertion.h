void insertion(int* tab, int n)
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
