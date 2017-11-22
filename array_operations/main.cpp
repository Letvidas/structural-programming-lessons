#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void menu()
{
    cout << "type 1=Create array from file" << endl;
    cout << "type 2=Create array manually" << endl;
    cout << "type 3= print array from lowest to highest" << endl;
    cout << "type 4= print array from highest to lowest" << endl;
    cout << "type 5= print array's average" << endl;
    cout << "type 6= print array's highest element" << endl;
    cout << "type 7= print how many highest elements there are in array" << endl;
    cout << "type 8= print multiplication sum of array's elements " << endl;
    cout << "type 9= print history" << endl;
    cout << "type 10=to end"<<endl;
}
void arrayfromfile(int mas[],int &siz)
{
    ifstream data("data.txt");
    data>>siz;
    for (int i=0; i<siz; i++)
    {
        data>>mas[i];
    }
    data.close();
}
void arrayfromhand(int mas[],int &siz)
{
    int element;
    cout << "type size of the array"<<endl;
    cin>>siz;
    for (int i=0; i<siz; i++)
    {
        cout<<"type "<<i+1<<"array element"<<endl;
        cin>>element;
        mas[i]=element;
    }
}
void lowtohigh(int a,int mas[])
{
    int temp,masb[a];
    for (int i=0; i<a; i++)
    {
        masb[i]=mas[i];
    }
    for (int i=0; i<a; i++)
    {
        for (int j=i; j<a; j++)
        {
            if(masb[i]>masb[j])
            {
                temp=masb[i];
                masb[i]=masb[j];
                masb[j]=temp;
            }
        }
    }
    for (int i=0; i<a; i++)
    {
        cout<<masb[i]<<" ";
    }
    cout<<endl;
}
void hightolow(int a, int mas[])
{
    int temp,masb[a];
    for (int i=0; i<a; i++)
    {
        masb[i]=mas[i];
    }
    for (int i=0; i<a; i++)
    {
        for (int j=i; j<a; j++)
        {
            if(masb[i]<masb[j])
            {
                temp=masb[i];
                masb[i]=masb[j];
                masb[j]=temp;
            }
        }
    }
    for (int i=0; i<a; i++)
    {
        cout<<masb[i]<<" ";
    }
    cout<<endl;
}
double average(int siz, int mas[])
{
    double avg=0;
    for (int i=0; i<siz; i++)
    {
        avg=avg+mas[i];
    }
    avg=avg/siz;
    return avg;
}
int highest(int a, int mas[])
{
    int high=-5000;
    for (int i=0; i<a; i++)
    {
        if (high<=mas[i])
            high=mas[i];
    }
    return high;
}
int highestcount(int siz,int mas[],int high)
{
    int highcount=0;
    for (int i=0; i<siz; i++)
    {
        if (mas[i]==high)
            highcount=highcount+1;

    }
    return highcount;
}
double multiplication(int siz,int mas[])
{
    double mul=1;
    for (int i=0; i<siz; i++)
    {
        mul=mul*mas[i];
    }
    return mul;
}
int main()
{
    int a,siz,sizff,sizfh,mas[100],masff[100],masfh[100],highc,high;
    double aver,mult;
    bool a1=false,a2=false,a3=false,a4=false,a5=false,a6=false,a7=false,a8=false;
    menu();
    while (a!=1||a!=2)
    {
        cin>>a;
        if (a!=1&&a!=2)
        {
            cout<<"you have to create array first;"<<endl;
            cout<<"1 - from file"<<endl;
            cout<<"2 - manually"<<endl;
        }
        else break;

    }
    if (a==1)
    {
        arrayfromfile(mas,siz);
        menu();
        a1=true;
        sizff=siz;
        for (int i=0; i<siz; i++)
            masff[i]=mas[i];
    }
    if (a==2)
    {
        arrayfromhand(mas,siz);
        menu();
        a2=true;
        sizfh=siz;
        for (int i=0; i<siz; i++)
            masfh[i]=mas[i];
    }
    while (a!=10)
    {
        cin>>a;
        if (a==1)
        {
            arrayfromfile(mas,siz);
            menu();
            sizff=siz;
            for (int i=0; i<siz; i++)
                masff[i]=mas[i];
            a1=true;
        }
        if (a==2)
        {
            arrayfromhand(mas,siz);
            menu();
            sizfh=siz;
            for (int i=0; i<siz; i++)
                masfh[i]=mas[i];
            a2=true;
        }
        if (a==3)
        {
            lowtohigh(siz,mas);
            menu();
            a3=true;
        }
        if (a==4)
        {
            hightolow(siz,mas);
            menu();
            a4=true;
        }
        if (a==5)
        {
            aver=average(siz,mas);
            cout<<"average = "<<aver<<endl;
            menu();
            a5=true;
        }
        if (a==6)
        {
            high=highest(siz,mas);
            cout<<"highest element= "<<high<<endl;
            menu();
            a6=true;
        }
        if (a==7)
        {
            high=highest(siz,mas);
            highc=highestcount(siz,mas,high);
            cout<<"count of highest = "<<highc<<endl;
            menu();
            a7=true;
        }
        if (a==8)
        {
            mult=multiplication(siz,mas);
            cout<<"multiplication of elements = "<<mult<<endl;
            menu();
            a8=true;

        }
        if (a==9)
        {
            if (a1==true)
            {
                cout<<"your array from file"<<endl;
                for(int i=0; i<sizff; i++)
                    cout<<masff[i]<<" ";
                cout<<endl;
            }
            if (a2==true)
            {
                cout<<"your array which was created manually"<<endl;
                for(int i=0; i<sizfh; i++)
                    cout<<masfh[i]<<" ";
                cout<<endl;
            }
            if (a3==true)
            {
                lowtohigh(siz,mas);
            }
            if (a4==true)
            {
                hightolow(siz,mas);
            }
            if (a5==true)
            {
                cout<<"average = "<<aver<<endl;
            }
            if (a6==true)
            {
                cout<<"highest element= "<<high<<endl;
            }
            if (a7==true)
            {
                cout<<"count of highest = "<<highc<<endl;
            }
            if (a8==true)
            {
                cout<<"multiplication of elements = "<<mult<<endl;
            }
            menu();
        }
        if (a==10)
            break;

    }


    return 0;
}
