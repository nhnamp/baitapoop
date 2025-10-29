// Viết chương trình cho phép nhập một dãy phân số. Cài đặt hàm tính tổng các phân số và tìm phân số lớn nhất.
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
    bool operator>(PhanSo b)
    {
        return tu * b.mau > mau * b.tu;
    }
};

void nhapMang(vector<PhanSo> &a, int n)
{
    a.resize(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap phan so thu " << i + 1 << ":" << endl;
        a[i].nhap();
        a[i].rutGon();
    }
}
PhanSo tinhTong(vector<PhanSo> a, int n)
{
    PhanSo tong;
    for (int i = 0; i < n; i++)
    {
        tong = tong + a[i];
    }
    return tong;
}
PhanSo timMax(vector<PhanSo> a, int n)
{
    PhanSo max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    return max;
}
int main()
{
    int n;
    cout << "Nhap so luong phan so: ";
    cin >> n;
    vector<PhanSo> a;
    nhapMang(a, n);
    cout << "Danh sach phan so vua nhap:" << endl;
    for (int i = 0; i < n; i++)
    {
        a[i].xuat();
    }
    PhanSo tong = tinhTong(a, n);
    cout << "Tong cac phan so: ";
    tong.xuat();
    PhanSo max = timMax(a, n);
    cout << "Phan so lon nhat: ";
    max.xuat();
    return 0;
}
