/*
Cài đặt lớp arrPhanSo cho phép lưu trữ và thực hiện các thao tác trên mảng các phân số:
1. Nhập các phân số
2. Xuất danh sách các phân số
3. Tạo n phân số ngẫu nhiên
4. Tìm phân số có giá trị lớn nhất
5. Đếm xem có bao nhiêu phân số có tử là số nguyên tố
6. Sắp xếp các phân số trong mang theo thứ tự tăng dần.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

class PhanSo
{
private:
    int tu;
    int mau;
    void rutGon()
    {
        int g = gcd(abs(tu), abs(mau));
        tu /= g;
        mau /= g;
        if (mau < 0)
        {
            tu = -tu;
            mau = -mau;
        }
    }

public:
    PhanSo() : tu(0), mau(1) {}
    PhanSo(int t, int m) : tu(t), mau(m)
    {
        if (mau == 0)
            return;
        rutGon();
    }
    
    void input()
    {
        cout << "Nhap tu va mau: ";
        cin >> tu >> mau;
        if (mau == 0)
        {
            cout << "Mau khong duoc bang 0" << endl;
            return;
        }
        rutGon();
    }
    void output()
    {
        cout << tu << "/" << mau << endl;
    }
    bool operator<(const PhanSo &other) const
    {
        return tu * other.mau < other.tu * mau;
    }
    int getTu()
    {
        return tu;
    }
};

class arrPhanSo
{
private:
    int size;
    PhanSo *array;

public:
    arrPhanSo() : size(0), array(nullptr) {}
    arrPhanSo(int s) : size(s)
    {
        array = (size > 0) ? new PhanSo[size] : nullptr;
    }
    arrPhanSo(const arrPhanSo &other) : size(other.size)
    {
        array = (size > 0) ? new PhanSo[size] : nullptr;
        if (array)
        {
            for (int i = 0; i < size; i++)
            {
                array[i] = other.array[i];
            }
        }
    }
    ~arrPhanSo()
    {
        delete[] array;
    }

    void input()
    {
        cout << "Nhap so luong phan so:";
        cin >> size;
        delete[] array;
        array = (size > 0) ? new PhanSo[size] : nullptr;
        if (array)
        {
            for (int i = 0; i < size; i++)
            {
                cout << "Phan so " << i + 1 << ":" << endl;
                array[i].input();
            }
        }
    }
    void output()
    {
        if (size == 0)
        {
            cout << "Mang rong" << endl;
            return;
        }
        cout << "Danh sach phan so:" << endl;
        for (int i = 0; i < size; i++)
        {
            array[i].output();
        }
    }
    void generateRandomArray(int n, int lower = -10, int upper = 10)
    {
        delete[] array;
        size = n;
        array = (size > 0) ? new PhanSo[size] : nullptr;
        if (array)
        {
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<> dis(lower, upper);
            for (int i = 0; i < size; i++)
            {
                int tu = dis(gen);
                int mau;
                do
                {
                    mau = dis(gen);
                } while (mau == 0);
                array[i] = PhanSo(tu, mau);
            }
        }
    }
    PhanSo findMax()
    {
        if (size == 0)
        {
            cout << "Mang rong" << endl;
            return PhanSo();
        }
        PhanSo maxPhanSo = array[0];
        for (int i = 1; i < size; i++)
        {
            if (array[i] < maxPhanSo == false)
            {
                maxPhanSo = array[i];
            }
        }
        return maxPhanSo;
    }
    int countPrimeInArrayNumerators()
    {
        if (size == 0)
        {
            return 0;
        }
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            if (isPrime(array[i].getTu()))
            {
                count++;
            }
        }
        return count;
    }
    void sortAscending()
    {
        if (size == 0)
        {
            return;
        }
        sort(array, array + size);
    }
};
