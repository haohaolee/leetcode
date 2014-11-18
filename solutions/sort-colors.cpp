#include <iostream>

// 0 red
// 1 white
// 2 blue
// one pass
using namespace std;

class Solution {
public:
    void sortColors(int A[], int n) {
       int redIndex = 0;
       while (redIndex < n-1 && A[redIndex] == 0)
           ++redIndex;

       if (redIndex == n-1)
           return;

       size_t blueIndex = n-1;
       while (blueIndex > 0 && A[blueIndex] == 2)
           --blueIndex;

       if (blueIndex == 0)
           return;
       
       size_t i = redIndex;
       while (i <= blueIndex)
       {
           if (A[i] == 0)
           {
               swap(A[redIndex], A[i]);
               redIndex++;
           }
           else if (A[i] == 2)
           {
               swap(A[blueIndex], A[i]);
               blueIndex--;
           }
           else
           {
               i++;
           }
       }
    }
};


