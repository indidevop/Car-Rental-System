//Car Rental System

#include <iostream>
#include <string>
#include <fstream>
#include<stdlib.h>
#include<windows.h>
using namespace std;
int menu();
string uname;

string tname, taddr, tcountry, tcnum, tcurrent, tdesti, tctype, tcmodel, tcar_num, tcolor;
int tdist, crate, tseat, k=0;

//Class for user details starts/////////////////////////

class user_login
{
private:
    string name, country, address, cnum;
    string password;

public:
    string username;
    void registeration()
    {
        cout << "\n\t\t\t\t\tName: ";
        cin >> name;
        cout << "\n\t\t\t\t\tCountry: ";
        cin >> country;
        cout << "\n\t\t\t\t\tAddress: ";
        cin.ignore();
        getline(cin, address);
        cout << "\n\t\t\t\t\tContact Number: ";
        cin >> cnum;
        cout << "\n\t\t\t\t\tUsername for your account: ";
        cin >> username;
        cout << "\n\t\t\t\t\tPassword for your account: ";
        cin >> password;
        cout << "\n\t\t\t\t\t-----------------------------------" << endl;
        cout << "\t\t\t\t\tYou are successfully registered :)" << endl;
        cout << "\t\t\t\t\t-----------------------------------" << endl;
        ofstream fout;
        fout.open("User_Data.txt", ios::app);
        fout.write((char *)this, sizeof(*this));
        fout.close();
        Sleep(2000);
        system("cls");
    }

    bool login()
    {
        ifstream fs;
        fs.open("User_Data.txt");
        if (!fs)
        {
            cout << "\n\t\t\t\tNo records exist!\n";
            return false;
        }
        string usn, psd;
        cout << "\n\t\t\t\t\tUsername : ";
        cin >> usn;
        cout << "\n\t\t\t\t\tPassword : ";
        cin >> psd;

        while (fs.read((char *)this, sizeof(*this)))
        {
            if (usn == username && psd == password)
            {
                cout << "\n\t\t\t\t\t-----------------------------------" << endl;
                cout << "\t\t\t\t\tYou have successfully logged in :)";
                cout << "\n\t\t\t\t\t-----------------------------------" << endl;
                cout << "\t\t\t\t\t\t    Hi " << name << "!\n"<<"\t\t\t\t\t\tContinue your booking\n\n";

                tname = name;
                taddr = address;
                tcountry = country;
                tcnum = cnum;
                uname = username;
                Sleep(2000);
                system("cls");
                return true;
            }
        }
        cout << "\n\t\t\t\t\t-----------------------------------" << endl;
                cout << "\t\t\t\t\tIncorrect username or password :(";
                cout << "\n\t\t\t\t\t-----------------------------------" << endl;
        cout << endl;
        Sleep(2000);
        system("cls");
        return false;
    }
};
user_login test1;

//Class for user details ends/////////////////////////

//Class location starts/////////////////////////
class location
{
private:
    string pickup, destination;
    int dist;

public:
    void input()
    {
        cout << "\n\t\t\t\t\t\tEnter pickup point:";
        cin >> pickup;
        cout << "\n\t\t\t\t\t\tEnter destination point:";
        cin >> destination;
        cout << "\n\t\t\t\t\t\tEnter distance:";
        cin >> dist;
        ofstream fout;
        fout.open("destination.txt", ios::app);
        fout.write((char *)this, sizeof(*this));
        fout.close();
    }

    void display()
    {
        cout << "\n\t\t\t\t\t\t" << pickup << "---> " << destination << "---> " << dist <<"km" <<endl;
    }

    void view()
    {
        ifstream fin;
        fin.open("destination.txt");

        if (!fin)
        {
            cout << "\n\t\t\t\t\t\t\t--------------\n\t\t\t\t\t\t\tFile not found\n\t\t\t\t\t\t\t--------------\n";
        }
        else
        {cout << "\n\t\t\t\t\t\t" << "FROM" << " ---> " << "TO" << " ---> " << "DISTANCE" << endl<<"\t\t\t\t\t__________________________________________";

            while (fin.read((char *)this, sizeof(*this)))
            {
                display();
            }
            fin.close();
        }
    }

