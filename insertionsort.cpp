#include <vector>
#include <iostream>
#include <algorithm>
#include "Clock.h"
#include <cstdlib>
using namespace std;

void insertionSort (vector<int> &v) {
    int insert,moveitem;
    for(int next=1;next<v.size();next++) {
        insert = v.at(next);
        moveitem=next;
        while(moveitem > 0 && v.at(moveitem-1) > insert ) {
            v.at(moveitem)=v.at(moveitem-1);
            --moveitem;
        }
        v.at(moveitem)=insert;
    }//for
}

int main() {
    Clock clk;
    const int size =100000;
    vector<int> v1(size),v2;
    srand(time(NULL));
    for(int i;i<size;i++) {
        v1.at(i)=rand();
    }
    v2=v1;
    clk.start();
    sort(v1.begin(),v1.end());
    cout << "sort():" << clk.getElapsedTime() << "seconde\n";
    cout << "v1 and v2 are " << ((v1==v2)?"the same\n":"different\n");
    clk.start();
    insertionSort(v2);
    cout << "insertionsort():" << clk.getElapsedTime() << "second\n";
    cout << "v1 and v2 are " <<((v1==v2)?"the same\n":"different\n");
    return 0;
}