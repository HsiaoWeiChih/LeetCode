#include <iostream>

using namespace std;

class Solution {
    public:
        int countPrimes(int n) {
            
            bool *p = new bool[n];
            
            
            for(int i=2; i < n; i++){
                p[i] = true;
            }
            
            //倍數刪掉:2345...的倍數
            for(int i=2; i*i<n; i++){
                if(!p[i])
                    continue;
                for(int j=i*i; j<n; j+=i){
                    p[j] = false;
                }
            }
            /*
            for(int i=2; i<n; i++){
                if(!p[i])
                    continue;
                else
                    p[i] = isPrime(i);
            }*/
            
            int count = 0;
            for(int i=2; i<n; i++){
                if(p[i])
                    count++;
            }
            delete [] p;
            return count;
            
            /*
            int count = 0;
            for (int i = 1; i < n; i++) {
                if (isPrime(i)) count++;
            }
            return count;*/
        }
    /*
    private: 
        bool isPrime(int num) {
            if (num <= 1) return false;
            // Loop's ending condition is i * i <= num instead of i <= sqrt(num)
            // to avoid repeatedly calling an expensive function sqrt().
            for (int i = 2; i * i <= num; i++) {
                if (num % i == 0) return false;
            }
            return true;
        }*/
    };