    void delete_location(string pcmp, string dcmp)
    {
        int flag;
        ifstream fin;
        ofstream fout;
        fin.open("destination.txt");
        fout.open("temp1.txt", ios::app);
        while (fin.read((char *)this, sizeof(*this)))
        {
            if (pickup == pcmp && destination == dcmp)
            {
                flag = 1; 
                cout<<"\n\t\t\t\t\t\tCleared\n";              
            }

            else
                fout.write((char *)this, sizeof(*this));
        }
        fin.close();
        fout.close();
        remove("destination.txt");
        rename("temp1.txt", "destination.txt");

        if (flag == 0)
            cout << "\n\t\t\t\t\t\t): Record not found :(";
    }

    void select_loc(string cloc, string dloc,int j)
    {
        int flag = 0;
        ifstream fin;
        fin.open("destination.txt");
        while (fin.read((char *)this, sizeof(*this)))
        {
            if (cloc == pickup && dloc == destination)
            {
                if(j==1)
                {
                 tdist = 2*dist;   
                }
                else
                {
                tdist = dist;
                }

                tcurrent = pickup;
                tdesti = destination;
                flag = 1;
            }
        }
        
        
            if (flag == 0)
           { cout << "\n!ERROR 101 Invalid input !\n";}
                
    
    }
};
location lobj;
//Class location ends/////////////////////////

//Class Car starts/////////////////////////
class car
{
public:
    string type;
    string model;
    string number;
    string color;
    string driver;
    int rate;
    int seats;

    void set_car()
    {
        cout << "\n\t\t\t\t\t\t-- Enter car details --\n\n";
        cout << "\n\t\t\t\t\t\tType: ";
        cin >> type;
        cout << "\n\t\t\t\t\t\tModel: ";
        cin >> model;
        cout << "\n\t\t\t\t\t\tNumber: ";
        cin >> number;
        cout << "\n\t\t\t\t\t\tBody Colour: ";
        cin >> color;
        cout << "\n\t\t\t\t\t\tSeating capacity: ";
        cin >> seats;
        cout << "\n\t\t\t\t\t\tRate per km of car: ";
        cin >> rate;
        cout << "\n\t\t\t\t\t\tDriver's name: ";
        cin >> driver;
        Sleep(2000);
        system("cls");
    }

    void display()
    {
        cout <<"\n\t\t\t\t\t"<< type << "\t" << model << "\t" << number << "\t" << color << "\t" << seats << "\t" << rate << "\t" << driver;
    }

    void viewallcars()
    {
        ifstream fin;
        fin.open("car.txt");

        if (!fin)
        {
            cout << "\n\t\t\t\t\t\t\t--------------\n\t\t\t\t\t\t\tFile not found\n\t\t\t\t\t\t\t--------------endl";
        }
        else
        {
            cout << "\n\t\t\t\t\tType\tModel\t"
                 << " "
                 << "Number"
                 << "    "
                 << "\tColour\tSeats\tRate\tDriver\n"
                 << "\t\t\t\t\t________________________________________________________________" << endl;
            while (fin.read((char *)this, sizeof(*this)))
            {
                display();
            }
            cout<<endl;
            fin.close();
        }
    }

    void deletecar(string num, int select = 0)
    {
        int flag = 0;
        ifstream fin;
        ofstream fout;
        fin.open("car.txt");
        fout.open("temp.txt", ios::app);
        while (fin.read((char *)this, sizeof(*this)))
        {
            if (num == number)
            {
                flag = 1;
                if (select == 1)
                {
                    tcmodel = model;
                    tcar_num = number;
                    tcolor = color;
                    tctype = type;
                    tseat = seats;
                    select = 0;
                    crate = rate;
                }
            }

            else
                fout.write((char *)this, sizeof(*this));
        }
        fin.close();
        fout.close();
        remove("car.txt");
        rename("temp.txt", "car.txt");

        if (flag == 0)
            {cout << "\n\t\t\t\t\t   Record not found :(";
            menu();}
            
    }

