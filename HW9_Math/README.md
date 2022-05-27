# Math
 
Choose a small algorithm to implement in different ways. Describe when/why you might use
each. You can choose any small algorithm.

Some possible options include:
* How many bits are one in a given 32-bit uint?
* How many leading zeros are in a 32-bit uint?
* Trigonometry functions like sin, cos, tan
* Integer division with remainder
* Find the first 100 prime numbers

## Finding prime numbers

I compared time and space complexity of two algorithm implementations used to search prime numbers between 1 and 100 (not exactly the problem statement but it will do I guess :sweat_smile:).
The [code](https://github.com/dliky/Making_Embedded_Systems_Homeworks/blob/master/HW9_Math/src/PrimeNumbersCodeComp.cpp) was reused from the website *PrepInsta.com* and compiled with [Compiler Explorer](https://godbolt.org/).

## Time Complexity, Space Complexity and Big-O Notation

Evaluating algorithms against time is not a reliable method as it is always machine dependent. Instead using the [big-O notation](https://www.youtube.com/watch?v=QnRx6V8YQy0) will help the developper to determine which algorithm is faster and how time complexity varies as the number of inputs changes(scalability). Big-O notation uses mathematical functions to describe algorithm’s runtime performance. Notation O(n), with n being the number of operations, doesn't tell about the speed in seconds but how fast the algorithm grows.

The *time complexity* of an algorithm quantifies the amount of time taken by an algorithm to run as a function of the length of the input. In order to calculate it, it is assumed that a constant time is taken to execute one operation, and then the total operations for an input length on N are calculated.
The *space complexity* of an algorithm quantifies the amount of space taken by an algorithm to run as a function of the length of the input. There is also an auxiliary space, which is different from space complexity. The main difference is where space complexity quantifies the total space used by the algorithm, auxiliary space quantifies the extra space that is used in the algorithm apart from the given input.
[Source](https://www.geeksforgeeks.org/time-complexity-and-space-complexity/?ref=rp).

## Method Test Results

Both implementations (a.k.a. methods) search for prime numbers between two bounds, 1 and 100.

1. The first code implementation loops between these bounds (see *main* part of the code). For each value of *i*, the *checkPrimeA* function checks if it is a prime number. If so, the prime number is printed otherwise the program goes to the next iteration. This implementation yields a time complexity of __0(n<sup>2</sup>)__ and a space complexity of __O(1)__. The total time recorded in *Compiler Explorer* was __708ms__.

2. The second code implementation is an optimization of the first one because it checks only the odd numbers meaning that about half of the number range is scrutinized. The core logic remains quite the same.
 This implementation yields a time complexity of __0(n√n)__ and a space complexity of __O(1)__. The total time recorded in Compiler Explorer was __506ms__.
 
Note: I have noticed that refreshing the compilation leads to time values not identical to the ones read after the first run.

### Output
![prime_output](https://github.com/dliky/Making_Embedded_Systems_Homeworks/blob/master/HW9_Math/images/prime_output.png)


### Big-O values explanation

- 0(n<sup>2</sup>): Called quadratic. It means that for every insert, it takes (n*n) operations i.e., 1 operation for 1 item, 4 operations for 2 items, 9 operations for 3 items. As one can see, 0(n<sup>2</sup>) algorithms become inefficient for handling large number of items. 
- 0(1): Called constant time, the alogorithm will always execute in the same time regardless of the number of items.
- 0(n√n): As √n must be positive, it is the form O(n) describing an algorithm increasing linearly. 











