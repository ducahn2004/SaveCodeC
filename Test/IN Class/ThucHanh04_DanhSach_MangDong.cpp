#include <iostream>
#include <fstream>
#include <assert.h>
using namespace std;

struct DArrayList
{
public:
    DArrayList(); // Khoi tao danh sach rong
    DArrayList(int arrayList[], int noElement); // Khoi tao DS bang du lieu luu trong mang a
    DArrayList(char * fileName); // Khoi tao DS bang du lieu luu trong tep filename
    DArrayList(const DArrayList & someList); // Ham kien tao sao chep (copy constructor)
    ~DArrayList(); // Ham huy (destructor)

    DArrayList operator=(const DArrayList & someList); // Nap chong phep gan
    bool empty() const; // Kiem tra DS rong hay khong
    int length() const; // Xac dinh do dai DS
    void insert(int index, const int value); // Xen gia tri x vao vi tri i trong DS
    void append(const int value); // Them x vao duoi DS
    void erase(int index); // Loai khoi DS phan tu o vi tri i
    int& at(int index); // Tra ve tham chieu toi phan tu o vi tri i
    void print() const; // In ra man hinh toan bo DS
private:
    int * element; // Mang dong element luu toan bo DS
    int last; // chi so cua phan tu cuoi cung
    int size; // kich thuoc (so phan tu toi da) cua mang element
};

// 1. Ham khoi tao danh sach rongs
DArrayList::DArrayList()
{
    last = -1;
    size = 100;
    element = new int[size];
}

DArrayList::~DArrayList()
{
    if (element)
    {
        delete [] element;
        element = NULL;
    }
    last = -1;
    size = 0;
}
// 2. Ham khoi tao danh sach bang du lieu luu trong mang so nguyen khac
DArrayList::DArrayList(int arrayList[], int noElement)
{
    last = -1;
    size = 100;
    element = new int[size];
    // Viet code cua ban o day ...
    if(noElement > size){
        delete element;
        element = new int[noElement + 1];
    }

    for(int i = 0; i < noElement; i++){
        element[i] = arrayList[i];
        last++;
    }
}

// 3. Ham khoi tao danh sach bang du lieu luu trong tep van ban
DArrayList::DArrayList(char * filename)
{
    ifstream inputFile(filename); // mo tep van ban 

    if(!inputFile){
        cerr << "Cannot Open this file" << filename << endl;
        return;
    }
    last = -1;
    size = 100;
    element = new int[size];

    string line;
    while(getline(inputFile,line)){
        int dataItem = stoi(line);
        if(last + 1 >= size){
            int newSize = size * 2;
            int *newElement = new int[newSize];
            for(int i = 0; i <= last; i++){
                newElement[i] = element[i];
            }
            delete[] element;
            element = newElement;
            size = newSize;
        }
        last++;
        element[last] = dataItem;
    }
    inputFile.close();

}

DArrayList::DArrayList(const DArrayList & someList)
{
    size = someList.size;
    last = someList.last;
    element = new int[size];
    for(int i = 0; i <= last; i++){
        element[i] = someList.element[i];
    }
}

DArrayList DArrayList::operator=(const DArrayList & someList)
{
    if(this == &someList){
        // Tránh trường hợp tự gán bản thân với bản thân
        return *this;
    }
    delete[] element;

    // Sao chép kích thước danh sách
    size = someList.size;
    last = someList.last;

    // Cấp phát bộ nhớ mới và sao chép dữ liệu từ danh sách someList
    element = new int[size];
    for (int i = 0; i <= last; i++) {
        element[i] = someList.element[i];
    }
    return *this;
}

// 4. Ham kiem tra danh sach co rong khong
bool DArrayList::empty() const
{
    return last == -1;
}

// 5. Ham xac dinh do dai danh sach
int DArrayList::length() const
{
    return last + 1;
}

