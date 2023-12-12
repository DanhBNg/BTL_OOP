#include <iostream>
#include "FileData.h"
#include "HienThi.h"

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

