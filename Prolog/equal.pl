equal(X,Y):-
  (
    X =:= Y -> write('Both are Equal');
  X =\= Y -> (
    write('Both are not equal')
  )
).
