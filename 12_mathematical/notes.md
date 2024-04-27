## Permutations
The permutation is the way of arranging the elements of a group or a set "in order".

**nPr = n!/(n-r)!**

## Combinations
The combination an is the selection of elements from a group or a set, where the order of the elements does not matter.

**nCr = n!/(r!(n-r)!)**

## Catalan Numbers
The Catalan numbers on nonnegative integers n are a set of numbers that arise in tree enumeration problems of the type, "In how many ways can a regular n-gon be divided into n-2 triangles if different orientations are counted separately?"

**C(0) = 1**

**C(n) = (2n)!/((n+1)! * n!)**

**C(n+1) = summation of (C(i) * C(n-i)) for 0<=i<=n**

## Pigeonhole Principle
We can say as, if n + 1 objects are put into n boxes, then at least one box contains two or more objects. The abstract formulation of the principle: Let X and Y be finite sets and let f:A->B be a function
- If X has more elements than Y, then f is not one-to-one.
- If X and Y have the same number of elements and f is onto, then f is one-to-one.
- If X and Y have the same number of elements and f is one-to-one, then f is onto.

**Examples:**
- In a computer science department, a student club can be formed with either 10 members from first year or 8 members from second year or 6 from third year or 4 from final year. What is the minimum no. of students we have to choose randomly from department to ensure that a student club is formed? Solution: we can directly apply from the above formula where, q1 =10, q2 =8, q3 =6, q4 =4 and n=4 Therefore the minimum number of students required to ensure department club to be formed is 10 + 8 + 6 + 4 – 4 + 1 = 25
- A box contains 6 red, 8 green, 10 blue, 12 yellow and 15 white balls. What is the minimum no. of balls we have to choose randomly from the box to ensure that we get 9 balls of same color? Solution: Here in this we cannot blindly apply pigeon principle. First we will see what happens if we apply above formula directly. From the above formula we have get answer 47 because 6 + 8 + 10 + 12 + 15- 5 + 1 = 47 But it is not correct. In order to get the correct answer we need to include only blue, yellow and white balls because red and green balls are less than 9. But we are picking randomly so we include after we apply pigeon principle. i.e., 9 blue + 9 yellow + 9 white – 3 + 1 = 25 Since we are picking randomly so we can get all the red and green balls before the above 25 balls. Therefore we add 6 red + 8 green + 25 = 39 We can conclude that in order to pick 9 balls of same color randomly, one has to pick 39 balls from a box.

## Inclusion Exculsion principle

Consider two finite sets, A and B. We can denote the Principle of Inclusion and Exclusion formula as follows:

**n(A⋃B) = n(A) + n(B) – n(A⋂B)**

Here, n(A) denotes the cardinality of set A, n(B) denotes the cardinality of set B and n(A⋂B) denotes the cardinality of (A⋂B). We have included A and B and excluded their common elements.

If we have 3 sets A, B, and C, then according to the Principle of Inclusion and Exclusion, 

**n(A⋃B⋃C) = n(A) + n(B) + n(C) – n(A⋂B) – n(A⋂C) – n(B⋂C) + n(A⋂B⋂C)**





