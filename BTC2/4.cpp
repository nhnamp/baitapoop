/*
Viết chương trình cho phép người dùng:
- Nhập vào thông tin của một học sinh gồm: mã học sinh (chuỗi), họ tên, giới tính, điểm toán, điểm lý, điểm hóa.
- Tính điểm trung bình và xuất thông tin chi tiết của học sinh ra màn hình.
*/

#include <bits/stdc++.h>
using namespace std;

class HocSinh
{
private:
    string maHS;
    string hoTen;
    string gioiTinh;
    float diemToan;
    float diemLy;
    float diemHoa;

public:
    void nhap()
    {
        cout << "Nhap ma hoc sinh: ";
        getline(cin, maHS);
        cout << "Nhap ho ten: ";
        getline(cin, hoTen);
        cout << "Nhap gioi tinh: ";
        getline(cin, gioiTinh);
        cout << "Nhap diem toan: ";
        cin >> diemToan;
        cout << "Nhap diem ly: ";
        cin >> diemLy;
        cout << "Nhap diem hoa: ";
        cin >> diemHoa;
        cin.ignore();
    }
    float tinhDiemTrungBinh()
    {
        return (diemToan + diemLy + diemHoa) / 3;
    }
    void xuat()
    {
        cout << "Ma hoc sinh: " << maHS << endl;
        cout << "Ho ten: " << hoTen << endl;
        cout << "Gioi tinh: " << gioiTinh << endl;
        cout << "Diem toan: " << diemToan << endl;
        cout << "Diem ly: " << diemLy << endl;
        cout << "Diem hoa: " << diemHoa << endl;
        cout << "Diem trung binh: " << fixed << setprecision(2) << tinhDiemTrungBinh() << endl;
    }
};
int main()
{
    HocSinh hs;
    hs.nhap();
    cout << "Thong tin hoc sinh:" << endl;
    hs.xuat();
    return 0;
}