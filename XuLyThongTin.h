#include "FileData.h"
#include <string>
#include <iostream>
using namespace std;

////CÁC HÀM NHẬP THÔNG TIN
//1.Thiết lập hàm nhập tay dữ liệu hàng hóa
//sử dụng trong 1 số trường hợp thử nghiệm với 1 vài dữ liệu nhỏ
//Hoặc cập nhật thêm hàng hóa, khách hàng
void NhapTT1HH(HangHoa& HH){
	string temp; 
    int a = 0; 
    SET_COLOR(10); cout << "\nMa hang hoa: "; SET_COLOR(7); cin >> HH.Ma; cin.ignore(); 
    temp = HH.Ma.substr(0, 2); 
    SET_COLOR(10); cout << "\nTen hang hoa: "; SET_COLOR(7); 
    getline(cin, HH.Ten); 
    SET_COLOR(10); cout << "\nGia san pham: "; SET_COLOR(7); cin >> HH.Gia; 
//dùng cin nhập chuỗi string liên tiếp và getline cho chuỗi có khoảng cách
//và xét đơn vị hay xét ngày như đọc file hàng hóa, khách hàng ở trên
    int t = stoi(temp); 
    switch (t) 
    { 
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
 	SET_COLOR(10); cout << "\nSo luong san pham: "; SET_COLOR(7); cin >> HH.SL; cin.ignore(); 
	while (true) 
 	{ 
 		SET_COLOR(10); cout << "\nNgay nhap hang: (dd/mm/yyyy) "; 
		SET_COLOR(7); cin >> HH.Ngaynhap; 
 		int a = 0; 
 		Phantichngay(HH.ngay, HH.thang, HH.nam, a, HH.Ngaynhap); 
 		if (a == 0 && HH.thang <= 12){
			break;
		} 
		else BaoLoi();
 			
    }
    HH.TimeNgaynhap = HH.ngay + HH.nam * 30 + HH.nam * 365;
    while (true) 
 	{ 
 		SET_COLOR(10); cout << "\nHan su dung: (dd/mm/yyyy) "; 
		SET_COLOR(7); cin >> HH.HSD; 
 		int a = 0; 
 		Phantichngay(HH.ngay, HH.thang, HH.nam, a, HH.HSD); 
 		if (a == 0 && HH.thang <= 12) 
 			break; 
 		else BaoLoi();
 	} 
	HH.TimeHSD = HH.ngay + HH.nam * 30 + HH.nam * 365; 
}
//Hàm nhập hết tt hàng
void NhapTTHH(HangHoa HH[], int& N) {
	int n = 50; 
    SET_COLOR(3); 
    cout << "\nNhap thong tin hang hoa\n\n"; cin.ignore(); 
	for (int i = 0; i < N; i++) { 
 		kehang(n); //graphic
 		cout << "\n"; 
 		SET_COLOR(3); 
 		cout << "sam pham thu " << (i + 1) << endl;
 		NhapTT1HH(HH[i]); //gọi các mảng hàng hóa hiện có và đưa nó vào hàm nhập 1
 	} 
 	SET_COLOR(3); 
	cout << "\nDa nhap xong!\n"; 
 	kehang(n); //trong tv graphic
	cout << "\n"; 
}

//Hàm nhập 1 khách
void NhapTT1KH(KhachHang& KH, int& pb){
	SET_COLOR(10); cout << "\nMa Khach Hang: "; SET_COLOR(7); cin >> KH.MaKhachHang; 
 	cin.ignore(); 
 	SET_COLOR(10); cout << "\nTen Khach Hang: "; SET_COLOR(7); 
	getline(cin,KH.TenKhachHang); 
 	SET_COLOR(10); cout << "\nSo Dien Thoai: "; SET_COLOR(7); cin >> KH.SoDienThoai; 
	if (pb == 1){ 
 		SET_COLOR(10); cout << "\nDiem tich luy: "; SET_COLOR(7); 
		cin >> KH.DiemTichLuy; cin.ignore(); 
 	} 
	if (pb == 2){ 
 		KH.DiemTichLuy = 0; 
 	}
}
//dùng hàm này ở 2 trường hợp, 
//Nếu thêm KH thì cần nhập các tt KH có điểm tích lũy = 0
//Nếu chỉnh sửa khách hàng thì đc nhập điểm tích lũy
//Biến pb để phân biệt 2 TH

//2.Hàm xóa và thêm thông tin
//Hàm xóa hàng
void XoaHH(HangHoa HH[], int& N){ 
	int i, k; 
	while (true) 
 	{ 
 	//Nhập vị trí(số thứ tự) cần xóa
 		SET_COLOR(10); cout << "chon vi tri hang hoa can xoa: "; 
		SET_COLOR(7); cin >> i; cout << "\n"; cin.ignore(); 
 		if (i <= N && i >= 1) 
 			break; 
 	} 
	if (i != N){ 
 		for (k = i - 1; k < N - 1; k++){ 
 			HH[k] = HH[k + 1]; 
 		} 
 	} 
} 
//hàm xóa khách
void XoaKH(KhachHang KH[], int& M){ 
	int i, k; 
	while (true){ 
 		SET_COLOR(10); cout << "chon vi tri khach hang can xoa: "; 
		SET_COLOR(7); cin >> i; cout << "\n"; cin.ignore(); 
 		if (i <= M && i >= 1) 
 			break; 
 	} 
	if (i != M){ 
 		for (k = i - 1; k < M - 1; k++){ 
 			KH[k] = KH[k + 1]; 
 		} 
 	} 
	cout << "Da xoa thong tin khach hang\n";
}
//Hàng thêm hàng
void ThemHH(HangHoa HH[], int& N){ 
	int i, k; 
	while (true){ 
 		SET_COLOR(10); cout << "chon vi tri thu tu hang hoa can them: "; 
		SET_COLOR(7); cin >> i; cout << "\n"; cin.ignore(); 
 		if (i <= N + 1 && i >= 1) 
 			break; 
 	} 
	for (k = N; k >= i; k--){ 
 		HH[k] = HH[k - 1];
 	} 
 	NhapTT1HH(HH[i - 1]); 
} 
//Hàng thêm khách
void ThemKH(KhachHang KH[], int& M, int& pb){ 
	int i, k; 
	while (true){ 
 		SET_COLOR(10); cout << "chon vi tri thu tu khach hang can them: "; 
		SET_COLOR(7); cin >> i; cout << "\n"; cin.ignore(); 
 		if (i <= M + 1 && i >= 1) 
 			break; 
 	} 
	if (i != (M + 1)){
		for (k = M; k >= i; k--){ 
 			KH[k] = KH[k - 1];
 		} 
	}
	NhapTT1KH(KH[i-1],pb); // biến pb để pb 2 trường hợp nhập khách hàng
}

//3.Cập nhật thông tin
//Chỉnh sửa tt đã nhập sai hoặc có sự cố cần thay đổi thông tin

//Cập nhật hàng hóa
void CapNhatHH(HangHoa HH[], int& N){ 
	int i;
	while (true){ 
 		SET_COLOR(10); cout << "chon vi tri hang hoa muon chinh sua: "; 
		SET_COLOR(7); cin >> i; cout << "\n"; cin.ignore(); 
 		if (i <= N && i >= 1) 
 			break; 
 	} 
 	NhapTT1HH(HH[i - 1]); 
}

//Cập nhật khách hàng
void CapNhatKH(KhachHang KH[], int& N, int& pb) // biến pb để phân biệt 2 trường hợp nhập KH 
{ 
	int i;
	while (true){ 
 		SET_COLOR(10); cout << "chon vi tri khach hang muon chinh sua: ";
		SET_COLOR(7); cin >> i; cout << "\n"; cin.ignore(); 
 		if (i <= N && i >= 1)
 			break;
 	}
 	NhapTT1KH(KH[i - 1], pb);
	cout << "Da cap nhat xong thong tin khach hang\n"; 
}

////CÁC HÀM IN RA THÔNG TIN
//1.Hàm xuất tt 1 hàng
void XuatTT1HH(HangHoa& HH){ 
 	SET_COLOR(7); 
	string ch = to_string(HH.Gia); 
	cout << HH.Ma << "\t\t" << HH.Ten; 
	khoang(HH.Ten, 25); 
	cout <<"\t\t" << HH.Gia; khoang(ch, 10); cout << "\t\t" << HH.SL << "\t\t" <<HH.Donvi << "\t\t" << HH.Ngaynhap << "\t" << HH.HSD << "\n"; 
} 

//2.Hàm xuất all tt
void XuatTTHH(HangHoa HH[], int& N){
 	SET_COLOR(3); cout << "Thong tin hang hoa: \n"; 
	int n = 140; 
 	kehang(n); 
	cout << "\n"; 
 	SET_COLOR(3); 
	cout << "\nSTT\tMa hang hoa\tTen san pham\t\t\t\tGia\t\t\tSo luong\tDon vi\t\tNgay nhap\tHSD\n"; 
 	SET_COLOR(7); 
	for (int i = 0; i < N; i++) { 
 		cout << i + 1 << "\t"; 
 		XuatTT1HH(HH[i]); 
 	} 
	cout << "\n"; 
 	kehang(n); 
	cout << "\n\n\n"; 
} 

//3.Hàm xuất tt 1 KH
void XuatTT1KH(KhachHang& KH) {
	cout << KH.MaKhachHang << "\t" << KH.getTenKhachHang(); 
	//khoang(KH.getTenKhachHang(), 25); 
	cout << KH.getSoDienThoai() << "\t\t" <<KH.DiemTichLuy << "\n"; 
}
//4.hàm xuất all tt khách 
void XuatTTKH(KhachHang KH[], int& N){ 
 	SET_COLOR(3); 
	cout << "\nThong tin khach hang: \n"; 
	string ten = "Ten Khach Hang"; 
	int n = 70; 
 	kehang(n);
 	SET_COLOR(3); 
	cout << "\n"; 
	cout << "\nSTT\tMa khach hang\t Ten khach hang"; 
	//khoang(ten, 25); 
	cout << "So dien thoai\t\tDiem tich luy\n"; 
 	SET_COLOR(7); 
	for (int i = 0; i < N; i++) { 
 		cout << i + 1 << "\t"; 
 		XuatTT1KH(KH[i]); 
 	} 
	cout << "\n"; 
 	kehang(n); 
 	SET_COLOR(7);
}

//5.Hàm xuất 1 bill
void XuatTT1BILL(HangHoa& BILL) { 
	string ch = to_string(BILL.Gia); 
	cout << BILL.Ma << "\t\t" << BILL.Ten; //khoang(BILL.Ten, 25); 
	cout << "\t\t" << BILL.Gia; //khoang(ch, 10);
	cout << "\t\t" << BILL.SL <<"\t\t" << BILL.Donvi << "\t\t" << BILL.Ngaynhap << " " <<BILL.TTP << "\n"; 
} 

//6.Hàm xuất tt all bill
void XuatTTBILL(HangHoa BILL[], int& M, int& N) {
	int n = 140; 
	int k = 0; 
 	kehang(n); 
 	SET_COLOR(3); 
	cout << "\n"; 
	cout << "\nSTT\tMa hang hoa\tTen san pham\t\t\t\tGia\t\t\tSo luong\tDon vi\t\tNgay mua hang Thanh tien\n"; 
 	SET_COLOR(7); 
	for (int i = M; i < N; i++){ 
 	cout << k + 1 << "\t"; 
 	XuatTT1BILL(BILL[i]); 
 	k++;
 	} 
	cout << "\n"; 
 	kehang(n); 
 	SET_COLOR(7); 
}

////CÁC HÀM SẮP XẾP:
//sử dụng thuật toán bubble sort

//1. Sắp xếp theo mã hàng
void SapxeptheoMaHH(HangHoa HH[], int& N){ 
	int i, j; 
	for (i = 0; i < N - 1; i++) 
 		for (j = 0; j < N - i - 1; j++) 
 			if (HH[j].Ma[0] > HH[j + 1].Ma[0]) 
 				swap(HH[j], HH[j + 1]); 
 	XuatTTHH(HH, N);
}

//2. theo tên hàng
void SapxeptheoTenHH(HangHoa HH[], int& N){ 
	int i, j; 
	for (i = 0; i < N - 1; i++) 
 		for (j = 0; j < N - i - 1; j++) 
 			if (HH[j].Ten[0] > HH[j + 1].Ten[0]) 
 				swap(HH[j], HH[j + 1]); 
 	XuatTTHH(HH, N);
}

//3.theo giá hàng
void SapxeptheoGiaHH(HangHoa HH[], int& N){ 
	int i, j; 
	for (i = 0; i < N - 1; i++) 
 		for (j = 0; j < N - i - 1; j++) 
 			if (HH[j].Gia > HH[j + 1].Gia) 
 				swap(HH[j], HH[j + 1]); 
 	XuatTTHH(HH, N);
}

//4.theo số lượng hàng
void SapxeptheoSoluongHH(HangHoa HH[], int& N){ 
	int i, j; 
	for (i = 0; i < N - 1; i++) 
 		for (j = 0; j < N - i - 1; j++) 
 			if (HH[j].SL > HH[j + 1].SL) 
 				swap(HH[j], HH[j + 1]);
	XuatTTHH(HH, N);
}

//5.theo ngày nhập
void SapxeptheoNgaynhapHH(HangHoa HH[], int& N){ 
	int i, j; 
	for (i = 0; i < N - 1; i++) 
 		for (j = 0; j < N - i - 1; j++) 
 			if (HH[j].TimeNgaynhap > HH[j + 1].TimeNgaynhap) 
 				swap(HH[j], HH[j + 1]); 
	XuatTTHH(HH, N);
} 

//6.theo hạn sử dụng hàng
void SapxeptheoHSDHH(HangHoa HH[], int& N){ 
	int i, j; 
	for (i = 0; i < N - 1; i++) 
 		for (j = 0; j < N - i - 1; j++) 
 			if (HH[j].TimeHSD > HH[j + 1].TimeHSD) 
 				swap(HH[j], HH[j + 1]); 
 	XuatTTHH(HH, N);
} 

//7.theo mã khách
void SapxeptheoMaKH(KhachHang KH[], int& M){ 
	int i, j; 
	for (i = 0; i < M - 1; i++) 
 		for (j = 0; j < M - i - 1; j++) 
 			if (KH[j].MaKhachHang[0] > KH[j + 1].MaKhachHang[0]) 
 				swap(KH[j], KH[j + 1]); 
 	XuatTTKH(KH, M);
}

//8. theo tên khách
void SapxeptheoTenKH(KhachHang KH[], int& M){ 
	int i, j; 
	for (i = 0; i < M - 1; i++) 
 		for (j = 0; j < M - i - 1; j++) 
 			if (KH[j].getTenKhachHang()[0] > KH[j + 1].getTenKhachHang()[0]) 
 				swap(KH[j], KH[j + 1]); 
 	XuatTTKH(KH, M);
}

////CÁC HÀM TÌM KIẾM THÔNG TIN
//Chung 1 thuật toán
//Tạo 1 biến found để thể hiện số phần tử có chuỗi giống với chuỗi cần tìm
//dùng hàm find để tìm, return >=0 thì lưu tt vào mảng khách đã tạo và ++ biến found

//1. Tìm kiếm theo mã hàng
void TimKiemTheoMaHH(HangHoa HH[], string Ma, int N){ 
	HangHoa TKHH[50]; 
	string MaHH; 
	int found = 0; 
	for (int i = 0; i < N; i++) { 
 		MaHH=HH[i].Ma; 
 		int sr = MaHH.find(Ma);
 		if (sr>=0) { 
 			TKHH[found] = HH[i]; 
 			found++; 
 		} 
 	} 
 	XuatTTHH(TKHH, found); 
}

//2.Theo tên hàng
void TimKiemTheoTenHH(HangHoa HH[], string Ten, int N){
	HangHoa TKHH[50]; 
	string TenHH; 
	int found = 0; 
	for (int i = 0; i < N; i++) { 
		TenHH = HH[i].Ten; 
 		int sr = TenHH.find(Ten);
 		if (sr >= 0) { 
 			TKHH[found] = HH[i]; 
 			found++; 
 		} 
 	}		 
 	XuatTTHH(TKHH, found); 
} 

//3. Theo mã khách
void TimKiemTheoMaKH(KhachHang KH[], string Ma, int M){
	KhachHang TKKH[50]; 
	string MaKH; 
	int found = 0;
	for (int i = 0; i < M; i++){ 
 		MaKH = KH[i].MaKhachHang; 
 		int sr = MaKH.find(Ma);
 		if (sr >= 0) { 
 			TKKH[found] = KH[i]; 
 			found++; 
 		} 
	} 
 	XuatTTKH(TKKH, found); 
}

//4.Theo tên khách
void TimKiemTheoTenKH(KhachHang KH[], string Ten, int M) { 
	KhachHang TKKH[50]; 
	string TenKH; 
	int found = 0; 
	for(int i = 0; i < M; i++){ 
 		TenKH = KH[i].getTenKhachHang(); 
 		int sr = TenKH.find(Ten);
 		if (sr >= 0) { 
 			TKKH[found] = KH[i]; 
 			found++; 
 		} 
 	} 
 	XuatTTKH(TKKH, found); 
}

//5.Theo SDT khách
void TimKiemTheoSDTKH(KhachHang KH[], string SDT, int M) { 
	KhachHang TKKH[50]; 
	string SDTKH; 
	int found = 0; 
	for(int i = 0; i < M; i++){ 
 		SDTKH = KH[i].getSoDienThoai(); 
 		int sr = SDTKH.find(SDT);
 		if (sr >= 0) { 
 			TKKH[found] = KH[i]; 
 			found++; 
 		} 
 	} 
 	XuatTTKH(TKKH, found); 
}

//MUA BÁN VÀ THANH TOÁN
//Các hàm liên quan

void Soluongkho(HangHoa& HH, int sl,int& checksl){ 
	if(HH.SL >= sl){ 
 		checksl = 0;
 		HH.SL = HH.SL - sl; 
 	} 
	else
 		checksl = 1;
}

void Soluongbill(HangHoa& BILL, float sl) 
{ 
	BILL.SL = sl; 
} 

void Tienthanhphan(HangHoa& BILL, string Ngaybill) 
{ 
	BILL.TTP = (long)BILL.SL * BILL.Gia; 
	BILL.Ngaynhap = Ngaybill.substr(0, 10); 
}

long TienTong(HangHoa BILL) 
{ 
	return BILL.TTP; 
} 

void thanhtoan(HangHoa BILL[], HangHoa HH[], KhachHang KH[], KhachHang KHB[], int& N, int& found1, int& found2, int y, int& z, long Tong[50], int& M, string Ngaybill, int& norcn) 
{ 
	while (true){ 
		string Masp; 
		SET_COLOR(10); 
		cout << "\nNhap ma san pham: "; 
		SET_COLOR(7); 
		cin >> Masp; 
		if ((Masp == "Q") || (Masp == "q"))
 			break; 
 		else{ 
	 		string MaHHB; 
 			int a = -1;
			for (int i = 0; i < N; i++) { 
 				MaHHB = HH[i].Ma; 
 				int sr = MaHHB.find(Masp); 
 				if (sr >= 0) { 
 					BILL[found2] = HH[i]; 
 					found2++; 
 					a = i; 
 				} 
 			} 
 			if (a < 0){ 
				SET_COLOR(4); 
				cout << "\nKhong tim thay san pham!!\n"; 
				SET_COLOR(7); 
 			} 
 			else{ 
 				int sl = 0; 
 				int checksl = 0; 
				y++;
 				while (true){ 
					SET_COLOR(10); 
					cout << "\nNhap so luong san pham: "; 
					SET_COLOR(7); 
					cin >> sl; cin.ignore(); 
					Soluongkho(HH[a], sl, checksl); 
					if (checksl == 0){ 
 						break; 
 					} 
 				} 
				Soluongbill(BILL[found2 - 1], sl); 
				Tienthanhphan(BILL[found2 - 1], Ngaybill);
				XuatTTBILL(BILL, found1, found2);
 			} 
 		} 
 	}
 	if (y > 0){ 
		z++;
		string yn; 
		Tong[z] = 0; 
		SET_COLOR(3); 
		cout << "\n\n\n\nHOA DON KHACH HANG: \n"; 
		XuatTTBILL(BILL, found1, found2);
		for (int i = found1; i < found2; i++) 
 			Tong[z] = Tong[z] + TienTong(BILL[i]);
 		SET_COLOR(4);
 		cout << "\nThanh tien: " << Tong[z] << "\n"; 
 		SET_COLOR(7);
 		while (true){ 
			SET_COLOR(3); 
			cout << "Ban co the thanh vien chua? (y/n) "; 
			SET_COLOR(7); 
			cin >> yn; 
			if (yn == "y" || yn == "n" || yn == "Y" || yn == "N") 
				break; 
		}
		if (yn == "n" || yn == "N"){ 
 			while (true){ 
				SET_COLOR(3); 
				cout << "Ban co muon tao the thanh vien khong? (y/n) "; 
				SET_COLOR(7); 
				cin >> yn; 
 				if (yn == "y" || yn == "n" || yn == "Y" || yn =="N") 
 					break; 
 			} 
 			if (yn == "y" || yn == "Y"){ 
				M++;
				NhapTT1KH(KH[M - 1], norcn);
			 	KH[M - 1].DiemTichLuy = Tong[z] / 100; 
 			} 
 		} 
 		else{ 
			string Makh; 
			SET_COLOR(10); 
			cout << "\nNhap ma khach hang: "; 
			SET_COLOR(7); 
			cin >> Makh; 
			string MakhB; 
			int found = 0; 
			int a = -1;
			for (int i = 0; i < M; i++){ 
				MakhB = KH[i].MaKhachHang; 
				int sr = MakhB.find(Makh); 
				if (sr >= 0){
					KHB[found] = KH[i];
					found++; 
					a = i; 
				}
			}
			if (a < 0){ 
				SET_COLOR(4); 
				cout << "\nKhong tim thay san pham!!\n"; 
				SET_COLOR(7); 
 			} 
 			else{
 				XuatTTKH(KHB, found); 
 				if (KHB[found - 1].DiemTichLuy >= 1000){ 
 					while (true){ 
						string yn; 
						cin.ignore(); 
						SET_COLOR(3); 
						cout << "\nBan co muon dung diem tich luy khong? (y/n) "; 
						SET_COLOR(7); 
						cin >> yn; 
 						if (yn == "y" || yn == "n" || yn =="Y" || yn == "N") 
							break; 
 					} 
 					if (yn == "n" || yn == "N"){ 
 						KHB[found - 1].DiemTichLuy = KHB[found - 1].DiemTichLuy + Tong[z] / 100; 
 						KH[a].DiemTichLuy = KHB[found - 1].DiemTichLuy; 
 						XuatTTKH(KHB, found); 
 					} 
 					else{ 
 						int n = KHB[found - 1].DiemTichLuy / 1000;
 						KHB[found - 1].DiemTichLuy = KHB[found - 1].DiemTichLuy - n * 1000; 
 						KHB[found - 1].DiemTichLuy = KHB[found - 1].DiemTichLuy + Tong[z] / 100; 
 						SET_COLOR(3); 
 						cout << "\n\n\n\nHOA DON KHACH HANG: \n"; 
						XuatTTBILL(BILL, found1, found2);
						SET_COLOR(4); 
						cout << "\nThanh tien: " << Tong[z] - n * 1000 << "\n"; 
 						SET_COLOR(7); 
 						KH[a].DiemTichLuy = KHB[found - 1].DiemTichLuy;
						XuatTTKH(KHB, found); 
					}
					else{ 
 						KHB[found - 1].DiemTichLuy = KHB[found - 1].DiemTichLuy + Tong[z] / 100; 
 						KH[a].DiemTichLuy = KHB[found - 1].DiemTichLuy; 
 						XuatTTKH(KHB, found); 
 					} 
 				} 
 			} 
 		} 
	}
}
