#include <iostream>
#include <vector>
#include <algorithm>
#include <utility> 
using namespace std;

class Sort{
public:
    void bubbleSort(vector<int>array, int size) {
        for (int step = 0; step < size - 1; ++step) {
            for (int i = 0; i < size - step - 1; ++i) {
                if (array[i] > array[i + 1]) {
                    swap(array[i],array[i+1]);
                }
            }
        }
    }

    /*O(N^2) and 0(n)    */
    void selectionSort(vector<int> &array){
        for (int i = 0; i < array.size(); i++){
            int min = i; // the smallest value from i to end.
            for (int j = i + 1; j < array.size(); j++){
                if (array[j] < array[min]){
                    min = j;
                }
            }
            swap(array[i], array[min]);
        }
    }

    void insertionSort(vector<int>&array){
        for (auto i = 1; i < array.size(); ++i){
            int j = i;
            while (j > 0 && array[j] < array[j - 1]){
                std::swap(array[j], array[j - 1]);
                --j;
            }
        }
    }

    void shellSort(vector<int>&array){
        int h = 1;
        while (h < array.size() / 3)
            h = 3 * h + 1;
        while (h >= 1){
            for (auto i = h; i < array.size(); ++i){
                for (auto j = i; j >= h && array[j] < array[j - h]; j -= h)
                    std::swap(array[j], array[j - h]);
            }
            h /= 3;
        }
    }

    void bucket_sort(vector<int>&array, unsigned int k){
        auto n = array.size();
        std::vector<std::vector<int>> buckets(k);
        auto max = *std::max_element(array.begin(), array.end());
        auto min = *std::min_element(array.begin(), array.end());

        for (auto i = 0; i < n; ++i){
            auto index = k * (array[i]-min) / (max+1-min);
            buckets[index].push_back(array[i]);
        }
        for (auto i = 0; i < k; ++i)
            insertionSort(buckets[i]);
        auto index = 0;
        for (auto i = 0; i < k; ++i){
            for (auto j = 0; j < buckets[i].size(); ++j)
                array[index++] = buckets[i][j];
        }
    }

    //merga sort
    void merge(vector<int>&arr, int low, int high, int pivot){

        // Create L ← A[p..q] and M ← A[q+1..r]
        int n1 = pivot - low + 1;
        int n2 = high - pivot;

        vector<int> LeftArray(arr.begin() + low, arr.begin() + pivot);
        vector<int> RightArray(arr.begin() + pivot, arr.begin() + high +  1); 
        
        int indexLeftArray = 0;
        int indexRightArray = 0;
        int indexArray = 0;

        while(indexLeftArray < LeftArray.size() && indexRightArray < RightArray.size()){
            if(LeftArray[indexLeftArray] <= RightArray[indexRightArray]){
                arr[indexArray] = LeftArray[indexLeftArray];
                indexLeftArray++;
            }
            else{
                arr[indexArray] = RightArray[indexRightArray];
                indexRightArray++;
            }
            indexArray++;
        }
        while(indexLeftArray < LeftArray.size()){
            arr[indexArray] = LeftArray[indexLeftArray];
            indexLeftArray++;
            indexArray++;
        }
        while(indexRightArray < RightArray.size()){
            arr[indexArray] = RightArray[indexRightArray];
            indexRightArray++;
            indexArray++;
        }
    }
    void mergeSort(vector<int>&arr , int low, int high){
        if(low < high){
            int pivot = low + (high - low)/2;
            //divide 
            mergeSort(arr, low, pivot);
            mergeSort(arr, pivot, high);
            //merge
            merge(arr, low, high, pivot);
        }
    }


    //quicksort
    int partition(vector<int>&arr, int low, int high){
        //select the rightmost element as pivot 
        int pivot = arr[high];
        //pointer to greater element 
        int i = low - 1;

        //traverse each element of the array
        //compare them with the pivot 
        for(int j = low; j < high; j++){
            if(arr[j] <= pivot){
                i++;
                swap(arr[j],arr[i]);
            }
        }
        //swap the pivot element with the greater element 
        swap(arr[i+1],arr[high]);

        return i + 1;
    }
    void quickSort(vector<int>&arr, int low, int high){
        if(low < high){
            int pi = partition(arr, low, high);

            //rescursie call on the left of pivot 
            quickSort(arr, low, pi - 1);
            //rescurise call on the right of pivot
            quickSort(arr, pi + 1, high);
        }
    }

    //HeapSort
    void sink(vector<int>&a, unsigned int k, unsigned int N){
        while (2*k+1 < N){
            int j = 2*k+1;
            if (j+1 < N && a[j] < a[j+1]) j++; // choose bigger child
            if (a[j] < a[k]) break; // heap is valid
            std::swap(a[k], a[j]); // swap with bigger child
            k = j;
        }
    }
    void heap_sort(vector<int> &array){
        int n = array.size();
        for (auto k = n / 2; k >= 0; --k)
            sink(array, k, n);
        while (n > 1){
            std::swap(array[0], array[--n]);
            sink(array, 0, n);
        }
    }

};

int main(){
    vector<int> array{4,7,1,5,9,6,2,8,3,0};
    Sort sort;
    sort.insertionSort(array);
    for(auto it : array){
        cout << it << " ";
    }

}