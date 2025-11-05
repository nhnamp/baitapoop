/*
Áp dụng kiến thức OOP đã học, viết chương trình quản lý sinh viên đại học của trường đại học CNTT, giả sử thông tin của mỗi sinh viên bao gồm: mã số sinh viên, họ tên, địa chỉ, tổng số tín chỉ, điểm trung bình, tên luận văn, điểm luận văn.

Chương trình cho phép thực hiện các chức năng sau:

Nhập thông tin các sinh viên

Xuất thông tin các sinh viên

Cho biết có bao nhiêu sinh viên đủ điều kiện tốt nhiệp? Cách xét tốt nghiệp của sinh viên như sau: sinh viên tốt nghiệp khi có tổng số tín chỉ từ 140 trở lên, điểm trung bình từ 5 trở lên và phải bảo vệ luận văn với điểm số đạt được từ 5 điểm trở lên.
*/

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

class SinhVien
{
private:
    string mssv;
    string hoTen;
    string diaChi;
    int tongSoTinChi;
    double diemTrungBinh;
    string tenLuanVan;
    double diemLuanVan;

public:
    // default constructor
    SinhVien() : mssv(""), hoTen(""), diaChi(""), tongSoTinChi(0), diemTrungBinh(0.0), tenLuanVan(""), diemLuanVan(0.0) {}
    void nhap()
    {
        cout << "Nhap ma so sinh vien: ";
        getline(cin, mssv);
        cout << "Nhap ho ten: ";
        getline(cin, hoTen);
        cout << "Nhap dia chi: ";
        getline(cin, diaChi);
        cout << "Nhap tong so tin chi: ";
        cin >> tongSoTinChi;
        cout << "Nhap diem trung binh: ";
        cin >> diemTrungBinh;
        cin.ignore();
        cout << "Nhap ten luan van: ";
        getline(cin, tenLuanVan);
        cout << "Nhap diem luan van: ";
        cin >> diemLuanVan;
        cin.ignore();
    }
    void xuat() const
    {
        cout << "MSSV: " << mssv << endl;
        cout << "Ho ten: " << hoTen << endl;
        cout << "Dia chi: " << diaChi << endl;
        cout << "Tong so tin chi: " << tongSoTinChi << endl;
        cout << "Diem trung binh: " << fixed << setprecision(2) << diemTrungBinh << endl;
        cout << "Ten luan van: " << tenLuanVan << endl;
        cout << "Diem luan van: " << fixed << setprecision(2) << diemLuanVan << endl;
    }
    bool duDieuKienTotNghiep() const
    {
        return (tongSoTinChi >= 140 && diemTrungBinh >= 5.0 && diemLuanVan >= 5.0);
    }
};

class QuanLySinhVien
{
private:
    vector<SinhVien> danhSachSinhVien;

public:
    void nhapDanhSachSinhVien()
    {
        int soLuongSinhVien;
        cout << "Nhap so luong sinh vien: ";
        cin >> soLuongSinhVien;
        cin.ignore();
        for (int i = 0; i < soLuongSinhVien; i++)
        {
            cout << "Nhap thong tin sinh vien thu " << i + 1 << endl;
            SinhVien sv;
            sv.nhap();
            danhSachSinhVien.push_back(sv);
        }
    }
    void xuatDanhSachSinhVien() const
    {
        if (danhSachSinhVien.empty())
        {
            cout << "Khong co sinh vien nao trong danh sach" << endl;
            return;
        }
        for (size_t i = 0; i < danhSachSinhVien.size(); i++)
        {
            cout << "Thong tin sinh vien thu " << i + 1 << ":" << endl;
            danhSachSinhVien[i].xuat();
            cout << "------------------------" << endl;
        }
    }
    void demSinhVienDuDieuKienTotNghiep() const
    {
        if (danhSachSinhVien.empty())
        {
            cout << "Khong co sinh vien nao trong danh sach" << endl;
            return;
        }
        int count = 0;
        for (const auto sv : danhSachSinhVien)
        {
            if (sv.duDieuKienTotNghiep())
            {
                count++;
            }
        }
        cout << "So luong sinh vien du dieu kien tot nghiep: " << count << " sinh vien" << endl;
    }
};

int main()
{
    QuanLySinhVien qlsv;
    qlsv.nhapDanhSachSinhVien();
    cout << "Danh sach sinh vien: " << endl;
    qlsv.xuatDanhSachSinhVien();
    qlsv.demSinhVienDuDieuKienTotNghiep();
    return 0;
}