#include <iostream>
#include <fstream>
#include <cmath>
#include <random>
#include "SourceCode.h"

using namespace std;

int main(){

    ofstream result("InsertionSort.result", ios::out);

    for(int i=15; i<=30; ++i){
        for(int time=0; time<10; ++time){
            int size = pow(2, i);
            int *arr = new int[size];

            random_device seed;
            default_random_engine generator(seed());
            uniform_int_distribution<int> uniform(1, 1000);
            for(int j=0; j<size; ++j){
                arr[j] = uniform(generator);
            }

            clock_t start = clock();
            // sortint...
            insertionSort(arr, size);
            clock_t end = clock();
            result << (double)(end - start)/CLOCKS_PER_SEC << endl;

            delete []arr;
        }
        result << endl;
    }

    result.close();
    return 0;
}