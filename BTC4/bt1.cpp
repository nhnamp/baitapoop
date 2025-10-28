/*
Khai báo và định nghĩa lớp mảng một chiều (lớp cArray) để lưu trữ danh sách các số nguyên, hỗ trợ các thao tác sau:
1. Nhập dãy số nguyên gồm n phần tử.
2. Xuất dãy số nguyên của mảng.
3. Tạo dãy gồm n số nguyên ngẫu nhiên.
4. Đếm số lần xuất hiện của x trong mảng.
5. Kiểm tra dãy số nguyên có tăng dần hay không.
6. Tìm phần tử lẻ nhỏ nhất trong dãy số nguyên.
7. Sắp xếp các số nguyên trong dãy tăng dần.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <limits>
#include <climits>
using namespace std;
class cArray
{
private:
    int size;
    int *array;

public:
    cArray() : size(0), array(nullptr) {}
    cArray(int s) : size(s)
    {
        array = (size > 0) ? new int[size] : nullptr;
    }
    cArray(const cArray &other) : size(other.size)
    {
        array = (size > 0) ? new int[size] : nullptr;
        if (array)
        {
            for (int i = 0; i < size; i++)
            {
                array[i] = other.array[i];
            }
        }
    }
    ~cArray()
    {
        delete[] array;
    }
    cArray &operator=(const cArray &other)
    {
        if (this == &other)
            return *this;
        delete[] array;
        size = other.size;
        array = (size > 0) ? new int[size] : nullptr;
        if (array)
        {
            for (int i = 0; i < size; i++)
            {
                array[i] = other.array[i];
            }
        }
        return *this;
    }

    void input()
    {
        cout << "Enter the number of integers:" << endl;
        cin >> size;
        delete[] array;
        array = (size > 0) ? new int[size] : nullptr;
        if (array)
        {
            cout << "Enter " << size << " integers:" << endl;
            for (int i = 0; i < size; i++)
            {
                cin >> array[i];
            }
        }
    }
    void output()
    {
        if (size == 0)
        {
            cout << "Array is empty" << endl;
            return;
        }
        cout << "Array elements:" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }
    void generateRandomArray(int n, int lower = 0, int upper = 100)
    {
        delete[] array;
        size = n;
        array = (size > 0) ? new int[size] : nullptr;
        if (array)
        {
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<> dis(lower, upper);
            for (int i = 0; i < size; i++)
            {
                array[i] = dis(gen);
            }
        }
    }
    int countFrequency(int x)
    {
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            if (array[i] == x)
            {
                count++;
            }
        }
        return count;
    }
    bool isSortedAscending()
    {
        for (int i = 1; i < size; i++)
        {
            if (array[i] < array[i - 1])
            {
                return false;
            }
        }
        return true;
    }
    int findMinOdd()
    {
        int minOdd = INT_MAX;
        for (int i = 0; i < size; i++)
        {
            if (array[i] % 2 != 0 && array[i] < minOdd)
            {
                minOdd = array[i];
            }
        }
        return (minOdd == INT_MAX) ? -1 : minOdd;
        // neu khong co so le tra ve -1
    }
    void sortAscending()
    {
        sort(array, array + size);
    }
};
