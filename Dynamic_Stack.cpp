#include <iostream>
#include <cstdlib>
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
		if (!Status())
			abort();
		delete[]data_;
		data_ = nullptr;
	};
	void Push(int elem); 
	int Pop(); 
	bool Status() const;// Check for faults
	void Dump() const; 

};

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
	if (size_ != 0) {
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
	}
	else {
		++size_;
		data_[0] = elem;
	}
	if (!Status())			
		abort();
}

int Stack::Pop() {
	if (size_ != 0) {
		if (!Status())
			abort();
		int* tmp = new int[size_];
		for (int i = 0; i < size_; i++)
			tmp[i] = data_[i]; // same as Push
		//delete[] data_;
		--size_;
		data_ = new int[size_]; 
		for (int i = 0; i < size_; i++)
			data_[i] = tmp[i];
		avg = Average();
		if (!Status())
			abort();
		return tmp[size_]; // the Last element is still stored in temporary
	}
	else
		cerr << "Stack is empty" << endl;
	return 0;
}

bool Stack::Status() const {
	if (size_ < 0)
	{
		cerr << "Wrong size" << endl;
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
	for (int i = 0; i < 30; i++)
		s.Push(i);
	s.Dump();
	s.Push(30);
	cout << "----------------" << endl;
	for (int i = 0; i < 20; i++)
		s.Pop();
	s.Dump();
	system("pause");
	return 0;
};	
