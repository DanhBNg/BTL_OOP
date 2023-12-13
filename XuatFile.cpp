#include "FileData.h"

//xuất file hàng hóa
void Xuatfile1HH(HangHoa& HH, string& Ma, string& Ten, string& Gia, string& SL, string& Donvi, string& Ngaynhap, string& HSD){ 
	Ma = HH.Ma; 
	Ten = HH.Ten; 
	Gia = to_string(HH.Gia); 
	SL = to_string(HH.SL); 
	Donvi = HH.Donvi; 
	Ngaynhap = HH.Ngaynhap; 
	HSD = HH.HSD; 
}

void XuatfileHH(HangHoa HH[], int& N,string filename) 
{ 
	fstream f;
	string Ma, Ten, Gia, SL, Donvi, Ngaynhap, HSD; 
 	f.open(filename, ios::out); 
	if (f.fail()){ cout << "Khong the mo file!!!" << endl; return; }
	f << "STT\tMa hang hoa\tTen hang hoa\tGia\tSo luong\tDon vi\tNgay nhap\tHSD" << endl; 
	for (int i = 0; i < N; i++){ 
 		Xuatfile1HH(HH[i], Ma, Ten, Gia, SL, Donvi, Ngaynhap, HSD); 
 		f << i+1 << "\t" << Ma << "\t" << Ten << "\t" << Gia << "\t"<< SL << "\t" << Donvi << "\t" << Ngaynhap << "\t" << HSD << endl; 
 	} 
 	f.close(); 
}

//Xuất file khách hàng
void Xuatfile1KH(KhachHang& KH, string& Ma, string& Ten, string& SDT, string& DTL){ 
	Ma = KH.MaKhachHang; 
	Ten = KH.getTenKhachHang(); 
	SDT = KH.getSoDienThoai(); 
	DTL = to_string(KH.DiemTichLuy); 
}

void XuatfileKH(KhachHang KH[], int& M, string filename){ 
	fstream f;
	string Ma, Ten, SDT, DTL; 
 	f.open(filename, ios::out); 
	if (f.fail()) { cout << "Khong the mo file!!!" << endl; return; }
	f << "STT\tMa khach hang\tTen khach hang\tSDT\tDiem tich luy" <<endl;
	for (int i = 0; i < M; i++){ 
 	Xuatfile1KH(KH[i], Ma, Ten, SDT, DTL); 
 	f << i + 1 << "\t" << Ma << "\t" << Ten << "\t" << SDT <<"\t" << DTL << endl; 
 	} 
 	f.close(); 
} 

//Xuất bill 
void Xuatfile1BILL(HangHoa& BILL, string& Ma, string& Ten, string& Gia, string& SL, string& Donvi, string& Ngaynhap, string& TTP){ 
	Ma = BILL.Ma; 
	Ten = BILL.Ten; 
	Gia = to_string(BILL.Gia); 
	SL = to_string(BILL.SL);
	Donvi = BILL.Donvi; 
	Ngaynhap = BILL.Ngaynhap; 
	TTP = to_string(BILL.TTP); 
}

void XuatfileBILL(hanghoa BILL[],int& found1, int& found2, string filename){ 
	fstream f;
	string Ma, Ten, Gia, SL, Donvi, Ngaynhap, TTP; 
	f.open(filename, ios::out); 
	if (f.fail()) { cout << "Khong the mo file!!!" << endl; return; }
	f << "STT\tMa hang hoa\tTen hang hoa\tGia\tSo luong\tDon vi\tNgay mua hang\tThanh tien" << endl; 
	int count = -1;
	for (int i = found1; i < found2; i++){ 
 		count++; 
 		Xuatfile1BILL(BILL[i], Ma, Ten, Gia, SL, Donvi, Ngaynhap, TTP);
 		f << count + 1 << "\t" << Ma << "\t" << Ten << "\t" << Gia << "\t" << SL << "\t" << Donvi << "\t" << Ngaynhap << "\t" << TTP <<endl;
 	} 
 	f.close(); 
}

