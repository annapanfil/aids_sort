// #include "generator.h"
#include <iostream>
#include "data_export.h"
// #include "selection_sort.h"
// #include"Merge_sort.h"
// #include"heap.h"
// #include"insertion.h"
#include <time.h>
#include <string>
#include "quick_sort.h"
using namespace std;


int main()
{
	srand(time(NULL));
	int probes = 5;
	char buffer[3];
	char shapes[] = { 'r','v','c','a','d' };
	string sorts[4] = { "data/selection_sort_","data/merge_sort_","data/insertion_sort_","data/heap_sort_" };
	string filenames[4] = {};
	// for (int shape = 0; shape < 5; shape++) {
		// for (int f = 0; f < 4; f++) {
		// 	sprintf(buffer, "%c", shapes[shape]);
		// 	filenames[f] = sorts[f] + buffer + ".txt";
		// }
		for (int i = 1000; i <= 10000; i += 200) {

			int* numbers = new int[i];
			//exportDataToFile(numbers, i, &selectionSort, &mgenerate, shapes[shape], filenames[0], 5);
			exportDataToFile(numbers, i, &quickSort, &mgenerate, 'A', "data/quicksort_middle.txt", 5);
			//exportDataToFile(numbers, i, &insertion, &mgenerate, shapes[shape], filenames[2], 5);
			//exportDataToFile(numbers, i, &heap, &mgenerate, shapes[shape], filenames[3], 5);

			delete[] numbers;
		}

	// }

	return 0;
}
//for (int b = 0; b < i; b++)
//	cout << numbers[b] << " ";
