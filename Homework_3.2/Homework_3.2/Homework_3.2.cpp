#include <iostream>
#include <locale.h>
#include <format>

using namespace std;

template <class T>
class Tabl {
public:
    Tabl(int rowCount, int columnCount) : rowCount(rowCount), columnCount(columnCount) {
        tabl = new T * [rowCount];
        for (int i = 0; i < rowCount; i++) {
            tabl[i] = new T[columnCount];
        }
    }

    ~Tabl() {
        for (int i = 0; i < rowCount; i++) {
            delete[] tabl[i];
        }

        delete[] tabl;
    }

    void fillingTable() {
        int num;
        for (int i = 0; i < rowCount; i++) {
            for (int j = 0; j < columnCount; j++) {
                cout << "Введите элемент таблицы стоящий в " << i + 1 << " ряду и в " << j + 1 << " солбце: ";
                cin >> num;
                tabl[i][j] = num;
            }
        }
    }

    T* operator[](int num) {
        return tabl[num];
    }

    const T* operator[](int num) const {
        return tabl[num];
    }

    string Size() const {
        return to_string(rowCount) + "x" + to_string(columnCount);
    }

private:
    const int rowCount, columnCount;
    T** tabl;
};

int main() {
    setlocale(LC_ALL,"Rus");
    Tabl<int> tabl(3, 3);
    tabl.fillingTable();
    cout << tabl[2][2] << std::endl;
    cout << tabl.Size() << endl;

    return 0;
}