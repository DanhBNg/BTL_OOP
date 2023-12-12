#ifndef FILEDATA_H
#define FILEDATA_H

#include <iostream>
#include <fstream>
#include "KhachHang.h"
#include "HangHoa.h"
#include "KhachHang.h"

using namespace std;

// Xác định năm nhuận
int nhuan(int a) { 
	if (a % 400 == 0) 
	 	return 1;
	else
	if ((a % 4 == 0) && (a % 100 != 0)) 
		return 1;
		else
		return 0;
} 

// Tạo 1 biến string tạm, vì dữ liệu nhập của time là dd/mm/yyyy nên dùng hàm substr để tách lấy dữ liệu 
void Phantichngay(int& day, int& month, int& year, int& a, string Ngay){ 
	string temp; 
	temp = Ngay.substr(0, 2); 
	day = stoi(temp); 
	temp = Ngay.substr(3, 2); 
	month = stoi(temp); 
	temp = Ngay.substr(6, 4); 
	year = stoi(temp); 
	if ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12)) 
		if (day > 31) 
			a = 1; 
		else a = 0; 
	else
	 	if ((month == 2) && (nhuan(year) == 1)) 
	 		if (day > 29) 
	 			a = 1; 
	 		else
	 			a = 0; 
	 	else
	 		if (month == 2) 
	 			if (day > 28) a = 1; 
	 			else a = 0; 
	 	else
	 			if (day > 30) a = 1; 
	 			else a = 0; 
}
// giá trị của a là dấu hiệu để báo lỗi về ngày trong năm

#endif
