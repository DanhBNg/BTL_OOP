#include "FileData.h"

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

long TienTong(hanghoa BILL) 
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
						