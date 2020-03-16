#include "generator.h"
#include <algorithm>
#include <iostream>

using namespace std;

void mgenerate(int* numbers, int n, char shape)
{
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

// int main()
// {
//   const int n=100;
//   char shape;
//   int numbers[n];
//
//   cin>>shape;
//
//   mgenerate(numbers, n, shape);
//
//   for (int i=0; i<n; i++)
//       cout << numbers[i] <<" ";
//   cout<<endl;
//
//   return 0;
// }
