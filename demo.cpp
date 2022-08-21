// Reference: 
// https://www.classes.cs.uchicago.edu/archive/2013/spring/12300-1/labs/lab6/

#include <iostream>
#include <vector>
#include <thread>
using namespace std;

int accum = 0;
mutex accum_mutex;

void square(int x, int& accum) {
    int tmp = x * x;
    accum_mutex.lock();
    accum += tmp;
    accum_mutex.unlock();
}

int main() {
    vector<thread> threads;   
    for(int i = 1; i <= 20; i++) {
        threads.push_back(thread(&square, i, ref(accum)));
    }

    for (auto& thrd:threads) {
        thrd.join();
    }

    cout << "accum = " << accum << endl;

    return 0;
}
