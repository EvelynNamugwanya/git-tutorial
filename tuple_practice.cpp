#include<iostream>
#include<tuple>
#include<vector>

int main(int argc ,char* argv[]){

std::tuple <char, int ,double> learning;
//std::tuple <char, int, float> learning;
// Assigning values to tuple using make_tuple()

learning= std::make_tuple('c',7,3.5);

//guess this will enable us move those individual elements from one blockto another
std::cout<<std::get<0>(learning) <<std::endl;
std::cout<<std::get<1>(learning) <<std::endl;
std::cout<<std::get<2>(learning) <<std::endl;
//get accessors in tuples access can both access elements and modify them later
std::get<0>(learning) ='b';
std::get<1>(learning) = 28;
std::cout<<std::get<0>(learning) <<std::endl;
std::cout<<std::get<1>(learning) <<std::endl;
//Now lets make avector tuples
//int row_size=3;
//will call this a 1D vector
//vector tuple
std::vector<std::tuple<int,int,int >>vec_tuple;

for(int i=0;i<3;i++){

  for(int j=0;j<3;j++){
    //at every row i we shall add j until j!?<3
    vec_tuple.push_back(std::make_tuple(j,j,j));
    std::cout<<std::get<0>(vec_tuple[i])<<std::endl;
    //std::cout<<std::get<1>(vec_tuple[i]) <<std::endl;

}
}
//std::cout<<std::get<0>(vec_tuple<<std::endl;
//std::cout<<std::get<1>(vec_tuple) <<std::endl;

std::vector<int>trial[3*3];
for(int i=0;i<3;i++){

  for(int j=0;j<3;j++){
    //at every row i we shall add j until j!?<3
    trial[i].push_back(j);
}
  //  std::cout << "Elements at index "
            // << i+3 << ": "<<"\n"<<std::endl
}
//printing the vector out
for(int i=0;i< 3;i++){

  for(int j=0;j<3;j++){

    std::cout<<trial[i][j];
}
  std::cout<<std::endl;
}
//1.vector of vectors
//2.declare the outer vector
//3.declare the inner vector inside the outer vector
//4.push_back the vector to the outer vector
//5.print or display the entire vector;

//1.Declaring the vector of vector
std::vector<std::vector<int> >trial_2;
for(int i=0;i<3;i++)
{//outer vector
  std::vector<int>inner_trial_2;
  for(int j=0;j<3;j++)
  {
    inner_trial_2.push_back(i);
  }            /* result:         000
                                111
                                222
                                I think this is because we are pushing/adding i and its has 3 rows*/

 trial_2.push_back(inner_trial_2);

}

//Displaying the vectors
 for(int i=0; i<trial_2.size();i++){

   for(int j=0;j<trial_2[i].size();j++){

     std::cout<<trial_2[i][j];
   }
   std::cout<<std::endl;
 }


return 0;
}
