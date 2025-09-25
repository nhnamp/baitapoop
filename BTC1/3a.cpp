// a. Viết chương trình nhập vào một phân số, rút gọn phân số và xuất kết quả.
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
        cout << "Phan so rut gon: " << tu << "/" << mau << endl;
    }
};

int main()
{
    PhanSo ps;
    ps.nhap();
    ps.rutGon();
    ps.xuat();
    return 0;
}