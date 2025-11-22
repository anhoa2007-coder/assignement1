# Chương trình Quản lý ASM (C)

## 📌 Mô tả ngắn
Chương trình console viết bằng **C** cung cấp menu tương tác cho 4 chức năng chính:
- Kiểm tra số (số nguyên, số thực, số chính phương, số nguyên tố)
- Tìm **UCLN** & **BCNN**
- Tính tiền quán karaoke theo giờ
- Tính tiền điện sinh hoạt theo bậc  

Có kiểm tra input cơ bản và hiển thị hoá đơn đơn giản cho tính tiền điện.

---

## ⚙️ Chức năng

### 1. Kiểm tra số
- Nhập số thực (có thể là số nguyên).  
- In ra: số nguyên hay số thực, có phải số chính phương hay không, có phải số nguyên tố hay không.

### 2. Tìm UCLN & BCNN
- Nhập hai số nguyên `a` và `b`.  
- Tính **UCLN** bằng thuật toán Euclid.  
- Tính **BCNN** dựa trên UCLN.

### 3. Tính tiền quán Karaoke
- Nhập giờ bắt đầu và giờ kết thúc (các dạng `14:30`, `14.30`, hoặc `14 30`).  
- Làm tròn lên giờ.  
- Tính tiền: **150.000 VND/giờ**.  
- Giảm giá:
  - 30% nếu bắt đầu trong khung **14h–17h**
  - Thêm 10% nếu hát ≥ 3 giờ

### 4. Tính tiền điện sinh hoạt
- Nhập số kWh (có thể là số thực).  
- Áp dụng bảng bậc giá (50, 51–100, 101–200, ...).  
- Cộng thêm **VAT 10%** và in hoá đơn tóm tắt.
---

