#include <stdlib.h>
#include <iostream>

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
using namespace std;

//for demonstration only. never save your password in the code!
const string server = "tcp://127.0.0.1:3306";
const string username = "root";


int main()
{
    sql::Driver* driver;
    sql::Connection* con;
   
    string password;

    cout << "enter password to connect to server :";
    cin >> password;

    try
    {
        driver = get_driver_instance();
        con = driver->connect(server, username, password);
        cout << "Connected to server" << endl;
    }
    catch (sql::SQLException e)
    {
        cout << "Could not connect to server. Error message: " << e.what() << endl;
        system("pause");
        exit(1);
    }
   
    delete con;
    system("pause");
    return 0;
}