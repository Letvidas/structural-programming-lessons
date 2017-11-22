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
void arrayfromfile(int arr[],int &siz)
{
    ifstream data("data.txt");
    data>>siz;
    for (int i=0; i<siz; i++)
    {
        data>>arr[i];
    }
    data.close();
}
void arrayfromhand(int arr[],int &siz)
{
    int element;
    cout << "type size of the array"<<endl;
    cin>>siz;
    for (int i=0; i<siz; i++)
    {
        cout<<"type "<<i+1<<"array element"<<endl;
        cin>>element;
        arr[i]=element;
    }
}
void lowtohigh(int a,int arr[])
{
    int temp,arrb[a];
    for (int i=0; i<a; i++)
    {
        arrb[i]=arr[i];
    }
    for (int i=0; i<a; i++)
    {
        for (int j=i; j<a; j++)
        {
            if(arrb[i]>arrb[j])
            {
                temp=arrb[i];
                arrb[i]=arrb[j];
                arrb[j]=temp;
            }
        }
    }
    for (int i=0; i<a; i++)
    {
        cout<<arrb[i]<<" ";
    }
    cout<<endl;
}
void hightolow(int a, int arr[])
{
    int temp,arrb[a];
    for (int i=0; i<a; i++)
    {
        arrb[i]=arr[i];
    }
    for (int i=0; i<a; i++)
    {
        for (int j=i; j<a; j++)
        {
            if(arrb[i]<arrb[j])
            {
                temp=arrb[i];
                arrb[i]=arrb[j];
                arrb[j]=temp;
            }
        }
    }
    for (int i=0; i<a; i++)
    {
        cout<<arrb[i]<<" ";
    }
    cout<<endl;
}
double average(int siz, int arr[])
{
    double avg=0;
    for (int i=0; i<siz; i++)
    {
        avg=avg+arr[i];
    }
    avg=avg/siz;
    return avg;
}
int highest(int a, int arr[])
{
    int high=-5000;
    for (int i=0; i<a; i++)
    {
        if (high<=arr[i])
            high=arr[i];
    }
    return high;
}
int highestcount(int siz,int arr[],int high)
{
    int highcount=0;
    for (int i=0; i<siz; i++)
    {
        if (arr[i]==high)
            highcount=highcount+1;

    }
    return highcount;
}
double multiplication(int siz,int arr[])
{
    double mul=1;
    for (int i=0; i<siz; i++)
    {
        mul=mul*arr[i];
    }
    return mul;
}
int main()
{
    int a,siz,sizff,sizfh,arr[100],arrff[100],arrfh[100],highc,high;
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
        arrayfromfile(arr,siz);
        menu();
        a1=true;
        sizff=siz;
        for (int i=0; i<siz; i++)
            arrff[i]=arr[i];
    }
    if (a==2)
    {
        arrayfromhand(arr,siz);
        menu();
        a2=true;
        sizfh=siz;
        for (int i=0; i<siz; i++)
            arrfh[i]=arr[i];
    }
    while (a!=10)
    {
        cin>>a;
        if (a==1)
        {
            arrayfromfile(arr,siz);
            menu();
            sizff=siz;
            for (int i=0; i<siz; i++)
                arrff[i]=arr[i];
            a1=true;
        }
        if (a==2)
        {
            arrayfromhand(arr,siz);
            menu();
            sizfh=siz;
            for (int i=0; i<siz; i++)
                arrfh[i]=arr[i];
            a2=true;
        }
        if (a==3)
        {
            cout<<"array from lowest to highest"<<endl;
            lowtohigh(siz,arr);
            menu();
            a3=true;
        }
        if (a==4)
        {
            cout<<"array from highest to lowest"<<endl;
            hightolow(siz,arr);
            menu();
            a4=true;
        }
        if (a==5)
        {
            aver=average(siz,arr);
            cout<<"average = "<<aver<<endl;
            menu();
            a5=true;
        }
        if (a==6)
        {
            high=highest(siz,arr);
            cout<<"highest element= "<<high<<endl;
            menu();
            a6=true;
        }
        if (a==7)
        {
            high=highest(siz,arr);
            highc=highestcount(siz,arr,high);
            cout<<"count of highest = "<<highc<<endl;
            menu();
            a7=true;
        }
        if (a==8)
        {
            mult=multiplication(siz,arr);
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
                    cout<<arrff[i]<<" ";
                cout<<endl;
            }
            if (a2==true)
            {
                cout<<"your array which was created manually"<<endl;
                for(int i=0; i<sizfh; i++)
                    cout<<arrfh[i]<<" ";
                cout<<endl;
            }
            if (a3==true)
            {
                cout<<"array from lowest to highest"<<endl;
                lowtohigh(siz,arr);
            }
            if (a4==true)
            {
                cout<<"array from highest to lowest"<<endl;
                hightolow(siz,arr);
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
