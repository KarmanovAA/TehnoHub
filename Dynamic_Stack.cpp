#include "stdafx.h"
#include <iostream>
using namespace std;


class Stack {
private:
	int *data_;
	int size_;
	double avg;
	double Average() const; // ������ ���-�������, ������� �� ������ ������ ����� ����������� ������
public:
	Stack() :  data_(new int[1]), size_(0), avg(0) {};//����������� �� ���������
	//Stack(int size);  ����������� �� ������������� ����� ���������
	Stack(const Stack&);//���������� ����������� 
	~Stack() {
		if (!Status())
			abort();
		delete[size_ + 1]data_;
	};// ����������
	void Push(int elem); // �������� �������
	int Pop(); // ������ �������
	bool Status() const;// ���������, ��� �� �� ������ � �������
	void Dump() const;

};
/*
Stack::Stack(int size) {
	if (size > 0) {
		size_ = 0;
		avg = 0;
		data_ = new int[size];
	}
	else
		cerr << "Size must be greater than zero" << endl;
}  
*/
Stack::Stack(const Stack& init) {
	if (init.Status()) {
		data_ = new int[init.size_ + 1];
		size_ = init.size_;
		for (int i = 0; i < init.size_; i++) {
			data_[i] = init.data_[i];
		}
		avg = Average();
	}
	else
		cerr << "Invalid initial data " << endl;
}

void Stack::Push(int elem) {
	if (!Status())
		abort();
	data_[size_] = elem;
	++size_; 
	avg = Average();
	data_[size_] = *(new int);  // �������� ��� ������ ������, ����� ������ �������� 
	if (!Status())				// (�� ����, �������� �� ������� � ����� ������)
		abort();
}

int Stack::Pop() {
	if (size_ != 0) {
		if (!Status())
			abort();
		int res = data_[size_ - 1];
		delete (data_ + size_); // ������ ����������� ��������� ������ 
		--size_;               // ������������ ������(��������� �� ��������� ���������) ��� �������?????????????
		avg = Average();
		if (!Status())
			abort();
		return res;
	}
	else
		cerr << "Stack is empty" << endl;
	return 0;
}

bool Stack::Status() const {
	if (size_ < 0)
	{
		cerr << "wrong size" << endl;
		return 0;
	}
	else
		if (data_ == NULL)
		{
			cerr << "No database" << endl;
			return 0;
		}
		else
			if (avg != Average())
			{
				cerr << "Data intruded" << endl;
				return 0;
			}
			else
				return 1;
}

void Stack::Dump() const {
	if (!Status())
		abort();
	for (int i = 0; i < size_; i++)
		cout << i << " : " << data_[i] << endl;
}

double Stack::Average() const {
	double avg = 0;
	for (int i = 0; i < size_; i++) {
		avg += static_cast<double>(data_[i]) / size_;
	}
	return avg;
}

int main() {
	int *data = new int[10];
	for (int i = 0; i < 10; i++) {
		data[i] = i;
	}
	for (int i = 0; i < 10; i++) {
		cout << data[i] << endl;
	}
	data[10] = *(new int);
	delete [] &data[10];
	for (int i = 0; i < 11; i++) {
		cout << data[i] << endl;
	}
	return 0;
};