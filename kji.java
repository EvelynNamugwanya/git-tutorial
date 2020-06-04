public class Matrix{  
 public static void main(String [] args){  
//creating two matrices  
int i,j,k;
int a[][]={{1,1,1},{2,2,2},{3,3,3}};    
int b[][]={{1,1,1},{2,2,2},{3,3,3}};    
 int c[][] ={{0,0,0},{0,0,0},{0,0,0}};  

 //i,k,j
 for(k=0;k<3;k++){//there is 3 columns .this moves last//columnwise
 
for(j=0;j<3;j++){//goes back to 0***and its j for columns and k for rows
     
    int temp=b[k][j];//b is fixed untill it jumps out of the loop from i
       
  for(i=0;i<3;i++){ 
        c[i][j]+=temp*  a[i][k];

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