// 6. Ham chen gia tri value vao vi tri index trong danh sach
void DArrayList::insert(int index, const int value)
{
    if(last + 1 >= size){
        int newSize = size + 10;
        int *newElement = new int[newSize];
        for(int i = 0; i <= last; i++){
            newElement[i] = element[i];
        }
        delete[] element;
        element = newElement;
        size = newSize;
    }
    for(int i = last + 1; i > index; i--){
        element[i] = element[i - 1];
    }
    element[index] = value;
    last++;
}

// 7. Ham chen gia tri value vao cuoi danh sach
void DArrayList::append(const int value)
{
    if(last + 1 >= size){
        int newSize = size + 10;
        int *newElement = new int[newSize];
        for(int i = 0; i <= last; i++){
            newElement[i] = element[i];
        }
        delete[] element;
        element = newElement;
        size = newSize;
    }
    last++;
    element[last] = value;
}

// 8. Ham loai khoi danh sach phan tu o vi tri index
void DArrayList::erase(int index)
{
    for(int i = index; i <= last; i++){
        element[i] = element[i+1];  
    }
    last--;
}

// 9. Ham tra ve tham chieu toi phan tu o vi tri index
int& DArrayList::at(int index)
{
    assert(last >= 0 && index <= last && index >= 0);
    return element[index];
}

// 10. Ham in ra man hinh toan bo danh sach
void DArrayList::print() const
{
    for(int i = 0; i <= last; i++){
        cout << element[i] << " ";
    }
}

void testappend(DArrayList & someList, const int value)
{
    cout << "Danh sach truoc khi append " << value << endl;
    someList.print(); cout << endl;
    someList.append(value);
    cout << "Danh sach sau khi append " << value << endl;
    someList.print(); cout << endl << endl;
}

void testinsert(DArrayList & someList, int index, const int value)
{
    cout << "Danh sach truoc khi insert " << value << " vao vi tri " << index << endl;
    someList.print(); cout << endl;
    someList.insert(index, value);
    cout << "Danh sach sau khi insert " << value << " vao vi tri " << index << endl;
    someList.print(); cout << endl << endl;
}

void testerase(DArrayList & someList, int index)
{
    cout << "Danh sach truoc khi erase tai vi tri " << index << endl;
    someList.print(); cout << endl;
    someList.erase(index);
    cout << "Danh sach sau khi erase tai vi tri " << index << endl;
    someList.print(); cout << endl << endl;
}

int main()
{
    cout << "Chuong trinh test KDLTT danh sach so nguyen" << endl;
    cout << "Tac gia: [Your name please]\n 22022171" << endl;

    DArrayList L1; L1.print(); cout << endl;

    testappend(L1, 3);
    testappend(L1, 4);
    testappend(L1, 5);
    testinsert(L1, 0, 2);
    testinsert(L1, 0, 1);
    testinsert(L1, 2, 3);

    DArrayList L2;
    testappend(L2, 4);
    testappend(L2, 4);
    testappend(L2, 1);
    testerase(L2, 2);
    testinsert(L2, 1, 5);
    testinsert(L2, 2, 3);

    cout << "L2.at(3): " << L2.at(3) << endl;
    L2.print(); cout << endl;

    // cout << "\nL3: input.txt" << endl;
    // DArrayList L3("input.txt");
    // L3.print(); cout << endl;

    char nameFile[] = "ThucHanh04_DanhSach_MangDong_Input.txt";
    cout << "\nL3: ThucHanh04_DanhSach_MangDong_Input.txt" << endl;
    DArrayList L3(nameFile);
    L3.print(); cout << endl;


    cout << "\nL4(L3); L4.insert(0, 10);" << endl;
    DArrayList L4(L3);
    L4.insert(0, 10);
    L4.print();
    cout << endl;

    cout << "\nL4 = L1" << endl;
    L4 = L1;
    L4.print();
    cout << endl;

    return 0;
}