    void savetofile()
    {
        ofstream fout;
        fout.open("car.txt", ios::app);
        fout.write((char *)this, sizeof(*this));
        fout.close();
    }
};
car cobj;
//Class Car ends/////////////////////////

//Class receipt starts/////////////////////////
class receipt
{
private:
    string name, addr, country, cnum, user, current, desti, ctype, cmodel, car_num, color, driver;
    int finalr, dist, rpkm, seat;

public:
    void savereceipt()
    {
        user = uname;
        name = tname;
        addr = taddr;
        country = tcountry;
        cnum = tcnum;
        current = tcurrent;
        desti = tdesti;
        ctype = tctype;
        cmodel = tcmodel;
        car_num = tcar_num;
        color = tcolor;
        seat = tseat;
        dist = tdist;
        rpkm = crate;
        if(k==1)
        {
            driver="Opted for driver";
            finalr=((dist*rpkm)+1000);
        }
        else
        {
            driver="Not opted";
            finalr = (dist * rpkm);
            }
        ofstream fout;
        fout.open(uname + ".txt", ios::app);
        fout.write((char *)this, sizeof(*this));
        fout.close();
    }

    void display(string check)
    {
        ifstream fin;
        fin.open(check + ".txt");

        if (fin)
        {
            while (fin.read((char *)this, sizeof(*this)))
            {
                cout << "\n\t\t\t\t\t\t     Your Receipt\n\t\t\t\t\t\t-----------------------\n";
                cout << "\n\t\t\t\t\t\t  Username: " << user
                     << "\n\t\t\t\t\t\t  Full Name: " << name
                     << "\n\t\t\t\t\t\t  Nationality: " << country
                     << "\n\t\t\t\t\t\t  Address: " << addr
                     << "\n\t\t\t\t\t\t  Contact: " << cnum
                     << "\n\t\t\t\t\t\t  Pickup point: " << current
                     << "\n\t\t\t\t\t\t  Destination: " << desti
                     << "\n\t\t\t\t\t\t  Distance: " << dist << " km"
                     << "\n\t\t\t\t\t\t  Car number: " << tcar_num
                     << "\n\t\t\t\t\t\t  Car type: " << ctype
                     << "\n\t\t\t\t\t\t  Car model: " << cmodel
                     << "\n\t\t\t\t\t\t  Color: " << color
                     << "\n\t\t\t\t\t\t  Seats: " << seat
                     << "\n\t\t\t\t\t\t  Driver: " << driver
                     << "\n\t\t\t\t\t\t  Rate per km: " << rpkm << " Rs"
                     << "\n\t\t\t\t\t\t  Total price: " << finalr << " Rs"
                     << "\n\t\t\t\t\t\t-----------------------\n";
            }

            fin.close();
            system("pause");
            system("cls");
        }

        else
        {
            cout << "\n\t\t\t\t\t\tUser not registered";
            Sleep(1500);
            system("cls");
        }
    }
};
receipt robj;
//Class receipt ends/////////////////////////

