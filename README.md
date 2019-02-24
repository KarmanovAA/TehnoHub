# TehnoHub
List of hometasks and projects

int main() {
	int *data = new int[10];
	for (int i = 0; i < 10; i++) {
		data[i] = i;
	}
	for (int i = 0; i < 10; i++) {
		cout << data[i] << endl;
	}
	data[10] = *(new int);
	delete (data + 10);
	for (int i = 0; i < 11; i++) {
		cout << data[i] << endl;
	}
	return 0;
};
