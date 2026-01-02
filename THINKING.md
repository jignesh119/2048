let boar be matrix
and each move chagnes the matrix
state= matrix
and transition(up,down,left,right) ---> change the state

functionalities are sliding the board, creating new numbers on the board

part1: sliding the board in the best possible way.

> NON FUNCTIONAL REQUIREMENT: I want it to be faast!
> when I hit <UP> then I should see new state fast, not after 10 seconds lag!!!

### merging strategy

generic slide function that slides the given input column/row to right side
and returns final list/row/column
imma write this simple functionality...

so for refactoring, I think I'm not leveraging cpp features or
optimisations good enough so Imma see learncpp.com for now and see if I can make any modifications
