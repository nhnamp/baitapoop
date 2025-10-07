/*
Cài đặt lớp cArray để biểu diễn mảng một chiều các số nguyên cho phép thực hiện các yêu cầu sau:
▪ Tạo lập mảng gồm n số nguyên ngẫu nhiên bằng constructor
▪ Xuất mảng ra màn hình
▪ Tìm số âm lớn nhất
▪ Đếm lần xuất hiện của một số nguyên x
▪ Kiểm tra mảng có giảm dần không
▪ Sắp xếp mảng tăng dần
*/

#include <bits/stdc++.h>
using namespace std;

class cArray
{
private:
    int *a;
    int n;

public:
    cArray()
    {
        n = 0;
        a = nullptr;
    }
    cArray(int size)
    {
        n = size;
        a = new int[n];
        srand(time(0));
        for (int i = 0; i < n; i++)
        {
            a[i] = rand() % 201 - 100;
        }
    }
    void output()
    {
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    int getMaxNegative()
    {
        int maxNeg = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (a[i] < 0 && a[i] > maxNeg)
            {
                maxNeg = a[i];
            }
        }
        return maxNeg;
    }
    int getFrequency(int x)
    {
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == x)
            {
                count++;
            }
        }
        return count;
    }
    bool isDescending()
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] < a[i + 1])
            {
                return false;
            }
        }
        return true;
    }
    void sortAscending()
    {
        sort(a, a + n);
    }
};

int main()
{
    int size;
    cout << "Nhap kich thuoc mang: ";
    cin >> size;
    cArray arr(size);
    cout << "Mang vua tao: ";
    arr.output();
    int maxNeg = arr.getMaxNegative();
    if (maxNeg == INT_MIN)
        cout << "Mang khong co so am." << endl;
    else
        cout << "So am lon nhat trong mang: " << maxNeg << endl;
    int x;
    cout << "Nhap so nguyen x can dem: ";
    cin >> x;
    cout << "So lan xuat hien cua " << x << ": " << arr.getFrequency(x) << endl;
    if (arr.isDescending())
        cout << "Mang giam dan." << endl;
    else
        cout << "Mang khong giam dan." << endl;
    arr.sortAscending();
    cout << "Mang sau khi sap xep tang dan: ";
    arr.output();
    return 0;
}