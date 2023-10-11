#include <bits/stdc++.h>
#include<vector>
int LongestSubsetWithZeroSum(Vector<int>&arr) {

  // Write your code here
  int n=arr.size();
  if(accumulate(arr.begin(), arr.end(), 0)==0){
    return n;
  }
  vector<int>sum;
  int len=0;
  for(int i=0;i<n;i++){
    sum.push_back(arr[i]);
    if(accumulate(sum.begin(), sum.end(), 0)==0){
      int l=sum.size();
      len=max(l,len);
    }
    for(int j=i+1;i<n;i++){
      sum.push_back(arr[j]);
      if(accumulate(sum.begin(), sum.end(), 0)==0){
        int l=sum.size();
        len=max(l,len);
      }
    }
    sum.clear();
  }
  if(len!=0){
    return len;
  }
  return 0;
}
int main(){
    vector<int> vec={1,3,-1,4,-4};
    cout<<LongestSubsetWithZeroSum(vec);
}
