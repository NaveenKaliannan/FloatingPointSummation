# Floating point summation

## Algorithm for comparing the performances of floating point summation methods (Normal, Pairwise and Kahan summations) for different datasets.

Below figures show the error and time performances of Normal, Pairwise and Kahan floating point summation methods. Kahan summation significantly reduces the error compared to Normal and Pairwise summations. But less exponent and mantissa shifting make the Pairwise summation faster and computationally cheaper, although it is a recursive function. It suggests that the function calling is faster than mantissa and exponent shifting.
![alt tag](https://raw.githubusercontent.com/NaveenKaliannan/FloatingPointSummation/master/output/graph/Error.png)
![alt tag](https://raw.githubusercontent.com/NaveenKaliannan/FloatingPointSummation/master/output/graph/Time.png)


