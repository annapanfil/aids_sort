#include "generator.h"
#include <iostream>
#include "data_export.h"
#include "selection_sort.h"
#include"Merge_sort.h"
#include"heap.h"
#include"insertion.h"
#include <time.h>
#include <string>
using namespace std;


int main()
{
	srand(time(NULL));
	char buffer[3];
	char shapes[] = { 'r','v','c','a','d' };
	string sorts[4] = { "data/selection_sort_","data/merge_sort_","data/insertion_sort_","data/heap_sort_" };
	string filenames[4] = {};
	for (int shape = 0; shape < 5; shape++) {
		for (int testNo = 1; testNo < 6; testNo++) {
			{
				for (int f = 0; f < 4; f++) {
					sprintf_s(buffer, "%c%d", shapes[shape], testNo);
					filenames[f] = sorts[f] + buffer +".txt";
				}
				for (int i = 1000; i <= 10000; i += 200) {

					int* numbers = new int[i];
					mgenerate(numbers, i, shapes[shape]);

					exportDataToFile(numbers, i, &selectionSort, filenames[0]);
					exportDataToFile(numbers, i, &merge_sort, filenames[1]);
					exportDataToFile(numbers, i, &insertion, filenames[2]);
					exportDataToFile(numbers, i, &heap, filenames[3]);

					delete[] numbers;
				}
			}
		}
	}
  return 0;
}
