#include <iostream>
#include <conio.h>
using namespace std;

void Admin ()
{
    

}



//Just for a time spacing
void loading()
{
    for (int i = 0 ; i < 200 ; i++ )
    {
        for (int i = 0 ; i < 900000 ; i++ )
    {

    }

    }
}

//main function to handle the whole program
int main()
{
    int choice , Admin_pass ;

    cout << "                                                   LOADING.........................              " << endl;
    loading();
    system("cls");
    cout << "....................................WELCOME TO THE STUDENT DATA BASE MANAGMENT SYSTEM.........................................    " << endl;
    getch();
    cout << "                                                   LOADING.........................              " << endl;
    loading();
    system("cls");

    cout << "(1. ADMIN LOGIN            (2. STUDENT LOGIN " << endl;

    cin >> choice ;
    switch (choice)
    {
    case 1:
        cout << "          SIGNING AS ADMIN.............. " << endl;
        loading();
        system("cls");
        cout << "          ENTER THE ADMIN KEY FOR LOG IN TO THE SYSTEM       " <<  endl;
        cin >> Admin_pass ;
        loading();
        system("cls");

        if ( Admin_pass == 1234 )
        {

              cout << "       LOGIN SUCCESSFULL TO THE SYSTEM " << endl;
              getch();
              system("cls");
              //calling the actual functional of ADMIN to deal with the student's data
              Admin();
        }
        else
        {
            cout << "      YOR ARE NOT ALLOWED TO ACCESS THE SYSTEM   " << endl;
            getch();
            system("cls");
        }

        break;
    case 2:
        cout <<"           SIGNING AS STUDENT............ " << endl;
        loading();
         system("cls");
        // Student();
        break;
    default:
        cout <<"            TRY AGAIN LATER                " << endl;

    }

    return 0;
}
