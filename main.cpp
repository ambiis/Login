#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool IsLoggedIn(string username, string password){
    string username2, password2;
    ifstream read("dir\\" + username + ".txt"); // dir where'll be file w username and password
    getline(read, username2);
    getline(read, password2);

    if(username2 == username && password2 == password)
        return true;
    return false;
}

int main(){

    int choice;

    cout << "1: Register\n2: Login\nYour choice: ";
    cin >> choice;
    if(choice==1){
        string username, password;
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;

        ofstream file;
        file.open("dir\\" + username + ".txt");

        file << username << endl << password;
        file.close();

        main();
    } else if(choice == 2){
        string username, password;
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;

        bool LogIn = IsLoggedIn(username, password);
        if(LogIn){
            cout << "U log in" << endl;
            system("PAUSE");
            return 0;
        }else{
            cout << "Wrong username or password" << endl;
            system("PAUSE");
            return 0;
        }
    }

}