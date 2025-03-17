#include <iostream>

class Counter {
public:
    Counter(int* arr, int sizeArr) {
        this->sizeArr = sizeArr;
        this->arr = new int[sizeArr];
        std::copy(arr, arr + sizeArr, this->arr);
    }
    ~Counter() {
        delete[] arr;
    }

    int getSum() {
        int sum = 0;
        for (int i = 0; i < sizeArr; i++) {
            if (arr[i] % 3 == 0) {
                sum += arr[i];
            }
        }
        return sum;
    }
    int getCount() {
        int count = 0;
        for (int i = 0; i < sizeArr; i++) {
            if (arr[i] % 3 == 0) {
                count++;
            }
        }
        return count;
    }

    void operator()() {
        printArr();
        std::cout << "[OUT]: get_sum() = " << getSum() << std::endl;
        std::cout << "[OUT]: get_count() = " << getCount() << std::endl;
    }
private:
    int* arr;
    int sizeArr;

    void printArr() {
        std::cout << "[IN]: ";
        for (int i = 0; i < sizeArr; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};
int main() {
    int arr[] = {4, 1, 3, 6, 25, 54};
    Counter counter(arr,sizeof(arr)/sizeof(arr[0]));
    counter();
}