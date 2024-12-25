#include <stdio.h>
#include <string.h>

struct Sach {
    char maSach[10];
    char tenSach[50];
    char tacGia[50];
    float giaTien;
    char theLoai[30];
};

struct Sach sachArray[100];
int soLuongSach = 0;

void nhapThongTinSach() {
    printf("Nh?p s? lu?ng sách: ");
    scanf("%d", &soLuongSach);
    for (int i = 0; i < soLuongSach; i++) {
        printf("Nh?p thông tin sách th? %d:\n", i + 1);
        printf("Mã sách: ");
        scanf("%s", sachArray[i].maSach);
        printf("Tên sách: ");
        scanf("%s", sachArray[i].tenSach);
        printf("Tác gi?: ");
        scanf("%s", sachArray[i].tacGia);
        printf("Giá ti?n: ");
        scanf("%f", &sachArray[i].giaTien);
        printf("Th? lo?i: ");
        scanf("%s", sachArray[i].theLoai);
    }
}

void hienThiThongTinSach() {
    for (int i = 0; i < soLuongSach; i++) {
        printf("Sách th? %d:\n", i + 1);
        printf("Mã sách: %s\n", sachArray[i].maSach);
        printf("Tên sách: %s\n", sachArray[i].tenSach);
        printf("Tác gi?: %s\n", sachArray[i].tacGia);
        printf("Giá ti?n: %.2f\n", sachArray[i].giaTien);
        printf("Th? lo?i: %s\n", sachArray[i].theLoai);
    }
}

void themSachVaoViTri() {
    if (soLuongSach >= 100) {
        printf("M?ng sách dã d?y, không th? thêm sách.\n");
        return;
    }
    
    int viTri;
    printf("Nh?p v? trí mu?n thêm sách (0 d?n %d): ", soLuongSach);
    scanf("%d", &viTri);

    if (viTri < 0 || viTri > soLuongSach) {
        printf("V? trí không h?p l?.\n");
        return;
    }

    for (int i = soLuongSach; i > viTri; i--) {
        sachArray[i] = sachArray[i - 1];
    }

    printf("Nh?p thông tin sách m?i:\n");
    printf("Mã sách: ");
    scanf("%s", sachArray[viTri].maSach);
    printf("Tên sách: ");
    scanf("%s", sachArray[viTri].tenSach);
    printf("Tác gi?: ");
    scanf("%s", sachArray[viTri].tacGia);
    printf("Giá ti?n: ");
    scanf("%f", &sachArray[viTri].giaTien);
    printf("Th? lo?i: ");
    scanf("%s", sachArray[viTri].theLoai);

    soLuongSach++;
}

void xoaSachTheoMaSach() {
    char maSach[10];
    printf("Nh?p mã sách c?n xóa: ");
    scanf("%s", maSach);

    int found = 0;
    for (int i = 0; i < soLuongSach; i++) {
        if (strcmp(sachArray[i].maSach, maSach) == 0) {
            found = 1;
            for (int j = i; j < soLuongSach - 1; j++) {
                sachArray[j] = sachArray[j + 1];
            }
            soLuongSach--;
            break;
        }
    }

    if (found) {
        printf("Sách có mã %s dã du?c xóa.\n", maSach);
    } else {
        printf("Không tìm th?y sách có mã %s.\n", maSach);
    }
}

void capNhatThongTinSach() {
    char maSach[10];
    printf("Nh?p mã sách c?n c?p nh?t: ");
    scanf("%s", maSach);

    int found = 0;
    for (int i = 0; i < soLuongSach; i++) {
        if (strcmp(sachArray[i].maSach, maSach) == 0) {
            found = 1;
            printf("Nh?p thông tin m?i cho sách có mã %s:\n", maSach);
            printf("Tên sách: ");
            scanf("%s", sachArray[i].tenSach);
            printf("Tác gi?: ");
            scanf("%s", sachArray[i].tacGia);
            printf("Giá ti?n: ");
            scanf("%f", &sachArray[i].giaTien);
            printf("Th? lo?i: ");
            scanf("%s", sachArray[i].theLoai);
            break;
        }
    }

    if (found) {
        printf("Thông tin sách có mã %s dã du?c c?p nh?t.\n", maSach);
    } else {
        printf("Không tìm th?y sách có mã %s.\n", maSach);
    }
}

void sapXepSachTheoGia(int tangDan) {
    struct Sach temp;
    for (int i = 0; i < soLuongSach - 1; i++) {
        for (int j = i + 1; j < soLuongSach; j++) {
            if ((tangDan && sachArray[i].giaTien > sachArray[j].giaTien) ||
                (!tangDan && sachArray[i].giaTien < sachArray[j].giaTien)) {
                temp = sachArray[i];
                sachArray[i] = sachArray[j];
                sachArray[j] = temp;
            }
        }
    }
}

void timKiemSachTheoTen() {
    char tenSach[50];
    printf("Nh?p tên sách c?n tìm: ");
    scanf("%s", tenSach);

    int found = 0;
    for (int i = 0; i < soLuongSach; i++) {
        if (strstr(sachArray[i].tenSach, tenSach) != NULL) {
            found = 1;
            printf("Mã sách: %s\n", sachArray[i].maSach);
            printf("Tên sách: %s\n", sachArray[i].tenSach);
            printf("Tác gi?: %s\n", sachArray[i].tacGia);
            printf("Giá ti?n: %.2f\n", sachArray[i].giaTien);
            printf("Th? lo?i: %s\n", sachArray[i].theLoai);
        }
    }

    if (!found) {
        printf("Không tìm th?y sách có tên %s.\n", tenSach);
    }
}

int main() {
    int luaChon;
    do {
        printf("\nMENU\n");
        printf
