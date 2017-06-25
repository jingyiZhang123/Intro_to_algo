#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>
#include <time.h>

void swap(int* arr, int index1, int index2){
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
    return;
}

int _rand_partition(int* arr, int left, int right){
    swap(arr, left, rand()%(right-left+1) + left);
    int pivot = arr[left];
    int lt_pt = left;
    for (int j=left+1; j <= right; j++)
        if(arr[j] < pivot)
            swap(arr, ++lt_pt, j);
    swap(arr, left, lt_pt);

    return lt_pt;
}

int Rand_Selection(int* arr, int left, int right, int target_rank){

    if(left == right)
        return arr[left];
    int partition_elem_index = _rand_partition(arr, left, right);
    int rank = partition_elem_index - left + 1;  // rank = rank(A[partition_elem_index] in A[left..right])

    if(target_rank == rank)
        return arr[partition_elem_index];
    else if(target_rank < rank)
        return Rand_Selection(arr, left, partition_elem_index-1, target_rank);
    else
        return Rand_Selection(arr, partition_elem_index+1, right, target_rank-rank);

    return 0;
}

int _find_median(int* arr, int left, int right, int target_rank){
    if(left >= right)
        return arr[left];
    int partition_elem_index = _rand_partition(arr, left, right);
    int rank = partition_elem_index - left + 1;

    if(target_rank == rank)
        return arr[partition_elem_index];
    else if(target_rank < rank)
        return _find_median(arr, left, partition_elem_index-1, target_rank);
    else
        return _find_median(arr, partition_elem_index+1, right, target_rank-rank);

}

int Find_Median(int* arr, int size){
    return _find_median(arr, 0, size-1, floor((size+1)/2));
}


// WRONG!
int Intro_Selection(int* arr, int left, int right, int target_rank){
    int n_groups = right/5;
    int groups_5_medians[n_groups];
    for (int i=0; i < n_groups; i+=5)
        groups_5_medians[i] = _find_median(arr, i, i+4, (right+1)/2);

    int temp = (n_groups+1)/2;
    int median_of_medians = _find_median(groups_5_medians, 0, n_groups-1, temp);

    swap(arr, left, median_of_medians);
    int pivot = arr[left];
    int lt_pt = left;
    for (int j=left+1; j <= right; j++)
        if(arr[j] < pivot)
            swap(arr, ++lt_pt, j);
    swap(arr, left, lt_pt);
    int partition_elem_index = lt_pt;
    int rank = partition_elem_index - left + 1;
    if(target_rank == rank)
        return arr[partition_elem_index];
    else if(target_rank < rank)
        return Intro_Selection(arr, left, partition_elem_index-1, target_rank);
    else
        return Intro_Selection(arr, partition_elem_index+1, right, target_rank-rank);

}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    int n = 5;
    int arr[n];
    for (int i=0; i < n; i++) {
        arr[i] = rand()%(n*2);
        printf("%d ", arr[i]);
    }
    printf("\n");
    int rank = 4;
    int rank_value = Find_Median(arr, n);
    printf("%d\n", rank_value);
    /* rank_value = Intro_Selection(arr, 0, n-1, rank); */
    /* printf("%d\n", rank_value); */
    return 0;
}

// useless function
bool Elem_In_Array(int elem, int* arr, int n){
    for (int i=0; i < n; i++)
        if (arr[i] == elem)
            return true;
    return false;
}
