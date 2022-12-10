mem(X,[X|_]).
mem(X,[_|T]):- mem(X,T).
/* insert  a number in the list. */ 
 insert(L,[X|Y],[L|_]).
 insert(L,P,[X|Y],[X|M]):-
 P>1,
 P1 is P-1,
 insert(L,P1,Y,M).
 insert(L,1,[X|Y],M):- append([L],[X|Y],M).
