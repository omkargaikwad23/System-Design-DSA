#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace std::chrono;
typedef unsigned long long ull;

/*
- In every appliction there is a default thread which is main(),
  in side this we create other threads

*/


ull evenSum = 0, oddSum = 0;

void findEven(ull start, ull end){
    for(ull i=start; i<=end; i++){
        if((i&1) == 0){
            evenSum += i;
        }
    }
}

void findOdd(ull start, ull end){
    for(ull i=start; i<=end; i++){
        if((i&1) == 1){
            oddSum += i;
        }
    }
}

int main()
{
    ull start = 0, end = 1900000000;
    
    auto startTime = high_resolution_clock::now();

    std::thread t1(findEven, start, end);
    std::thread t2(findOdd, start, end);

    t1.join();
    t2.join(); // t1, t2 will be joined to main thread
    

    // findEven(start, end);
    // findOdd(start, end);

    auto stopTime = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stopTime - startTime);

    cout << "evenSum: " << evenSum << "\n";
    cout << "oddSum: " << oddSum << "\n";

    cout << "Time: " << duration.count()/1000000 << "sec\n";
    return 0;
}

/*

without threads:
evenSum: 902500000950000000
oddSum: 902500000000000000
Time: 3.3241 sec


using threads:
evenSum: 902500000950000000
oddSum: 902500000000000000
Time: 3.18 sec

g++ -Wall -g -std=c++0x -pthread A_simple.cpp

*/