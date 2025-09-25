/* Cho một danh sách lưu thông tin của các nhân viên trong một công ty, thông tin gồm:
- Mã nhân viên (chuỗi, tối đa là 8 ký tự)
- Họ và tên (chuỗi, tối đa là 20 ký tự)
- Phòng ban (chuỗi, tối đa 10 ký tự)
- Lương cơ bản (số nguyên)
- Thưởng (số nguyên)
- Thực lãnh (số nguyên, trong đó thực lãnh = lương cơ bản + thưởng )
Hãy thực hiện các công việc sau:
a.Tính tổng thực lãnh tháng của tất cả nhân viên trong công ty.
b.In danh sách những nhân viên có mức lương cơ bản thấp nhất.
c.Đếm số lượng nhân viên có mức thưởng >= 1200000.
*/

#include <bits/stdc++.h>
using namespace std;
struct NhanVien
{
    string maNV, hoTen, phongBan;
    int luongCoBan, thuong, thucLanh;
    void nhap()
    {
        cout << "Nhap ma nhan vien: ";
        cin.ignore();
        getline(cin, maNV);
        if (maNV.length() > 8)
        {
            cout << "Ma nhan vien khong hop le" << endl;
            exit(1);
        }
        cout << "Nhap ho va ten: ";
        cin.ignore();
        getline(cin, hoTen);
        if (hoTen.length() > 20)
        {
            cout << "Ho va ten khong hop le" << endl;
            exit(1);
        }
        cout << "Nhap phong ban: ";
        cin.ignore();
        getline(cin, phongBan);
        if (phongBan.length() > 10)
        {
            cout << "Phong ban khong hop le" << endl;
            exit(1);
        }
        cout << "Nhap luong co ban: ";
        cin >> luongCoBan;
        cout << "Nhap thuong: ";
        cin >> thuong;
        thucLanh = luongCoBan + thuong;
    }
};

int main()
{
    cout << "Nhap so luong nhan vien: ";
    int soLuong;
    cin >> soLuong;
    vector<NhanVien> dsNV(soLuong);
    for (int i = 0; i < soLuong; i++)
    {
        cout << "Nhap thong tin nhan vien thu " << i + 1 << ":" << endl;
        dsNV[i].nhap();
    }
    // a. Tinh tong thuc lanh thang cua tat ca nhan vien trong cong ty.
    int tongThucLanh = 0;
    for (auto nv : dsNV)
    {
        tongThucLanh += nv.thucLanh;
    }
    cout << "Tong thuc lanh thang cua tat ca nhan vien: " << tongThucLanh << endl;
    // b. In danh sach nhung nhan vien co muc luong co ban thap nhat.
    int luongCoBanThapNhat = INT_MAX;
    for (auto nv : dsNV)
    {
        luongCoBanThapNhat = min(luongCoBanThapNhat, nv.luongCoBan);
    }
    cout << "Danh sach nhung nhan vien co muc luong co ban thap nhat:" << endl;
    for (auto nv : dsNV)
    {
        if (nv.luongCoBan == luongCoBanThapNhat)
        {
            cout << "Ma NV: " << nv.maNV << ", Ho ten: " << nv.hoTen << ", Phong ban: " << nv.phongBan
                 << ", Luong co ban: " << nv.luongCoBan << ", Thuong: " << nv.thuong
                 << ", Thuc lanh: " << nv.thucLanh << endl;
        }
    }
    // c. Dem so luong nhan vien co muc thuong >= 1200000.
    int demNVThuongCao = 0;
    for (auto nv : dsNV)
    {
        if (nv.thuong >= 1200000)
        {
            demNVThuongCao++;
        }
    }
    cout << "So luong nhan vien co muc thuong >= 1200000: " << demNVThuongCao << endl;
    return 0;
}