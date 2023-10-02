#include <iostream>
#include <algorithm> 
#include <math.h>
using namespace std;

struct dathuc
{
    int bac;
    int heso[10];
};
typedef struct dathuc DaThuc;

void nhapDT(DaThuc *);
void inDT(const DaThuc *);
DaThuc * congDT(const DaThuc *, const DaThuc *);
double giaTriDT(const DaThuc *, double);

int main()
{
    DaThuc * dt1 = new DaThuc;
    DaThuc * dt2 = new DaThuc;
    DaThuc * tongDT = new DaThuc;

    nhapDT(dt1);
    inDT(dt1);

    nhapDT(dt2);
    inDT(dt2);

    tongDT = congDT(dt1, dt2);
    inDT(tongDT);

    double x = 3.5;
    cout << giaTriDT(tongDT, x);

    return 0;
}

void nhapDT(DaThuc * dt){
    cin >> dt->bac;
    int n;  
    for(int i = dt->bac;i>=0; i--){
        cout << "Da thuc bac " << i << " "; 
        cin >> n;
        dt->heso[i] = n;
    }
    for(int i = dt->bac+1; i < 10; i++){
        dt->heso[i] = 0;
    }
}

void inDT(const DaThuc * dt){
    for(int i = dt->bac;i>=0; i--){ 
        cout << dt->heso[i] << "x" << i << " ";
    }
    cout << endl;
}

DaThuc * congDT(const DaThuc * dt1, const DaThuc * dt2){
    // gia tri tra ve la tong 2 so huu ti DT1 va DT2
	// can cap phat bo nho dong cho bien tong cua 2 so huu ti
	// sau do tra con tro nay ve
	DaThuc * tongDT = new DaThuc;
    tongDT->bac = max(dt1->bac,dt2->bac);

    for(int i = 0; i <= tongDT->bac; i++){
        tongDT->heso[i] = dt1->heso[i] + dt2->heso[i];
    }
    // tongDT = dt1 + dt2;
	return tongDT;
}

double giaTriDT(const DaThuc * dt, double x)
{
    double result = 0;
    for(int i = 0; i <= dt->bac; i++){
        result += dt->heso[i]*pow(x,i);
    }
    return result;
}
