#include "Graphic.h"
#include <string>
#include "FileData.h"

//Các hàm sử dụng để hiện thông tin lên Console

//1.Hàm xuất tt 1 hàng
void XuatTT1HH(HangHoa& HH){ 
 	SET_COLOR(7); 
	string ch = to_string(HH.Gia); 
	cout << HH.Ma << "\t\t" << HH.Ten; 
	//khoang(HH.Ten, 25); 
	cout <<"\t\t" << HH.Gia; khoang(ch, 10); cout << "\t\t" << HH.SL << "\t\t" <<HH.Donvi << "\t\t" << HH.Ngaynhap << " " << HH.HSD << "\n"; 
} 

//2.Hàm xuất all tt
void XuatTTHH(HangHoa HH[], int& N){
 	SET_COLOR(3); cout << "Thong tin hang hoa: \n"; 
	int n = 140; 
 	kehang(n); 
	cout << "\n"; 
 	SET_COLOR(3); 
	cout << "\nSTT\tMa hang hoa\tTen san pham\t\t\t\tGia\t\t\tSo luong\tDon vi\t\tNgay nhap HSD\n"; 
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
	cout << "\t\t" << BILL.Gia; khoang(ch, 10);
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
