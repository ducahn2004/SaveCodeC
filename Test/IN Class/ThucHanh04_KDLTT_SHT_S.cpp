#include <iostream>

using namespace std;

struct SoHuuTy
{
	int tuSo;
	int mauSo;
};
typedef struct SoHuuTy SHT;

void nhapSHT(SHT *);
void inSHT(const SHT *);
void toiGianSHT(SHT *);
SHT* congSHT(const SHT *, const SHT *);
int soSanhSHT(const SHT *, const SHT *);
void sapXepLuaChonMangSHT(SHT *, int);

int main()
{
	// cap phat bo nho dong cho con tro toi mot so huu ti
	SHT * sht1 = new SHT;
    SHT * sht2 = new SHT;
    SHT * tongSHT = new SHT;

	// cap phat bo nho dong cho mang cac so huu ti
	SHT * mangSHT = new SHT[100];

    nhapSHT(sht1);
    inSHT(sht1); cout << endl;

    nhapSHT(sht2);
    inSHT(sht2); cout << endl;

    tongSHT = congSHT(sht1, sht2);
    inSHT(tongSHT);

	return 0;
}

void nhapSHT(SHT * sht)
{
    cin >> sht->tuSo >> sht->mauSo;
    toiGianSHT (sht);
}

void inSHT(const SHT *sht)
{
    cout << sht->tuSo << "/" << sht->mauSo;
}

void toiGianSHT(SHT * sht)
{
    int a = sht->tuSo;
    int b = sht->mauSo;
    int r;
    while (a > 0 && b > 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    r = a + b;
    sht->tuSo /= r;
    sht->mauSo /= r;
}

SHT * congSHT(const SHT * sht1, const SHT * sht2)
{
	SHT * tongSHT = new SHT;
	tongSHT->tuSo = sht1->tuSo * sht2->mauSo + sht1->mauSo * sht2->tuSo;
	tongSHT->mauSo = sht1->mauSo * sht2->mauSo;
	toiGianSHT(tongSHT);
	return tongSHT;
}

// tra ve 1 neu sht1 > sht2
// tra ve 0 neu sht1 = sht2
// tra ve -1 neu sht1 < sht2
int soSanhSHT(const SHT * sht1, const SHT * sht2)
{
    return ( ((double)sht1->tuSo / sht1->mauSo) < ((double)sht2->tuSo / sht2->mauSo) );
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

