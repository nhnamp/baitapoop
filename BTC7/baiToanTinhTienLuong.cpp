/*
Bài toán: Công ty ABC là công ty sản xuất kinh doanh thú nhồi bông. Công ty có nhiều nhân viên làm việc trong ba bộ phận khác nhau: bộ phận quản lý, bộ phận sản xuất, bộ phận văn phòng. Việc tính lương cho nhân viên dựa vào các yếu tố sau:

Đối với nhân viên văn phòng: Lương = Lương Cơ Bản + Số ngày làm việc *200.000 + Trợ Cấp

Đối với nhân viên sản xuất: Lương = Lương Cơ Bản + Số Sản Phẩm * 2.000

Đối với nhân viên quản lý: Lương = Lương Cơ Bản* Hệ số chức vụ + Thưởng.

Ngoài ra công ty cần quản lý các thông tin về nhân viên của mình như: họ tên, ngày sinh và các thông số trên để tính lương cho từng nhân viên trong công ty.

Yêu cầu: Thiết kế các lớp thích hợp để thực hiện các yêu cầu sau:

Nhập thông tin của các nhân viên để phục vụ cho việc tính lương.

Thực hiện việc tính lương cho từng nhân viên.

Xuất thông tin của các nhân viên.

Tính tổng lương của công ty.

Tìm kiếm một nhân viên theo họ tên.
*/

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>
#include <memory>

using namespace std;

const double LUONG_NGAY_VP = 200000;
const double LUONG_SAN_PHAM_SX = 2000;
// lop cha chua thong tin chung cua nhan vien
class NhanVien
{
protected:
    string hoTen;
    string ngaySinh;
    double luongCoBan;

public:
    virtual ~NhanVien() {}
    virtual void nhap()
    {
        cout << "Nhap ho ten: ";
        getline(cin, hoTen);
        cout << "Nhap ngay sinh (ngay/thang/nam): ";
        getline(cin, ngaySinh);
        cout << "Nhap luong co ban: ";
        cin >> luongCoBan;
        cin.ignore();
    }
    virtual void xuat() const
    {
        cout << "Ho ten: " << hoTen << endl;
        cout << "Ngay sinh: " << ngaySinh << endl;
        cout << "Luong co ban: " << fixed << setprecision(2) << luongCoBan << endl;
    }

    virtual double tinhLuong() const = 0;

    string getHoTen() const
    {
        return hoTen;
    }
};

class NhanVienVanPhong : public NhanVien
{
private:
    int soNgayLamViec;
    double troCap;

public:
    void nhap() override
    {
        cout << "Nhap thong tin nhan vien van phong:" << endl;
        NhanVien::nhap();
        cout << "Nhap so ngay lam viec: ";
        cin >> soNgayLamViec;
        cout << "Nhap tro cap: ";
        cin >> troCap;
        cin.ignore();
    }
    void xuat() const override
    {
        cout << "Thong tin nhan vien van phong:" << endl;
        NhanVien::xuat();
        cout << "So ngay lam viec: " << soNgayLamViec << endl;
        cout << "Tro cap: " << fixed << setprecision(2) << troCap << endl;
        cout << "Luong: " << fixed << setprecision(2) << tinhLuong() << endl;
    }
    double tinhLuong() const override
    {
        return luongCoBan + soNgayLamViec * LUONG_NGAY_VP + troCap;
    }
};

class NhanVienSanXuat : public NhanVien
{
private:
    int soSanPham;

public:
    void nhap() override
    {
        cout << "Nhap thong tin nhan vien san xuat:" << endl;
        NhanVien::nhap();
        cout << "Nhap so san pham: ";
        cin >> soSanPham;
        cin.ignore();
    }
    void xuat() const override
    {
        cout << "Thong tin nhan vien san xuat:" << endl;
        NhanVien::xuat();
        cout << "So san pham: " << soSanPham << endl;
        cout << "Luong: " << fixed << setprecision(2) << tinhLuong() << endl;
    }
    double tinhLuong() const override
    {
        return luongCoBan + soSanPham * LUONG_SAN_PHAM_SX;
    }
};

