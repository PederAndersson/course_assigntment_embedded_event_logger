#include "../header/sortAlgo.h"

#include <stdlib.h>

Event** insertionSort(EventLog *log, int* out) {
    if (isEmpty(log)){return NULL;}

    EventLog* current = log;
    int size = logSize(log);
    int n = 0;
    *out = size;

    Event **tempArr = malloc(sizeof(*tempArr) * size);
    if (!tempArr){return NULL;}

    while (current != NULL && n < size) {
        tempArr[n] = current->_node;
        current = current->_next;
        n++;
    }
    for (int i = 1; i < n; i++) {
        Event *key = tempArr[i];
        int firstIdx = 0;
        int idxToCompare = i - 1;

        while (idxToCompare >= firstIdx &&
            (tempArr[idxToCompare]->_Id > key->_Id ||
            (tempArr[idxToCompare]->_Id == key->_Id && tempArr[idxToCompare]->_value > key->_value)))
            {
            tempArr[idxToCompare + 1] = tempArr[idxToCompare];
            idxToCompare--;
        }
        tempArr[idxToCompare + 1] = key;
    }
    return  tempArr;
}

static void merge(Event **e, int startIndex, int middleIndex, int lastIndex) {
    int leftSize = middleIndex - startIndex + 1;
    int rightSize = lastIndex - middleIndex;

    Event* leftArr[leftSize];
    Event* rightArr[rightSize];

    for (int i = 0; i < leftSize; i++) {
        leftArr[i] = e[startIndex + i];
    }
    for (int j = 0; j < rightSize; j++) {
        rightArr[j] = e[middleIndex + 1 + j];
    }

    int leftIdx = 0;
    int rightIdx = 0;
    int mainIdx = startIndex;

    while (leftIdx < leftSize && rightIdx < rightSize){
        if (leftArr[leftIdx]->_Id > rightArr[rightIdx]->_Id ||
        (leftArr[leftIdx]->_Id == rightArr[rightIdx]->_Id && leftArr[leftIdx]->_value > rightArr[rightIdx]->_value)) {
            e[mainIdx] = rightArr[rightIdx];
            rightIdx++;
            mainIdx++;
        } else {
            e[mainIdx] = leftArr[leftIdx];
            leftIdx++;
            mainIdx++;
        }
    }
    while (leftIdx < leftSize) {
        e[mainIdx] = leftArr[leftIdx];
        leftIdx++;
        mainIdx++;
    }
    while (rightIdx < rightSize) {
        e[mainIdx] = rightArr[rightIdx];
        rightIdx++;
        mainIdx++;
    }

}

static void mergeSortRec(Event **e, int startIndex, int lastIndex) {
    if ( startIndex < lastIndex) {
        int middle = startIndex + (lastIndex - startIndex)/2;

        mergeSortRec(e, startIndex, middle);
        mergeSortRec(e, middle + 1, lastIndex);
        merge(e, startIndex, middle, lastIndex);
    }

}

Event** mergeSort(EventLog *log, int* out) {
    if (isEmpty(log)){return NULL;}

    EventLog* current = log;
    int size = logSize(log);
    int n = 0;
    *out = size;

    Event** tempArr = malloc(sizeof(*tempArr) * size);
    if (!tempArr){ return NULL;}

    while (current != NULL && n < size) {
        tempArr[n] = current->_node;
        current = current->_next;
        n++;
    }
    if (n > 1) {
        mergeSortRec(tempArr, 0, n - 1);

    }
    return tempArr;
}
