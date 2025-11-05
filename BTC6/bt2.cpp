/*
CT phần mềm Hoàn cầu 2 loại nhân viên. Các lập trình viên là những người sẽ viết mã nguồn cho các ứng dụng. Các kiểm chứng viên có nhiệm vụ kiểm tra mã nguồn và chương trình mà lập trình viên viết ra, để tìm các lỗi trước khi giao sản phẩm cho khách hàng. Hiện tại, Công ty phần mềm Hoàn cầu lưu trữ các thông tin sau:

Đối với lập trình viên: mã nhân viên, họ tên, tuổi, số điện thoại, email, lương cơ bản, số giờ overtime.

Đối với kiểm chứng viên: mã nhân viên, họ tên, tuổi, số điện thoại, email, lương cơ bản, số lỗi phát hiện được.

Do tính chất công việc khác nhau, nên lương hàng tháng của lập trình viên và kiểm chứng viên cũng khác nhau. Cụ thể:

Lương (lập trình viên) = lương cơ bản + số giờ làm thêm * 200.000

Lương (kiểm chứng viên) = lương cơ bản + số lỗi * 50.000

Bạn hãy đề xuất thiết kế các lớp đối tượng cần thiết để quản lý danh sách các nhân viên của Công ty và hỗ trợ tính lương cho nhân viên theo tiêu chí đặt ra như trên.

Hãy viết chương trình bằng C++ cho phép thực hiện các yêu cầu sau:

Nhập vào danh sách nhân viên

Xuất danh sách nhân viên

Liệt kê danh sách nhân viên có lương thấp hơn mức lương trung bình của các nhân viên trong công ty
*/

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>
#include <memory>

using namespace std;
// lop cha la NhanVien, chua cac thong tin chung
class NhanVien
{
protected:
    string maNV;
    string hoTen;
    int tuoi;
    string soDienThoai;
    string email;
    double luongCoBan;

public:
    virtual ~NhanVien() {}
    virtual void nhap()
    {
        cout << "Nhap Ma nhan vien: ";
        getline(cin, maNV);
        cout << "Nhap Ho ten: ";
        getline(cin, hoTen);
        cout << "Nhap Tuoi: ";
        cin >> tuoi;
        cin.ignore();
        cout << "Nhap So dien thoai: ";
        getline(cin, soDienThoai);
        cout << "Nhap Email: ";
        getline(cin, email);
        cout << "Nhap Luong co ban: ";
        cin >> luongCoBan;
    }
    virtual void xuat() const
    {
        cout << "Ma nhan vien: " << maNV << endl;
        cout << "Ho ten: " << hoTen << endl;
        cout << "Tuoi: " << tuoi << endl;
        cout << "So dien thoai: " << soDienThoai << endl;
        cout << "Email: " << email << endl;
        cout << "Luong co ban: " << fixed << setprecision(2) << luongCoBan << endl;
    }
    virtual double tinhLuong() const = 0;
};

class LapTrinhVien : public NhanVien
{
private:
    int soGioOvertime;
    static constexpr double DON_GIA_OVERTIME = 200000;

public:
    void nhap() override
    {
        cout << "Nhap thong tin lap trinh vien:" << endl;
        NhanVien::nhap();
        cout << "Nhap so gio overtime: ";
        cin >> soGioOvertime;
        cin.ignore();
    }
    void xuat() const override
    {
        cout << "Thong tin lap trinh vien:" << endl;
        NhanVien::xuat();
        cout << "So gio overtime: " << soGioOvertime << endl;
        cout << "Luong: " << fixed << setprecision(2) << tinhLuong() << endl;
    }
    double tinhLuong() const override
    {
        return luongCoBan + soGioOvertime * DON_GIA_OVERTIME;
    }
};

class KiemChungVien : public NhanVien
{
private:
    int soLoiPhatHien;
    static constexpr double DON_GIA_LOI = 50000;

public:
    void nhap() override
    {
        cout << "Nhap thong tin kiem chung vien:" << endl;
        NhanVien::nhap();
        cout << "Nhap so loi phat hien: ";
        cin >> soLoiPhatHien;
        cin.ignore();
    }
    void xuat() const override
    {
        cout << "Thong tin kiem chung vien:" << endl;
        NhanVien::xuat();
        cout << "So loi phat hien: " << soLoiPhatHien << endl;
        cout << "Luong: " << fixed << setprecision(2) << tinhLuong() << endl;
    }
    double tinhLuong() const override
    {
        return luongCoBan + soLoiPhatHien * DON_GIA_LOI;
    }
};

class QuanLyNhanVien
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
            cout << "1. Lap trinh vien" << endl;
            cout << "2. Kiem chung vien" << endl;
            cout << "0. Ket thuc nhap" << endl;
            cout << "Lua chon cua ban: ";
            cin >> choice;
            cin.ignore();

            if (choice == 0)
                break;
            unique_ptr<NhanVien> nv;
            if (choice == 1)
                nv = make_unique<LapTrinhVien>();
            else if (choice == 2)
                nv = make_unique<KiemChungVien>();
            else
            {
                cout << "Hay chon 1 hoac 2" << endl;
                continue;
            }
            nv->nhap();
            danhSachNhanVien.push_back(move(nv));
        }
    }

    void xuatDanhSachNhanVien() const
    {
        if (danhSachNhanVien.empty())
        {
            cout << "Chua co nhan vien nao trong danh sach" << endl;
            return;
        }
        cout << "Danh sach nhan vien:" << endl;
        for (const auto &nv : danhSachNhanVien)
        {
            nv->xuat();
            cout << "------------------------" << endl;
        }
    }
};

int main()
{
    QuanLyNhanVien qlnv;
    qlnv.nhapDanhSachNhanVien();
    qlnv.xuatDanhSachNhanVien();
    return 0;
}