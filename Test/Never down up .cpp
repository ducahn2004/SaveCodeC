#include <iostream>
#include <vector>
#include <algorithm>

struct Student {
    int index;
    int height;
    bool isMale;
};

bool compareStudents(const Student& s1, const Student& s2) {
    if (s1.isMale != s2.isMale) {
        return s1.isMale < s2.isMale; // Các bạn nữ đứng trước các bạn nam
    } else if (s1.height != s2.height) {
        return s1.height < s2.height; // Người có chiều cao thấp hơn đứng trước
    } else {
        return s1.index < s2.index; // Người có số thứ tự nhỏ hơn đứng trước
    }
}

std::vector<int> arrangeStudents(int n, const std::vector<int>& heights) {
    std::vector<Student> students;
    for (int i = 0; i < n; i++) {
        Student student;
        student.index = i + 1;
        student.height = heights[i];
        student.isMale = (i % 2 == 0); // Số thứ tự lẻ là nữ, số thứ tự chẵn là nam
        students.push_back(student);
    }
    
    std::sort(students.begin(), students.end(), compareStudents); // Sắp xếp danh sách sinh viên
    
    std::vector<int> result;
    for (const auto& student : students) {
        result.push_back(student.index);
    }
    
    return result;
}

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        std::cin >> heights[i];
    }
    
    std::vector<int> result = arrangeStudents(n, heights);
    
    for (int i = 0; i < n; i++) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
/*Toàn bộ sinh viên nam của lớp giáo dục thể chất có số thứ tự trong danh sách lớp là số lẻ, 
còn lại các sinh viên nữ có số thứ tự là số chẵn. Giảng viên muốn các bạn sinh viên xếp thành một hàng dài.
Trong đó các bạn nữ đứng trước các bạn nam, và người có chiều cao thấp hơn sẽ được đứng trước 
(nếu bằng nhau thì người có số thứ tự nhỏ hơn đứng trước). Danh sách lớp đã có chiều cao của các sinh viên
trong lớp, giảng viên muốn gọi các bạn sinh viên theo số thứ tự để lên xếp hàng. Hãy viết chương trình 
giúp giảng viên thực hiện việc này.

Đầu vào: số nguyên n
 là sĩ số lớp và n
 số nguyên tiếp theo là chiều cao tính bằng centimét của các sinh viên trong lớp (được sắp theo số thứ tự, số thứ tự bắt đầu từ 1).

Đầu ra: số thứ tự của các sinh viên để sắp thành hàng, cách nhau bởi dấu cách.  C++*/