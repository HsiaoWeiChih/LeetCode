#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
        vector<string> fizzBuzz(int n) {
            vector<string> f;
            for(int i=1; i<=n; i++){
                if(i%3 == 0 && i%5 == 0){
                    f.push_back("FizzBuzz");
                }
                else if(i%3 == 0){
                    f.push_back("Fizz");
                }
                else if(i%5 == 0){
                    f.push_back("Buzz");
                }
                else{
                    f.push_back(std::to_string(i));
                }
            }
            return f;
        }
    };