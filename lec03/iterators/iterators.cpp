#include<vector>
#include<iostream>
#include<algorithm>
int main(){
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    std::vector<int>::iterator iter  = v.begin();
    *iter = 10;  // can update values

    iter++;  // iterate to next element
    *iter = 20;

    std::vector<int>::iterator iter2  = v.end();
    /*
    v.end() returns address to a memory location just past the last elem. 
    *iter2 = 50; --> this can cause undefined behavior

    Dereferencing v.end() is undefined behavior in C++. 
    
    What that means in practice:
        - It might appear to do nothing.
        - It might overwrite another object on the heap or the heap allocator's metadata.
        - It might crash immediately with a “bus error” or “segmentation fault".
        - It’s unpredictable because the C++ standard gives no guarantees once you dereference an invalid iterator.
    
    end() is a sentinel, not a valid element. It’s only meant for comparison
    */

    // iterating through the elements
    for(auto iter  = v.begin(); iter != v.end(); iter++) {
        std::cout << *iter << " ";
    }
    std::cout << "\n";

    // reverse iterator
    for(auto iter  = v.rbegin(); iter != v.rend(); iter++) {
        std::cout << *iter << " ";
    }
    std::cout << "\n";

    // standard algorithms in STL are based on iterators
    std::sort(v.begin() + 1, v.end());  // sort elements from index 1 onwards    
}