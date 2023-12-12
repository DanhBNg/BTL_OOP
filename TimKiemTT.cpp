#include <iostream>
#include "FileData.h"
#include "HienThi.h"

//Chung 1 thuật toán
//Tạo 1 biến found để thể hiện số phần tử có chuỗi giống với chuỗi cần tìm
//dùng hàm find để tìm, return >=0 thì lưu tt vào mảng khách đã tạo và ++ biến found

//1. Tìm kiếm theo mã hàng
void TimKiemTheoMaHH(HangHoa HH[], string Ma, int N){ 
	hanghoa TKHH[50]; 
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
	hanghoa TKHH[50]; 
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
	khachhang TKKH[50]; 
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
	khachhang TKKH[50]; 
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
	khachhang TKKH[50]; 
	string SDTKH; 
	int found = 0; 
	for(int i = 0; i < M; i++){ 
 		SDTKH = KH[i].getSoDienThoai; 
 		int sr = SDTKH.find(SDT);
 		if (sr >= 0) { 
 			TKKH[found] = KH[i]; 
 			found++; 
 		} 
 	} 
 	XuatTTKH(TKKH, found); 
}