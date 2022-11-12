#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;
// khai bao lop cha: information
class information {
protected:
	string hoten, sdt;
	int chuyenxe;
public:
	virtual  void read_file(ifstream&);
	virtual void xuat();
	virtual void nhap();
	friend int main();
	string get_sdt()
	{
		return this->sdt;
	}
	virtual void ghi_file(fstream&);
};
// cai dat phuong thuc ghi file cho lop cha 
void information::ghi_file(fstream &fileout)
{
	fileout << hoten << ", " << sdt << ", " << chuyenxe << ", ";
}
// cai dat phuong thuc doc file cho lop cha
void information::read_file(ifstream& filein)
{
	getline(filein, hoten, ',');
	filein.seekg(1, 1);
	getline(filein, sdt, ',');
	filein >> chuyenxe;
}
// cai dat phuong thuc xuat thong tin cho lop cha
void information::xuat()
{
	cout << hoten << setw(20) << sdt << setw(10) << chuyenxe;
}
// cai dat phuong thuc nhap thong tin cho lop cha
void information::nhap()
{
	cout << "Nhap Vao Ho Va Ten :";
	cin.ignore();
	getline(cin, hoten);
	cout << "Nhap Vao So Dien Thoai :";
	cin.ignore();
	getline(cin, sdt);
	cout << "Nhap Vao Chuyen Xe :";
	cin >> chuyenxe;
}
// khai bao lop con : chuyen xe ke thua lai lop cha : information
class car_infor : public information {
private:
	std::string cccd, trangthai;
	int soluong;
public:
	virtual  void read_file(ifstream&);
	virtual void xuat();
	virtual void nhap();
	friend int main();
	virtual void ghi_file(fstream&);
};
// cai dat phuong thuc ghi file cho lop car_infor
void car_infor::ghi_file(fstream& fileout)
{
	information::ghi_file(fileout);
	fileout << soluong << ", " << trangthai << ", " << cccd << endl;
}
// cai dat phuong thuc doc file cho lop car_infor
void car_infor::read_file(ifstream& filein)
{
	information::read_file(filein);
	filein.seekg(1, 1);
	filein >> soluong;
	filein.seekg(2, 1);
	getline(filein, trangthai, ',');
	filein.seekg(1, 1);
	getline(filein, cccd, '\n');
}
// cai dat phuong thuc xuat cho lop car_infor
void car_infor::xuat()
{
	information::xuat();
	cout << setw(5) << soluong << setw(15) << trangthai << setw(15) << cccd;
}
// cai dat phuong thuc nhap cho lop con car_infor
void car_infor::nhap()
{
	information::nhap();
	cout << "Nhap Vao So Can Cuoc Cong Dan cua tai xe :";
	cin.ignore();
	getline(cin, cccd);
	cout << "Nhap Vao Trang Thai cua xe :";
	cin.ignore();
	getline(cin, trangthai);
	cout << "Nhap Vao So Luong Cho Ngoi Con Trong :";
	cin >> soluong;
}
class customer : public information {
private:
	std::string place;
	int sove, chongoi;
	long long cost;
	int day, month, year;
public:
	virtual  void read_file(ifstream&);
	virtual void xuat();
	virtual void nhap();
	friend int main();
	virtual void ghi_file(fstream&);
};
void customer::ghi_file(fstream& fileout)
{
	information::ghi_file(fileout);
	fileout << place << ", " << sove << ", " << chongoi << ", " << cost << ", " << day << ", " << month << ", " << year << endl;
}
void customer::read_file(ifstream& filein)
{
	information::read_file(filein);
	filein.seekg(1, 1);
	getline(filein, place, ',');
	filein >> sove;
	filein.seekg(1, 1);
	filein >> chongoi;
	filein.seekg(1, 1);
	filein >> cost;
	filein.seekg(1, 1);
	filein >> day;
	filein.seekg(1, 1);
	filein >> month;
	filein.seekg(1, 1);
	filein >> year;
}
// cai dat phuong thuc xuat cho lop car_infor
void customer::xuat()
{
	information::xuat();
	cout << setw(30) << place << setw(3) << sove << setw(5) << chongoi << setw(10) << cost << setw(3) << day << "/" << month << "/" << year;

}
void customer::nhap()
{
	information::nhap();
	cout << "Nhap Vao Dia Diem Len Xe:";
	cin.ignore();
	getline(cin, place);
	cout << "Nhap Vao So Luong Ve dat :"; cin >> sove;
	cout << "Nhap Vao Vi Tri Cho Ngoi :"; cin >> chongoi;
	cout << "Nhap Vao Gia Tien :"; cin >> cost;
	cout << "Nhap Vao Ngay: "; cin >> day;
	cout << "Nhap Vao Thang :"; cin >> month;
	cout << "Nhap Vao Nam :"; cin >> year;
}
void doc_file1(information* ds[], int& n)
{
	ifstream filein;
	filein.open("car_infor.txt", ios_base::in);
	filein >> n;
	information* x = NULL;
	for (int i = 0; i < n; i++)
	{
		x = new car_infor();
		x->read_file(filein);
		ds[i] = x;
	}

	filein.close();
}
void doc_file2(information* ds[], int& n)
{
	ifstream filein;
	filein.open("customer.txt", ios_base::in);
	filein >> n;
	information* x = NULL;
	for (int i = 0; i < n; i++)
	{
		x = new customer();
		x->read_file(filein);
		ds[i] = x;
	}
	filein.close();
}
int search(information* ds[], string dt, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (ds[i]->get_sdt() == dt)
		{
			return i;
		}
	}
}
void ghi_file1(information *ds[], int n)
{
	fstream fileout;
	fileout.open("car_infor.txt", ios::out);
	fileout << n;
	for (int i = 0; i < n; i++)
	{
		ds[i]->ghi_file(fileout);
	}

}
void ghi_file2(information* ds[], int n)
{
	fstream fileout;
	fileout.open("customer.txt", ios::out);
	fileout << n;
	for (int i = 0; i < n; i++)
	{
		ds[i]->ghi_file(fileout);
	}

}
int main() {
	int n, chon, a;
	string pn;
	information* x = NULL;
	information* ds[100];
	customer *cr[100];
	car_infor *car[100];
	do {
		cout << "============MENU=============" << endl;
		cout << "1: Doc Thong Tin Chuyen Xe. " << endl;
		cout << "2: Doc Thong Tin Khach Hang" << endl;
		cout << "3: Thay doi thong tin khach hang." << endl;
		cout << "4: Thay doi thong tin chuyen xe." << endl;
		cout << "5: Xoa khach hang." << endl;
		cout << "6: Them khach hang." << endl;
		cout << "7: Tim Theo So Dien Thoai." << endl;
		cout << "0: Thoat Chuong Trinh." << endl;
		cout << "Moi nhap lua chon cua ban :"; cin >> chon;
		switch (chon)
		{
		case 1:
			doc_file1(ds, n);
			for (int i = 0; i < n; i++)
			{
				ds[i]->xuat(); cout << endl;
			}
			break;
		case 2:
			doc_file2(ds, n);
			for (int i = 0; i < n; i++)
			{
				ds[i]->xuat(); cout << endl;
			}
			break;   // luu y dau { } giua moi case do loi lien quan toi he thong file 
		case 3:
			cout << "Moi Nhap Vao So Dien Thoai Cua Khach Hang Can Tim : ";
			cin.ignore();
			getline(cin, pn);
			a = search(ds, pn, n);
			for (int i = 0; i < n; i++)
			{
				if (i == a)
				{
					x = new customer();
					x->nhap();
					ds[i] = x;
					ds[i]->xuat(); cout << endl;
				}
			}
			ghi_file2(ds, n);
			break;
		case 4:
			cout << "Nhap Vao Chuyen Xe Ban Muon Thay Doi Thong Tin :"; cin >> a;
			for (int i = 0; i < n; i++)
			{
				if (ds[i]->chuyenxe == a)
				{
					x = new car_infor();
					x->nhap();
					ds[i] = x;
					ds[i]->xuat(); cout << endl;
				}
			}
			ghi_file1(ds, n);
			break;
		case 5:
			cout << "Moi Nhap Vao So Dien Thoai Cua Khach Hang Can Xoa : ";
			cin.ignore();
			getline(cin, pn);
			a = search(ds, pn, n);
			for (int i = a; i < n; i++)
			{
				ds[i] = ds[i + 1];
			}
			n--;
			for (int i = 0; i < n; i++)
			{
				ds[i]->xuat(); cout << endl;
			}
			ghi_file2(ds, n);
			break;
		case 7:

			cout << "Moi Nhap Vao So Dien Thoai Cua Khach Hang Can Tim : ";
			cin.ignore();
			getline(cin, pn);

			a = search(ds, pn, n);
			for (int i = 0; i < n; i++)
			{
				if (i == a)
				{
					ds[i]->xuat(); cout << endl;
				}
			}
			break;
		case 6:
			n++;
			x = new customer();
			x->nhap();
			ds[n - 1] = x;
			for (int i = 0; i < n; i++)
			{
				ds[i]->xuat(); cout << endl;
			}
			ghi_file2(ds, n);
			break;
		case 0:
			break;
		default:
			break;

		}
	} while (chon);
	return 0;
}
