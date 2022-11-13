#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _point {
	double x, y;

	double p, q;

} Point;

Point* stack;
int top;

void Input(FILE*, Point[], int);
void Sort(Point[], int);
double ccw(Point, Point, Point);
void GrahamScan(Point[], int);
double TotalDist();

void StackInit(int);
void Push(Point);
Point Pop();

int main() {
	FILE* fp;
	if ((fp = fopen("test.txt", "r")) == NULL) {
		printf("File open fail!\n");
		exit(-1);
	}

	int sampleNum;
	fscanf(fp, "%d", &sampleNum);
	
	for (int i = 0; i < sampleNum; i++) {
		int pointNum;
		fscanf(fp, "%d", &pointNum);

		Point* point = (Point*)malloc(sizeof(Point) * (pointNum + 1));
		double result;

		StackInit(pointNum);
		
		Input(fp, point, pointNum);

		Sort(point, pointNum);

		GrahamScan(point, pointNum);

		result = TotalDist() + 2;

		printf("%0.2lf\n", ceil(result * 100) / 100);

		free(point);
		free(stack);

	}

	return 0;
}

void Input(FILE* fp, Point* point, int pointNum) {
	float x, y;
	
	for (int i = 0; i < pointNum; i++) {
		fscanf(fp, "%f %f", &x, &y);
		point[i].x = x;
		point[i].y = y;
	}
}


bool cmp(Point a, Point b) {
	if (1LL * a.p * b.q != 1LL * a.q * b.p) return 1LL * a.q * b.p < 1LL * a.p * b.q;
	if (a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}


void Sort(Point point[], int n) {
	int stdIdx = 0;
	for (int i = 1; i < n; i++) {
		if (point[stdIdx].y > point[i].y) {
			stdIdx = i;
		}
		else if (point[stdIdx].y == point[i].y) {
			if (point[stdIdx].x > point[i].x) {
				stdIdx = i;
			}
		}
	}
	Point tmp = point[0];
	point[0] = point[stdIdx];
	point[stdIdx] = tmp;

	for (int i = 1; i < n; i++) {
		point[i].p = point[i].x - point[0].x;
		point[i].q = point[i].y - point[0].y;
	}

	for (int i = 1; i < n; i++) {
		int minIdx = i;
		for (int j = i + 1; j < n; j++) {
			if (cmp(point[j], point[minIdx])) {
				minIdx = j;
			}
		}
		Point temp = point[minIdx];
		point[minIdx] = point[i];
		point[i] = temp;
	}

}

void StackInit(int n) {
	stack = (Point*)malloc(sizeof(Point) * (n + 1));
	top = -1;
}

void Push(Point point) {
	stack[++top] = point;
}

Point Pop() {
	return stack[top--];
}

double ccw(Point A, Point B, Point C) {
	return (B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y);
}

void GrahamScan(Point point[], int n) {

	Push(point[0]);
	Push(point[1]);

	for (int i = 2; i < n; i++) {
		if (ccw(point[i - 2], point[i - 1], point[i]) < 0)
			Pop();
		Push(point[i]);
	}
}

double PointDist(Point A, Point B) {
	return sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2));
}

double TotalDist() {
	double result = 0;
	Point origin;
	origin.x = 0;
	origin.y = 0;

	for (int i = 1; i <= top; i++) {
		result += PointDist(stack[i - 1], stack[i]);
	}

	result += PointDist(stack[top], origin);
	result += PointDist(stack[0], origin);

	return result;
}