//Admin menu function
void admin_menu()
{

    int ch;
    while (1)
    {
        system("pause");
         system("cls");
        cout << "\n\t\t\t\t\t    What changes would you like to do ?\n\t\t\t\t\t__________________________________________\n\n\t\t\t\t\t\t  1. Add car\n\t\t\t\t\t\t  2. Remove car \n\t\t\t\t\t\t  3. View all cars \n\t\t\t\t\t\t  4. Add pickup point and destination \n\t\t\t\t\t\t  5. Remove pickup point and destination \n\t\t\t\t\t\t  6. View location \n\t\t\t\t\t\t  7. Exit\n\t\t\t\t\t\t  Enter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            
            cobj.set_car();
            cobj.savetofile();
            break;
        }
        case 2:
        {
            cobj.viewallcars();
            cout << "\n\t\t\t\t\t\t  Car Number: ";
            string num;
            cin >> num;
            cobj.deletecar(num);
            break;
        }
        case 3:
        {
           
            cobj.viewallcars();
            break;
        }
        case 4:
        {
            lobj.input();
            break;
        }
        case 5:
        {
            string dpick, ddest;
            cout << "\n\t\t\t\t\t\t  Enter pickup point to delete:";
            cin >> dpick;
            cout << "\n\t\t\t\t\t\t  Enter destination point to delete:";
            cin >> ddest;
            lobj.delete_location(dpick, ddest);
            break;
        }
        case 6:
        {
            lobj.view();
            break;
        }
        case 7:
        {
             system("cls");
            return;
        }
        }
    }
}

//Admin function
void alogin()
{
    string apass, admin_pass = "pass";
retry:
    cout << "\n\t\t\t\t\t\t  Enter password:";
    try
    {
        cin >> apass;
        if (admin_pass != apass)
        {
            throw 101;
        }
        admin_menu();
    }
    catch (int e)
    {
        cout << "\n\t\t\t\t!! Error!!\n\t\t\t\tPassword does not match try again\n";
        goto retry;
    }
}

//Main menu function
int menu()
{
    int ch;
    string num;
    int m=1;
    while (m)
    {
        cout << "\n\t\t\t\t\t||||||| Welcome to our Car Rental System |||||||\n";
        cout << "\n\t\t\t\t\t\t  1. Already an user \n\t\t\t\t\t\t  2. Create a new accout \n\t\t\t\t\t\t  3. Exit \n\t\t\t\t\t\t  4. View receipt \n\t\t\t\t\t\t  0. Admin login" << endl;
        cout << "\n\t\t\t\t\t\t  Enter choice: ";
        cin >> ch;

        switch (ch)
        {
        case 0:
        {
            alogin();
            break;
        }

        case 1:
        {
            bool logins;
            logins = test1.login();
            if (logins)
            {
                string cloc, dloc;
                cobj.viewallcars();
                cout << "\n\t\t\t\t\tChoose one car and enter its number: "<<"";
                cin >> num;
                cobj.deletecar(num, 1);
                Sleep(2000);
                system("cls");
                cout << "\n\t\t\t\t\t\t  Do you need a driver ?\n\t\t\t\t\t\tEnter 1 if 'yes' else enter 2\n\t\t\t\t\t\t";
                cin >> k;
                cout << "\n\t\t\t\t\t\t  Choose your trip \n";
                lobj.view();
                cout << "\n\t\t\t\t\t\t  Enter current location: ";
                cin >> cloc;
                cout << "\n\t\t\t\t\t\t  Enter destination: ";
                cin >> dloc;
                cout << "\n\t\t\t\t\t\t  Do you want a return trip ?\n\t\t\t\t\t\tEnter 1 if 'yes' else enter 2\n\t\t\t\t\t\t";
                int j;
                cin >> j;
                Sleep(2000);
                system("cls");
                lobj.select_loc(cloc, dloc,j);
                robj.savereceipt();
                robj.display(uname);
                menu();
            }
            break;
        }

        case 2:
        {
            system("cls");
            test1.registeration();
            break;
        }

        case 3:
        {
            cout<<"\n\t\t\t\tThank and enjoy your ride !";
            Sleep(2000);
            system("cls");
            m=0;
            return 0;
        }
        case 4:
        {
            string ur;
            cout << "\n\t\t\t\t\t\t  Username:";
            cin >> ur;
            robj.display(ur);
            break;
        }
        }
    }return 0;
}

int main()
{
    menu();
    return 0;
}
