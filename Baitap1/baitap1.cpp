#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <istream>
using namespace std;

class VienChuc
{
protected:
    /* data */
    int ma;
    string ten;
    float he_so_luong;
public:
    VienChuc(/* args */);
    ~VienChuc();
    void nhap()
    {
        cout << "\nnhap ma vien chuc : ";
        cin >> ma;
        cout << "nhap ten vien chuc : ";
        fflush(stdin);
        getline(cin, ten);
        cout << "nhap he so luong :";
        cin >> he_so_luong;
    }

    void in()
    {
        cout << "|" << setw(19) << ma;
         cout << "|" << setw(19) << ten;
    cout << "|" << setw(19) << he_so_luong;
    }

    
};

void line()
{
    cout  << "+" ;
    int i = 98;
    while(i--)
    cout << "-";
    cout  << "+\n";
}

void tieude()
{
    cout << endl;
    line();
    cout << "|" << setw(19) << "Ma vien chuc";
    cout << "|" << setw(19) << "Ten vien chuc";
    cout << "|" << setw(19) << "He so luong";
    cout << "|" << setw(19) << "Chuc vu ";
    cout << "|" << setw(18) << "He so chuc vu" << "|\n";
    line(); 
}
class CanBoQuanLy : protected VienChuc
{
private:
    string chucvu;
    float he_so_cv;
public:
    friend istream& operator>>(istream& is, CanBoQuanLy& a)
    {
        a.nhap();
        cout << "nhap chuc vu : ";
        fflush(stdin);
        getline(is, a.chucvu);
        cout << "nhap he so chuc vu : ";
        fflush(stdin);
        is >> a.he_so_cv;
        return is;
    }

    friend ostream& operator<<(ostream& os, CanBoQuanLy& a)
    {
        a.in();
        os << "|" << setw(19) << a.chucvu;
         os << "|" << setw(18) << a.he_so_cv<< "|\n";
         line();
        return os;
    }
    string getten()
    {
        string s = "";
        int i = ten.size() - 1;
        while(ten[i] != ' ')
        s += ten[i--];
        return s;
    }

    string getho()
    {
        string s = "";
        int i = 0;
        while(ten[i] != ' ')
        s += ten[i++];
        return s;
    }

    int getma()
    {
        return ma;
    }
    friend bool cmp(CanBoQuanLy a, CanBoQuanLy b);

    void sethesolg(float x)
    {
        he_so_luong = x;
    }
};

bool cmp(CanBoQuanLy a, CanBoQuanLy b)
    {
        return a.ma <= b. ma;
    }
VienChuc::VienChuc(/* args */)
{
}

VienChuc::~VienChuc()
{
}

