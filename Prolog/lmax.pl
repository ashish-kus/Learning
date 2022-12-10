max(X,Y,R):-
 X>=Y -> 
  R is X, 
  write(R)
 ;
  R is Y,
  write(R).


/* with list. */
grandiose([H|T],R):-
 H>T -> 
  R is H,
  write(R)
  ;
  R is T,
  write(T).
