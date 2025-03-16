#include <iostream>
#include <vector>


template <class T>
T squaring (T num){
	std::cout << num * num << std::endl;
	return num * num;
}

template <class T>
std::vector<T> squaring(std::vector<T> &vec) {
	int size = vec.size();
	std::vector<int> newVect(size);
	for (int i = 0; i < size; i++) {
		newVect[i] = vec[i] * vec[i];
	}
	return newVect;
}

template <class T>
void printArray(const std::vector<T>& arr) {
	for (const auto& elem : arr) {
		std::cout << elem << " ";
	}
	std::cout << std::endl;
}
int main() {
	squaring(7);
	std::vector<int> vec{ 1, 10,7,-9,4 };
	printArray(vec);
	printArray(squaring(vec));
}
