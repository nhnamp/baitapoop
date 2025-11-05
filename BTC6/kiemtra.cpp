/*
Giả sử Trường ĐH CNTT TP.HCM đào tạo sinh viên theo 2 hệ là hệ cao đẳng và hệ đại học.
Thông tin cần quản lí của một sinh viên cao đẳng bao gồm:
mã số sinh viên, họ tên, địa chỉ, tổng số tín chỉ, điểm trung bình, điểm thi tốt nghiệp.
Thông tin cần quản lí của một sinh viên đại học bao gồm:
mã số sinh viên, họ tên, địa chỉ, tổng số tín chỉ, điểm trung bình, tên luận văn, điểm luận văn.

Cách xét tốt nghiệp của sinh viên mỗi hệ là khác nhau:

Sinh viên hệ cao đẳng tốt nghiệp khi có tổng số tín chỉ từ 120 trở lên, điểm trung bình từ 5 trở lên và điểm thi tốt nghiệp phải đạt từ 5 trở lên.

Sinh viên hệ đại học tốt nghiệp khi có tổng số tín chỉ từ 170 trở lên, điểm trung bình từ 5 trở lên và phải bảo vệ luận văn với điểm số đạt được từ 5 điểm trở lên.

Hãy viết chương trình bằng C++ cho phép thực hiện các yêu cầu sau:

Nhập vào một sinh viên cao đẳng và một sinh viên đại học

Cho biết sinh viên đủ điều kiện tốt nghiệp?

Xuất thông tin 2 sinh viên trên
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;
// lop cha la SinhVien, chua cac thong tin chung
class SinhVien
{
protected:
    string mssv;
    string hoTen;
    string diaChi;
    int tongSoTinChi;
    double diemTrungBinh;

public:
    virtual ~SinhVien() {}

    virtual void nhap()
    {
        cout << "Nhap Ma so sinh vien: ";
        getline(cin, mssv);
        cout << "Nhap Ho ten: ";
        getline(cin, hoTen);
        cout << "Nhap Dia chi: ";
        getline(cin, diaChi);
        cout << "Nhap Tong so tin chi: ";
        cin >> tongSoTinChi;
        cout << "Nhap Diem trung binh: ";
        cin >> diemTrungBinh;
    }

    virtual void xuat() const
    {
        cout << "MSSV: " << mssv << endl;
        cout << "Ho ten: " << hoTen << endl;
        cout << "Dia chi: " << diaChi << endl;
        cout << "Tong so tin chi: " << tongSoTinChi << endl;
        cout << "Diem trung binh: " << fixed << setprecision(2) << diemTrungBinh << endl;
    }

    virtual bool duDieuKienTotNghiep() const = 0;
};

class SinhVienCaoDang : public SinhVien
{
private:
    double diemThiTotNghiep;

public:
    void nhap() override
    {
        SinhVien::nhap();
        cout << "Nhap Diem thi tot nghiep: ";
        cin >> diemThiTotNghiep;
        cin.ignore();
    }
    void xuat() const override
    {
        SinhVien::xuat();
        cout << "Diem thi tot nghiep: " << fixed << setprecision(2) << diemThiTotNghiep << endl;
    }
    bool duDieuKienTotNghiep() const override
    {
        return (tongSoTinChi >= 120 && diemTrungBinh >= 5.0 && diemThiTotNghiep >= 5.0);
    }
};

class SinhVienDaiHoc : public SinhVien
{
private:
    string tenLuanVan;
    double diemLuanVan;

public:
    void nhap() override
    {
        SinhVien::nhap();
        cin.ignore();
        cout << "Nhap Ten luan van: ";
        getline(cin, tenLuanVan);
        cout << "Nhap Diem luan van: ";
        cin >> diemLuanVan;
        cin.ignore();
    }
    void xuat() const override
    {
        SinhVien::xuat();
        cout << "Ten luan van: " << tenLuanVan << endl;
        cout << "Diem luan van: " << fixed << setprecision(2) << diemLuanVan << endl;
    }
    bool duDieuKienTotNghiep() const override
    {
        return (tongSoTinChi >= 170 && diemTrungBinh >= 5 && diemLuanVan >= 5.0);
    }
};

int main()
{
    SinhVienCaoDang svcd;
    SinhVienDaiHoc svdh;

    cout << "Nhap thong tin sinh vien cao dang:" << endl;
    svcd.nhap();
    cout << endl;
    cout << "Nhap thong tin sinh vien dai hoc:" << endl;
    svdh.nhap();
    cout << endl;
    cout << "Thong tin sinh vien cao dang:" << endl;
    svcd.xuat();
    if (svcd.duDieuKienTotNghiep())
        cout << "Sinh vien cao dang du dieu kien tot nghiep." << endl;
    else
        cout << "Sinh vien cao dang khong du dieu kien tot nghiep." << endl;

    cout << "------------------------" << endl;
    cout << "Thong tin sinh vien dai hoc:" << endl;
    svdh.xuat();
    if (svdh.duDieuKienTotNghiep())
        cout << "Sinh vien dai hoc du dieu kien tot nghiep." << endl;
    else
        cout << "Sinh vien dai hoc khong du dieu kien tot nghiep." << endl;
    return 0;
}