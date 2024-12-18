void swap(int* a, int* b);
void populateRandomIntArray(int *arr, int len);
void bubbleSort(int * arr, int len);
void selectionSort(int * arr, int len);
void quickSort(int *arr, int low, int high);
void checkAllSort();
int arrayIsSorted(int *arr, int len);
int testerSort(void(*sortAlgorithm)(int*, int));
int testerForRecursiveSort(void(*sortAlgorithm)(int*, int, int));
int partition(int arr[], int low, int high);