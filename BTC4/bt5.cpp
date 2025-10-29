/*
Giả sử mỗi đối tượng sách trong hệ thống thư viện có các thuộc tính sau:
Mã sách, Tên sách, Năm xuất bản, Tổng số trang.
Hãy xây dựng lớp cBook với các thuộc tính như trên và các phương thức
cần thiết sau:
Thiết lập thông tin sách
Nhập thông tin cho đối tượng sách từ bàn phím
Xuất thông tin đối tượng sách ra màn hình
Truy vấn và cập nhật thông tin
Xây dựng lớp cListBook để quản lý danh sách các đối tượng sách và thực hiện các yêu cầu sau:
Nhập danh sách các đối tượng sách
Xuất danh sách các đối tượng sách
Cho biết thông tin sách nào được xuất bản gần đây nhất
*/

#include <iostream>

using namespace std;

class cBook
{
private:
    string maSach;
    string tenSach;
    int namXuatBan;
    int tongSoTrang;

public:
    cBook() : maSach(""), tenSach(""), namXuatBan(0), tongSoTrang(0) {}
    cBook(string ma, string ten, int nam, int trang)
        : maSach(ma), tenSach(ten), namXuatBan(nam), tongSoTrang(trang) {}

    void input()
    {
        cout << "Nhap ma sach: ";
        cin >> maSach;
        cout << "Nhap ten sach: ";
        cin.ignore();
        getline(cin, tenSach);
        cout << "Nhap nam xuat ban: ";
        cin >> namXuatBan;
        cout << "Nhap tong so trang: ";
        cin >> tongSoTrang;
    }
    void output()
    {
        cout << "Ma sach: " << maSach << endl;
        cout << "Ten sach: " << tenSach << endl;
        cout << "Nam xuat ban: " << namXuatBan << endl;
        cout << "Tong so trang: " << tongSoTrang << endl;
    }
    string getMaSach()
    {
        return maSach;
    }
    void setMaSach(string newMaSach)
    {
        maSach = newMaSach;
    }
    int getNamXuatBan()
    {
        return namXuatBan;
    }
    void setNamXuatBan(int newNamXuatBan)
    {
        namXuatBan = newNamXuatBan;
    }
    int getTongSoTrang()
    {
        return tongSoTrang;
    }
    void setTongSoTrang(int newTongSoTrang)
    {
        tongSoTrang = newTongSoTrang;
    }
};

class cListBook
{
private:
    int size;
    cBook *books;

public:
    cListBook() : size(0), books(nullptr) {}
    cListBook(int s) : size(s)
    {
        books = (size > 0) ? new cBook[size] : nullptr;
    }
    cListBook(const cListBook &other) : size(other.size)
    {
        books = (size > 0) ? new cBook[size] : nullptr;
        if (books)
        {
            for (int i = 0; i < size; i++)
            {
                books[i] = other.books[i];
            }
        }
    }
    ~cListBook()
    {
        delete[] books;
    }

    void input()
    {
        cout << "Nhap so luong sach: ";
        cin >> size;
        delete[] books;
        books = (size > 0) ? new cBook[size] : nullptr;
        if (books)
        {
            for (int i = 0; i < size; i++)
            {
                cout << "Nhap thong tin sach thu " << (i + 1) << ":" << endl;
                books[i].input();
            }
        }
    }
    void output()
    {
        if (size == 0)
        {
            cout << "Danh sach sach rong." << endl;
            return;
        }
        cout << "Danh sach cac sach:" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << "Sach thu " << (i + 1) << ":" << endl;
            books[i].output();
        }
    }
    cBook findMostRecentBook()
    {
        if (size == 0)
        {
            cout << "Danh sach sach rong." << endl;
            return cBook();
        }
        cBook mostRecentBook = books[0];
        for (int i = 1; i < size; i++)
        {
            if (books[i].getNamXuatBan() > mostRecentBook.getNamXuatBan())
            {
                mostRecentBook = books[i];
            }
        }
        return mostRecentBook;
    }
};
