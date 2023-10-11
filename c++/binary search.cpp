#include<iostream>
using namespace std;
int BSearch(int arr[], int i, int j,int ele){
	int low=i;
	int high=j;
	int mid;
	while(low<=high){
		mid=(low+high)/2;
		if(arr[mid]==ele){
			return mid;
		}
		else if(arr[mid]>ele){
			low=mid+1;
		}
		else{
			high=mid-1;
		}
	}
	return -1;
	
}
int main(){
	int arr[10]={1,2,3,4,5,6};
	int size=sizeof(arr)/sizeof(int);
	int index=BSearch(arr,0,size-1,5);
	if(index==-1){
		cout<<"element not found"<<endl;
		
	}
	else{
		cout<<"element is found at index : "<<index<<endl;
	}
	
}
