# Floating point summation

Algorithm for comparing the error and time performances of the floating point summation methods (Normal, Pairwise and Kahan summations). Below figures show the comparisons for these 3 summation methods. Kahan summation significantly reduces the error compared to the Normal and Pairwise summation methods. But less exponent and mantissa shifting make the Pairwise summation method faster and computationally cheaper although the pairwise summation method is a recursive function.
![alt tag](https://raw.githubusercontent.com/NaveenKaliannan/FloatingPointSummation/master/output/graph/Error.png)
![alt tag](https://raw.githubusercontent.com/NaveenKaliannan/FloatingPointSummation/master/output/graph/Time.png)
