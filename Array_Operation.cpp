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
        cout<<"\nInserted Successfully.....\n";
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
        cout<<"\nDeleted Successfully.....\n";
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
                cout<<"\nElement Found At Index : "<<i<<"\n";
                break;
            }
        }

        cout<<"\nElement Not Found.....\n";

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
        cout<<"\nSorted Successfully.....\n";
    }

    void Display()
    {
        cout<<"\nThe Current Array : \n";
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<"\n";
        }
    }
    
    void Size()
    {
        cout<<"\nSize of the Array : "<<sizeof(a)<<"\n";
    }
    
    void Capacity()
    {
        cout<<"\nLength of the Array : "<<sizeof(a)/sizeof(a[0])<<"\n";
    }
};

int main()
{
    int n,ch=0;
    cout<<"\nEnter the Number of Elements : \n";
    cin>>n;

    arr s(n);
    cout<<"\nOperations : \n1.Insertion\n2.Deletion\n3.Search\n4.Sort\n5.Display\n6.Size\n7.Length\n8.Exit\n";

    while(ch!=8)
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
            s.Size();
            break;
            
            case 7:
            s.Capacity();
            break;
            
            case 8:
            cout<<"\nThank You .......!!!";
            return 0;
            break;

            default:
            cout<<"\nInvalid Choice .....";
            break;

        }
    }
}
