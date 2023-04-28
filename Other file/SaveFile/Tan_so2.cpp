#include <stdio.h>

/*
Cho mot day so nguyen n phan tu. Dem so lan xuat hien cua cac
phan tu trong mang va in ra phan tu co so lan xuat hien nhieu
nhat
*/

int main() {
	int n;
	scanf("%d", &n);
	int arr[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	int a[n];
	int b[n];
	int index = -1;
	//Index la chi so cua mot cuoi cung da duoc su dung trong mang a va b
	for (int i = 0; i < n; i++) {
		//Kiem tra arr[i] da duoc dien vao mang a chua?
		//Duyet tu 0 -> index trong mang b xem co phan tu nao
		//bang arr[i] hay khong?
		int daXuatHien = 0;
		for (int j = 0; j <= index; j++) {
			//j la de chay mang a va b
			//a[j] kiem tra cac so da duoc dien phia truoc co bang arr[i] la
			//so dang can kiem tra hay khong
			if (a[j] == arr[i]) {
				//Da duoc dien truoc/da xuat hien truoc do roi
				b[j] += 1;
				daXuatHien = 1;
			}
		}
		if (daXuatHien == 0) {
			//Neu chua xuat hien, tao them mot o trong mang a va b
			index += 1;
			a[index] = arr[i];
			b[index] = 1;
		}
	}
	//Duyet xong mang thi duoc mang a va b.
	//Trong do b[i] la so lan xuat hien cua a[i] trong mang
	//Di tim so lon nhat trong mang b ~ so lan xuat hien lon nhat
	//Kich thuoc cua mang b: Index
	int maxFreq = 0;
	for (int i = 0; i <= index; i++)
		if (b[i] > maxFreq)
			maxFreq = b[i];
	//Duyet lai mang b, neu b[i] == maxFreq -> in ra a[i]
	for (int i = 0; i <= index; i++)
		if (b[i] == maxFreq)
			printf("%d\n", a[i]);
}
