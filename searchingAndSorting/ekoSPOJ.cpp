#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossible(vector<long long int> &trees, long long int mid, long long int m){
  long long int woodCollected = 0;
  for(int i = 0; i < trees.size(); i++){
    if(trees[i] > mid){
      woodCollected += trees[i]-mid;
      if(woodCollected >= m)
        return true;
    }
  }
  return false;
}

long long int maxHeightOfBlade(vector<long long int> &trees, long long int m){
  long long int start = 0;
  long long int end = *max_element(trees.begin(), trees.end());
  long long ans = -1;
  while(start <= end){
    long long int mid = start + (end-start)/2;
    if(isPossible(trees, mid, m)){
      ans = mid;
      start = mid+1;
    } 
    else
      end = mid-1;
  }
  return ans;
}
int main() {
  long long int n, m;
  cin>>n>>m;
  vector<long long int> trees;
  while(n--){
    long long int height;
    cin>>height;
    trees.push_back(height);
  }
  cout<<maxHeightOfBlade(trees, m);
    return 0;
}