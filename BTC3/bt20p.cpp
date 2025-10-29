/*
Định nghĩa lớp cPhanSo biểu diễn khái niệm phân số gồm 2 thành phần dữ liệu: tử số, mẫu số và các thao tác:
- Nhập phân số
- Khởi tạo tử số và mẫu số cho phân số
- Xuất phân số
- Lấy giá trị phân số
- Tính tổng 2 phân số
Viết chương trình cho phép người dùng nhập vào 2 phân số, tính tổng 2 phân số và xuất kết quả ra màn hình dưới dạng phân số.
*/

#include <bits/stdc++.h>
using namespace std;

class cPhanSo
{
private:
    int tuSo, mauSo;

public:
    void nhap()
    {
        cout << "Nhap tu so: ";
        cin >> tuSo;
        do
        {
            cout << "Nhap mau so: ";
            cin >> mauSo;
            if (mauSo == 0)
            {
                cout << "Mau so khong the bang 0. Hay nhap lai." << endl;
            }
        } while (mauSo == 0);
    }
    cPhanSo()
    {
        tuSo = 0;
        mauSo = 1;
    }
    cPhanSo(int tu, int mau)
    {
        tuSo = tu;
        mauSo = mau == 0 ? 1 : mau;
    }
    void xuat()
    {
        cout << tuSo << "/" << mauSo;
    }
    float layGiaTri()
    {
        return (float)tuSo / mauSo;
    }
    cPhanSo tong(cPhanSo ps)
    {
        cPhanSo ketQua;
        ketQua.tuSo = this->tuSo * ps.mauSo + this->mauSo * ps.tuSo;
        ketQua.mauSo = this->mauSo * ps.mauSo;
        return ketQua;
    }
    int gcd(int a, int b)
    {
        return b == 0 ? a : gcd(b, a % b);
    }
    void rutGon()
    {
        int u = gcd(abs(tuSo), abs(mauSo));
        tuSo /= u;
        mauSo /= u;
        if (mauSo < 0)
        {
            tuSo = -tuSo;
            mauSo = -mauSo;
        }
    }
};

int main()
{
    cPhanSo ps1, ps2, psTong;
    cout << "Nhap phan so thu nhat:" << endl;
    ps1.nhap();
    cout << "Nhap phan so thu hai:" << endl;
    ps2.nhap();
    psTong = ps1.tong(ps2);
    psTong.rutGon();
    cout << "Tong hai phan so la: ";
    psTong.xuat();
    cout << endl;
    return 0;
}