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

    void getSum() {
        std::cout << "[OUT]: get_sum() = " << sumThreeArray << std::endl;
    }
    void getCount() {
        std::cout << "[OUT]: get_count() = " << countThreeArray << std::endl;
    }

    void operator()() {
        for (int i = 0; i < sizeArr; i++) {
            if (arr[i] % 3 == 0) {
                sumThreeArray += arr[i];
                countThreeArray++;
            }
        }
    }
private:
    int* arr;
    int sizeArr, sumThreeArray = 0, countThreeArray = 0;
};

void printArray(int* arr,int sizeArr) {
    for (int i = 0; i < sizeArr; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
int main() {
    int arr[] = {4, 1, 3, 6, 25, 54};
    std::cout << "[IN]: ";
    printArray(arr, sizeof(arr) / sizeof(arr[0]));
    Counter counter(arr,sizeof(arr)/sizeof(arr[0]));
    counter();
    counter.getSum();
    counter.getCount();
}