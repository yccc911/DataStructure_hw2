#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream data;
    data.open("CountingSort.result", ios::in);

    double ave[16];
    char tmp[10];
    double temp;
    for(int i=0; i<16; ++i){
        for(int j=0; j<10; ++j){
            data >> tmp;
            temp = stod(tmp);
            ave[i] += temp;
        }
    }
    data.close();

    ofstream average("CountingSort.average", ios::out);
    for(int i=0; i<16; ++i){
        ave[i]/=10;
        average << ave[i] << endl;
    }
    average.close();

    return 0;
}