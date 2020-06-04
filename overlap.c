#include<stdio>
#include<stdlib.h>



int main(){



typedef struct DRI_Overlap{
	int ndims;
	int *overlap;
	int dimsizes[];

	}DRI Overlap;/*created datatype DRI Overlap---normally the returned object is 1 dimesion  */



typedef struct DRI_Overlaptype{
	int ndims;
	}DRI Overlaptype;




int DRI_Overlap_create ( DRI_Overlaptype ovr_type, unsigned int num_pos,DRI Overlap *overlap){
	for(int i=0;i<gdo;i++){
	num_pos= 5;//how is the num_pos incoparated to this overlap
	int start=0;int end=gdo-1;
	int mid=start + end/2;
	if (i<mid){
	end =mid-1;
/*left overlap     */

		}else if(start=mid+1){

/*Right overlap */
	

}else if(start==end){

	num_pos=0;
/* edge overlap policy*/

}






/*-how to move /overlap/copy dataelements to ajacent partitions/neigbouring partitions|| how to keep truk of them
-Overlap-->
-may be array binary......choose a pivot/,those indices less  than the mid go are left and those greater are right 
- write the condition for the ovr type to deal with the no adjacent partitions.


-1.by saying adjacent partitions..,do they mean adjacent processes  2.coping edata elements from adjacent partitions */



return 0;
}
