# v0.2

How to run the program:

build with IDE, then select what you would like the program to do.
Once the program is build, an automatically generated vector of users is created.
A blockchain vector is also created, and a genesis block is immedeatly added to the vector.
  1. mines a new block, and adds it to the blockChain, when the block is mined, the user specified is awarded some currenncy;
  2. creates a trade and adds it to the newest block, pick the users who are trading between each other, and specify the amount.
  3. prints the newest blocks data (block hash, prevblock hash, merkell tree hash, index, version, difficulty target and timestamp).
  4. prints a transaction (transaction must be specified with an index, typing in an index which does not exist, will not print anything).
  5. creates a txt file of all the transactions which have occured in the current block.
  6. shows a users data (public key, name (which is automatically generated), and balance), the user must be specified using an index).
  7. closes the program.
