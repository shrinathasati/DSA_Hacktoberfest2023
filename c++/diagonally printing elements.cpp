#include<iostream>
using namespace std;
int main(){
	int arr[5][5]={{1,2,3},
				{4,5,6},
				{7,8,9}};
	int i=0;
	int k=0;
	int n=3;
	while(n!=0){
		for(int j=k;j<n;j++){
			cout<<arr[i][j]<<endl;
			i++;
		}
		i=0;
		k=k+1;
//		n=n-1;
	}
}
