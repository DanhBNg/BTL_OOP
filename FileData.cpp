#include "FileData.h"


//1. file hàng hóa
// hàm giúp lấy dữ liệu từ file từng dòng tương ứng với từng hàng
void file1HH(HangHoa& HH, string Ma, string Ten, string Gia, string SL, string Ngaynhap, string HSD, int& m){ 
	HH.Ma = Ma; 
	int a = 0; 
	int b = 0; 
	string temp; 
	temp = HH.Ma.substr(0, 2); 
	int t = stoi(temp); 
	switch (t){ 
	case 21:
		HH.Donvi = "Kg"; 
		break; 
	case 22:
	 	HH.Donvi = "Cai"; 
	 	break; 
	case 10:
	 	HH.Donvi = "Hop"; 
	 	break; 
	case 11:
	 	HH.Donvi = "Chai"; 
	 	break; 
	case 20:
	 	HH.Donvi = "Thung"; 
	 	break; 
	default: 
	 	HH.Donvi = "San Pham"; 
	 	break; 
	 } 
	HH.Ten = Ten; 
	HH.SL = stoi(SL);
	HH.Gia = stoi(Gia);
	HH.Ngaynhap = Ngaynhap; 
 	Phantichngay(HH.ngay, HH.thang, HH.nam, a, HH.Ngaynhap); 
	if (a == 1 || HH.thang > 12) 
 		m = 1; 
	HH.TimeNgaynhap = HH.ngay + HH.thang * 30 + HH.nam * 365; 
	HH.HSD = HSD; 
 	Phantichngay(HH.ngay, HH.thang, HH.nam, a, HH.HSD); 
	if (a == 1 || HH.thang > 12) 
 		b = 1; 
	if (m || b) m=1;
	HH.TimeHSD = HH.ngay + HH.thang * 30 + HH.nam * 365;
}

//Hàm giúp lấy toàn bộ dữ liệu file
void fileHH(HangHoa HH[], int& N, string filename){
	fstream f;
 	f.open(filename, ios::in); // đọc file
	if (f.fail()) { cout << "Khong the mo file!!!" << endl; return; }
	string str; 
	N = 0; 
 	getline(f, str); //đọc từng hàm của file, dữ liệu từ f sẽ lưu vào str
	int q = 0; 
	while (!f.eof())//nếu xuống dòng thì dừng đọc file
	{ 
		string t[20]; 
		string tmp = ""; 
		int cnt = 0; 
		getline(f, str); 
		for (int i = 0; i < str.size(); i++){ 
			if (str[i] == '\t') { t[cnt] = tmp; tmp = ""; cnt++; } 
			else{ 
		 		tmp += str[i]; 
		 	} 
		} 
		t[cnt] = tmp; 
		int m = 0; 
		file1HH(HH[N], t[1], t[2], t[3], t[4], t[5], t[6], m); 
		if (m == 1){ 
			q = 1; 
		 	break; 
		} 
		N++; //tăng số hàng lên 1
	} 
	if (q == 1){ 
		cout << "loi file do nhap ngay sai tai hang " << N + 1 <<endl;
		N = 0; 
	} 
	else { 
		cout << "Da upload file thanh cong!\n"; 
	} 
	f.close(); 
} 

//2.file khách hàng
//Hàm thiết lập thông tin
void file1KH(KhachHang& KH, string Ma, string Ten, string SDT, string DTL){
	KH.MaKhachHang = Ma;
	KH.getTenKhachHang() = Ten;
	KH.getSoDienThoai() = SDT;
	KH.DiemTichLuy = stoi(DTL); // chuyển điểm về dạng số
}
//Hàm đọc dữ liệu file khách hàng
//tương tự như cách thức đọc của file hàng hóa
void fileKH(KhachHang KH[], int& M, string filename){
	fstream f;
 	f.open(filename, ios::in); 
	if (f.fail()) { cout << "Khong the mo file!!!" << endl; return; }
	else { cout << "Da upload file thanh cong\n"; } 
	string str; 
	M = 0; 
 	getline(f, str); 
	int q = 0; 
	while (!f.eof()) 
	{ 
		string t[20]; 
		string tmp = ""; 
		int cnt = 0; 
		getline(f, str); 
		for (int i = 0; i < str.size(); i++){ 
			if (str[i] == '\t') { t[cnt] = tmp; tmp = ""; cnt++; } 
			else{ 
 				tmp += str[i]; 
 			} 
 		} 
		t[cnt] = tmp; 
		int m = 0; 
		file1KH(KH[M], t[1], t[2], t[3], t[4]); 
		M++; // tăng số khách lên 1
 	} 
 	f.close();
}

//3.file lịch sử hàng đã mua
//Hàm thiết lập 
void file1LS(HangHoa& BILL, string Ma, string Ten, string Gia, string SL, string Ngaynhap, string TTP, int& m){
	BILL.Ma = Ma; 
	int a = 0; 
	int b = 0; 
	string temp; 
	temp = BILL.Ma.substr(0, 2); 
	int t = stoi(temp); 
	switch (t) 
 	{ 
	case 21:
		BILL.Donvi = "Kg"; 
		break; 
	case 22:
	    BILL.Donvi = "Cai"; 
	    break; 
	case 10:
	    BILL.Donvi = "Hop"; 
	    break; 
	case 11:
	    BILL.Donvi = "Chai"; 
	    break; 
	case 20:
	    BILL.Donvi = "Thung"; 
	    break; 
	default: 
	    BILL.Donvi = "San Pham"; 
	    break; 
 	} 
	BILL.Ten = Ten; 
	BILL.SL = stoi(SL);
	BILL.Gia = stoi(Gia);
	BILL.Ngaynhap = Ngaynhap; 
	Phantichngay(BILL.ngay, BILL.thang, BILL.nam, a, BILL.Ngaynhap); 
	if (a == 1 || BILL.thang > 12) 
 		m = 1; 
	BILL.TimeNgaynhap = BILL.ngay + BILL.thang * 30 + BILL.nam * 365;
	BILL.TTP = stoi(TTP);
}
//Tương tự như hàm đọc file của hàng hóa cũng như khách hàng
//Ta có hàm đọc file Lịch sử
void fileLS(HangHoa BILL[], int& found2, string filename){
	fstream f;
    f.open(filename, ios::in); 
    if (f.fail()) { cout << "Khong the mo file!!!" << endl; return; }
    string str; 
    getline(f, str); 
    int q = 0; 
    while (!f.eof()) 
    { 
		string t[10]; 
		string tmp = ""; 
		int cnt = 0; 
		getline(f, str); 
		for (int i = 0; i < str.size(); i++){ 
			if (str[i] == '\t') { t[cnt] = tmp; tmp = ""; cnt++; } 
			else{ 
 				tmp += str[i]; 
 			} 
 		} 
 		t[cnt] = tmp; 
 		int m = 0; 
 		file1LS(BILL[found2], t[1], t[2], t[3], t[4], t[5], t[6], m); 
 		if (m == 1) 
		{ 
 			q = 1;
 			break; 
 		} 
 		found2++; 
 	} 
	if (q == 1){ 
 		cout << "loi file!!!\n"; 
 		found2 = 0; 
 	} 
 	f.close(); 
}
