// Viết chương trình nhập vào 2 ma trận. Tính tổng, hiệu, tích hai ma trận đã nhập và in kết quả ra màn hình.
#include <bits/stdc++.h>
using namespace std;

class Matran
{
private:
    int n, m;
    vector<vector<int>> data;

public:
    void nhap()
    {
        cout << "Nhap so hang va so cot: ";
        cin >> n >> m;
        data.resize(n, vector<int>(m));
        cout << "Nhap cac phan tu cua ma tran: ";
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> data[i][j];
    }
    void xuat()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cout << data[i][j] << " ";
            cout << endl;
        }
    }
    Matran operator+(Matran b)
    {
        if (n != b.n || m != b.m)
        {
            cout << "Hai ma tran phai co cung kich thuoc de thuc hien phep cong." << endl;
            exit(1);
        }
        Matran c;
        c.n = n;
        c.m = m;
        c.data.resize(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                c.data[i][j] = data[i][j] + b.data[i][j];
        return c;
    }
    Matran operator-(Matran b)
    {
        if (n != b.n || m != b.m)
        {
            cout << "Hai ma tran phai co cung kich thuoc de thuc hien phep tru." << endl;
            exit(1);
        }
        Matran c;
        c.n = n;
        c.m = m;
        c.data.resize(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                c.data[i][j] = data[i][j] - b.data[i][j];
        return c;
    }
    Matran operator*(Matran b)
    {
        if (m != b.n)
        {
            cout << "So cot cua ma tran thu nhat phai bang so hang cua ma tran thu hai de thuc hien phep nhan." << endl;
            exit(1);
        }
        Matran c;
        c.n = n;
        c.m = b.m;
        c.data.resize(n, vector<int>(b.m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < b.m; j++)
                for (int k = 0; k < m; k++)
                    c.data[i][j] += data[i][k] * b.data[k][j];
        return c;
    }
};
int main()
{
    Matran A, B;
    cout << "Nhap ma tran A:" << endl;
    A.nhap();
    cout << "Nhap ma tran B:" << endl;
    B.nhap();

    cout << "Ma tran A:" << endl;
    A.xuat();
    cout << "Ma tran B:" << endl;
    B.xuat();

    Matran C = A + B;
    cout << "Tong hai ma tran A + B:" << endl;
    C.xuat();

    Matran D = A - B;
    cout << "Hieu hai ma tran A - B:" << endl;
    D.xuat();

    Matran E = A * B;
    cout << "Tich hai ma tran A * B:" << endl;
    E.xuat();

    return 0;
}