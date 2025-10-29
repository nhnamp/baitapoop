// b. Viết chương trình nhập vào hai phân số, tìm phân số lớn nhất và xuất kết quả.
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
    bool operator>(PhanSo b)
    {
        return tu * b.mau > mau * b.tu;
    }
};

int main()
{
    PhanSo ps1, ps2;
    cout << "Nhap phan so thu nhat:" << endl;
    ps1.nhap();
    ps1.rutGon();
    cout << "Nhap phan so thu hai:" << endl;
    ps2.nhap();
    ps2.rutGon();

    cout << "Phan so lon hon la: ";
    if (ps1 > ps2)
    {
        ps1.xuat();
    }
    else
    {
        ps2.xuat();
    }
    return 0;
}