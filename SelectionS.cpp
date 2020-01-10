#include <stdio.h>
#include <stdlib.h>
#define SWAP(x,y,t)((t)=(x),(x)=(y),(y)=(t))

// ���� �Լ��� �̿��Ͽ� int �迭�� 0~max-1�� ������ �������� ä��� �Լ�
static void initRandom( int list[], int n, int max=100 )
{
    for( int i=0 ; i<n ; i++ )
	list[i] = rand() % max;
}

// �迭�� ȭ�鿡 ���� ���� ����ϴ� �Լ�. ����Ʈ �Ű����� ���
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
    least = i;   	     //least=������ ����Ʈ ���� �ε���
    for(j=i+1; j<n; j++)		
      if(list[j]<list[least]) //�� ���� �� ã��
		least = j; 
    SWAP(list[i],list[least],tmp); // ��ȯ
    printStep(list, n, i+1);
  }
}

void main()
{
	int list[9] = { 5, 3, 8, 4, 9, 1, 6, 2, 7 };
	printArray( list, 9, "Original Data" );	// ���� �� �迭 ��� 
	selection_sort( list, 9 ); 		// ���� ���� ���� 
	printArray( list, 9, "Sorted Data  " );	// ���� �� �迭 ��� 

	system("pause");
}
