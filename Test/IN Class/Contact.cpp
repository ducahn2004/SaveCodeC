#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class Location {
public:
    std::string city;
    std::string address;

    Location(const std::string& city, const std::string& address)
        : city(city), address(address) {}
};

class Contact {
public:
    std::string name;
    std::string phoneNumber;
    Location location;

    Contact(const std::string& name, const std::string& phoneNumber, const Location& location)
        : name(name), phoneNumber(phoneNumber), location(location) {}
};

class PhoneBook {
private:
    std::vector<Contact> contacts;
    std::string filename;

public:
    PhoneBook(const std::string& filename) : filename(filename) {
        loadContacts();
    }

    // Thêm liên hệ mới vào danh bạ
    void addContact(const std::string& name, const std::string& phoneNumber, const std::string& city, const std::string& address) {
        Location location(city, address);
        Contact newContact(name, phoneNumber, location);
        contacts.push_back(newContact);
        saveContacts();
    }

    // Hiển thị tất cả các liên hệ trong danh bạ
    void displayContacts() {
        std::cout << "Danh bạ điện thoại:" << std::endl;
        for (const Contact& contact : contacts) {
            std::cout << "Tên: " << contact.name << ", Số điện thoại: " << contact.phoneNumber << ", Thành phố: " << contact.location.city << ", Địa chỉ: " << contact.location.address << std::endl;
        }
    }

    // Tìm kiếm liên hệ theo tên
    void searchContact(const std::string& name) {
        bool found = false;
        for (const Contact& contact : contacts) {
            if (contact.name == name) {
                std::cout << "Tìm thấy liên hệ: " << contact.name << ", Số điện thoại: " << contact.phoneNumber << ", Thành phố: " << contact.location.city << ", Địa chỉ: " << contact.location.address << std::endl;
                found = true;
            }
        }
        if (!found) {
            std::cout << "Không tìm thấy liên hệ với tên: " << name << std::endl;
        }
    }

    // Xóa liên hệ theo tên
    void deleteContact(const std::string& name) {
        for (auto it = contacts.begin(); it != contacts.end(); ++it) {
            if (it->name == name) {
                contacts.erase(it);
                saveContacts();
                std::cout << "Đã xóa liên hệ với tên: " << name << std::endl;
                return;
            }
        }
        std::cout << "Không tìm thấy liên hệ với tên: " << name << std::endl;
    }

    // Chỉnh sửa liên hệ theo tên
    void editContact(const std::string& name, const std::string& newPhoneNumber, const std::string& newCity, const std::string& newAddress) {
        for (auto& contact : contacts) {
            if (contact.name == name) {
                contact.phoneNumber = newPhoneNumber;
                contact.location.city = newCity;
                contact.location.address = newAddress;
                saveContacts();
                std::cout << "Đã chỉnh sửa liên hệ: " << contact.name << ", Số điện thoại mới: " << contact.phoneNumber << ", Thành phố mới: " << contact.location.city << ", Địa chỉ mới: " << contact.location.address << std::endl;
                return;
            }
        }
        std::cout << "Không tìm thấy liên hệ với tên: " << name << std::endl;
    }

    // Lưu danh bạ vào tệp tin
    void saveContacts() {
        std::ofstream file(filename);
        if (file.is_open()) {
            for (const Contact& contact : contacts) {
                file << contact.name << "," << contact.phoneNumber << "," << contact.location.city << "," << contact.location.address << std::endl;
            }
            file.close();
        }
    }

    // Đọc danh bạ từ tệp tin
    void loadContacts() {
        std::ifstream file(filename);
        if (file.is_open()) {
            std::string line;
            while (getline(file, line)) {
                size_t pos1 = line.find(",");
                size_t pos2 = line.find(",", pos1 + 1);
                size_t pos3 = line.find(",", pos2 + 1);
                if (pos1 != std::string::npos && pos2 != std::string::npos && pos3 != std::string::npos) {
                    std::string name = line.substr(0, pos1);
                    std::string phoneNumber = line.substr(pos1 + 1, pos2 - pos1 - 1);
                    std::string city = line.substr(pos2 + 1, pos3 - pos2 - 1);
                    std::string address = line.substr(pos3 + 1);
                    contacts.push_back(Contact(name, phoneNumber, Location(city, address)));
                }
            }
            file.close();
        }
    }
};

int main() {
    PhoneBook phoneBook("contacts.txt");

    while (true) {
        std::cout << "Chọn một tùy chọn:" << std::endl;
        std::cout << "1. Thêm liên hệ mới" << std::endl;
        std::cout << "2. Hiển thị danh bạ" << std::endl;
        std::cout << "3. Tìm kiếm liên hệ" << std::endl;
        std::cout << "4. Xóa liên hệ" << std::endl;
        std::cout << "5. Chỉnh sửa liên hệ" << std::endl;
        std::cout << "6. Thoát" << std::endl;

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string name, phoneNumber, city, address;
                std::cout << "Nhập tên liên hệ: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                std::cout << "Nhập số điện thoại: ";
                std::cin >> phoneNumber;
                std::cout << "Nhập thành phố: ";
                std::cin.ignore();
                std::getline(std::cin, city);
                                std::cout << "Nhập địa chỉ: ";
                std::getline(std::cin, address);
                phoneBook.addContact(name, phoneNumber, city, address);
                break;
            }
            case 2:
                phoneBook.displayContacts();
                break;
            case 3: {
                std::string name;
                std::cout << "Nhập tên cần tìm: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                phoneBook.searchContact(name);
                break;
            }
            case 4: {
                std::string name;
                std::cout << "Nhập tên liên hệ cần xóa: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                phoneBook.deleteContact(name);
                break;
            }
            case 5: {
                std::string name, newPhoneNumber, newCity, newAddress;
                std::cout << "Nhập tên liên hệ cần chỉnh sửa: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                std::cout << "Nhập số điện thoại mới: ";
                std::cin >> newPhoneNumber;
                std::cout << "Nhập thành phố mới: ";
                std::cin.ignore();
                std::getline(std::cin, newCity);
                std::cout << "Nhập địa chỉ mới: ";
                std::getline(std::cin, newAddress);
                phoneBook.editContact(name, newPhoneNumber, newCity, newAddress);
                break;
            }
            case 6:
                return 0;
            default:
                std::cout << "Tùy chọn không hợp lệ. Vui lòng chọn lại." << std::endl;
        }
    }
}

