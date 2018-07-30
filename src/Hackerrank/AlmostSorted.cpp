/*
Given an array of integers, can you sort an array in ascending order using only one of the following operations one time?

Swap two elements.
Reverse one sub-segment.
If either one would work, choose swap over reverse. For instance, given an array  we can swap the  and , or reverse them. We choose swap.
*/


#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the almostSorted function below.
void almostSorted(vector<int> arr) {
  
int n = arr.size();
int temp[n];
 
 for(int i = 0; i<n; i++)
 {
     temp[i] = arr[i];
 }
sort(temp,temp+n);
int count = 0;
int flag= 0,start,end;
for(int i = 0; i<n; i++)
{
    if(temp[i] != arr[i])
    {
        count++;
        if(flag == 0)
        {
            start = i;
            end = i;
        }
        else
        {
            end = i;
        }
        flag = 1;
    }
}

if(count == 0)
{
    cout<<"yes";
}
if(count == 2)
{
    cout<<"yes"<<endl;
    cout<<"swap"<<" "<<start+1<<" "<<end+1<<endl;
}
else
{
    for(int i = start, j = end; i<=j; i++, j--)
    {
        if(temp[i] != arr[j])
        {
            cout<<"no"<<endl;
            return;
        }
    }
    cout<<"yes"<<endl;
    cout<<"reverse"<<" "<<start+1<<" "<<end+1<<endl;
}
        
    
}
