// view_test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include"pch.h"
#include <iostream>
#include <math.h>
#include<string>
using namespace std;

double MAX(double *list)
{
	double max=list[0];
	int i = 0;
	while (list[i]!=NULL) {
		if (max < list[i]) {
			max = list[i];
		}
		i++;
	}
	return max;
}

void draw_routine(int N) {
	string result;
	if (N <= 10 && N >= 1) {
		for (int i = 0; i <= N;i++) {
			for (int m = 0; m <= N; m++) {
				if (i == 0) {
					if(m==0) result += to_string(4*N) + "\t";
					else result +=( to_string(m)+"\t");
				}if (i==N) {
					result += ( to_string(3 * N - m) + "\t");
				}
				if(i<N&&i>0){
					if (m == 0) result += to_string(4 * N-i);
					if (m == N) result += to_string(N + i);
					else result += "\t";
				}

			}	
			result += "\n";
		}
	}
	else
	{
		result = "请输入1~10范围的正整数\n";
	}
	cout << result;
}

double max(double x1, double x2) {
	double max=x1;
	if (x1 < x2) max = x2;
	return max;
}

const int N = 15;

/*int main()
{
	int v[N] = { 0,8,10,6,3,7,2 };
	int w[N] = { 0,4,6,2,2,5,1 };


	int m[N][N];
	int n = 6, c = 12;
	memset(m, 0, sizeof(m));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			if (j >= w[i])
				m[i][j] = max(m[i - 1][j], m[i - 1][j - w[i]] + v[i]);


			else
				m[i][j] = m[i - 1][j];
		}
	}


	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			cout << m[i][j] << '\t';
		}
		cout << endl;
	}


	return 0;
}*/

/**冒泡***/

double *bubble_sort(double a[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			double tem = a[j];
			if (a[j] > a[j + 1]) {
				a[j] = a[j + 1];
				a[j + 1] = tem;
			}
		}
	}
	return a;
}

/**选择排序***/
double* select_sort(double a[],int n) {
	for (int i = 0; i < n; i++) {
		double min = a[i];
		int index=i;
		for (int j = i; j < n; j++) {
			if (min > a[j]) {
				min = a[j];
				index = j;
			}
		}
		a[index] = a[i];
		a[i] = min;
	}
	return a;
}

/****直接插入排序****/

double* insertion_sort(double a[], int n) {
	for (int i = 1; i < n; i++) {
		double s = a[i];
		int j = i;
		while (j >= 0 && s>a[j]) {
			a[j] = a[j - 1];
			j--;
		}
		a[j] = s;
	}
	return a;
}
/***快速排序**/
double* quick_sort(double v[], int left,int right) {
	if (left < right)
	{
		int key = v[left];  
		int low = left;
		int high = right;
		while (low < high)   
		{
			while (low < high && v[high] >= key)     
			{
				high--;     //最高位数组下标自减
			}
			v[low] = v[high];   //如果高位下标的值小于基准值就放到数组左边
			while (low < high && v[low] < key)   //将小于基准值的值放在数组左边
			{
				low++;      //最低位数组下标自增
			}
			v[high] = v[low];   //如果低位下标的值大于基准值就放到数组右边
		}
		v[low] = key;   //最后将基准值放入数组
		quick_sort(v, left, low - 1);    //遍历调用排序函数
		quick_sort(v, low + 1, right);
	}
	return v;
}

int main() {
	double x[] = {11, 5,3,2,7,1,8,4,9,6,0 };

	cout << "bubble_sort:\n";
	for (int i = 0; i < 10; i++) {
		cout << bubble_sort(x, 10)[i];
		cout << '\t';
	}
	cout << '\n';

	cout << "select_sort:\n";
	for (int i = 0; i < 10; i++) {
		cout << select_sort(x, 10)[i];
		cout << '\t';
	}
	cout << '\n';

	cout << "insertion_sort:\n";
	for (int i = 0; i < 10; i++) {
		cout << insertion_sort(x, 10)[i];
		cout << '\t';
	}
	cout << '\n';

	cout << "quick_sort:\n";
	for (int i = 0; i < 10; i++) {
		cout << quick_sort(x, 0,9)[i];
		cout << '\t';
	}
	cout << '\n';

	cout << 8 % 3;
	return 0;
}