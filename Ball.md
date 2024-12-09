In this solution i use Binary Indexed Trees (https://www.geeksforgeeks.org/binary-indexed-tree-or-fenwick-tree-2/ for documentation).
The first step you need to do is sort all the data you read in decreasing order by the first second and eventually last variable so that we do not have problems with the tree later on.
Before you start the binary tree you need to save all the data in different vectors based on the value off of every womans beauty so that we can update the tree only with women that do not kill themselves.
In the binary tree you need to do the querys first so we can later update with every woman that survives.
