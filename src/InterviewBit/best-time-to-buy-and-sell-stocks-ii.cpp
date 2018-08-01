/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again)
*/


int Solution::maxProfit(const vector<int> &A) {
    
    if(A.size() == 0 || A.size() == 1)return 0;
    int max_profit = 0;
    for(int i = 1; i<A.size(); i++)
    {
        if(A[i] > A[i-1]){
            
            max_profit += A[i] - A[i-1]; //Approach based by finding an increasing slope instead of separately calculating the peak and valley.
        }
    }
    return max_profit;
}


