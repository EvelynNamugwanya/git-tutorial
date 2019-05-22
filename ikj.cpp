/******************************************************************************

                             MATRIX  MULTIPLICATION
*******************************************************************************/


//#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>


using namespace std;

int main()
{    int r1=2, c1=2, r2=2, c2=2, i, j, k,temp;
    int a[][2]={ { 2, 4 }, { 3, 4 } };int b[][2]={ { 1, 2 }, { 1, 3 } };int C[r1][c2];

//int mult[r1][c2]; 


    // Initializing elements of matrix mult to 0.
   while (c1!=r2)
    {
        cout << "Error! column of first matrix not equal to row of second.";
} 

 for(i = 0; i < r1; ++i)
        for(j = 0; j < c2; ++j)
        {
            C[i][j]=0;
     
       }
//******************************************************************************
                             MATRIX  MULTIPLICATION(ikjorder)
//******************** IKJ*************************************************
    // Multiplying matrix a and b hence the product in c.***rowise
     for(i = 0; i < r1; ++i)
     for(k = 0; k < c1; ++k)
     for(j = 0; j < c2; ++j)
    //for(i = 0; i < r1; ++i)
        //for(j = 0; j < c2; ++j)
       // temp=a[i][k];
            //for(k = 0; k < c1; ++k)
            {
                
                C[i][j] += a[i][k] * b[k][j];
            }

    // Displaying the multiplication of  matrix A and B.
    cout << endl << "Output Matrix: " << endl;
    for(i = 0; i < r1; ++i)
    for(j = 0; j < c2; ++j)
    {
        cout << " " << C[i][j];
        if(j == c2-1)
            cout << endl;
    }
//cout<<product[i][j]<<" ";
 //              cout<<endl;


    return 0;
}
