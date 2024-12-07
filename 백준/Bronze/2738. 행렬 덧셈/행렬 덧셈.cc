#include <stdio.h>
#include <iostream>
int main() {
    int N = 0;
	int M = 0;
	scanf("%d", &N);
	scanf("%d", &M);

	int temp;
	int arr[N][M];
	int arr2[N][M];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &temp);
			arr[i][j] = temp;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &temp);
			arr2[i][j] = temp;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%d ", arr[i][j] + arr2[i][j]);
		}
		printf("\n");
	}
    return 0;
}
