#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <unistd.h>
#include<conio.h>
#include<dos.h>
#include<windows.h>
 
using namespace std;
 HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE); 
void main_menu()
{system("cls");
system("Color 80"); 
    char data[15];
    int n = 0, option = 0, count_n = 0;
    string empty = "00";
    string proctor = "";
    ifstream f("Example.txt");
    string line;
    for (int i = 0; std::getline(f, line); ++i) {
        count_n++;
    }
 
    while (option != 6) {
        cout << "\nAvailable operations: \n1. Add New "
                "Students\n2."
             << " Student Login\n3. Faculty Login\n4. "
                "Proctor Login\n5. Admin View\n"
             << "6. Exit\nEnter option: ";
        cin >> option;
 
        if (option == 1) {
            cout << "Enter the number of students: ";
            cin >> n;
 
            count_n = count_n + n;
 
            for (int i = 0; i < n; i++) {
                ofstream outfile;
                outfile.open("Example.txt", ios::app);
                cout << "Enter your registration number: ";
                cin >> data;
                outfile << data << "\t";
 
                cout << "Enter your name: ";
                cin >> data;
                int len = strlen(data);
 
                while (len < 15) {
                    data[len] = ' ';
                    len = len + 1;
                }
                outfile << data << "\t";
                outfile << empty << "\t";
                outfile << empty << "\t";
 
                cout << "Enter your proctor ID: ";
                cin >> proctor;
 
                outfile << proctor << endl;
            }
        }
 
        else if (option == 2) {
            char regno[9];
            cout << "Enter your registration number: ";
            cin >> regno;
            ifstream infile;
            int check = 0;
            infile.open("Example.txt", ios::in);
            while (infile >> data) {
                if (strcmp(data, regno) == 0) {
                    cout
                        << "\nRegistration Number: " << data
                        << endl;
                    infile >> data;
                    cout << "Name: " << data << endl;
 
                    infile >> data;
                    cout << "SUBCODE1 mark: " << data
                         << endl;
 
                    infile >> data;
                    cout << "SUBCODE2 mark: " << data
                         << endl;
 
                    infile >> data;
                    cout << "Proctor ID: " << data << endl;
 
                    infile.close();
                    check = 1;
                }
            }
 
            if (check == 0) {
                cout << "No such registration number found!"
                     << endl;
            }
        }
        else if (option == 3) {
            char subcode[7];
            cout << "Enter your subject code: ";
            cin >> subcode;
            string code1 = "SUBCODE1", code2 = "SUBCODE2",
                   mark = "";
            ifstream infile;
            int check = 0;
 
            cout << "\nAvailable operations: \n1. Add data "
                    "about marks\n"
                 << "2. View data\nEnter option: ";
            cin >> option;
 
            if (option == 1) {
                cout
                    << "Warning! You would need to add mark"
                    << "details for all the students!"
                    << endl;
                for (int i = 0; i < count_n; i++) {
                    fstream file("Example.txt"); 
                    if (strcmp(subcode, code1.c_str())
                        == 0) {
                        file.seekp(26 + 37 * i,
                                   std::ios_base::beg);
                        cout << "Enter the mark of student#"
                             << (i + 1) << " : ";
                        cin >> mark;
                        file.write(mark.c_str(), 2);
                    }
 
                    if (strcmp(subcode, code2.c_str())
                        == 0) {
                        file.seekp(29 + 37 * i,
                                   std::ios_base::beg);
                        cout << "Enter the mark of student#"
                             << (i + 1) << " : ";
                        cin >> mark;
                        file.write(mark.c_str(), 2);
                    }
                }
            }
 
            // This loop is used to view marks of a student.
            // The extra infile commands have been used to
            // get a specific mark only since the data has
            // been seperated by a tabspace.
 
            else if (option == 2) {
                infile.open("Example.txt", ios::in);
                if (strcmp(subcode, code1.c_str()) == 0) {
                    cout << "Registration number - Marks\n"
                         << endl;
                    while (infile >> data) {
                        cout << data;
                        infile >> data;
                        infile >> data;
                        cout << " - " << data << endl;
                        infile >> data;
                        infile >> data;
                        check = 1;
                    }
                }
 
                infile.close();
                infile.open("Example.txt", ios::in);
 
                if (strcmp(subcode, code2.c_str()) == 0) {
                    cout << "Registration number - Marks\n"
                         << endl;
                    while (infile >> data) {
                        cout << data;
                        infile >> data;
                        infile >> data;
                        infile >> data;
                        cout << " - " << data << endl;
                        infile >> data;
                        check = 1;
                    }
                }
            }
 
            infile.close();
 
            if (check == 0) {
                cout << "No such subject code found!"
                     << endl;
            }
        }
 
        
 
        else if (option == 4) {
            char procid[7];
            cout << "Enter your proctor ID: ";
            cin >> procid;
            int check = 0;
            char temp1[100], temp2[100], temp3[100];
            char temp4[100], id[100];
            ifstream infile;
            infile.open("Example.txt", ios::in);
 
            while (infile >> temp1) {
                infile >> temp2;
                infile >> temp3;
                infile >> temp4;
                infile >> id;
 
                if (strcmp(id, procid) == 0) {
                    cout << "\nRegistration Number: "
                         << temp1 << endl;
                    cout << "Name: " << temp2 << endl;
                    cout << "SUBCODE1 Mark: " << temp3
                         << endl;
                    cout << "SUBCODE2 Mark: " << temp4
                         << endl;
                    check = 1;
                }
            }
 
            if (check == 0) {
                cout << "No such proctor ID found!" << endl;
            }
        }
 
      
 
        else if (option == 5) {
            char password[25];
            cout << "Enter the admin password: ";
            cin >> password;
 
           
 
            string admin_pass = "admin";
 
            if (strcmp(password, admin_pass.c_str()) == 0) {
                cout << "Reg No.       "
                        "\tName\tSUBCODE1\tSUBCODE2\tProctor "
                        "ID"
                     << endl;
                ifstream infile;
                infile.open("Example.txt", ios::in);
                char data[20];
 
                while (infile >> data) {
                    cout << data << "\t";
                    infile >> data;
                    cout << data << "\t";
                    infile >> data;
                    cout << data << "\t";
                    infile >> data;
                    cout << data << "\t";
                    infile >> data;
                    cout << data << endl;
                }
            }
        }
    }
}
 void fontsize(int a, int b){  
  PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = new CONSOLE_FONT_INFOEX();  
  lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX);  
  GetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);  
  lpConsoleCurrentFontEx->dwFontSize.X = a;  
  lpConsoleCurrentFontEx->dwFontSize.Y = b;  
  SetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);  
 }  
int main()
{system("cls");
		system("Color 0B"); 
		fontsize(10, 18); 
	cout<<"\n\t\t\t*******************************************";
	cout<<"\n\t\t\t* STUDENT DATABASE MANAGEMENT SYSTEM *";
	cout<<"\n\t\t\t*******************************************\n\n";
    cout<<"\n\t\tMade By ::  Abhishek verma"<<endl;
    cout<<"\n\n\n\n\t\t\t\t---->>press any key ....!!";
   sleep(2);
    getch();
    main_menu();
	
}
