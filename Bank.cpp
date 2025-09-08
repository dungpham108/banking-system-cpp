#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include <windows.h>
using namespace std;

class bank {
private:
    float balance;
    string id, pass, pin, name, fname, address, phone;
public:
    void menu();
    void bank_management();
    void atm_management();
    void new_user();
    void already_user();
    void deposit();
    void withdraw();
    void transfer();
    void payment();
    void search_account();
    void edit();
    void del();
    void show_records();
    void show_payment();
    void user_balance();
    void withdraw_atm();
    void check_detail();
};

void bank::menu() {
p:
    system("cls");
    int n;
    char ch;
    string pin, pass, email;
    cout << "\n\n\t\t\tBANG CHUC NANG";
    cout << "\n\n 1. QUAN LY TAI KHOAN";
    cout << "\n 2. GIAO DICH ATM";
    cout << "\n 3. THOAT";
    cout << "\n\n Chon chuc nang: ";
    cin >> n;
    switch (n) {
    case 1:
        system("cls");
        cout << "\n\n\t\t\tDANG NHAP QUAN TRI";
        cout << "\n\n Email : ";
        cin >> email;
        cout << "\n\n\t\t Ma PIN (5 so): ";
        for (int i = 1; i <= 5; i++) {
            ch = _getch();
            pin += ch;
            cout << "*";
        }
        cout << "\n\n Mat khau (5 so): ";
        for (int i = 1; i <= 5; i++) {
            ch = _getch();
            pass += ch;
            cout << "*";
        }
        if (email == "dung@gmail.com" && pin == "13366" && pass == "14366") {
            bank_management();
        }
        else {
            cout << "\n\n Email, PIN hoac mat khau khong dung!";
        }
        break;
    case 2:
        atm_management();
        break;
    case 3:
        exit(0);
    default:
        cout << "\n\n VUI LONG NHAP LUA CHON HOP LE!";
    }
    _getch();
    goto p;
}

void bank::bank_management() {
p:
    system("cls");
    int n;
    cout << "\n\n\t\t\tHE THONG QUAN LY NGAN HANG";
    cout << "\n\n 1. Them tai khoan moi";
    cout << "\n 2. Tra cuu tai khoan";
    cout << "\n 3. Nap tien";
    cout << "\n 4. Rut tien";
    cout << "\n 5. Chuyen khoan";
    cout << "\n 6. Thanh toan hoa don";
    cout << "\n 7. Tim kiem tai khoan";
    cout << "\n 8. Sua thong tin tai khoan";
    cout << "\n 9. Xoa tai khoan";
    cout << "\n 10. Hien thi tat ca tai khoan";
    cout << "\n 11. Lich su giao dich";
    cout << "\n 12. Quay lai";
    cout << "\n\n Chon chuc nang: ";
    cin >> n;
    switch (n) {
    case 1:
        new_user();
        break;
    case 2:
        already_user();
        break;
    case 3:
        deposit();
        break;
    case 4:
        withdraw();
        break;
    case 5:
        transfer();
        break;
    case 6:
        payment();
        break;
    case 7:
        search_account();
        break;
    case 8:
        edit();
        break;
    case 9:
        del();
        break;
    case 10:
        show_records();
        break;
    case 11:
        show_payment();
        break;
    case 12:
        menu();
    default:
        cout << "VUI LONG NHAP LUA CHON HOP LE!";
    }
    _getch();
    goto p;
}

void bank::atm_management() {
p:
    system("cls");
    int n;
    cout << "\n\n\t\t\tHE THONG GIAO DICH ATM";
    cout << "\n\n 1. Dang nhap & Kiem tra so du";
    cout << "\n 2. Rut tien";
    cout << "\n 3. Xem thong tin tai khoan";
    cout << "\n 4. Quay lai";
    cout << "\n\n Chon chuc nang: ";
    cin >> n;
    switch (n) {
    case 1:
        user_balance();
        break;
    case 2:
        withdraw_atm();
        break;
    case 3:
        check_detail();
        break;
    case 4:
        menu();
    default:
        cout << "VUI LONG NHAP LUA CHON HOP LE!";
    }
    _getch();
    goto p;
}

