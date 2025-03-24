#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        /*void swap(int &a, int &b){
            int temp = a;
            a = b;
            b = temp;
        }
        
        int Partition(vector<int>& n, int front, int end){
            int pivot = n[end];
            int i = front - 1;
            for(int j=front; j<end; j++){
                if(n[j] < pivot){
                    i++;
                    swap(n[i], n[j]);
                }
            }
            i++;
            swap(n[i], n[end]);
            return i;
        }
        
        void QuickSort(vector<int>& n, int front, int end){
            if(front < end){
                int pivot = Partition(n, front, end);
                QuickSort(n, front, pivot-1);
                QuickSort(n, pivot+1, end);
            }
            
        }*/
        
        bool containsDuplicate(vector<int>& nums) {
            
            /*int size = nums.size();
            
            QuickSort(nums, 0, size-1);
            
            for(int i=1; i<size; i++){
                if(nums[i-1] == nums[i])
                    return true;
            }
            return false;*/
            
            if(nums.size()<2)
                return false;
            
            
            
            int min=*min_element(nums.begin(),nums.end());
            int max=*max_element(nums.begin(),nums.end());
            int n = max-min;
            
            int * array;
            array = new int [n+1];
            
            for(int i=0; i<n+1; i++){
                array[i] = 0;
            }
            
            for(int i=0; i<nums.size(); i++){
                array[nums[i]-min]++;
                if(array[nums[i]-min]>1){
                    delete [] array;
                    return true;
                }
                                    
            }
            return false;
        }
    };