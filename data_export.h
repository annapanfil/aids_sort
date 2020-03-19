#include <chrono>
#include <iostream>
#include <fstream>
#include <string>
#include "generator.h"

using namespace std;
/*Funkcja dopisuje do pliku czas w jakim dany algorytm sortowania posortuje tablice*/
void exportDataToFile(int* arr, int n, void (*sort)(int* arr, int n), void (*generateArray)(int* arr, int n, char shape), char shape, string filename, int probes = 5) {
	ofstream myfile(filename, ofstream::app);
	double time = 0;

	for (int prob = 0; prob < probes; prob++) {
		mgenerate(arr, n, shape);

		auto start = chrono::high_resolution_clock::now();
		sort(arr, n);
		auto stop = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
		time += duration.count();
	}

	time /= probes;

	if (myfile.is_open())
	{
		myfile << time << endl;
	}
	else cout << "Unable to open file";

}
// overloading
void exportDataToFile(int* arr, int n, void (*sort)(int* arr,int low, int n), void (*generateArray)(int* arr, int n, char shape), char shape, string filename, int probes = 5) {
	ofstream myfile(filename, ofstream::app);
	double time = 0;

	for (int prob = 0; prob < probes; prob++) {
		mgenerate(arr, n, shape);

		auto start = chrono::high_resolution_clock::now();
		sort(arr,0 ,n-1);
		auto stop = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
		time += duration.count();
	}

	time /= probes;

	if (myfile.is_open())
	{
		myfile << time << endl;
	}
	else cout << "Unable to open file";

}


string DataToString(int* arr, int n, void (*sort)(int* arr, int n)) {

	auto start = chrono::high_resolution_clock::now();
	sort(arr, n);
	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
	return (to_string(duration.count())+ "\t");

}

void stringToFile(string message, string filename) {
	ofstream myfile(filename, ofstream::app);

	if (myfile.is_open())
	{
		myfile << message << endl;
	}
	else cout << "Unable to open file";
}
