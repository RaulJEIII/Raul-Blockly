//copied c++ perceptron

#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
//2D array
  double sample[4][2]=
  {
    {0,0},
    {0,1},
    {1,0},
    {1,1}
  };
  double cd[]={0, 1, 1, 1};
  double weight[]={0,0};
  int epochs = 100;
  int error[100];
  int minEpoch=0;
  double percent=0;
  double prevPercent=100;
  //double weight1, weight2 = 0;
  double const alpha = .05;
  double const theta = .25;
  for (int e = 0; e < epochs; e++){
    error[e] = 0;
    for(int i = 0; i < 4; i++){
    //Initialize feed forward
    double dot = 0;
    double c;
    //Feed Forward
    for(int feat = 0; feat < 2; feat++)
      dot += weight[feat]*sample[i][feat];
      
    dot -= theta;
    if(dot > 0)
      c = 1;
    else
      c = 0;
    //Error Calc
    double delta = cd[i]-c;
    if(delta != 0){
      error[e]++;
      for(int feat = 0; feat < 2; feat++){
      weight[feat]+=alpha*sample[i][feat]*delta;
      }
    }
    cout << "weight 0 is " << weight[0] << " and Weight 1 is " << weight[1] << endl;
  }
  percent = (double)error[e]/4*100;
  cout << "Epoch " << e+1 << " has a " << percept << "% error rate. " << error[e] << " error found." << endl;
  if (percent < prevPercent){
  minEpoch = e+1;
  prevPercent = percent;
  }
}
cout << "Lowest error rate of " << percent << "% found at Epoch: " << minEpoch << endl;
return 0;
}
