#include <iostream>

using namespace std;

class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        /*
        int max = x>=y ? x:y;
        int loop = 0;

        while(max>=2){
            loop++;
            if(max%2 == 1){
                max--;
                max /= 2;
            }
            else{
                max /= 2;
            }
        }*/
        /*
        int count = 0;
        bitset<32> bsx(x);
        bitset<32> bsy(y);
        for(int i=0; i<loop; i++){

        }*/

        int dis = 0;
        while (x != 0 || y != 0)
        {
            if (x % 2 == 1 && y % 2 == 1)
            {
                x--;
                y--;
                x /= 2;
                y /= 2;
            }
            else if (x % 2 == 0 && y % 2 == 0)
            {
                x /= 2;
                y /= 2;
            }
            else if (x % 2 == 0 && y % 2 == 1)
            {
                dis++;
                y--;
                x /= 2;
                y /= 2;
            }
            else
            {
                dis++;
                x--;
                x /= 2;
                y /= 2;
            }
        }
        return dis;
    }
};