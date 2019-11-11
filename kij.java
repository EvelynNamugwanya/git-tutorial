public class Matrix{  
 public static void main(String [] args){  
//creating two matrices  
int i,j,k;
int a[][]={{1,1,1},{2,2,2},{3,3,3}};    
int b[][]={{1,1,1},{2,2,2},{3,3,3}};    
 int c[][] ={{0,0,0},{0,0,0},{0,0,0}};  

 //k,i,j
for(k=0;k<3;k++){//never goes back to 0***and its K which determines to move to the next column
    for(i=0;i<3;i++){   //there is 2 rows .0 and 1********this loop goes back to 0 when k increments
    int temp=a[i][k];//a is fixed untill it jumps out of the loop from j
        for(j=0;j<3;j++){    
  
        c[i][j]+=temp*b[k][j];  

}//end of k loop  
  
}//end of j loop  
 
}    

  for ( i=0; i<3; i++){
for ( j=0; j<3; j++)
{
System.out.printf("%d \t", c[i][j]);
}
System.out.printf("\n");
}
}  
}
