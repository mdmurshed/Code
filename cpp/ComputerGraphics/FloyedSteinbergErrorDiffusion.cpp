#include<bits/stdc++.h>
using namespace std;


int main()
{
    //float arr[3][3] = {{1,32,120},{132,252,18},{80,140,255}};
    float arr[3][3] = {{.5,.5,.5},{.5,.5,.5},{.5,.5,.5}};
    float arr1[3][3] = {{.5,.5,.5},{.5,.5,.5},{.5,.5,.5}};

    float error[3][3];
    int step  = 1;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout << endl << endl;
            cout << "Step : " << step << endl;
            float pixel = arr[i][j];
            cout << "Old Pixel: " << pixel << endl;
            float newPixel;
            if(pixel <= .5) newPixel =0;
            else newPixel=1;
            cout << "New Pixel : " << newPixel << endl;
            float err = pixel - newPixel;
            if(i==0&j==0) error[0][0] = err;
            if(j<2){
                printf("position (%d,%d),newPixel value : %.2f + %.2f * 7/16 = %.2f \n",i,j+1,arr[i][j+1],err,arr[i][j+1]);
                arr[i  ][j+1]+=err*(7.0/16.0);
                error[i][j+1] = pixel - abs(err*(7.0/16.0));
            }
            if(i<2){
                printf("position (%d,%d),newPixel value : %.2f + %.2f * 5/16 = %.2f \n",i+1,j,arr[i+1][j],err,arr[i+1][j]);
                arr[i+1][j  ]+=err*5/16;
                error[i+1][j  ]=pixel - abs(err*5/16);
            }
            if(i<3 && j>0) {
                printf("position (%d,%d),newPixel value : %.2f + %.2f * 3/16 = %.2f \n",i+1,j-1,arr[i+1][j-1],err,arr[i+1][j-1]);

                arr[i+1][j-1]+=err*3/16;
                error[i+1][j-1]=pixel - abs(err*3/16);
            }
            if(i<2&&j<2){
                printf("position (%d,%d),newPixel value : %.2f + %.2f * 1/16 = %.2f \n",i+1,j+1,arr[i+1][j+1],err,arr[i+1][j+1]);

                arr[i+1][j+1]+=err*1/16;
                error[i+1][j+1]=pixel - abs(err*1/16);

            }

            cout << "Array updated : " << endl;

            for(int x=0; x<3; x++)
            {
                for(int y=0; y<3; y++)
                {
                    float pixel = arr[x][y];
                    cout << pixel << " ";
                }
                cout << endl;
            }
            cout << "Array error : " << endl;

            for(int x=0; x<3; x++)
            {
                for(int y=0; y<3; y++)
                {
                    float pixel = error[x][y];
                    cout << pixel << " ";
                }
                cout << endl;
            }
            step++;
        }
    }
}
