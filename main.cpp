//Final project for Introduction to Programing in C++
// Course ID: COP1334-2227-1851
// Professor: George Gabb
// Student: Vicente Ernesto Tejeda Sanchez
// Institution: Miami Dade College

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "play.cpp"
#include "auth.cpp"
using namespace std;

string g_username, g_password;
string l_username, l_password;
user logued_user(" "," ");
bool logued_in;


void login() // this will perform a validation
{
    cout<<"         Username: ";
    cin >> l_username;
    cout<<"         Password: ";
    cin >> l_password; 
    system("clear");
    logued_user.set_username(l_username);
    logued_user.set_password(l_password);
    logued_in = logued_user.validate_data();
    if (logued_in == false){
        cout << "No credentials were found :( \n";
    }
}
void logout(){
    system("clear");
    logued_in = false;
}



void register_new_account(){ 
    cout<<"         Register new account: \n";
    cout<<"         Username: ";
    cin >> g_username;
    cout<<"         Password: ";
    cin >> g_password;
    user NewUser(g_username,g_password);
    register_user(NewUser);
    get_login_credentials();
    system("clear"); 
}

void print_menu(){
    if (not logued_in){
        cout <<"    Menu"
         <<"\n    1    a: Login"
	     <<"\n    2    b: Register"
         <<"\n    3    c: Project Info"
	     <<"\n    0    c: Exit"
         <<"\n    Please enter a selection :";
    } else{
        cout <<"    Welcome " << logued_user.get_username()
         <<"\n    1    a: Logout"
	     <<"\n    2    b: Play"
         <<"\n    3    c: Score"
	     <<"\n    0    c: Exit"
         <<"\n    Please enter a selection :"; 
    }
}

void info(){
    system("clear");
    cout<< "Final project for Introduction to Programing in C++ \n"
    << "Course ID: COP1334-2227-1851 \n"
    << "Professor: George Gabb\n"
    << "Student: Vicente Ernesto Tejeda Sanchez\n"
    << "Institution: Miami Dade College\n"
    ;
}
//main
int main()
{
    cout <<"WELCOME TO WARSHIP BATTLE\n";
    get_login_credentials();
    logued_in = false;
    int user_choice;

    while (true){
    print_menu();
    cin >> user_choice;

    switch (user_choice)
    {
    case 1:
        if (logued_in == false)
            login();
        else if (logued_in == true)
            logout();
        break;
    case 2:
        if (logued_in == false)
            register_new_account();
        else if (logued_in == true){
            int score = play();
            logued_user.set_score(score);
            logued_user.set_score_file();
        }
        break;
    case 3:
        if (logued_in == false)
            info();
        else if (logued_in == true){
            system("clear");
            logued_user.set_score(0);
            logued_user.set_score_file();
        }
        break;
    case 0:
        return 0;
    default:
        break;
    }
    }

    
    return 0;

}

