#include<iostream>
using namespace std;
void input(int arr[],int size){
	for(int i=0;i<size;i++){
		cout<<"enter element "<<(i+1)<<endl;
		cin>>arr[i];
	}
}

void display(int arr[],int size){
	cout<<"given array is:"<<endl;
	for(int i=0;i<size;i++){
		cout<<arr[i]<<endl;
	}
}
void merge(int arr[],int arr1[],int b[],int m,int n){
	int i=0;
	int j=0;
	int k=0;
	
	while(i<m&&j<n){
		if(arr[i]<arr1[j]){
			b[k]=arr[i];
			i++;
			k++;
			
		}
		else{
			b[k]=arr1[j];
			j++;
			k++;
		}
	}
	while(i<m){
		b[k]=arr[i];
		i++;
		k++;
		
	}
	while(j<n){
		b[k]=arr1[j];
		j++;
		k++;
		
	}
}
int bubble(int arr[],int size){
	int temp;
	for(int i=0;i<size-1;i++){
		for(int j=0;j<size-i-1;j++){
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}

int main(){
	int size1,size2;
	cout<<"enter size of array1:"<<endl;
	cin>>size1;
	int arr[size1];
	input(arr,size1);
	
	cout<<endl;
	
	cout<<"enter size of array2:"<<endl;
	cin>>size2;
	int arr1[size2];
	input(arr1,size2);
	
	cout<<endl;
	
	cout<<"array 1 is:"<<endl;
	display(arr,size1);
	
	cout<<endl;
		
	cout<<"array 2 is:"<<endl;
	display(arr1,size2);
	
	cout<<endl;
	bubble(arr,size1);
	bubble(arr1,size2);
	

	int b[size1+size2];
	merge(arr,arr1,b,size1,size2);
	cout<<"the sorted and merged array of array1 and array2 is:"<<endl;
	display(b,size1+size2);
	return 0;
	
}