void nhapn(CanBoQuanLy a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void indanhsach(CanBoQuanLy a[], int n)
{
    cout << "\nDanh sach can bo quan ly la : \n";
    tieude();
    for(int i = 0; i < n; i++)
    cout << a[i];
}
void intheoten(CanBoQuanLy a[], int n)
{
    cout << "\nnhap ten can tim kiem : ";
    string s;
    fflush(stdin);
    getline(cin, s);
    tieude();
    for(int i = 0 ; i < n; i++)
    {
        if(a[i].getten() == s)
        cout << a[i];
    }
}

void intheoho(CanBoQuanLy a[], int n)
{
    cout << "\nnhap ho can tim kiem : ";
    string s;
    fflush(stdin);
    getline(cin, s);
    tieude();
    for(int i = 0 ; i < n; i++)
    {
        if(a[i].getho() == s)
        cout << a[i];
    }
}

void themcanbo(CanBoQuanLy a[], int& n)
{
    int k;
    cout << "\nnhap vi tri can them : ";
    cin >> k;
    CanBoQuanLy them;
    cout << "\nnhap thong tin can bo can them : ";
    cin >> them;
    while(k <= 0 || k >= n)
    {
        cout << "nhap lai vi tri : ";
        cin >> k;
    }
    k--;
    for(int i = n; i > k; i--)
    {
        a[i] = a[i - 1];
    }
    a[k] = them;
    n++;
    cout << "them can bo thanh cong ";
}

void sapxep(CanBoQuanLy a[], int n)
{
    sort(a, a + n, cmp);
    cout << "\nsap xep thanh cong : ";
}

void timkiemtheoma(CanBoQuanLy a[], int n)
{
    int x;
    cout << "\nnhap ma can bo can tim kiem ";
    cin >> x;
    for(int i = 0; i < n; i++)
    {
        if(a[i].getma() == x)
        {
            cout << "\nthong tin can bo co ma " << x << " la : \n"; 
            cout << a[i];
            return;
        }
    }
    cout << "\nkhong tim thay can bo co ma : " << x;

}

void themvass(CanBoQuanLy a[], int& n)
{
    int k;
    cout << "\nnhap vi tri can them : ";
    cin >> k;
    CanBoQuanLy them;
    cout << "\nnhap thong tin can bo can them : ";
    cin >> them;
    while(k <= 0 || k >= n)
    {
        cout << "nhap lai vi tri : ";
        cin >> k;
    }
    k--;
    for(int i = n; i > k; i--)
    {
        a[i] = a[i - 1];
    }
    a[k] = them;
    n++;
    sort(a, a + n, cmp);
    cout << "them can bo va sap xep thanh cong \n";
}

void xoa(CanBoQuanLy a[], int& n)
{
    int k;
    cout << "nhap ma  can bo can xoa : ";
    cin >> k;
    for(int i = 0; i < n; i++)
    {
        if(a[i].getma() == k)
        {
            for(int j = i; j < n - 1; j++)
            {
                a[j] = a[j + 1];
             }
            n--;
            cout << "xoa thanh cong ";
            return;
            
        }
    }
    cout << "khong tim thay nhan vien co ma : " << k;
}

void sua(CanBoQuanLy a[], int n)
{
    int k;
    cout << "nhap ma  can bo can sua : ";
    cin >> k;
    for(int i = 0; i < n; i++)
    {
        if(a[i].getma() == k)
        {
            cout << "nhap he so luong moi :  ";
            float temp;
            cin >> temp;
            a[i].sethesolg(temp);
            cout << "sua he so luong thanh cong : ";
            return;
        }
    }
    cout << "khong tim thay nhan vien co ma : " << k;
}

void menu()
{
    int luachon;
    CanBoQuanLy a[30];
    int n;
    cout << "Nhap so can bo : ";
    cin >> n;
    nhapn(a, n);
    note:
    cout << "\n1. In danh sach can bo quan ly : \n";
    cout << "2. Tim kiem can bo quan ly theo ten :\n";
    cout << "3. Tim kiem can bo quan ly theo ho : \n";
    cout << "4. Them can bo quan ly tai vi tri k \n";
    cout << "5. Sap xep can bo quan ly theo chieu tang dan ma vien chuc \n";
    cout << "6. Tim kiem can bo quan ly theo ma \n";
    cout << "7. Them can bo quan ly va danh sach duoc sap xep theo chieu tang dan cua ma\n";
    cout << "8. Xoa mot can bo quan ly \n";
    cout << "9. Sua he so luong mot can bo quan ly\n";
    cout << "10. Xoa man hinh \n";
    cout << "Nhap lua chon cua ban : ";
    cin >> luachon;
    switch(luachon)
    {
        case 1:
        indanhsach(a, n);
        goto note;
        break;
        case 2:
        intheoten(a, n);
        goto note;
        break;
        case 3:
        intheoho(a, n);
        goto note;
        break;
        case 4:
        themcanbo(a, n);
        goto note;
        break;
        case 5:
        sapxep(a, n);
        goto note;
        break;
        case 6:
        timkiemtheoma(a, n);
        goto note;
        break;
        case 7:
        themvass(a, n);
        goto note;
        break;
        case 8:
        xoa(a, n);
        goto note;
        break;
        case 9:
        sua(a, n);
        goto note;
        break;
        case 10:
        system("cls");
        goto note;
        break;
        default:
        break;

    }
}
int main()
{  
    menu();
    return 0;
}