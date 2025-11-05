/*
Xây dựng chương trình quản lý cán bộ viên chức trường Đại học CNTT, giả sử trường gồm 2 loại CBVC:

Giảng Viên gồm các thông tin: mã cán bộ, họ tên, giới tính, số giờ dạy, số giờ nghiên cứu. Lương = (số giờ dạy + số giờ nghiên cứu ) * đơn giá

Nhân viên hành chính: mã cán bộ, họ tên, giới tính, số ngày làm việc, số giờ làm them. Lương = số ngày làm việc * tiền công 1 ngày + số giờ làm thêm * đơn giá
*/

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>
#include <memory>

using namespace std;

const double DON_GIA = 120000;
const double TIEN_CONG_1_NGAY = 300000; // vi du

// lop cha la CanBo, chua thong tin chung va ham tinh Luong
class CanBo
{
protected:
    string maCanBo;
    string hoTen;
    string gioiTinh;

public:
    virtual ~CanBo() {}
    virtual void nhap()
    {
        cout << "Nhap ma can bo: ";
        getline(cin, maCanBo);
        cout << "Nhap ho ten: ";
        getline(cin, hoTen);
        cout << "Nhap gioi tinh: ";
        getline(cin, gioiTinh);
    }
    virtual void xuat() const
    {
        cout << "Ma can bo: " << maCanBo << endl;
        cout << "Ho ten: " << hoTen << endl;
        cout << "Gioi tinh: " << gioiTinh << endl;
    }

    virtual double tinhLuong() const = 0;
};
// cac lop ke thua bao gom GiangVien va NhanVienHanhChinh
class GiangVien : public CanBo
{
private:
    int soGioDay;
    int soGioNghienCuu;

public:
    void nhap() override
    {
        cout << "Nhap thong tin giang vien:" << endl;
        CanBo::nhap();
        cout << "Nhap so gio day: ";
        cin >> soGioDay;
        cout << "Nhap so gio nghien cuu: ";
        cin >> soGioNghienCuu;
        cin.ignore();
    }

    void xuat() const override
    {
        cout << "Thong tin giang vien:" << endl;
        CanBo::xuat();
        cout << "So gio day: " << soGioDay << endl;
        cout << "So gio nghien cuu: " << soGioNghienCuu << endl;
        cout << "Luong: " << fixed << setprecision(2) << tinhLuong() << endl;
    }

    double tinhLuong() const override
    {
        return (soGioDay + soGioNghienCuu) * DON_GIA;
    }
};

class NhanVienHanhChinh : public CanBo
{
private:
    int soNgayLamViec;
    int soGioLamThem;

public:
    void nhap() override
    {
        cout << "Nhap thong tin nhan vien hanh chinh:" << endl;
        CanBo::nhap();
        cout << "Nhap so ngay lam viec: ";
        cin >> soNgayLamViec;
        cout << "Nhap so gio lam them: ";
        cin >> soGioLamThem;
        cin.ignore();
    }
    void xuat() const override
    {
        cout << "Thong tin nhan vien hanh chinh:" << endl;
        CanBo::xuat();
        cout << "So ngay lam viec: " << soNgayLamViec << endl;
        cout << "So gio lam them: " << soGioLamThem << endl;
        cout << "Luong: " << fixed << setprecision(2) << tinhLuong() << endl;
    }
    double tinhLuong() const override
    {
        return soNgayLamViec * TIEN_CONG_1_NGAY + soGioLamThem * DON_GIA;
    }
};

class QuanLyCanBo
{
private:
    vector<unique_ptr<CanBo>> danhSachCanBo;
    // dung unique_ptr de quan ly vung nho dong
    // vector chua cac con tro den doi tuong CanBo (co the la GiangVien hoac NhanVienHanhChinh vi do la lop con ke thua)

public:
    void nhapDanhSachCanBo()
    {
        int choice;
        while (true)
        {
            cout << "Nhap thong tin cho can bo nao?" << endl;
            cout << "1. Giang Vien" << endl;
            cout << "2. Nhan Vien Hanh Chinh" << endl;
            cout << "0. Ket thuc nhap" << endl;
            cout << "Lua chon: ";
            cin >> choice;
            cin.ignore();

            if (choice == 0)
                break;

            unique_ptr<CanBo> cb;
            if (choice == 1)
                cb = make_unique<GiangVien>();
            else if (choice == 2)
                cb = make_unique<NhanVienHanhChinh>();
            else
            {
                cout << "Hay chon 1 hoac 2" << endl;
                continue;
            }
            cb->nhap();
            danhSachCanBo.push_back(move(cb));
        }
    }
    void xuatDanhSachCanBo() const
    {
        if (danhSachCanBo.empty())
        {
            cout << "Chua co can bo nao trong danh sach" << endl;
            return;
        }
        cout << "Danh sach can bo:" << endl;
        for (const auto &cb : danhSachCanBo)
        {
            cb->xuat();
            cout << "------------------------" << endl;
        }
    }
};

int main()
{
    QuanLyCanBo qlcb;
    qlcb.nhapDanhSachCanBo();
    qlcb.xuatDanhSachCanBo();
    return 0;
}