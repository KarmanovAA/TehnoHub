#include <iostream>
#include <cstdlib>
#include <stdexcept>
using std::cin;
using std::cout;
#define CriticalCapacity 25000

class Stack {
private:
	int *data_;
	int size_;
	long hash_;
	int capacity_;
	long Hash_Function() const; // Hash-function, enough to track unwelcome changes
public:
	Stack() : data_(new int[1]), size_(0), hash_(0), capacity_(1) {};//default constructor
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
		init.Status();
		data_ = new int[init.size_ + 1];
		size_ = init.size_;
		for (int i = 0; i < init.size_; i++) {
			data_[i] = init.data_[i];
		}
		hash_ = Hash_Function();
}

void Stack::Push(int elem) {
	Status();
	if(capacity_ == size_) // Reached the border
	{
		if (capacity_ >= CriticalCapacity)			  // Working on a big amount of data and trying 
		{											 //to avoid overreserving of data
			capacity_ += CriticalCapacity / 25;
			int* tmp = new int[size_];
			for (int i = 0; i < size_; i++)
				tmp[i] = data_[i]; //Moving data to temporary storage
			++size_;
			data_ = new int[capacity_]; // Building stack with an up-to-date capacity
			for (int i = 0; i < size_ - 1; i++)
				data_[i] = tmp[i];
			data_[size_ - 1] = elem; // pushback itself
			hash_ = Hash_Function();
			Status();
		}
		else
		{ 							// Having relatively small stack
			capacity_ *= 2;
			int* tmp = new int[size_];
			for (int i = 0; i < size_; i++)
				tmp[i] = data_[i]; //Moving data to temporary storage
			++size_;
			data_ = new int[capacity_]; // Building stack with an up-to-date capacity
			for (int i = 0; i < size_ - 1; i++)
				data_[i] = tmp[i];
			data_[size_ - 1] = elem; // pushback itself
			hash_ = Hash_Function();
			Status();
		}
	}
	else 								//Still free space reserved
	{
		Status();
		data_[size_] = elem;
		size_++;
		hash_ = Hash_Function();
		Status();
	}
}

int Stack::Pop() {
	if (size_ != 0) 
	{
		Status();
		if (capacity_ < CriticalCapacity) // Same as Push
		{
			Status();
			if (size_ < capacity_ / 2) //Lots of unused space 
			{
				capacity_ /= 2;
				int *tmp = new int[size_];
				for (int i = 0; i < size_; i++)
					tmp[i] = data_[i];
				--size_	;
				data_ = new int[capacity_];
				for (int i = 0; i < size_; i++)
					data_[i] = tmp[i];
				hash_ = Hash_Function();
				return tmp[size_];
			}			// Not a lot of data free
			--size_;
			hash_ = Hash_Function();
			Status();
			return data_[size_];
		}
		else 						//Moving to bigger Stack
		{
			if (size_ < capacity_ - CriticalCapacity / 25)
			{

				capacity_ -= CriticalCapacity / 25;
				int *tmp = new int[size_];
				for (int i = 0; i < size_; i++)
					tmp[i] = data_[i];
				--size_;
				data_ = new int[capacity_];
				for (int i = 0; i < size_; i++)
					data_[i] = tmp[i];
				hash_ = Hash_Function();
				return tmp[size_];
			}
			--size_;
			hash_ = Hash_Function();
			Status();
			return data_[size_];
		}
	}
	else
	{
		std::cerr << "Can`t Pop from empty stack" << std::endl;
		return 0;
	}
}

void Stack::Status() const {
	if (size_ < 0)
	{
		std::cerr << "Wrong size" << std::endl;
		abort();
	}
	else
	{
		if (data_ == nullptr)
		{
			std::cerr << "No database" << std::endl;
			abort();
		}
		else
		{
			if (hash_ != Hash_Function()) 
			{
				std::cerr << "Data intruded" << std::endl;
				for (int i = 0; i < size_; i++)
					cout << i << " : " << data_[i] << std::endl;
				abort();
			}
			else
			{
				if (capacity_ < size_) {
					std::cerr << "Capacity is less than current size" << std::endl;
					abort();
				}
			}
		}
	}
}

void Stack::Dump() const {
	Status();
	for (int i = 0; i < size_; i++)
		cout << i << " : " << data_[i] << std::endl;
}


long Stack::Hash_Function() const{
	long result = size_;
	for (int i = 0; i < size_; i++) {
		result *= 2;
		result += data_[i];
	}
	return result;
}


int main() {
	Stack s;
	for (int i = 0; i < 10; i++) {
		s.Push(i);
	}
	for (int i = 0; i < 11; i++) {
		cout << s.Pop() << std::endl;
	}
	system("pause");
	return 0;
};	
