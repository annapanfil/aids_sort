#include <chrono>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
/*Funkcja dopisuje do pliku czas w jakim dany algorytm sortowania posortuje tablice*/
void exportDataToFile(int* arr, int n, void (*sort)(int* arr, int n), string filename, int flag=0) {
	ofstream myfile(filename,ofstream::app);

	auto start = chrono::high_resolution_clock::now();
	sort(arr, n);
	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
		
	if (myfile.is_open())
	{
		if (flag != 0) myfile << n << "\t" << duration.count() << endl;
		else myfile << duration.count() << endl;
	}
	else cout << "Unable to open file";
}

void exportDataToFile(int* arr, int n, void (*sort)(int* arr, int low, int n), string filename,int flag=0) {
	ofstream myfile(filename, ofstream::app);

	auto start = chrono::high_resolution_clock::now();
	sort(arr, 0, n-1);
	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

	if (myfile.is_open())
	{
		if (flag != 0) myfile << n << "\t" << duration.count() << endl;
		else myfile << duration.count() << endl;
	}
	else cout << "Unable to open file";
}