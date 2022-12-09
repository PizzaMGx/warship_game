#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

string user_data_array[100][3];

class user{
    private:
        int pos;
        string username;
        string password;
        int score = 0;
    public:
    user (string username_input,string password_input){
            username = username_input;
            password = password_input;

        }
    // GETTERS AND SETTERS
    string get_username(){
        return username;
    }
    string get_password(){
        return password;
    }
    int get_score(){
        return score;
    }
    void set_score(int amount){
        score = amount;
    }
    void set_username(string username_inp){
        username = username_inp;
    }
    void set_password(string password_inp){
        password = password_inp;
    }

    // DATA MANAGEMENT IN FILES
    // Create a new file for every user to manage the score
    void set_score_file(){
        string score_value;
        string filename = "score/" + username + ".txt";
        ifstream f(filename.c_str());
        fstream f1;
        if (f.good()){
            // read the file and save the current score
            f1.open(filename,ios::in);
            if(f1.is_open()){
            while(getline(f1, score_value)){
                increase_score(stoi(score_value));
            }}
        }       
        ofstream outfile ("score/" + username + ".txt");
        outfile << score;
        outfile.close();
        cout <<"\nYour Total score is: " << score << "\n";
        
    }
    
    void increase_score(int amount){
        score+=amount;
    }
    
 
    bool validate_data(){

    for (int x = 0;x<50;x++){
          if ((user_data_array[x][0] == username) && (user_data_array[x][1] == password)){
              pos = x;
              return true;
              }
          
    }
    return false;
}
};

void register_user(user user){
    //Declare FW to open the file
    fstream f;
    ofstream fw;
    ifstream fin;
    fin.open("data.txt");
    fw.open("data.txt",ios::app);

    if (fin.is_open()){
        fw << user.get_username() << "," << user.get_password() << "|\n";
        }
    fin.close();
    fw.close();
}

void get_login_credentials(){
    string user_data;
    fstream f;
    string deli = "";
    int user_count = 0;
    int prop_count = 0;

    f.open("data.txt",ios::in);
    if(f.is_open()){
        while(getline(f, user_data)){  //read data from file object and put it into string.
            for (auto x : user_data){
                if (x == '|'){
                    user_data_array[user_count][prop_count] = deli;
                    deli = "";
                    prop_count = 0;
                    continue;
                }
                else if(x == ','){
                    user_data_array[user_count][prop_count] = deli;
                    prop_count ++;
                    deli = "";
                }
                else
                    deli = deli + x;
            }
            user_count++;
         }
         f.close();
    }
}



// int main(){
//     user user1("VICEN1wf","1234");
//     get_login_credentials();
//     bool test = user1.validate_data();
//     cout << "test: " << test;
//     // user1.set_score_file();
//     // user1.set_score(46);
//     // user1.set_score_file();
//     return 0;
// }