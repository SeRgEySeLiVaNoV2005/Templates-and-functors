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
    class getSum {
    public:
        getSum(Counter& counter) : counter(counter) {} 
        int operator()() const { 
            int sum = 0;
            for (int i = 0; i < counter.sizeArr; ++i) {
                if (counter.arr[i] % 3 == 0) {
                    sum += counter.arr[i];
                }
            }
            return sum;
        }
    private:
        Counter& counter;
    };
    class getCount {
    public:
        getCount(Counter& counter) : counter(counter) {}

        int operator()() const {
            int count = 0;
            for (int i = 0; i < counter.sizeArr; i++) {
                if (counter.arr[i] % 3 == 0) {
                    count++;
                }
            }
            return count;
        }
    private:
        Counter& counter; 
    };

    getSum getSumFunctor() {
        return getSum(*this);
    }
    getCount getCountFunctor() {
        return getCount(*this);
    }
private:
    int* arr;
    int sizeArr;
};
void printArr(int* arr,int size){
    std::cout << "[IN]: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
int main() {
    int arr[] = {4, 1, 3, 6, 25, 55};
    printArr(arr, sizeof(arr) / sizeof(arr[0]));
    Counter counter(arr,sizeof(arr)/sizeof(arr[0]));
    std::cout << "[OUT]: get_sum() = " << counter.getSumFunctor()() << std::endl;
    std::cout << "[OUT]: get_count() = " << counter.getCountFunctor()() << std::endl;
}