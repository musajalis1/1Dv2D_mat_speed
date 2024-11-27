# 1-D vs. 2-D Matrix Multiplication Operation Speed Test [C]
A speed test between two matrix multiplication operations in C, one in which the matrices are represented in 2-D, and the other in which the matrices have been flattened into 1-D.

At the level of machine code, 2-D matrices are represented as flat 1-D matrices. The matrix values are indexed by indexing through the flat 1-D matrix. When building code to construct and multiply matrices in C, the design choice must be made whether to represent the matrices in 2-D or represent them as flat 1-D matrices and index through them. Constructing a 2-D matrix requires more memory allocation and deallocation calls, whereas indexing through a flat matrix introduces an arithmetic operation to calculate the index for each iteration. This speed test was performed to calculate which procedure yields a faster runtime.

## The Results
The results were calculated as the average runtime out of 10 runs of the program.

Average Runtime of 1-D: 0.0000770 seconds <br>
Average Runtime of 2-D: 0.0000788 seconds

WINNER! The 1-D Matrix Multiplication Operation has won the speed test!

The 1-D matrix multiplication operation is faster than the 2-D matrix multiplication operation by an average of 0.0000018 seconds. 

To put this into perspective, if you are running a program which performs 100 billion matrix multiplication operations (such as a very large machine learning model), additional time saved by utilizing a 1-D matrix multiplication operation is approximately 179999.984375 seconds, which is 2999.999756 minutes, 49.999996 hours, or 2.083333 days. An invaluable saving of time. 
