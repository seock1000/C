#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DOUBLE_MAX 1.7976931348623157e+308

typedef struct _point {
	double x;
	double y;
} Point;

void DrawRouteFromThePoint(double* graph, Point* point, int n, int target) {
	for (int i = 0; i < n; i++) {
		graph[i] = sqrt(pow(point[target].x - point[i].x, 2.0) + pow(point[target].y - point[i].y, 2.0));
	}
}

void DrawGraph(double (*graph)[30], Point* point, int n) {
	for (int i = 0; i < n; i++) {
		DrawRouteFromThePoint(graph[i], point, n, i);
	}
}

double MST(double (*graph)[30], int n) {
	double result = 0;
	int visit[30];
	int unvisit[30];
	int i, j, k;

	visit[0] = 0;

	for (i = 0; i < n; i++) {
		unvisit[i] = i + 1;
	}

	for (i = 1; i < n; i++) {
		double min = DOUBLE_MAX;
		int min_index = 0;

		for (j = 0; j < i; j++) {
			for (k = 0; k < n - i; k++) {
				if (graph[visit[j]][unvisit[k]] > 0 && min > graph[visit[j]][unvisit[k]]) {
					min = graph[visit[j]][unvisit[k]];
					min_index = k;
				}
			}
		}
		visit[i] = unvisit[min_index];
		for (j = min_index; j < n - i; j++)
			unvisit[j] = unvisit[j + 1];
		result += min;
	}

	return result;
}

int main() {
	FILE* fp;

	if ((fp = fopen("test.txt", "r")) == NULL) {
		printf("File open failed!\n");
		exit(-1);
	}

	int numOfPoint;
	fscanf(fp, "%d", &numOfPoint);

	Point point[30];
	double graph[30][30];
	int i;

	// input point data
	for (i = 0; i < numOfPoint; i++) {
		fscanf(fp, "%lf", &point[i].x);
		fscanf(fp, "%lf", &point[i].y);
	}

	// drawGraph
	DrawGraph(graph, point, numOfPoint);

	printf("%.2f\n", MST(graph, numOfPoint));

	return 0;
}