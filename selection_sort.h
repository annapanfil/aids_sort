
void selectionSort(int* table,int n) {
	int sortedIndex = 0;
	int minIndex = 0;
	// oddzielaj posortowane od nieposortowanych
	for (int sortedIndex = 0; sortedIndex < n -1 ; sortedIndex++) {
		minIndex = sortedIndex;
		// szukaj namniejszego
		for (int i = sortedIndex; i < n; i++) {
			if (table[minIndex] > table[i]) {
				minIndex = i;
			}
		}
		// zamieñ namniejszy z pierwszym nieposortowanym
		int temp = table[sortedIndex];
		table[sortedIndex] = table[minIndex];
		table[minIndex] = temp;
	}

}