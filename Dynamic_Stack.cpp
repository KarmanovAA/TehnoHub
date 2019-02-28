#include <iostream>
#include <cstdlib>
#include <stdexcept>
using namespace std;


class Stack {
private:
	int *data_;
	int size_;
	double avg; // last Average
	double Average() const; // Hash-function, enough to track unwelcome changes
public:
	Stack() : data_(new int[0]), size_(0), avg(0) {};//default constructor
	Stack(const Stack&);//Copying constructor
	~Stack() {
		delete[]data_;
		data_ = nullptr;
	};
	void Push(int elem); 
	int Pop(); 
	void Status() const;// Check for faults
	void Dump() const; 

};

Stack::Stack(const Stack& init) {
	try{
		init.Status();
		data_ = new int[init.size_ + 1];
		size_ = init.size_;
		for (int i = 0; i < init.size_; i++) {
			data_[i] = init.data_[i];
		}
		avg = Average();
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}
}

void Stack::Push(int elem) {
	try {
		Status();
		int* tmp = new int[size_];
		for (int i = 0; i < size_; i++)
		tmp[i] = data_[i]; //Moving data to temporary storage
		//delete[] data_; Why cant i do this? Do I need it?
		++size_;
		data_ = new int[size_]; // Building stack with an up-to-date size
		for (int i = 0; i < size_ - 1; i++)
			data_[i] = tmp[i];
		data_[size_ - 1] = elem; // pushback itself
		avg = Average();
		Status();
	} catch (const exception& e) {
		cout << e.what() << endl;
	}
}

int Stack::Pop() {
	try{
		if (size_ != 0) {
			Status();
			int* tmp = new int[size_];
			for (int i = 0; i < size_; i++)
				tmp[i] = data_[i]; // same as Push
			//delete[] data_;
			--size_;
			data_ = new int[size_]; 
			for (int i = 0; i < size_; i++)
				data_[i] = tmp[i];
			avg = Average();
			Status();
			return tmp[size_]; // the Last element is still stored in temporary
		}
		else
			throw logic_error("Stack is empty");
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}
	return 0;
}

void Stack::Status() const {
	if (size_ < 0)
		throw logic_error("Wrong size");
	if (data_ == NULL)
		throw logic_error("No database");
	if (avg != Average())
		throw logic_error("Data intruded");
}

void Stack::Dump() const {
	try {
		Status();
		for (int i = 0; i < size_; i++)
			cout << i << " : " << data_[i] << endl;
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}
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
	for (int i = 0; i < 30; i++)
		s.Push(i);
	s.Dump();
	s.Push(30);
	cout << "----------------" << endl;
	for (int i = 0; i < 32; i++)
		s.Pop();
	s.Dump();
	s.Push(5);
	s.Dump();
	system("pause");
	return 0;
};	
