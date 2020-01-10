#include <stdio.h>
#include <stdlib.h>
#define SWAP(x,y,t)((t)=(x),(x)=(y),(y)=(t))

// 랜덤 함수를 이용하여 int 배열을 0~max-1의 값으로 무작위로 채우는 함수
static void initRandom( int list[], int n, int max=100 )
{
    for( int i=0 ; i<n ; i++ )
	list[i] = rand() % max;
}

// 배열을 화면에 보기 좋게 출력하는 함수. 디폴트 매개변수 사용
static void printArray( int arr[], int n, char *str="Array" )
{
    printf("%s = ", str);
    for( int i=0 ; i<n ; i++ )
       printf("%3d", arr[i]);
    printf("\n");
}

static void printStep( int arr[], int n, int c )
{
    printf("Step        %d = ", c);
    for( int i=0 ; i<n ; i++ )
       printf("%3d", arr[i]);
    printf("\n");
}

void selection_sort(int list[], int n) 
{
  int i, j, least,tmp;
  for( i=0 ; i<n-1 ; i++) { 
    least = i;   	     //least=오른쪽 리스트 시작 인덱스
    for(j=i+1; j<n; j++)		
      if(list[j]<list[least]) //더 작은 수 찾기
		least = j; 
    SWAP(list[i],list[least],tmp); // 교환
    printStep(list, n, i+1);
  }
}

void main()
{
	int list[9] = { 5, 3, 8, 4, 9, 1, 6, 2, 7 };
	printArray( list, 9, "Original Data" );	// 정렬 전 배열 출력 
	selection_sort( list, 9 ); 		// 선택 정렬 실행 
	printArray( list, 9, "Sorted Data  " );	// 정렬 후 배열 출력 

	system("pause");
}
