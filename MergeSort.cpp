
// Merge Sort C++
// Time complexity: O(nlogn)

void MergeSort(int numbers[], int i, int k) {
    int j;
    if (i < k) {
        j = (i + k) / 2;
        MergeSort(numbers, i, j);
        MergeSort(numbers, j + 1, k);
        Merge(numbers, i, j, k);
    }
}

void Merge(int numbers[], int i, int j, int k) {
    int mergePos = 0;
    int mergedSize = k - i + 1;
    int leftPos = i;
    int rightPos = j + 1;
    int* mergedNumbers = new int[mergedSize];
    while (leftPos <= j && rightPos <= k) {
        if (numbers[leftPos] < numbers[rightPos]) {
            mergedNumbers[mergePos] = numbers[leftPos];
            ++leftPos;
        } 
        else {
            mergedNumbers[mergePos] = numbers[rightPos];
            ++rightPos;
        }
        ++mergePos;
    }
    while (leftPos <= j) { 
        mergedNumbers[mergePos] = numbers[leftPos]; ++leftPos; ++mergePos; 
    }
    while (rightPos <= k) { 
        mergedNumbers[mergePos] = numbers[rightPos]; ++rightPos; ++mergePos; 
    }
    for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
    numbers[i + mergePos] = mergedNumbers[mergePos];
    }
}
