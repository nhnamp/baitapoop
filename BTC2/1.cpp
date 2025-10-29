// Viết chương trình nhập vào 2 phân số, tính tổng, hiệu, tích, thương và xuất kết quả.
#include <bits/stdc++.h>
using namespace std;
class PhanSo
{
private:
    int tu, mau;

public:
    PhanSo() : tu(0), mau(1) {}
    void nhap()
    {
        cout << "Nhap tu so: ";
        cin >> tu;
        cout << "Nhap mau so: ";
        cin >> mau;
        if (mau == 0)
        {
            cout << "Mau so phai khac 0" << endl;
            exit(1);
        }
    }
    void rutGon()
    {
        int u = gcd(tu, mau);
        tu /= u;
        mau /= u;
    }
    void xuat()
    {
        cout << tu << "/" << mau << endl;
    }
    PhanSo operator+(PhanSo b)
    {
        PhanSo tong;
        tong.tu = tu * b.mau + mau * b.tu;
        tong.mau = mau * b.mau;
        tong.rutGon();
        return tong;
    }
    PhanSo operator-(PhanSo b)
    {
        PhanSo hieu;
        hieu.tu = tu * b.mau - mau * b.tu;
        hieu.mau = mau * b.mau;
        hieu.rutGon();
        return hieu;
    }
    PhanSo operator*(PhanSo b)
    {
        PhanSo tich;
        tich.tu = tu * b.tu;
        tich.mau = mau * b.mau;
        tich.rutGon();
        return tich;
    }
    PhanSo operator/(PhanSo b)
    {
        if (b.tu == 0)
        {
            cout << "Khong the chia cho phan so 0" << endl;
            exit(1);
        }
        PhanSo thuong;
        thuong.tu = tu * b.mau;
        thuong.mau = mau * b.tu;
        thuong.rutGon();
        return thuong;
    }
};
int main()
{
    PhanSo a, b;
    cout << "Nhap phan so a:" << endl;
    a.nhap();
    a.rutGon();
    cout << "Nhap phan so b:" << endl;
    b.nhap();
    b.rutGon();
    cout << "Phan so a: ";
    a.xuat();
    cout << "Phan so b: ";
    b.xuat();
    PhanSo tong = a + b;
    PhanSo hieu = a - b;
    PhanSo tich = a * b;
    PhanSo thuong = a / b;
    cout << "Tong a + b = ";
    tong.xuat();
    cout << "Hieu a - b = ";
    hieu.xuat();
    cout << "Tich a * b = ";
    tich.xuat();
    cout << "Thuong a / b = ";
    thuong.xuat();
    return 0;
}