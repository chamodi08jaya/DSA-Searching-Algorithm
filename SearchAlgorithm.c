#include <stdio.h>
#include <math.h>
#include <stdlib.h>

	int result;
	int i;
	
	int binarysearch(int array[],int leftmost,int rightmost,int x){
		while(leftmost <= rightmost){
			int middle = leftmost + (rightmost - leftmost)/2;
			
			if(array[middle]==x){
				return middle;
			}
			if(array[middle]<x){
				leftmost=middle+1;
			}else{
				rightmost=middle-1;
			}
			
		}
		return -1;
		
	}
	
	int linearSearch(int array[],int n,int search){
		for(i=0;i<n;i++){
			if(array[i]==search){
				printf("%d is present at index %d.\n", search,i);
				break;
			}
		}
		if(i==n){
			printf("%d isn't present in the array.\n",search);
		}
		
		return 0;
	}

	int jumpSearch(int array[],int n,int x){
		int root=sqrt(n);
		int prev=0;
		int step=0;
		int location=0;
		int i,j;
		
		for(i=0;i<n;i++){
			if(root*i*step<=x){
				step++;
			}else{
				prev=root*(i-1);
				location=prev;
		   }
				for( j=prev;j<=prev+root;j++){
					location++;
					if(array[j]==x){
						printf("%d is present in the  array in the location of %d.\n",x,location);
						exit(0);
						
						
					}
				}
				
			
		}
		printf("Element not found in the array.\n" );
		
	}


	int interpolationSearch(int array[],int n,int x){
		int lowEnd = 0;
		int highEnd =(n-1);
		
		while (lowEnd <= highEnd && x>= array[lowEnd] && x <= array[highEnd]){
			if(lowEnd== highEnd){
				if(array[lowEnd]==x);
				return lowEnd;
			}else{
				return -1;
			}
			
			int pos=lowEnd+(((double)(highEnd-lowEnd)/(array[highEnd]-array[lowEnd]))*(x-array[lowEnd]));
			
			if(array[pos]==x){
				return pos;
			}
			
			if(array[pos]<x){
				lowEnd=pos+1;	
			}else{
				highEnd=pos-1;
			}
		}
		return -1;
		
		
	}
	
	
	int comparisonFunction(const void * element1,const void * element2){
		int first = *((int*)element1);
		int second = *((int*)element2);
		
		if(first > second){
			return 1;
		}
		if(first < second){
			return -1;
		}
		 return 0;
		
	}
	
	
	int main(){
		
		int array[]={0,1,1,2,3,5,8,13,21,34,55,89,144,233,377,610};
		
		int searchtype;
		
		printf("Welcome!\n");
		printf("Enter 1- Binary Search\n");
		printf("Enter 2- Linear search\n");
		printf("Enter 3- Jump Search\n");
		printf("Enter 4- Interpoltion Search\n");
		
		scanf("%i",&searchtype);
		
		int n=sizeof(array)/sizeof(array[0]);
		int x=21;
		
		qsort(array,sizeof(array)/sizeof(*array),sizeof(*array),comparisonFunction);
		
		switch(searchtype){
			case 1:
				result=binarysearch(array,0,n-1,x);
				
				(result==-1)?printf( "Element is not present in array\n "): printf("Element is present at index %d\n",result);
				break;
				
			case 2:
				linearSearch(array,n,x);
				break;
			
			case 3:
				result=jumpSearch(array,n,x);
				
			case 4:
				result=interpolationSearch(array,n,x);
//				default;
				
			if(result != -1){
				printf("Element found at index %d\n", result);
			}else{
				printf("Element not found");
			}
			
		  	default:
			break;	
		}
		return 0;
	}
