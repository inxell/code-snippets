//
// Created by ke on 1/28/18.
//

#ifndef PLAYGROUND_BIT_H
#define PLAYGROUND_BIT_H

#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<new>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<deque>
#include<random>
#include<ctime>


using namespace std;

class Bit{
/*
 * Binary index tree could be used to count the number of inversions
 * in a sequence, mutable range sum.
 */
public:
    Bit() = default;

    Bit(size_t N):data(vector<int>(N+1)), arr(vector<int>(N+1)), capacity(N){}

    Bit(const vector<int>& vec):capacity(vec.size()){
        data = vector<int>{0};
        data.insert(data.end(), vec.begin(), vec.end());
        arr = vector<int>(vec.size() + 1);
        for(int i = 1; i <= vec.size(); ++i) {
            int k = i;
            while (k <= capacity) {
                arr[k] += data[i];
                k += (k & -k);
            }
        }
    }


    void print(){
        for(int i : data){
            cout << i << ',';
        }
    }

    int get_val(int ind){
        // 1 <= ind <= capacity
        return data[ind];
    }

    int count_le(int ind){
        // 0 <= ind <= capacity
        int total = 0;
        while(ind){
            total += arr[ind];
            ind -= (ind & -ind);
        }
        return total;
    }

    void add(int ind, int val = 1){
        data[ind] += val;
        while(ind <= capacity){
            arr[ind] += val;
            ind += (ind & -ind);
        }
    }

private:
    vector<int> arr;
    vector<int> data;
    int capacity;

};







#endif //PLAYGROUND_BIT_H
