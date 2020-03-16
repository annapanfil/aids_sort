#include <algorithm>
#include <iostream>

using namespace std;

void mgenerate(int* numbers, int n, char shape)
{
  /*numbers - wskażnik do tablicy, w której mają pojawić się liczby
  n - jej rozmiar
  shape - r-random, a-ascending, d-descending, c-constant, v-vshaped
  */
  srand(time(NULL));
  switch(shape)
  {
    case 'r':
      for(int i=0; i<n;i++)
        numbers[i] = rand() % 1000000;
      break;

    case 'c':
      int number;
      number = rand() % 1000;
      for(int i=0; i<n;i++)
        numbers[i]=number;
      break;

    case 'a':
      numbers[0]= rand() % 1000;
      for (int i=1; i<n;i++)
        numbers[i]=rand() % 300 + numbers[i-1];
      break;

    case 'd':
      mgenerate(numbers, n, 'a');
      reverse(numbers, numbers+n);
      break;

    case 'v':
      mgenerate(numbers, n, 'a');
      reverse(numbers, numbers+int(n/2)+1);
      break;
  }
}
