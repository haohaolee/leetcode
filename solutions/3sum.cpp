#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
    	if (num.size() < 3)
    		return v_;
    	
    	sort(num.begin(), num.end());

    	for (size_t i = 0; i < num.size()-2;)
    	{
    		int a = num[i];
    		size_t j = i + 1;
    		size_t k = num.size()-1;
    		while (j < k)
    		{
    			int b = num[j];
    			int c = num[k];
   
   				int sum = a + b + c;
    			if (sum == 0)
    			{
    				push_triple(a, b, c);
    				while(++j < k && num[j] == num[j-1])
    					;
    			}
    			else if (sum > 0)
    			{
    				while(j < --k && num[k] == num[k+1])
    					;
    			}
    			else
    			{
    				while(++j < k && num[j] == num[j-1])
    					;
    			}
    			
    				
    			
    		}
    		while(++i < num.size()-2 && num[i] == num[i-1])
    		;
    	}
    	
        return v_;
    }
private:
	void push_triple(int i, int j, int k)
	{
		static vector<int> temp(3);
		temp[0] = i;
		temp[1] = j;
		temp[2] = k;
		v_.push_back(temp);
	}
private:
	vector<vector<int> > v_;
	
};


