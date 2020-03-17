#include "generator.h"
#include <algorithm>
#include <iostream>
#include <time.h>
using namespace std;

int* mgenerate(int* numbers, int n, char shape)
{

  switch(shape)
  {
    case 'r':
      for(int i=0; i<n;i++)
        numbers[i] = rand() % 100;
      break;

    case 'c':
      int number;
      number = rand() % 100;
      for(int i=0; i<n;i++)
        numbers[i]=number;
      break;

    case 'a':
      numbers[0]= rand() % 100;
      for (int i=1; i<n;i++)
        numbers[i]=rand() % 30 + numbers[i-1];
      break;

    case 'd':
      numbers = mgenerate(numbers, n, 'a');
      reverse(numbers, numbers+n);
      break;

    case 'v':
      numbers = mgenerate(numbers, n, 'a');
      reverse(numbers, numbers+int(n/2)+1);
      break;
  }

  return numbers;
}

// int main()
// {
//   const int n=9;
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
