Problem 1)
a) README.md went from being untracked to being a tracked unmodified file.
b) fun_problem.txt is an untracked file in the local directory and README.md is now a modified file with that modification being thats its new contents is the statement: Markdown is easy 
c) README.md is now a modified file that has been staged and fun_problem.txt is now a tracked file that is also staged.
d) Both README.md and fun_problem.txt are staged files that are then commited following the command: git commit -m "My opinion on markdown" . However, the following two echo commands change the unmodified recently commited files to be modified. 
e) README.md is now a modified file that has been staged and fun_problem.txt does not seem to be on the same branch anymore because the changes in the working directory seem to have been discarded.
f) README.md is now a modified file that both has a ready to commit version as well as a version that is nt staged to be committed yet and this split has been cuased by the "git checkout -- fun_problem.txt" command earlier because of the affect this command has on the working directory. 

Problem 3)
a)
The inner loop only executes when i%(int)sqrt(n) == 0 which means it will execute n/sqrt(n) times thus the inner loop will execute (n/sqrt(n))/(n) times. Therefore in big theta notation the answer to the problem must be theta of n^(3/2)
b)
The series is 10 + 10(3/2)^1 + 10(3/2)^2 + ... + 10(3/2)^k
The series will have log base 1.5 of (n/10) terms
   Therefore (in sigma notation with the index of summation being, k) the lower limit of the summation would be k = 0 and the upper limit would be log base 1.5 of (n/10) and the formula for the kth would be 10*(3/2)^k. Then I took the 10 out if the formula for the kth term and moved it out in from if the sigma. After that it becomes rather apparent that the output of this expression must mean in big theta notation the answer to the problem must be theta of n*log(n).
c)
The series is 10 + [10 + sqrt(n)] + [10 + 2*sqrt(n)] + ... + [10 + k*sqrt(n)]
The series will have n/sqrt(n) terms
When the outer loop completes, n * n/sqrt(n) = n^(3/2)
Thus, in big theta notation the answer to the problem must be 
theta of n^(3/2).

Problem 4)
a)
A good data type that could be used to store all the words that appear on a single web page would be a set of strings. This would work well because a set typically doesn't allow repeats. This would be extremely benefitial because commonly used words like "the", "and", and "is" would only appear once in the whole set if the strings are all originally put in with each character of every word being lowecase for example. Also searching a set is quite fast with the use of the count and find functions.
b)
A good data type for this situation would be a map of structs consisting of a key being the students ID number (int) and a there classes (string). This would be a good data type because maps are very good for searching with the use of the key. This is because the map stores items in key order. Therefore iterating over the integer keys would be rather easy and fast. 
c)
A good data type for this situation would be a list of structs consisting of the name of the country (string) and the position in the march order (int). A list would prove to be a good data type for this situation because a list is good for anything where index order matters. Also, it has a fast insert runtime time for adding new countries to the front of the list. 


   

   