void bank::new_user() {
p:
    system("cls");
    fstream file;
    float b;
    string n, f, pa, p, a, ph, i;
    cout << "\n\n\t\t\tTHEM NGUOI DUNG MOI";
    cout << "\n\n Ma tai khoan: ";
    cin >> id;
    cout << "\n\n Ho: ";
    cin >> name;
    cout << "\n\n Ten: ";
    cin >> fname;
    cout << "\n\n Dia chi: ";
    cin >> address;
    cin.ignore();
    getline(cin, address);
    cout << "\n\n Ma PIN (5 so): ";
    cin >> pin;
    cout << "\n\n Mat khau: ";
    cin >> pass;
    cout << "\n\n So dien thoai: ";
    cin >> phone;
    cout << "\n\n So du ban dau: ";
    cin >> balance;

    file.open("bank.txt", ios::in);
    if (!file) {
        file.open("bank.txt", ios::app | ios::out);
        file << " " << id << " " << name << " " << fname << " " << address
            << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
        file.close();
    }
    else {
        file >> i >> n >> f >> a >> p >> pa >> ph >> b;
        while (!file.eof()) {
            if (i == id) {
                cout << "\n\n Ma tai khoan da ton tai!";
                _getch();
                goto p;
            }
            file >> i >> n >> f >> a >> p >> pa >> ph >> b;
        }
        file.close();
        file.open("bank.txt", ios::app | ios::out);
        file << " " << id << " " << name << " " << fname << " " << address
            << " " << pin << " " << pass << " " << phone << " " << balance << endl;
        file.close();
    }
    cout << "\n\n Them tai khoan thanh cong!";
}

void bank::already_user() {
    system("cls");
    fstream file;
    string t_id;
    int found = 0;
    cout << "\n\nTRA CUU TAI KHOAN";
    file.open("bank.txt", ios::in);
    if (!file) {
        cout << "\n\n Loi khi mo file!";
    }
    else {
        cout << "\n\nNhap ma tai khoan: ";
        cin >> t_id;
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        while (!file.eof()) {
            if (t_id == id) {
                cout << "\n\n Ma ID: " << id << " Ma Pin: " << pin << " Mat khau: " << pass;
                found++;
                break;
            }
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        }
        file.close();
        if (found == 0) {
            cout << "\n\n KHONG TIM THAY TAI KHOAN!";
        }
    }
}

