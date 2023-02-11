#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class FenwickTree{
    vector<int>tree;
    int N;

    // Returns the value of the least significant bit (LSB)
    // lsb(108) = lsb(0b1101100) =     0b100 = 4
    // lsb(104) = lsb(0b1101000) =    0b1000 = 8
    int lsb(int i){
        // Isolates the lowest one bit value
        return i&-i;
    }

    // Computes the prefix sum from [1, i], O(log(n))
    ll prefixSum(int i){
        ll sum = 0ll;
        while(i!=0){
            sum += tree[i];
            i &= ~lsb(i); // Equivalently, i -= lsb(i);
        }
    }
public:
    FenwickTree(vector<int>& values){
        tree = values;
        N = values.size();
    }

    void constructTree(){
        for(int i=1; i<N; i++){
            int parent = i + lsb(i);
            if(parent < N) tree[parent] += tree[i];
        }
    }

    // Returns the sum of the interval [left, right], O(log(n))
    ll intervalSum(int left, int right){
        if(right < left) return -1;
        return prefixSum(right) - prefixSum(left - 1);
    }

    // Add 'v' to index 'i', O(log(n))
    void add(int i, ll v){
        while(i < N){
            tree[i] += v;
            i += lsb(i);
        }
    }

    // Set index i to be equal to v, O(log(n))
    void set(int i, ll v){
        add(i, v - intervalSum(i, 1));
    }
};

int main()
{
    vector<int> values;
    
    return 0;
}