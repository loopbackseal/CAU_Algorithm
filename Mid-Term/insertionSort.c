//
// Created by Young Soo Hwang on 2022/04/21.
//

#include <stdio.h>
#include <sys/time.h>

void insertionSort(int *arr, int n) {
	int i;
	int j;
	int key;

	j = 0;
	while (++j < n)
	{
		key = arr[j];
		i = j;
		while (--i >= 0 && arr[i] > key)
			arr[i + 1] = arr[i];
		arr[i + 1] = key;
	}
}

long long timestamp() {
	long long milliseconds;

	struct timeval te; 
	gettimeofday(&te, NULL); // get current time
	milliseconds = te.tv_sec*1000LL + te.tv_usec/1000; // calculate milliseconds
    //printf("milliseconds: %lld\n", milliseconds);
    return milliseconds;
}

int main()
{
	int			arr[10000];
	int 		i;
	long long	startTime;
	long long	endTime;

	i = -1;
	while (++i < 10000)
	{
		arr[i] = 10000 - i;
		printf("%d ", arr[i]);
	}
	printf("\n");
	startTime = timestamp();
	insertionSort(arr, 10000);
	endTime = timestamp();
	while (--i > -1)
	{
		printf("%d ", arr[9999 - i]);
	}
	printf("\n");
	printf("time: %lld\n", endTime - startTime);
	return (0);
}

