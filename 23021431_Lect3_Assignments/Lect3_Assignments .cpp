Bài 1: Sắp xếp các hàm theo thứ tự tăng dần của ký hiệu Big O
Function SapXepBigO():
DanhSach = [
"4nlogn + 2n -> O(nlogn)",
"2^10 -> O(1)",
"2^logn -> O(n)",
"3n + 100logn -> O(n)",
"4n -> O(n)",
"2^n -> O(2^n)",
"n^2 + 10n -> O(n^2)",
"n^3 -> O(n^3)",
"nlogn -> O(nlogn)"
]
KetQua = SapXepTangDan(DanhSach theo BigO):

O(1): 2^10
O(n): 2^logn, 3n + 100logn, 4n
O(nlogn): 4nlogn + 2n, nlogn
O(n^2): n^2 + 10n
O(n^3): n^3
O(2^n): 2^n In(KetQua)
Bài 2: Viết hai thuật toán tính 2^n và đánh giá độ phức tạp
Function TinhMuHai_VongLap(n):
ketQua = 1
If n == 0:
Return ketQua
If n > 0:
For i from 1 to n:
ketQua = ketQua * 2
Return ketQua
Else:
For i from 1 to -n:
ketQua = ketQua / 2
Return ketQua
PhucTap: O(n)

Function TinhMuHai_DeQuy(n):
If n == 0:
Return 1
If n > 0:
nuaMu = TinhMuHai_DeQuy(n / 2)
If n % 2 == 0:
Return nuaMu * nuaMu
Else:
Return 2 * nuaMu * nuaMu
Else:
nuaMu = TinhMuHai_DeQuy(n / 2)
If n % 2 == 0:
Return nuaMu * nuaMu
Else:
Return nuaMu * nuaMu / 2
PhucTap: O(log n)

Bài 3: Viết các thao tác của hàng đợi dùng mảng và đánh giá độ phức tạp
Structure HangDoiMang:
mang[max_kich_thuoc]
viTriDau = -1
viTriCuoi = -1
kichThuoc = 0

Function ThemVaoHang(mangHangDoi, giaTri):
If kichThuoc == max_kich_thuoc:
In("Hang doi day!")
Return
If viTriDau == -1:
viTriDau = 0
viTriCuoi = viTriCuoi + 1
mang[viTriCuoi] = giaTri
kichThuoc = kichThuoc + 1
PhucTap: O(1)

Function XoaKhoiHang(mangHangDoi):
If kichThuoc == 0:
In("Hang doi rong!")
Return
If viTriDau == viTriCuoi:
viTriDau = -1
viTriCuoi = -1
Else:
viTriDau = viTriDau + 1
kichThuoc = kichThuoc - 1
PhucTap: O(1)

Bài 4: Viết các thao tác của hàng đợi dùng danh sách liên kết và đánh giá độ phức tạp
Structure NutHangDoi:
giaTri
tiepTheo = null

Structure HangDoiLienKet:
dau = null
cuoi = null
kichThuoc = 0

Function ThemVaoHang(lienKetHangDoi, giaTri):
nutMoi = New NutHangDoi(giaTri)
If cuoi == null:
dau = nutMoi
cuoi = nutMoi
Else:
cuoi.tiepTheo = nutMoi
cuoi = nutMoi
kichThuoc = kichThuoc + 1
PhucTap: O(1)

Function XoaKhoiHang(lienKetHangDoi):
If dau == null:
In("Hang doi rong!")
Return
nutXoa = dau
If dau == cuoi:
dau = null
cuoi = null
Else:
dau = dau.tiepTheo
Delete nutXoa
kichThuoc = kichThuoc - 1
PhucTap: O(1)

Bài 5: Viết các thao tác của ngăn xếp dùng mảng và đánh giá độ phức tạp
Structure NganXepMang:
mang[max_kich_thuoc]
dinh = -1
kichThuoc = 0

Function DayVaoNganXep(mangNganXep, giaTri):
If kichThuoc == max_kich_thuoc:
In("Ngan xep day!")
Return
dinh = dinh + 1
mang[dinh] = giaTri
kichThuoc = kichThuoc + 1
PhucTap: O(1)

Function LayKhoiNganXep(mangNganXep):
If kichThuoc == 0:
In("Ngan xep rong!")
Return
dinh = dinh - 1
kichThuoc = kichThuoc - 1
PhucTap: O(1)

Bài 6: Viết các thao tác của ngăn xếp dùng danh sách liên kết và đánh giá độ phức tạp
Structure NutNganXep:
giaTri
tiepTheo = null

Structure NganXepLienKet:
dinh = null
kichThuoc = 0

Function DayVaoNganXep(lienKetNganXep, giaTri):
nutMoi = New NutNganXep(giaTri)
nutMoi.tiepTheo = dinh
dinh = nutMoi
kichThuoc = kichThuoc + 1
PhucTap: O(1)

Function LayKhoiNganXep(lienKetNganXep):
If dinh == null:
In("Ngan xep rong!")
Return
nutXoa = dinh
dinh = dinh.tiepTheo
Delete nutXoa
kichThuoc = kichThuoc - 1
PhucTap: O(1)