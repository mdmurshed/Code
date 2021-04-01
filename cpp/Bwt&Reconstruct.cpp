#include<bits/stdc++.h>
using namespace std;

vector<string>com,nmar;

struct charNum
{
    char ch;
    int num=0;
};

string countString(string BWT)
{
    charNum aa[1000];
    int count = 0;
    aa[0].ch = BWT[0];
    aa[0].num = 1;
    for(int i=1; i<BWT.length(); i++)
    {
        if(BWT[i] == '$')
        {
            count++;
            aa[count].ch ='$';
            aa[count].num = 0;
        }
        else if(BWT[i]==BWT[i-1])
        {
            aa[count].num+=1;
        }
        else
        {
            count++;
            aa[count].ch = BWT[i];
            aa[count].num = 1;

        }
    }

    string letterCountBwt = "";
    for(int i=0; i<=count; i++)
    {
        letterCountBwt +=aa[i].ch;
        stringstream ss;
        ss<<aa[i].num;
        string str;
        ss>>str;
        letterCountBwt +=str;
//        cout << aa[i].ch << str;
    }
    return letterCountBwt;
}

string ReconstuctBWT(string BWT)
{
    cout << "Reconstruct the BWT : ";
    string sortedBwt = BWT;
    sort(sortedBwt.begin(),sortedBwt.end());
//    cout << sortedBwt << endl;
    int len = BWT.length();
    for(int i=1; i<len; i++)
    {
        string temp;
        for(int j =0; j<len; j++)
        {
            if(i==1)
            {
                temp = BWT[j];
                temp+=sortedBwt[j];
                nmar.push_back(temp);
//                cout << temp << endl;
            }
            else
            {
                temp = BWT[j];
                temp+=nmar[j];
                nmar[j] = temp;
            }
        }
//        cout << "Building string:" << endl;
//        for(int k = 0;k<len;k++){
//            cout << nmar[k] << endl;
//        }
        sort(nmar.begin(),nmar.end());
//        cout << "sorted string" << endl;
//         for(int k = 0;k<len;k++){
//            cout << nmar[k] << endl;
//        }

    }
    return nmar[0].substr(1,len-1);

}

int main()
{
    string name;
    cin >> name;
    name+="$";
    com.push_back(name);
    int len = name.size();
    // cyclic rotation
    for(int i=0; i<len-1; i++)
    {
        string str = "";
        str = name[len-1] + name.substr(0,len-1);
        com.push_back(str);
        name = str;
    }
//    cout << com.size() << endl;
//    output of cyclic rotation
//    for(int i=0; i<len; i++)
//    {
//        cout << com[i] << endl;
//    }
    sort(com.begin(),com.end());
//    sorted output
//    for(int i=0; i<len; i++)
//    {
//        cout << com[i] << endl;
//    }
//    output the last element of every string
    string BWT = "";
    for(int i = 0; i<len; i++)
    {
        BWT+=com[i][len-1];
    }

    cout <<"BWT string : " <<BWT << "\nOptimized the BWT string : " << countString(BWT) << endl;

    // recnstuct BWT
    cout << ReconstuctBWT(BWT) << endl;
}