void bank::withdraw() {
    fstream file, file1;
    string t_id;
    float with;
    int found = 0;
    system("cls");
    cout << "\n\n\t\t\tRUT TIEN";
    file.open("bank.txt", ios::in);
    file1.open("bank1.txt", ios::out);
    if (!file) {
        cout << "\n\nLoi khi mo file!";
    }
    else {
        cout << "\n\nNhap ma tai khoan: ";
        cin >> t_id;
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        while (!file.eof()) {
            if (t_id == id) {
                cout << "\n\nNhap so tien can rut: ";
                cin >> with;
                if (with <= balance) {
                    balance -= with;
                    cout << "\n\n\t\t\tSo tien " << with << " da duoc rut thanh cong!";
                    cout << "\n\n\t\t\tBien dong so du: " << balance;
                }
                else {
                    file1 << " " << id << " " << name << " " << fname << " " << address
                        << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
                    cout << "\n\n\t\t\tSo du hien tai cua ban la " << balance
                        << " (khong du de rut)";
                }
                found++;
            }
            file1 << " " << id << " " << name << " " << fname << " " << address
                << " " << pin << " " << pass << " " << phone << " " << balance << endl;

            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt", "bank.txt");
        if (found == 0) {
            cout << "\n\n KHONG TIM THAY TAI KHOAN!";
        }
    }
}

void bank::transfer() {
    fstream file, file1, history;
    string s_id, r_id;
    float amount;
    bool senderFound = false, receiverFound = false;
    float senderBalance = 0.0;

    system("cls");
    cout << "\n\n\t\t\tCHUYEN TIEN";

    file.open("bank.txt", ios::in);
    if (!file) {
        cout << "\n\nLoi khi mo file!";
        return;
    }

    cout << "\n\nNhap ma tai khoan nguoi gui: ";
    cin >> s_id;
    cout << "Nhap ma tai khoan nguoi nhan: ";
    cin >> r_id;
    cout << "Nhap so tien can chuyen: ";
    cin >> amount;

    while (file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance) {
        if (id == s_id) {
            senderFound = true;
            senderBalance = balance;
        }
        if (id == r_id) {
            receiverFound = true;
        }
    }
    file.close();

    if (!senderFound) {
        cout << "\n\nKhong tim thay tai khoan nguoi gui!";
        return;
    }
    if (!receiverFound) {
        cout << "\n\nKhong tim thay tai khoan nguoi nhan!";
        return;
    }
    if (senderBalance < amount) {
        cout << "\n\nSo du khong du de chuyen tien!";
        return;
    }

    file.open("bank.txt", ios::in);
    file1.open("bank1.txt", ios::out);
    while (file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance) {
        if (id == s_id) {
            balance -= amount;
        }
        else if (id == r_id) {
            balance += amount;
        }
        file1 << id << " " << name << " " << fname << " " << address
            << " " << pin << " " << pass << " " << phone << " " << balance << endl;
    }
    file.close();
    file1.close();

    remove("bank.txt");
    rename("bank1.txt", "bank.txt");

    SYSTEMTIME x;
    GetLocalTime(&x);
    history.open("payment.txt", ios::app | ios::out);
    history << s_id << " CHUYEN -" << amount << " "
        << x.wYear << "-" << x.wMonth << "-" << x.wDay << "_"
        << x.wHour << ":" << x.wMinute << ":" << x.wSecond << endl;
    history << r_id << " NHAN +" << amount << " "
        << x.wYear << "-" << x.wMonth << "-" << x.wDay << "_"
        << x.wHour << ":" << x.wMinute << ":" << x.wSecond << endl;
    history.close();

    cout << "\n\nChuyen tien thanh cong!";
}

void bank::deposit() {
    fstream file, file1;
    string t_id;
    float dep;
    int found = 0;
    system("cls");
    cout << "\n\n\t\t\tNAP TIEN";
    file.open("bank.txt", ios::in);
    file1.open("bank1.txt", ios::out);
    if (!file) {
        cout << "Loi khi mo file!";
    }
    else {
        cout << "\n\nNhap ma tai khoan: ";
        cin >> t_id;
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        while (!file.eof()) {
            if (t_id == id) {
                cout << "\n\nNhap so tien can nap: ";
                cin >> dep;
                balance += dep;
                cout << "\n\n\t\t\tSo tien " << dep << " da duoc nap thanh cong!" << endl;
                cout << "\n\n\t\t\tBien dong so du " << balance;
                found++;
            }
            file1 << " " << id << " " << name << " " << fname << " " << address
                << " " << pin << " " << pass << " " << phone << " " << balance << endl;

            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt", "bank.txt");
        if (found == 0) {
            cout << "\n\n KHONG TIM THAY TAI KHOAN!";
        }
    }
}

void bank::payment() {
    system("cls");
    string t_id, b_name;
    float amount;
    int found = 0;
    SYSTEMTIME x;
    fstream file, file1, paymentFile;

    cout << "\n\n\t\t\t=== CHUC NANG THANH TOAN HOA DON ===";
    file.open("bank.txt", ios::in);

    if (!file) {
        cout << "\n\n Loi khi mo file bank.txt!";
        return;
    }

    cout << "\n\nNhap User ID: ";
    cin >> t_id;
    cout << "Nhap ten hoa don (VD: Dien, Nuoc, Internet): ";
    cin >> b_name;
    cout << "Nhap so tien thanh toan: ";
    cin >> amount;

    file1.open("bank1.txt", ios::out);

    file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
    while (!file.eof()) {
        if (t_id == id) {
            if (amount <= balance) {
                balance -= amount;
                found = 1;

                cout << "\n\nThanh toan thanh cong!";
                cout << "\nSo du con lai: " << balance << " VND";

                file1 << " " << id << " " << name << " " << fname << " " << address
                    << " " << pin << " " << pass << " " << phone << " " << balance << endl;

                GetSystemTime(&x);
                paymentFile.open("payments.txt", ios::app);
                paymentFile << t_id << " " << b_name << " " << amount << " "
                    << x.wDay << "/" << x.wMonth << "/" << x.wYear << endl;
                paymentFile.close();
            }
            else {
                cout << "\n\nSo du khong du de thanh toan!";
                file1 << " " << id << " " << name << " " << fname << " " << address
                    << " " << pin << " " << pass << " " << phone << " " << balance << endl;
            }
        }
        else {
            file1 << " " << id << " " << name << " " << fname << " " << address
                << " " << pin << " " << pass << " " << phone << " " << balance << endl;
        }
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
    }

    file.close();
    file1.close();
    remove("bank.txt");
    rename("bank1.txt", "bank.txt");

    if (found == 0) {
        cout << "\n\nKhong tim thay User ID!";
    }
    _getch();
}

void bank::search_account() {
    system("cls");
    fstream file;
    string t_id;
    int found = 0;

    cout << "\n\n\t\t\tTIM KIEM TAI KHOAN";
    file.open("bank.txt", ios::in);
    if (!file) {
        cout << "\n\nLoi khi mo file!";
    }
    else {
        cout << "\n\nNhap ma tai khoan can tim: ";
        cin >> t_id;

        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        while (!file.eof()) {
            if (t_id == id) {
                system("cls");
                cout << "\n\n\t\t\tTHONG TIN TAI KHOAN";
                cout << "\n\n Ma tai khoan : " << id;
                cout << "\n Ho : " << name;
                cout << "\n Ten : " << fname;
                cout << "\n Dia chi : " << address;
                cout << "\n So dien thoai : " << phone;
                cout << "\n So du hien tai : " << balance;
                found = 1;
                break;
            }
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        }
        file.close();

        if (found == 0) {
            cout << "\n\nKHONG TIM THAY TAI KHOAN!";
        }
    }
}

void bank::edit() {
    system("cls");
    fstream file, file1;
    string t_id;
    int found = 0;

    cout << "\n\n\t\t\tSUA THONG TIN TAI KHOAN";
    file.open("bank.txt", ios::in);
    if (!file) {
        cout << "\n\nLoi khi mo file!";
    }
    else {
        cout << "\n\nNhap ma tai khoan can chinh sua: ";
        cin >> t_id;

        file1.open("bank1.txt", ios::app | ios::out);
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;

        while (!file.eof()) {
            if (t_id == id) {
                cout << "\n\n Ho moi: ";
                cin >> name;
                cout << "\n\n Ten moi: ";
                cin >> fname;
                cout << "\n\n Dia chi moi: ";
                cin >> address;
                cin.ignore();
                getline(cin, address);
                cout << "\n\n Ma PIN (5 so) moi: ";
                cin >> pin;
                cout << "\n\n Mat khau moi: ";
                cin >> pass;
                cout << "\n\n So dien thoai moi: ";
                cin >> phone;

                file1 << " " << id << " " << name << " " << fname << " " << address
                    << " " << pin << " " << pass << " " << phone << " " << balance << endl;

                cout << "\n\n\t\tThong tin tai khoan da duoc cap nhat!";
                found = 1;
            }
            else {
                file1 << " " << id << " " << name << " " << fname << " " << address
                    << " " << pin << " " << pass << " " << phone << " " << balance << endl;
            }
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        }

        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt", "bank.txt");

        if (found == 0) {
            cout << "\n\nKHONG TIM THAY TAI KHOAN!";
        }
    }
}


void bank::del() {
    system("cls");
    fstream file, file1;
    string t_id;
    int found = 0;

    cout << "\n\n\t\t\tXOA TAI KHOAN";
    file.open("bank.txt", ios::in);
    if (!file) {
        cout << "\n\nLoi khi mo file!";
    }
    else {
        cout << "\n\nNhap ma tai khoan can xoa: ";
        cin >> t_id;

        file1.open("bank1.txt", ios::app | ios::out);
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;

        while (!file.eof()) {
            if (t_id == id) {
                cout << "\n\nTai khoan co ID " << id << " da duoc xoa!";
                found = 1;
            }
            else {
                file1 << " " << id << " " << name << " " << fname << " " << address
                    << " " << pin << " " << pass << " " << phone << " " << balance << endl;
            }
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        }

        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt", "bank.txt");

        if (found == 0) {
            cout << "\n\nKHONG TIM THAY TAI KHOAN!";
        }
    }
}

void bank::show_records() {
    system("cls");
    fstream file;
    int count = 0;

    cout << "\n\n\t\t\tDANH SACH TAT CA TAI KHOAN\n";

    file.open("bank.txt", ios::in);
    if (!file) {
        cout << "\n\nLoi khi mo file!";
    }
    else {
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        while (!file.eof()) {
            cout << "\n------------------------------------------";
            cout << "\n Ma tai khoan : " << id;
            cout << "\n Ho           : " << name;
            cout << "\n Ten          : " << fname;
            cout << "\n Dia chi      : " << address;
            cout << "\n PIN          : " << pin;
            cout << "\n Mat khau     : " << pass;
            cout << "\n So dien thoai: " << phone;
            cout << "\n So du        : " << balance;
            cout << "\n------------------------------------------\n";
            count++;

            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        }
        file.close();

        if (count == 0) {
            cout << "\n\nKHONG CO TAI KHOAN NAO TRONG HE THONG!";
        }
    }
}


void bank::show_payment() {
    system("cls");
    fstream file;
    string t_id, acc_id, trans_type, date_time;
    float amount;
    int found = 0;

    cout << "\n\n\t\t\tLICH SU GIAO DICH";
    file.open("payment.txt", ios::in);

    if (!file) {
        cout << "\n\nKhong the mo file payment.txt hoac chua co giao dich nao!";
        return;
    }

    cout << "\n\nNhap ma tai khoan de xem lich su giao dich: ";
    cin >> t_id;

    cout << "\n\n-------------------------------------------------------------";
    cout << "\nMa TK\tLoai GD\t\tSo tien\t\tThoi gian";
    cout << "\n-------------------------------------------------------------";

    while (file >> acc_id >> trans_type >> amount) {
        getline(file, date_time);

        if (t_id == acc_id) {
            cout << "\n" << acc_id << "\t" << trans_type << "\t\t"
                << amount << "\t\t" << date_time;
            found = 1;
        }
    }

    file.close();

    if (found == 0) {
        cout << "\n\nKhong tim thay lich su giao dich cho tai khoan: " << t_id;
    }

    cout << "\n-------------------------------------------------------------\n";
}

void bank::user_balance() {
    system("cls");
    fstream file;
    string t_id, t_pin, t_pass;
    char ch;
    bool found = false;

    cout << "\n\n\t\t\tDANG NHAP & KIEM TRA SO DU\n";

    file.open("bank.txt", ios::in);
    if (!file) {
        cout << "\n\nLoi: khong the mo file du lieu!";
        return;
    }

    cout << "\nNhap ma ID: ";
    cin >> t_id;

    cout << "\nNhap ma PIN (5 so): ";
    t_pin.clear();
    for (int i = 0; i < 5; i++) {
        ch = _getch();
        t_pin += ch;
        cout << "*";
    }

    cout << "\nNhap mat khau (5 ky tu): ";
    t_pass.clear();
    for (int i = 0; i < 5; i++) {
        ch = _getch();
        t_pass += ch;
        cout << "*";
    }

    while (file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance) {
        if (t_id == id && t_pin == pin && t_pass == pass) {
            cout << "\n\n-------------------------------------------";
            cout << "\nXin chao, " << name << " " << fname;
            cout << "\nSo du hien tai cua ban la: " << balance << " VND";
            cout << "\n-------------------------------------------\n";
            found = true;
            break;
        }
    }

    file.close();

    if (!found) {
        cout << "\n\nThong tin dang nhap khong chinh xac!";
    }
}

void bank::withdraw_atm() {
    fstream file, file1;
    string t_id, t_pass, t_pin;
    float with;
    char ch;
    int found = 0;
    system("cls");
    cout << "\n\n\t\t\tRUT TIEN";
    file.open("bank.txt", ios::in);
    file1.open("bank1.txt", ios::out);
    if (!file) {
        cout << "\n\nLoi khi mo file!";
    }
    else {
        cout << "\n\nNhap ma tai khoan: ";
        cin >> t_id;
        cout << "\nNhap ma PIN (5 so): ";
        for (int i = 0; i < 5; i++) {
            ch = _getch();
            t_pin += ch;
            cout << "*";
        }

        cout << "\nNhap mat khau (5 ky tu): ";
        t_pass.clear();
        for (int i = 0; i < 5; i++) {
            ch = _getch();
            t_pass += ch;
            cout << "*";
        }
        file1.open("bank1.txt", ios::app | ios::out);
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        while (!file.eof()) {
            if (t_id == id && t_pin == pin && t_pass == pass) {
                cout << "\n\nNhap so tien can rut: ";
                cin >> with;
                if (with <= balance) {
                    balance -= with;
                    cout << "\n\n\t\t\tSo tien " << with << " da duoc rut thanh cong!";
                    cout << "\n\n\t\t\tBien dong so du: " << balance;
                }
                else {
                    file1 << " " << id << " " << name << " " << fname << " " << address
                        << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
                    cout << "\n\n\t\t\tSo du hien tai cua ban la " << balance
                        << " (khong du de rut)";
                }
                found++;
            }
            file1 << " " << id << " " << name << " " << fname << " " << address
                << " " << pin << " " << pass << " " << phone << " " << balance << endl;

            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt", "bank.txt");
        if (found == 0) {
            cout << "\n\n KHONG TIM THAY TAI KHOAN!";
        }
    }
}

void bank::check_detail() {
    fstream file;
    string t_id, t_pass, t_pin;
    float with;
    char ch;
    int found = 0;
    system("cls");
    cout << "\n\n\t\t\tXEM THONG TIN TAI KHOAN";
    file.open("bank.txt", ios::in);
    if (!file) {
        cout << "\n\nLoi khi mo file!";
    }
    else {
        cout << "\n\nNhap ma tai khoan: ";
        cin >> t_id;
        cout << "\nNhap ma PIN (5 so): ";
        for (int i = 0; i < 5; i++) {
            ch = _getch();
            t_pin += ch;
            cout << "*";
        }

        cout << "\nNhap mat khau (5 ky tu): ";
        t_pass.clear();
        for (int i = 0; i < 5; i++) {
            ch = _getch();
            t_pass += ch;
            cout << "*";
        }
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        while (!file.eof()) {
            if (t_id == id && t_pin == pin && t_pass == pass) {
                system("cls");
                cout << "\n------------------------------------------";
                cout << "\n Ma tai khoan : " << id;
                cout << "\n Ho           : " << name;
                cout << "\n Ten          : " << fname;
                cout << "\n Dia chi      : " << address;
                cout << "\n PIN          : " << pin;
                cout << "\n Mat khau     : " << pass;
                cout << "\n So dien thoai: " << phone;
                cout << "\n So du        : " << balance;
                cout << "\n------------------------------------------\n";
                found++;
            }
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        }
        file.close();

        if (found == 0) {
            cout << "\n\nKhong tim thay tai khoan";
        }
    }
}

int main() {
    bank obj;
    obj.menu();
    return 0;
}
