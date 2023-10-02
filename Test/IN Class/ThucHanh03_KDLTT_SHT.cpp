#include <iostream>
#include <stdlib.h> 
using namespace std;

struct SoHuuTy
{
	int tuSo;
	int mauSo;// thiet ke cac truong o day
};
typedef struct SoHuuTy SHT;

void nhapSHT(SHT *);
void inSHT(const SHT *);
void toiGianSHT(SHT *);
SHT* congSHT(const SHT *, const SHT *);
int soSanhSHT(const SHT *, const SHT *);
void sapXepLuaChonMangSHT(SHT *, int);
void nhapMang(SHT *, int);
void inMangDaSapXep(SHT *, int);


int main()
{
	// cap phat bo nho dong cho con tro toi mot so huu ti
	SHT * sht1 = new SHT;
    SHT * sht2 = new SHT;
    SHT * tongSHT = new SHT;

	// cap phat bo nho dong cho mang cac so huu ti
	SHT * mangSHT = new SHT[100];

    // nhapSHT(sht1);
    // inSHT(sht1);

    // nhapSHT(sht2);
    // inSHT(sht2);

    // tongSHT = congSHT(sht1, sht2);
    // inSHT(tongSHT);

    int sophantuMang;
    cin >> sophantuMang;
    nhapMang(mangSHT, sophantuMang);
    sapXepLuaChonMangSHT(mangSHT, sophantuMang);
    inMangDaSapXep(mangSHT, sophantuMang);
    SHT* tongMang;
    tongMang->tuSo = 0;
    tongMang->mauSo = 1;
    for(int i = 0 ; i < sophantuMang; i++){
        tongMang = congSHT(tongMang,mangSHT + i);
    }
    cout << ((double)tongMang->tuSo / tongMang->mauSo) / sophantuMang;
	return 0;
}

// phai kiem tra xem mau so co khac 0 khong
// va so doc vao can luu o dang toi gian
void nhapSHT(SHT * sht)
{
    cout << "Nhap tu so: ";
    cin >> sht->tuSo;
    cout << endl;
    cout << "Nhap mau so: ";
    cin >> sht->mauSo;
    cout << endl;
    toiGianSHT (sht);
}

// in duoi dang phan so a/b
void inSHT(const SHT *sht)
{
    cout << sht->tuSo << "/" << sht->mauSo << endl;
}

int ucln(int a, int b){
    if(a == b) return a;
    else{
        if(a > b) return ucln(b,a-b);
        else return ucln(a,b-a);
    }
}
// tu so va mau so cua 1 so huu ti nguyen to cung nhau
// luu y: so huu ti luon luon phai luu duoi dang nay
void toiGianSHT(SHT * sht)
{
    if(sht->tuSo < 0 && sht->mauSo < 0){
        sht->mauSo = abs(sht->mauSo);
        sht->tuSo = abs(sht->tuSo);
    }
    else if(sht->tuSo > 0 && sht->mauSo < 0){
        sht->tuSo = -sht->tuSo;
        sht->mauSo = abs(sht->mauSo);
    }
    if(ucln(abs(sht->tuSo),abs(sht->mauSo)) != 1){
        sht->tuSo /= ucln(sht->tuSo,sht->mauSo);
        sht->mauSo /= ucln(sht->tuSo,sht->mauSo);
    } 
}

SHT * congSHT(const SHT * sht1, const SHT * sht2)
{
	// gia tri tra ve la tong 2 so huu ti sht1 va sht2
	// can cap phat bo nho dong cho bien tong cua 2 so huu ti
	// sau do tra con tro nay ve
	SHT * tongSHT = new SHT;
    tongSHT->tuSo = sht1->tuSo * sht2->mauSo +  sht2->tuSo * sht1->mauSo;
    tongSHT->mauSo = sht1->mauSo * sht2->mauSo;
	// tongSHT = sht1 + sht2;
	toiGianSHT(tongSHT);
	return tongSHT;
}

// tra ve 1 neu sht1 > sht2
// tra ve 0 neu sht1 = sht2
// tra ve -1 neu sht1 < sht2
int soSanhSHT(const SHT * sht1, const SHT * sht2)
{
    SHT hieuSHT;
    hieuSHT.tuSo = sht1->tuSo * sht2->mauSo - sht2->tuSo * sht1->mauSo;
    hieuSHT.mauSo = sht1->mauSo * sht2->mauSo;
    
    if((double)hieuSHT.tuSo / hieuSHT.mauSo > 0) return 1;
    else if((double)hieuSHT.tuSo / hieuSHT.mauSo == 0) return 0;
	return -1;
}

void inMangDaSapXep(SHT *mangSHT, int soPhanTu){
    for(int i = 0; i < soPhanTu; i++){
        cout << mangSHT[i].tuSo << "/" << mangSHT[i].mauSo << " ";
    }
}
void nhapMang(SHT *mangSHT, int soPhanTu){
    for(int i = 0; i < soPhanTu; i++){
        // SHT*sht = new SHT;
        // nhapSHT(sht);
        // mangSHT[i].tuSo = sht->tuSo;
        // mangSHT[i].mauSo = sht->mauSo;
        // delete sht;
        nhapSHT(mangSHT+i);
    }
}
// sap xep su dung thuat toan lua chon
void sapXepLuaChonMangSHT(SHT * mangSHT, int soPhanTu)
{
    int i, j;
    int viTriMin;
    for (i = 0; i < soPhanTu-1; i++)
    {
        viTriMin = i;
        for (j=i+1; j<soPhanTu; j++)
        {
            // thay doi vi tri cua min moi
            if (soSanhSHT(&mangSHT[viTriMin], &mangSHT[j]) == 1)
            {
                viTriMin = j;
            }
        }
        // doi cho phan tu nho nhat voi phan tu dau tien trong day chua sap xep (vi tri i)
        SHT temp = mangSHT[i];
        mangSHT[i] = mangSHT[viTriMin];
        mangSHT[viTriMin] = temp;
    }
}

