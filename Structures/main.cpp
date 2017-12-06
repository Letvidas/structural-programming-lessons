#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <ctime>
using namespace std;
ifstream residents("residents.txt");
time_t t = time(0);   // get time now
struct tm * now = localtime( & t );
unsigned int currentyear=(now->tm_year + 1900);
struct resident
{
    string name;
    string surname;
    unsigned int year;
    string city;
    string sex;
};
void menu()
{
    cout<<"choose option"<<endl;
    cout<<"1 = oldest person in the list"<<endl;
    cout<<"2 = print all people living in chosen city"<<endl;
    cout<<"3 = print all man from the list"<<endl;
    cout<<"4 = print all people living in chosen city older than 30 years"<<endl;
    cout<<"5 = end structure"<<endl;
}
void structure(resident res[],int &siz)
{

    for (int i=0; i<siz; i++)
    {
        residents>>res[i].name;
        residents>>res[i].surname;
        residents>>res[i].year;
        residents>>res[i].city;
        residents>>res[i].sex;
    }
}
void eldest(resident res[],int siz)
{
    unsigned int maxi=0;
    for (int i=0; i<siz; i++)
    {
        if (maxi<=currentyear-res[i].year)
        {
            maxi=currentyear-res[i].year;
        }
    }
    for (int j=0; j<siz; j++)
    {
        if(maxi==currentyear-res[j].year)
        {
            cout<<"Oldest resident is "<<res[j].name<<" "<<res[j].surname<<endl;
        }
    }



}
void res_of_city(resident res[],int siz)
{
    int a=0;
    string city;
    cout<<"Type city whose residents you want to find"<<endl;
    cin>>city;
    for (int i=0; i<siz; i++)
    {
        if (res[i].city==city)
        {
            cout<<"In city "<<city<<" there lives "<<res[i].name<<" "<<res[i].surname<<endl;
            a++;
        }
    }
    if (a==0)
    {
        cout<<"No one from the list lives in "<<city<<endl;
    }
}
void all_man(resident res[],int siz)
{
    int a=0;
    string man="Man";
    for (int i=0; i<siz; i++)
    {
        if (res[i].sex==man)
        {
            cout<<"There is man called "<<res[i].name<<" "<<res[i].surname<<endl;
            a++;
        }
    }
    if (a==0)
    {
        cout<<"there is only women in the list"<<endl;
    }

}
void city_and_age(resident res[],int siz)
{
    string city;
    int a=0;
    cout<<"enter city"<<endl;
    cin>>city;
    int age=30;

    for (int i=0; i<=siz; i++)
    {
        if (res[i].city==city)
        {
            if (currentyear-res[i].year>=30)
            {
                cout<<"In city "<<city<<" lives "<<res[i].name<<" "<<res[i].surname<<" and this "<<res[i].sex<< " is "<<currentyear-res[i].year<<" years old"<<endl;
                a++;
            }
        }
    }
    if (a==0)
    {
        cout<<"there is no person from the list who is 30 years old or older and lives in "<<city<<endl;
    }
}
int main()
{
    int option=0,siz;
    residents>>siz;
    resident res[siz];
    structure(res,siz);
    while (option!=5)
    {
        menu();
        cin>>option;

        while (option<1||option>5)
        {
            if (option<1||option>5)
            {
                cout<<"invalid option try again"<<endl;
                menu();
                cin>>option;
            }
        }
        if (option==1)
        {
            eldest(res,siz);
        }
        else if (option==2)
        {
            res_of_city(res,siz);
        }
        else if (option==3)
        {
            all_man(res,siz);
        }
        else if (option==4)
        {
            city_and_age(res,siz);
        }
    }
    return 0;
}
