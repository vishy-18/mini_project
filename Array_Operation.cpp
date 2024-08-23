#include<iostream>
using namespace std;

class arr
{
    int a[200],n;

    public:
    arr(int x)
    {
        n=x;
        cout<<"\nEnter the Elements : \n";
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
    }

    void Insertion()
    {
        int data,pos;
        cout<<"\nEnter the Element and Its Position : \n";
        cin>>data>>pos;

        for(int i=n;i>=pos;i--)
        {
            a[i]=a[i-1];
        }

        a[pos-1]=data;

        n++;
    }

    void Deletion()
    {
        int pos;
        cout<<"\nEnter the Positon to Be Deleted : \n";
        cin>>pos;

        for(int i=pos-1;i<n-1;i++)
        {
            a[i]=a[i+1];
        }
        n--;
    }

    void Search()
    {
        int s;
        bool flag=false;

        cout<<"\nEnter the Element to be Searched : \n";
        cin>>s;

        for(int i=0;i<n;i++)
        {
            if(a[i]==s)
            {
                flag=true;
                cout<<"\nElement Found At Index : "<<i;
                break;
            }
        }

        cout<<"\nElement Not Found.....";

    }

    void Sort()
    {
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<n-i-1;j++)
            {
                if(a[j]>a[j+1])
                {
                    int temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                }
            }
        }
    }

    void Display()
    {
        cout<<"\nThe Current Array : \n";
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<"\n";
        }
    }
};

int main()
{
    int n,ch=0;
    cout<<"\nEnter the Number of Elements : \n";
    cin>>n;

    arr s(n);
    cout<<"\nOperations : \n1.Insertion\n2.Deletion\n3.Search\n4.Sort\n5.Display\n6.Exit\n";

    while(ch!=6)
    {
        cout<<"\nEnter Your Choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1:
            s.Insertion();
            break;

            case 2:
            s.Deletion();
            break;

            case 3:
            s.Search();
            break;

            case 4:
            s.Sort();
            break;

            case 5:
            s.Display();
            break;
            
            case 6:
            cout<<"\nThank You .......!!!";
            return 0;
            break;

            default:
            cout<<"\nInvalid Choice .....";
            break;

        }
    }
}