class NhanVienQuanLy : public NhanVien
{
private:
    double heSoChucVu;
    double thuong;

public:
    void nhap() override
    {
        cout << "Nhap thong tin nhan vien quan ly:" << endl;
        NhanVien::nhap();
        cout << "Nhap he so chuc vu: ";
        cin >> heSoChucVu;
        cout << "Nhap thuong: ";
        cin >> thuong;
        cin.ignore();
    }
    void xuat() const override
    {
        cout << "Thong tin nhan vien quan ly:" << endl;
        NhanVien::xuat();
        cout << "He so chuc vu: " << heSoChucVu << endl;
        cout << "Thuong: " << fixed << setprecision(2) << thuong << endl;
        cout << "Luong: " << fixed << setprecision(2) << tinhLuong() << endl;
    }
    double tinhLuong() const override
    {
        return luongCoBan * heSoChucVu + thuong;
    }
};

class CongTy
{
private:
    vector<unique_ptr<NhanVien>> danhSachNhanVien;

public:
    void nhapDanhSachNhanVien()
    {
        int choice;
        while (true)
        {
            cout << "Nhap thong tin cho nhan vien nao?" << endl;
            cout << "1. Nhan vien van phong" << endl;
            cout << "2. Nhan vien san xuat" << endl;
            cout << "3. Nhan vien quan ly" << endl;
            cout << "0. Ket thuc nhap" << endl;
            cout << "Lua chon: ";
            cin >> choice;
            cin.ignore();

            if (choice == 0)
                break;

            unique_ptr<NhanVien> nv;
            if (choice == 1)
                nv = make_unique<NhanVienVanPhong>();
            else if (choice == 2)
                nv = make_unique<NhanVienSanXuat>();
            else if (choice == 3)
                nv = make_unique<NhanVienQuanLy>();
            else
            {
                cout << "Hay chon 1, 2 hoac 3" << endl;
                continue;
            }

            nv->nhap();
            danhSachNhanVien.push_back(move(nv));
        }
    }

    void xuatDanhSachNhanVien() const
    {
        for (const auto &nv : danhSachNhanVien)
        {
            nv->xuat();
            cout << "------------------------" << endl;
        }
    }

    void tinhTongLuong() const
    {
        if (danhSachNhanVien.empty())
        {
            cout << "Chua co nhan vien nao trong danh sach" << endl;
            return;
        }
        double tongLuong = 0;
        for (const auto &nv : danhSachNhanVien)
        {
            tongLuong += nv->tinhLuong();
        }
        cout << "Tong luong cua cong ty: " << fixed << setprecision(2) << tongLuong << endl;
    }

    void timKiemNhanVienTheoHoTen(const string &hoTen) const
    {
        if (danhSachNhanVien.empty())
        {
            cout << "Chua co nhan vien nao trong danh sach" << endl;
            return;
        }
        bool found = false;
        for (const auto &nv : danhSachNhanVien)
        {
            if (nv->getHoTen() == hoTen)
            {
                cout << "Thong tin nhan vien tim thay:" << endl;
                nv->xuat();
                found = true;
                cout << "------------------------" << endl;
            }
        }
        if (!found)
        {
            cout << "Khong tim thay nhan vien voi ho ten: " << hoTen << endl;
        }
    }
};

int main()
{
    CongTy congTy;
    congTy.nhapDanhSachNhanVien();

    cout << "Danh sach nhan vien:" << endl;
    congTy.xuatDanhSachNhanVien();

    cout << "Tong luong cong ty: ";
    congTy.tinhTongLuong();

    string hoTenTimKiem;
    cout << "Nhap ho ten nhan vien can tim: ";
    getline(cin, hoTenTimKiem);
    congTy.timKiemNhanVienTheoHoTen(hoTenTimKiem);

    return 0;
}