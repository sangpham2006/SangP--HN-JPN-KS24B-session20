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
    printf("Nh?p s? lu?ng s�ch: ");
    scanf("%d", &soLuongSach);
    for (int i = 0; i < soLuongSach; i++) {
        printf("Nh?p th�ng tin s�ch th? %d:\n", i + 1);
        printf("M� s�ch: ");
        scanf("%s", sachArray[i].maSach);
        printf("T�n s�ch: ");
        scanf("%s", sachArray[i].tenSach);
        printf("T�c gi?: ");
        scanf("%s", sachArray[i].tacGia);
        printf("Gi� ti?n: ");
        scanf("%f", &sachArray[i].giaTien);
        printf("Th? lo?i: ");
        scanf("%s", sachArray[i].theLoai);
    }
}

void hienThiThongTinSach() {
    for (int i = 0; i < soLuongSach; i++) {
        printf("S�ch th? %d:\n", i + 1);
        printf("M� s�ch: %s\n", sachArray[i].maSach);
        printf("T�n s�ch: %s\n", sachArray[i].tenSach);
        printf("T�c gi?: %s\n", sachArray[i].tacGia);
        printf("Gi� ti?n: %.2f\n", sachArray[i].giaTien);
        printf("Th? lo?i: %s\n", sachArray[i].theLoai);
    }
}

void themSachVaoViTri() {
    if (soLuongSach >= 100) {
        printf("M?ng s�ch d� d?y, kh�ng th? th�m s�ch.\n");
        return;
    }
    
    int viTri;
    printf("Nh?p v? tr� mu?n th�m s�ch (0 d?n %d): ", soLuongSach);
    scanf("%d", &viTri);

    if (viTri < 0 || viTri > soLuongSach) {
        printf("V? tr� kh�ng h?p l?.\n");
        return;
    }

    for (int i = soLuongSach; i > viTri; i--) {
        sachArray[i] = sachArray[i - 1];
    }

    printf("Nh?p th�ng tin s�ch m?i:\n");
    printf("M� s�ch: ");
    scanf("%s", sachArray[viTri].maSach);
    printf("T�n s�ch: ");
    scanf("%s", sachArray[viTri].tenSach);
    printf("T�c gi?: ");
    scanf("%s", sachArray[viTri].tacGia);
    printf("Gi� ti?n: ");
    scanf("%f", &sachArray[viTri].giaTien);
    printf("Th? lo?i: ");
    scanf("%s", sachArray[viTri].theLoai);

    soLuongSach++;
}

void xoaSachTheoMaSach() {
    char maSach[10];
    printf("Nh?p m� s�ch c?n x�a: ");
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
        printf("S�ch c� m� %s d� du?c x�a.\n", maSach);
    } else {
        printf("Kh�ng t�m th?y s�ch c� m� %s.\n", maSach);
    }
}

void capNhatThongTinSach() {
    char maSach[10];
    printf("Nh?p m� s�ch c?n c?p nh?t: ");
    scanf("%s", maSach);

    int found = 0;
    for (int i = 0; i < soLuongSach; i++) {
        if (strcmp(sachArray[i].maSach, maSach) == 0) {
            found = 1;
            printf("Nh?p th�ng tin m?i cho s�ch c� m� %s:\n", maSach);
            printf("T�n s�ch: ");
            scanf("%s", sachArray[i].tenSach);
            printf("T�c gi?: ");
            scanf("%s", sachArray[i].tacGia);
            printf("Gi� ti?n: ");
            scanf("%f", &sachArray[i].giaTien);
            printf("Th? lo?i: ");
            scanf("%s", sachArray[i].theLoai);
            break;
        }
    }

    if (found) {
        printf("Th�ng tin s�ch c� m� %s d� du?c c?p nh?t.\n", maSach);
    } else {
        printf("Kh�ng t�m th?y s�ch c� m� %s.\n", maSach);
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
    printf("Nh?p t�n s�ch c?n t�m: ");
    scanf("%s", tenSach);

    int found = 0;
    for (int i = 0; i < soLuongSach; i++) {
        if (strstr(sachArray[i].tenSach, tenSach) != NULL) {
            found = 1;
            printf("M� s�ch: %s\n", sachArray[i].maSach);
            printf("T�n s�ch: %s\n", sachArray[i].tenSach);
            printf("T�c gi?: %s\n", sachArray[i].tacGia);
            printf("Gi� ti?n: %.2f\n", sachArray[i].giaTien);
            printf("Th? lo?i: %s\n", sachArray[i].theLoai);
        }
    }

    if (!found) {
        printf("Kh�ng t�m th?y s�ch c� t�n %s.\n", tenSach);
    }
}

int main() {
    int luaChon;
    do {
        printf("\nMENU\n");
        printf
