delte(1,[_|T],T).
delte(P,[X|Y],[X|R]):-
 P1 is P-1,
 delte(P1,Y,R).

/* delete before and after. */
daltob(P,L,R):-
 P1 is P-1,
 delte(P1,L,R1),
 /* delete before. */
 delte(P,R1,R).
 /* delete after. */
