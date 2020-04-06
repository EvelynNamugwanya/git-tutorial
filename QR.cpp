#include <iostream>
#include <math.h>
# define n 3
# define M 3
# define N 3
# define L 3
#include <iomanip>
using namespace std;

int main()
{


//declare all variables

double u1,u2,d1,d2,z,y,x,f,p,proju2a3,c,c4; int i;
    double proj,d5,d7,d6;
   
   int A[N][L]={{1,2,4},
                  {0,0,5},
                  {0,3,6},
                  
   };
   double e1[n];double e3[n];
    double e2[n]; double u3[n];
double a1[n]={1.0,0.0,0.0};
//double u1 =a1;
double sum =0.0;//geting norm of a1
for( i=0; i<n; i++){
 sum+=(a1[i]*a1[i]);//, is this right, or?
}
  c=sqrt(sum);//so //c is the norm of u1
   cout<<"****sum of a1 or u1 by its self:";cout<<endl;
  cout << sum << " ";cout<<endl;
   
   cout<<"****the actual norm of a1 or u1:";cout<<endl;
 
  cout << c << " ";cout<<endl;
   cout<<"****The vector e1:";cout<<endl;
   // getting e1 u1/|| u1 ||
  for( i=0; i<n; i++){
  e1[i]=a1[i]/c;
  
  cout << e1[i] << " ";cout<<endl;
  
  

  }
  
  
  //*******e2
  double a2[n] = { 2.0,0.0,3.0}; 
  double uzp[n];
  
 
cout <<"vector u2 prime is :";cout<<endl;
    for(i=0;i<n;i++){
uzp[i] =  a2[i]-(a2[i]*a1[i])*a1[i];

cout <<uzp[i] << " ";cout<<endl;//"the vector u2 is:" 
}

double sumk =0.0;//geting norm of uzp
for( i=0; i<n; i++){
 sumk+=(uzp[i]*uzp[i]);
}
  c4=sqrt(sumk);//so //c4 is the norm of u2
   cout<<"****norm of u2prime is: ";cout<<endl;
  cout << c4 << " ";cout<<endl;
 // e2=u2prime[i]/c4;
  cout<<"****vector e2 is: ";cout<<endl;
  for( i=0; i<n; i++){
  e2[i] =uzp[i]/c4;
  
  cout << e2[i] << " ";cout<<endl;
  

}

//e3**********
double a3[n]={4.0,5.0,6.0};
double u3p[n];
cout << "*****vector u3 is******: ";cout<<endl;
for(i=0;i<n;i++){
u3p[i] =  a3[i]-(a3[i]*a1[i])*a1[i]-(a3[i]*e2[i])*e2[i];

cout <<u3p[i] << " ";cout<<endl;//"the vector u2 is:" 
}

//lets get e3 by first getting its norm || u3prime//

double sumt =0.0;double c8=0.0;//geting norm of u3p
for( i=0; i<n; i++){
 sumt+=(u3p[i]*u3p[i]);
}
  c8=sqrt(sumt);//so //c8 is the norm of u3p
   cout<<"****norm of u3prime is: ";cout<<endl;
  cout << c8 << " ";cout<<endl;
 
  cout<<"****vector e3 is******: ";cout<<endl;
  for( i=0; i<n; i++){
  e3[i] =u3p[i]/c8;
  
  cout << e3[i] << " ";cout<<endl;
  
}

cout<<"****matrix A decomposed into  matrix Q******: ";cout<<endl;
  double Q [][3]={ {e1[0], e2[0],e3[0]},
                   {e1[1], e2[1],e3[1]},
                   {e1[2], e2[2],e3[2]},
                   
                  
  };
      
      
      for (int i = 0; i < n; i++){ 
     for(int j = 0; j < 3; j++)
      
     
 cout << Q[i][j]<<  " " " " " ";cout<<endl;
 
  
  }


 cout<<"Transposed Q:****matrix QT ";cout<<endl;
double QT[M][N] ={
       {e1[0],e1[1],e1[2]},
       {e2[0],e2[1],e2[2]},
       {e3[0],e3[1],e3[2]},
   };              
                  
                  
         for (int i = 0; i < M; i++){ 
    
     for(int j = 0; j < N; j++)
     
     
 cout << QT[i][j]<<   "  ";cout<<endl;
 
  
  }   
  
 

double R[M][L];
  for(i = 0; i < M; ++i)
        for(int j = 0; j < L; ++j)
        {
            R[i][j]=0;
     
       }
 
 // Multiplying matrix QT and A TO get matrix R.***rowise
     for(int i = 0; i < M; ++i)
     for(int j = 0; j < L; ++j)
     for(int k = 0; k < N; ++k)
     
    
            {
                
                R[i][j] += QT[i][k] * A[k][j];
            }

    // Displaying the mATRIX R.
    cout << endl << " Matrix R: " << endl;
    for(int i = 0; i < M; ++i)
    for(int j = 0; j < L; ++j)
    {
        cout << " " << R[i][j];
        if(j == L-1)
            cout << endl;
    }









  
    return 0;
}
