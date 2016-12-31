

/* @file - main.cpp
 * author - Naveen Kumar Kaliannan

 * The main.cpp file computes and compare the error 
 * and performance for 3 differnt floating summation
 * algorithm (Normal, Kahan and Pairwise summation).
 * The computed solution (Error.png and time.png) is 
 * availale in the output/graph directory.
*/



#include<iostream>
#include<iomanip>
#include<cmath>
#include<vector>
#include<algorithm>
#include<fstream>
#include<chrono>

using namespace std;

// Pi
const double Pi = 22.0/7.0; 

// Normal summation
template<class T>
T Sum(vector<T> const &v)
{
  T sum = 0;
  for(auto& el : v )
    {
      sum += el;
    }
  return sum;
}

// Kahan summation
template<class T>
T KahanSum(vector<T> const &v)
{
  T sum = 0, C = 0, Y = 0, Temp = 0;
  for(auto& el : v )
    {
      Y = el - C;
      Temp = sum + Y;
      C = (Temp - sum) - Y;
      sum = Temp;
    }
  return sum;
}

// Pairwise summation
template<class T>
T PairwiseSum(vector<T> const &v, unsigned int N, unsigned int start, unsigned int end)
{
  T sum = 0;
  if((end - start) < N) // summing smaller array
    {
      for(unsigned int i = start; i < end; ++i)
        {
          sum += v[i];
        } 
    }
    else
    {
      unsigned int end_ = floor((end - start)/2);
      sum =  PairwiseSum(v, N, start, start + end_) + PairwiseSum(v, N, start + end_, end);
    }
  return sum;
}




// Main implementation
int main()
{

  // Error Comparison - Normal, Kahan and Pairwise summation
  ofstream outfile("output/data/AbsoluteErrorData.dat");
  for(unsigned int i = 1;i <= 1.E9;i *= 2)
    {
      vector<double> v(i,Pi/i);
      outfile << i << " " << max(abs(Sum(v) - Pi), 1.E-16) << " " 
              << max(abs(KahanSum(v) - Pi), 1.E-16) << " "  
              << max(abs(PairwiseSum(v, 100, 0, i) - Pi), 1.E-16) << " "
              << max(abs(PairwiseSum(v, 1000, 0, i) - Pi), 1.E-16) << "\n";
              // Here 1.E-16  == 0 (Plotting purpose - see Error.png graph in the output/graph directory)
    }
  outfile.close();
  outfile.clear(); 


  // Time Comparison - Normal, Kahan and Pairwise summation
  ofstream outfile1("output/data/TimeData.dat");
  for(unsigned int i = 1;i <= 1.E9;i *= 2)
    { 
      vector<double> v(i,Pi/i);

      auto start = chrono::steady_clock::now();
      Sum(v);
      auto end   = chrono::steady_clock::now();
      auto diff_1 = end - start;
      
      start = chrono::steady_clock::now();
      KahanSum(v);
      end   = chrono::steady_clock::now();
      auto diff_2 = end - start;
      
      start = chrono::steady_clock::now();
      PairwiseSum(v, 100, 0, i);
      end   = chrono::steady_clock::now();
      auto diff_3 = end - start;
      
      start = chrono::steady_clock::now();
      PairwiseSum(v, 1000, 0, i);
      end   = chrono::steady_clock::now();
      auto diff_4 = end - start;
      
      outfile1 << i << " " << chrono::duration <double, milli> (diff_1).count() << " " <<
                              chrono::duration <double, milli> (diff_2).count() << " " <<
                              chrono::duration <double, milli> (diff_3).count() << " " <<
                              chrono::duration <double, milli> (diff_4).count() << "\n";
    }
  outfile1.close();
  outfile1.clear(); 


  return 0;
}
