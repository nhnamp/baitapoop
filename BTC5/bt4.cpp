/*
Một ma trận là một mảng hai chiều gồm m dòng và n cột.
Hãy khai báo và cài đặt lớp biểu diễn khái niệm ma trận để thực hiện các yêu cầu sau:
Tạo ma trận ngẫu nhiên m dòng, n cột
Nhập ma trận m dòng n cột
Operator cộng hai ma trận
Operator nhân hai ma trận
Viết chương trình cho phép tạo 2 ma trận, cộng, trừ 2 ma trận và xuất kết quả ra màn hình.
*/

#include <iostream>

using namespace std;

class Matrix
{
private:
    int rows;
    int cols;
    int **data;

    void allocate()
    {
        if (rows <= 0 || cols <= 0)
        {
            data = nullptr;
            return;
        }
        data = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            data[i] = new int[cols];
            for (int j = 0; j < cols; j++)
            {
                data[i][j] = 0;
            }
        }
    }

    void free()
    {
        if (data)
        {
            for (int i = 0; i < rows; i++)
            {
                delete[] data[i];
            }
            delete[] data;
            data = nullptr;
        }
    }

public:
    Matrix(int row = 0, int col = 0);
    ~Matrix();
    Matrix(const Matrix &other);
    Matrix operator=(const Matrix &other);

    int getRows() const;
    int getCols() const;

    void randomCreate(int lower = 0, int upper = 10);
    void input();
    void output() const;

    int &operator()(int i, int j);
    int operator()(int i, int j) const;

    Matrix operator+(const Matrix &other) const;
    Matrix operator-(const Matrix &other) const;
    Matrix operator*(const Matrix &other) const;
};

Matrix::Matrix(int row, int col) : rows(row), cols(col)
{
    allocate();
}

Matrix::~Matrix()
{
    free();
}

Matrix::Matrix(const Matrix &other) : rows(other.rows), cols(other.cols)
{
    allocate();
    if (data)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                data[i][j] = other.data[i][j];
            }
        }
    }
}

Matrix Matrix::operator=(const Matrix &other)
{
    if (this != &other)
    {
        free();
        rows = other.rows;
        cols = other.cols;
        allocate();
        if (data)
        {
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    data[i][j] = other.data[i][j];
                }
            }
        }
    }
    return *this;
}

int Matrix::getRows() const
{
    return rows;
}

int Matrix::getCols() const
{
    return cols;
}

void Matrix::randomCreate(int lower, int upper)
{
    if (!data)
        return;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            data[i][j] = lower + rand() % (upper - lower + 1);
        }
    }
}

void Matrix::input()
{
    if (!data)
        return;
    cout << "Nhap cac phan tu cua ma tran " << rows << "x" << cols << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Phan tu [" << i << "][" << j << "]: ";
            cin >> data[i][j];
        }
    }
}

void Matrix::output() const
{
    if (!data)
        return;
    cout << "Ma tran " << rows << "x" << cols << " la:" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << data[i][j] << "\t";
        }
        cout << endl;
    }
}

int &Matrix::operator()(int i, int j)
{
    if (i < 0 || i >= rows || j < 0 || j >= cols)
    {
        throw out_of_range("Chi so ngoai pham vi");
    }
    return data[i][j];
}

int Matrix::operator()(int i, int j) const
{
    if (i < 0 || i >= rows || j < 0 || j >= cols)
    {
        throw out_of_range("Chi so ngoai pham vi");
    }
    return data[i][j];
}

Matrix Matrix::operator+(const Matrix &other) const
{
    if (rows != other.rows || cols != other.cols)
    {
        cerr << "Khong the cong hai ma tran khac kich thuoc" << endl;
        return Matrix();
    }
    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator-(const Matrix &other) const
{
    if (rows != other.rows || cols != other.cols)
    {
        cerr << "Khong the tru hai ma tran khac kich thuoc" << endl;
        return Matrix();
    }
    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result.data[i][j] = data[i][j] - other.data[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix &other) const
{
    if (cols != other.rows)
    {
        cerr << "Dieu kien nhan hai ma tran: " << endl;
        cerr << "So cot cua ma tran 1 phai bang so hang cua ma tran 2" << endl;
        return Matrix();
    }
    Matrix result(rows, other.cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < other.cols; j++)
        {
            for (int k = 0; k < cols; k++)
            {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
}

int main()
{
    int m1, n1, m2, n2;
    cout << "Nhap so dong va so cot cua ma tran 1: ";
    cin >> m1 >> n1;
    Matrix matrix1(m1, n1);
    matrix1.input();

    cout << "Nhap so dong va so cot cua ma tran 2: ";
    cin >> m2 >> n2;
    Matrix matrix2(m2, n2);
    matrix2.input();

    cout << "Ma tran 1:" << endl;
    matrix1.output();
    cout << "Ma tran 2:" << endl;
    matrix2.output();

    Matrix sum = matrix1 + matrix2;
    cout << "Tong hai ma tran:" << endl;
    sum.output();

    Matrix diff = matrix1 - matrix2;
    cout << "Hieu hai ma tran:" << endl;
    diff.output();

    Matrix prod = matrix1 * matrix2;
    cout << "Tich hai ma tran:" << endl;
    prod.output();

    return 0;
}