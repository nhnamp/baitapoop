/*
Giả sử lớp PhanSo đã được khai báo.
a. Cài đặt toán tử > như khai báo cho lớp PhanSo
b. Hãy xây dựng lớp DSPhanSo để lưu trữ một mảng các phân số cho phép thực hiện các thao tác sau:
Nhập giá trị cho các phân số trong mảng
Tìm phân số có giá trị lớn nhất.
Tính tổng các phân số trong mảng
c. Hãy viết chương trình để nhập một mảng gồm n phân số (n do người dùng nhập). Sau đó tìm và in ra màn hình phân số có giá trị lớn nhất.
*/

#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

class PhanSo
{
private:
    int tu;
    int mau;
    void rutGon();

public:
    PhanSo(int t = 0, int m = 1);
    PhanSo(const PhanSo &p);

    int LayTu();
    int LayMau();
    void GanTu(int t);
    void GanMau(int m);

    void Nhap();
    void Xuat();

    bool operator>(PhanSo) const;
    PhanSo operator+(PhanSo) const;
    PhanSo operator-(PhanSo) const;
};

void PhanSo::rutGon()
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

PhanSo::PhanSo(int t, int m)
{
    tu = t;
    mau = (m == 0) ? 1 : m;
    rutGon();
}

PhanSo::PhanSo(const PhanSo &p)
{
    tu = p.tu;
    mau = p.mau;
}

int PhanSo::LayTu()
{
    return tu;
}
int PhanSo::LayMau()
{
    return mau;
}
void PhanSo::GanTu(int t)
{
    tu = t;
    rutGon();
}
void PhanSo::GanMau(int m)
{
    mau = (m == 0) ? 1 : m;
    rutGon();
}

void PhanSo::Nhap()
{
    cout << "Nhap tu so: ";
    cin >> tu;
    do
    {
        cout << "Nhap mau so: ";
        cin >> mau;
    } while (mau == 0);
    rutGon();
}

void PhanSo::Xuat()
{
    if (mau == 1 | tu == 0)
    {
        cout << tu;
    }
    else
    {
        cout << tu << "/" << mau;
    }
}

bool PhanSo::operator>(PhanSo b) const
{
    return (this->tu * b.mau) > (b.tu * this->mau);
}

PhanSo PhanSo::operator+(PhanSo b) const
{
    PhanSo tong;
    tong.tu = this->tu * b.mau + b.tu * this->mau;
    tong.mau = this->mau * b.mau;
    tong.rutGon();
    return tong;
}

PhanSo PhanSo::operator-(PhanSo b) const
{
    PhanSo hieu;
    hieu.tu = this->tu * b.mau - b.tu * this->mau;
    hieu.mau = this->mau * b.mau;
    hieu.rutGon();
    return hieu;
}

class DSPhanSo
{
private:
    int size;
    PhanSo *array;

public:
    DSPhanSo() : size(0), array(nullptr) {}
    DSPhanSo(int s) : size(s)
    {
        array = (size > 0) ? new PhanSo[size] : nullptr;
    }
    DSPhanSo(const DSPhanSo &other) : size(other.size)
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
    ~DSPhanSo()
    {
        delete[] array;
    }

    void NhapDS()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "Nhap phan so thu " << (i + 1) << endl;
            array[i].Nhap();
        }
    }
    PhanSo TimMax()
    {
        if (size == 0)
            throw runtime_error("Danh sach rong");
        PhanSo maxPS = array[0];
        for (int i = 1; i < size; i++)
        {
            if (array[i] > maxPS)
            {
                maxPS = array[i];
            }
        }
        return maxPS;
    }
    PhanSo TinhTong()
    {
        PhanSo tong(0, 1);
        for (int i = 0; i < size; i++)
        {
            tong = tong + array[i];
        }
        return tong;
    }
};

int main()
{
    int n;
    cout << "Nhap so luong phan so: ";
    cin >> n;

    DSPhanSo ds(n);
    ds.NhapDS();

    PhanSo maxPS = ds.TimMax();
    cout << "Phan so lon nhat trong danh sach la: ";
    maxPS.Xuat();
    cout << endl;

    PhanSo tongPS = ds.TinhTong();
    cout << "Tong cac phan so trong danh sach la: ";
    tongPS.Xuat();
    cout << endl;

    return 0;
}