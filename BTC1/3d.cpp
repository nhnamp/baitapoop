// d. Viết chương trình nhập vào một ngày. Tìm ngày kế tiếp và xuất kết quả.
#include <bits/stdc++.h>
using namespace std;
class Ngay
{
private:
    int ngay, thang, nam;

public:
    void nhap()
    {
        cout << "Nhap ngay: ";
        cin >> ngay;
        cout << "Nhap thang: ";
        cin >> thang;
        cout << "Nhap nam: ";
        cin >> nam;
        if (thang < 1 || thang > 12 || ngay < 1 || ngay < 1 || nam < 0 || ngay > soNgayTrongThang(thang, nam))
        {
            cout << "Ngay thang nam khong hop le" << endl;
            exit(1);
        }
    }
    bool namNhuan(int n)
    {
        return (n % 4 == 0 && n % 100 != 0) || (n % 400 == 0);
    }
    int soNgayTrongThang(int t, int n)
    {
        if (t == 2)
            return namNhuan(n) ? 29 : 28;
        if (t == 4 || t == 6 || t == 9 || t == 11)
            return 30;
        return 31;
    }
    void ngayKeTiep()
    {
        ngay++;
        if (ngay > soNgayTrongThang(thang, nam))
        {
            ngay = 1;
            thang++;
            if (thang > 12)
            {
                thang = 1;
                nam++;
            }
        }
    }
    void xuat()
    {
        cout << "Ngay ke tiep: " << ngay << "/" << thang << "/" << nam << endl;
    }
};
int main()
{
    Ngay d;
    d.nhap();
    d.ngayKeTiep();
    d.xuat();
    return 0;
}