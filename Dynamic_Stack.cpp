#include <cstdlib>
#include <iostream>
using namespace std;


class Stack {
private:
	int *data_;
	int size_;
	double avg;
	double Average() const; // Аналог Хэш-Функции, дешевый по памяти способ иметь контрольные данные
public:
	Stack() :  data_(new int[1]), size_(0), avg(0) {};//конструктор по умолчанию
	//Stack(int size);  конструктор на фиксированное число элементов
	Stack(const Stack&);//копирующий конструктор 
	~Stack() {
		if (!Status())
			abort();
		delete[]data_;
	};// деструктор
	void Push(int elem); // добавить элемент
	int Pop(); // убрать элемент
	bool Status() const;// Проверить, все ли со стеком в порядке
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
	if (!Status())	
		abort();
}

int Stack::Pop() {
	if (size_ != 0) {
		if (!Status())
			abort();
		--size_;
		avg = Average();
		if (!Status())
			abort();
		return data_[size_];
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
	Stack s;
	s.Push(1);
	s.Push(2);
	s.Push(3);
	s.Push(4);
	s.Push(5);
	s.Dump();
	s.Pop();
	s.Pop();
	s.Dump();

	return 0;
};
