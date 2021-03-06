// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<vector>
#include<string>
using namespace std;

class MyCircularQueue {
public:
	/** Initialize your data structure here. Set the size of the queue to be k. */
	MyCircularQueue(int k) {
		size = k;
		head = -1;
		tail = -1;
	}

	/** Insert an element into the circular queue. Return true if the operation is successful. */
	bool enQueue(int value) {
		if (isFull()) {
			return false;
		}
		else {
			if (!isEmpty()) {
				tail++;
				data.push_back(value);
			}
			else {
				head++;
				tail++;
				data.push_back(value);
			}
			return true;
		}
	}

	/** Delete an element from the circular queue. Return true if the operation is successful. */
	bool deQueue() {
		if (isEmpty()) {
			return false;
		}
		else {
			head++;
			if (tail < head) {
				head = -1;
				tail = -1;
				data.clear();
			}
			return true;
		}
	}

	/** Get the front item from the queue. */
	int Front() {
		if (isEmpty()) {
			return -1;
		}
		else {
			return data[head];
		}
	}

	/** Get the last item from the queue. */
	int Rear() {
		if (isEmpty()) {
			return -1;
		}
		else {
			return data[tail];
		}
	}

	/** Checks whether the circular queue is empty or not. */
	bool isEmpty() {
		if (head == -1) {
			return true;
		}
		else {
			return false;
		}
	}

	/** Checks whether the circular queue is full or not. */
	bool isFull() {
		if ((tail - head + 1) == size) {
			return true;
		}
		else {
			return false;
		}
	}
	int size;
	int head;
	int tail;
	vector<int> data;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * bool param_1 = obj.enQueue(value);
 * bool param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * bool param_5 = obj.isEmpty();
 * bool param_6 = obj.isFull();
 */

int main()
{
	int k = 4;
	int value = 5;
	MyCircularQueue obj = MyCircularQueue(k);
	bool param_1 = obj.enQueue(value);
	cout << param_1 << '\t';
	bool param_2 = obj.deQueue();
	cout << param_2 << '\t';
	int param_3 = obj.Front();
	cout << param_3 << '\t';
	int param_4 = obj.Rear();
	cout << param_4 << '\t';
	bool param_5 = obj.isEmpty();
	cout << param_5 << '\t';
	bool param_6 = obj.isFull();
	cout << param_6 << '\t';
	bool param_7 = obj.enQueue(6);
	cout << param_7 << '\t';
	int param_8 = obj.Front();
	cout << param_8 << '\t';
	bool param_9 = obj.enQueue(7);
	cout << param_9 << '\t';
	int param_10 = obj.Rear();
	cout << param_10 << '\t';
	
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
