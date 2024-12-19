typedef struct {
    int *data;
    int length;
} Array;

void swap(int* a, int* b);
void populateRandomIntArray(int *arr, int len);
int arrayIsSorted(int *arr, int len);
void showArray(int *arr, int len);