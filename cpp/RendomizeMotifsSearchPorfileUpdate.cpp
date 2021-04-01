#include<bits/stdc++.h>
using namespace std;

double profile[4][100];

void DisplayProfile(int k)
{
    cout << "Profile-Motifs" << endl;
    for(int i=0; i<4; i++)
    {
        cout <<(i==0?'A':(i==1)?'C':(i==2)?'G':'T')<< ": ";
        for(int j=0; j<k-1; j++)
        {
            printf("%.2lf , ",profile[i][j]);
        }
        printf("%.2lf",profile[i][k-1]);
        cout << endl;
    }
    return;
}


int main()
{
    int n,k,t;
    cin >> n >> k >> t;
    vector <string> v;
    string dna;
    for(int i = 0; i<t; i++)
    {
        cin >> dna;
        v.push_back(dna);
//        if(dna.length()==n) v.push_back(dna);
//        else {
//            cout << "ERROR" << endl;
//            return 0;
//        }
    }

    // Motifs
    int motifs[100];
    // initialize motifs
    for(int i =0; i<t; i++)
    {
        int temp = rand()%(n-k+1);
        motifs[i] = temp;
    }
    cout << "Initial Motifs" << endl;
    for(int i = 0; i<t; i++)
        cout <<"Position:" << motifs[i] << " ,Motif: " << v[i].substr(motifs[i],k) << endl;

    //Profile Motifs
    for(int i = 0; i<k; i++)
    {
        int A = 0, C = 0,G = 0,T = 0;
        for(int j=0; j<t; j++)
        {
            if(v[j][i+motifs[j]] == 'a')
                A++;
            else if(v[j][i+motifs[j]] =='c')
                C++;
            else if(v[j][i+motifs[j]] =='g')
                G++;
            else
                T++;
        }
//        cout << "A="<<A << ", C=" << C << ", G=" << G << ", T=" << T << endl;

        // A = 0 , C = 1 , G = 2 , T = 3
        profile[0][i] = A/(double)t;
        profile[1][i] = C/(double)t;
        profile[2][i] = G/(double)t;
        profile[3][i] = T/(double)t;
    }
    // Display profile motifs
    DisplayProfile(k);
    // updadte code
    for(int i=0; i<t; i++)
    {
        double temp=1,mx=-1;
        string str="",sub = "";
        for(int j=0; j<=n-k; j++)
        {
            for(int x=0; x<k; x++)
            {
                if(v[i][x+j]=='a')
                    temp*=profile[0][x];
                else if(v[i][x+j]=='c')
                    temp*=profile[1][x];
                else if(v[i][x+j]=='g')
                    temp*=profile[2][x];
                else
                    temp*=profile[3][x];
                sub+=v[i][x+j];
            }
            if(mx<temp)
            {
            // motifs update
            // motifs[i] = j;
                mx=temp;
                str = sub;
            }
            printf("%.5lf/%s ,",temp,sub.c_str());
            sub="",temp=1;
        }
        cout << endl;
        cout << "New Motifs:" << str << endl;
    }
}
/*
10 5 8
ttaccttaac
gatgtctgtc
ccggcgttag
cactaacgag
cgtcagaggt
ccggcgttag
cactaacgag
cgtcagaggt

10 4 5
ttaccttaac
gatgtctgtc
ccggcgttag
cactaacgag
cgtcagaggt
*/
