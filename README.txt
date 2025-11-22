Done by: Somang Lee

My idea for my hash function is to use a combination of two of the methods (multiplication and devision methods) described in the geeksforgeeks 
article. Done by reading words from the inputs folder (sample_input.txt file), making all the letters lowercase, then taking the running sum of 
these lower case character's ASCII value. Normally, stopping here would result in words like 'cat' and 'act' having the same sum value. So my 
program reduces this collision issue by incorportating a rolling calculation by using the formula 
tracker = tracker * 31 + (unsigned char)c; per character.
We use unsigned characters to avoid dealing with possible negatives or overflows and choose the number 31 as our multiplier as its a prime odd 
number often used in Java hash functions. The last step is to return the value 'tracker % k' (where k is the amount of words in the file) that 
will determine its slot spot in the hash table. 

References: https://www.geeksforgeeks.org/dsa/hash-functions-and-list-types-of-hash-functions/
