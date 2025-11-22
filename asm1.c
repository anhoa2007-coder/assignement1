#include <stdio.h> 
#include <math.h>
#include <stdlib.h> 
#include <stdbool.h> 
#include <conio.h> 
int tim_UCLN(int a, int b) {
    a = abs(a); 
    b = abs(b);
    if (a == 0 && b == 0) {
        return 0;
    }
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int tim_BCNN(int a, int b) {
    if (a == 0 || b == 0) {
        return 0; 
    }    
    int ucln = tim_UCLN(a, b);
    return (int)((long long)abs(a) / ucln * abs(b)); 
}

// Khai báo nguyên mẫu hàm (Function Prototype) - DÙNG CHO PHÂN LOẠI CHỨC NĂNG
// Nếu sau này bạn cần các hàm này, hãy định nghĩa lại chúng.
// void check_number(double x);
// int isPrime(long long n); 
void bamPhimBatKyDeTiepTuc() {
    printf("Bam phim bat ky de tiep tuc...");
    getch(); 
}

int main(){
    int luaChon; 
    
    do {
        printf("\n================================================");
        printf("\nChào mừng bạn đến với Chương trình Quản lý ASM");
        printf("\nNhập 1: Lựa chọn chức năng Số nguyên (Bao gồm SNT)");
        printf("\nNhập 2: Lựa chọn chức năng tìm UCLN và BCNN");
        printf("\nNhập 3: Lựa chọn chức năng Tính tiền quán Karaoke");
        printf("\nNhập 4: Lựa chọn chức năng Tính tiền điện");
        printf("\nNhập 0: Thoát chương trình");
        printf("\n================================================");
        printf("\nMời bạn nhập lựa chọn: ");
        
        // **SỬA LỖI INPUT 1: Kiểm tra scanf**
        if (scanf("%d", &luaChon) != 1) {
            printf("\nLoi nhap lieu! Vui long nhap mot so nguyen cho lua chon.\n");
            // Xóa bộ đệm đầu vào
            while(getchar() != '\n'); 
            luaChon = -1; 
            continue;
        }

        switch(luaChon){
            case 1: {
                printf("\n--- Bạn chọn CHỨC NĂNG 1: KIỂM TRA SỐ NGUYÊN & NGUYÊN TỐ ---\n");
                float x;
                printf("Nhập một số thực (có thể là số nguyên): "); scanf("%f", &x);
                if (x == (int)x)
                    printf("%.0f la so nguyen\n" ,x);
                else
                    printf("%.2f la so thuc\n" ,x);
                    // Kiem tra so chinh phuong
                if (x >= 0) {
                    float sqrt_x = sqrt(x);
                    if (sqrt_x == (int)sqrt_x) {
                        printf("%.0f la so chinh phuong\n", x);
                    } else {
                        printf("%.0f khong phai la so chinh phuong\n", x);
                    }
                } else {
                    printf("%.0f khong phai la so chinh phuong\n", x);
                }
                // Kiem tra so nguyen to
                int x_nguyen = (int)x;
					for(int i=2;i<=sqrt(x);i++){
                        if((int)x%i==0) x_nguyen=0;
                        					}
					if(x_nguyen==0) printf("%.0f Khong phai la so NT\n",x);
					else printf("%.0f Là số NT\n",x);
                break;
            }
case 2: {
    printf("\n--- Bạn chọn CHỨC NĂNG 2: TÌM UCLN và BCNN ---\n");
    int a, b;
    while(getchar() != '\n'); 
    
    printf("Nhập số nguyên a: "); 
    if (scanf("%d", &a) != 1) { 
        printf("Loi nhap lieu a! Quay lai Menu.\n"); 
        while(getchar() != '\n');
        break; 
    }
    while(getchar() != '\n'); 
    
    printf("Nhập số nguyên b: ");
    if (scanf("%d", &b) != 1) { 
        printf("Loi nhap lieu b! Quay lai Menu.\n"); 
        while(getchar() != '\n');
        break; 
    }

    while(getchar() != '\n'); 
    
    int ucln = tim_UCLN(a, b);
    int bcnn = tim_BCNN(a, b);
    printf("UCLN(%d, %d) = %d\n", a, b, ucln);
    printf("BCNN(%d, %d) = %d\n", a, b, bcnn);
    break;
}
            case 3: {
                printf("=== CHUC NANG 3: TINH TIEN QUAN KARAOKE ===\n\n");

                char inputBD[10], inputKT[10];
                int gioBD, phutBD, gioKT, phutKT;

                printf("Nhap gio BAT DAU (vi du: 14:30 hoac 14.30 hoac 14 30): ");
                scanf("%9s", inputBD);

                printf("Nhap gio KET THUC (tuong tu): ");
                scanf("%9s", inputKT);

                // Detect và parse cả 3 kiểu: 14:30  hoặc 14.30  hoặc 14 30
                if (sscanf(inputBD, "%d:%d", &gioBD, &phutBD) != 2)
                    if (sscanf(inputBD, "%d.%d", &gioBD, &phutBD) != 2)
                        sscanf(inputBD, "%d %d %d", &gioBD, &phutBD);

                if (sscanf(inputKT, "%d:%d", &gioKT, &phutKT) != 2)
                    if (sscanf(inputKT, "%d.%d", &gioKT, &phutKT) != 2)
                        sscanf(inputKT, "%d %d", &gioKT, &phutKT);

                // Kiểm tra hợp lệ
                if (gioBD < 0 || gioBD > 23 || phutBD < 0 || phutBD > 59 ||
                    gioKT < 0 || gioKT > 23 || phutKT < 0 || phutKT > 59) {
                    printf("\nLoi: Gio hoac phut khong hop le!\n");
                    bamPhimBatKyDeTiepTuc();
                    break;
                }

                int batDau = gioBD * 60 + phutBD;
                int ketThuc = gioKT * 60 + phutKT;

                if (ketThuc <= batDau) {
                    printf("\nLoi: Gio ket thuc phai lon hon gio bat dau!\n");
                    bamPhimBatKyDeTiepTuc();
                    break;
                }

                int soGioHat = (ketThuc - batDau + 59) / 60;  // làm tròn lên giờ

                long long tien = (long long)soGioHat * 150000;

                printf("\nBan hat tu %02d:%02d den %02d:%02d => %d tieng\n",
                       gioBD, phutBD, gioKT, phutKT, soGioHat);

                // Giảm 30% nếu bắt đầu trong khung 14h - 17h
                if (gioBD >= 14 && gioBD <= 17) {
                    tien = tien * 70 / 100;
                    printf("=> Giam 30%% khung gio vang 14h-17h\n");
                }

                // Giảm thêm 10% nếu hát từ 3 tiếng trở lên
                if (soGioHat >= 3) {
                    tien = tien * 90 / 100;
                    printf("=> Giam them 10%% vi hat tu 3 tieng tro len\n");
                }

                printf("\nTONG CONG PHAI TRA: %lld VND\n", tien);
                break;
            }
            case 4: {
                printf("=== CHUC NANG 4: TINH TIEN DIEN SINH HOAT ===\n\n");

                double sokWh;
                printf("Nhap so dien tieu thu (kWh): ");
                if (scanf("%lf", &sokWh) != 1 || sokWh < 0) {
                    printf("\nLoi: So kWh khong hop le!\n");
                    bamPhimBatKyDeTiepTuc();
                    break;
                }

                long long tien = 0;
                int daDung = 0;  // số kWh đã tính ở các bậc trước

                if (sokWh <= 50) {
                    tien = (long long)(sokWh * 1678);
                }
                else {
                    tien += 50 * 1678;          daDung = 50;
                    if (sokWh <= 100) {
                        tien += (long long)((sokWh - daDung) * 1734);
                    }
                    else {
                        tien += 50 * 1734;      daDung = 100;
                        if (sokWh <= 200) {
                            tien += (long long)((sokWh - daDung) * 2014);
                        }
                        else {
                            tien += 100 * 2014; daDung = 200;
                            if (sokWh <= 300) {
                                tien += (long long)((sokWh - daDung) * 2536);
                            }
                            else {
                                tien += 100 * 2536; daDung = 300;
                                if (sokWh <= 400) {
                                    tien += (long long)((sokWh - daDung) * 2834);
                                }
                                else {
                                    tien += 100 * 2834; daDung = 400;
                                    tien += (long long)((sokWh - daDung) * 2927);
                                }
                            }
                        }
                    }
                }

                // Thêm 10% VAT
                long long vat = tien / 10;
                long long tongCong = tien + vat;

                printf("\n");
                printf("╔══════════════════════════════════════════╗\n");
                printf("║         CHI TIET HOA DON DIEN            ║\n");
                printf("╠══════════════════════════════════════════╣\n");
                printf("║ So dien tieu thu : %8.0lf kWh         ║\n", sokWh);
                printf("║ Tien dien chua VAT: %8lld VND         ║\n", tien);
                printf("║ VAT 10%%           : %8lld VND         ║\n", vat);
                printf("╚══════════════════════════════════════════╝\n");
                printf("      TONG CONG PHAI TRA: %lld VND\n\n", tongCong);

                break;
            }
            case 0: { 
                printf("\nThoat chuong trinh. Cam on ban da su dung!\n");
                break;
            }
            default: 
                printf("\nLUA CHON KHONG HOP LE. Vui long chon tu 0 den 4.\n"); 
                break; 
        }
        
        
if (luaChon != 0) {
             printf("\n");
                         bamPhimBatKyDeTiepTuc();

        }
    } while(luaChon != 0);

    return 0;

}
