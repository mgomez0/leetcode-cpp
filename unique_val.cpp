#include <iostream>

int single_number(int arr[], int sz)
{   
    if(sz == 1){
        return arr[0];
    }

    int max_value = 0;
    
    for (int i = 0; i < sz - 1; i++){
        if(arr[i] < arr[i+1]){
            max_value = arr[i+1];
        }
    }
    
    int freq_array[max_value+1];
    
    for(int i = 0; i < max_value; i++){
        freq_array[i] = 0;
    }
    
    for (int i = 0; i < sz; i++){
        freq_array[arr[i]] += 1;
    }
    
    for(int i = 0; i<sz; i++){
        if(freq_array[i] == 1){
            return i;
        }
    }
    
    return 0;
    
}

int main(){
    int arr[] = {1,2,3,4,2,4,3,1,5};
    std::cout << single_number(arr, 9);
}