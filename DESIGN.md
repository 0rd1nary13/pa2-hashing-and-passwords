1.How many password variations were hashed and tested for a match?
secret118: 
We cange the case for every letters in the words, then we change the number from 0-9. It means we have to 6 for letters change, 9 for numbers changes. So it end up with 6 + 3*9 = 33 conbinaiton. 
secret111:
Same for this one. 

2.How many duplicate password variations were hashed and checked?
Total unique password variations: 1 (original) + 6 (case variations) + 27 (digit variations) = 34.
Total password checks considering redundancy: 1 + 6 + 6 * 27 = 163.
Total number of duplicates: 163 - 34 = 129 duplicate password checks.

3.What are ways you might change your implementation to avoid this repeated and redundant work?
We can implement a single loop that handles both modifications in a systematic manner to avoid overlaps. 
