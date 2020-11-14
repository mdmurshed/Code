#include<bits/stdc++.h>
using namespace std;

int n,k,t;
vector <string> dna,p;
string d;
float aa[45][1000];

int main(){
    cin >> n >> k >> t;
    for(int i = 0;i<t;i++)
    {
        cin >> d;
        dna.push_back(d);
    }
    int temp = 2;
    for(int i =0;i<t;i++,temp--){
        p.push_back(dna[i].substr(temp,k));
        if(temp == 0) temp = (n-k)+1;
    }
    cout << "Initial: " << endl;
    for(int i = 0;i<t;i++) cout << p[i] << endl;
    for(int i = 0;i<k;i++){
        int a = 0, b = 0,c = 0,d = 0;
        for(int j=0;j<t;j++)
        {
           if(p[j][i] == 'a') a++;
           else if(p[j][i] =='c') b++;
           else if(p[j][i] =='g') c++;
           else d++;
        }
          cout << "A="<<a << ", C=" << b << ", G=" << c << ", T=" << d << endl;
        float x = float(t);
        aa[0][i] = a/x;
        aa[1][i] = b/x;
        aa[2][i] = c/x;
        aa[3][i] = d/x;
    }
    cout << "Profile: " << endl;
    for(int i=0;i<4;i++){
        if(i == 0) cout<<"A: ";
        else if(i == 1) cout<<"C: ";
        else if(i == 2) cout<<"G: ";
        else cout << "T: ";
        for(int j=0;j<k;j++)
        {
            printf("%.2f , ",aa[i][j]);
        }
        cout << endl;
    }
}
