#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    int N = 0;
    int fiji = -1;
    string name,myText;
    
    cout<<"insert file name:"<<endl;
    cin>>name;
    
    ifstream MyReadFile(name);
    
    while (getline (MyReadFile, myText))
    {
        N +=1;
    }
    
    int fij[N][N];
    int friends[N][N];
    
    ifstream inFile;
    inFile.open(name.c_str());
    
    if (inFile.is_open())
    {
        for (int i=0; i<N-1; i++)
        {
            for (int j=0; j<N-1; j++)
            {
                inFile>>fij[i][j];
                cout<<fij[i][j]<<" ";
            }
        }
        
        inFile.close();
    }
    else
    {
        cerr<<"error"<<name<<endl;
    }
    
    for (int i=0; i<N-1; i++)
    {
        for (int j=0; j<N-1; j++)
            {
                if (fij[i][j] == 1)
                {
                    fiji = 1;
                    friends[i][j] = i+j;
                    cout<<i<<" friend with "<<j<<endl;
                }
                else
                {
                    fiji = 0;
                }
            }
    }
    
    int max = -1;
    
    for (int i=0; i<N-1; i++)
    {
        for (int j=0; j<=N-1; j++)
        {
            if (friends[i][j]>max)
            {
                max = friends[i][j];
            }
        }
    }
    
    cout<<max<<endl;
    
    return 0;
}