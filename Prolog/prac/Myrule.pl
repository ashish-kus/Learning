friends(X,Y) :- likes(X,Y),likes(Y,X).           
hates(X,Y) :- not(likes(X,Y)).                   
enemies(X,Y) :- not(likes(X,Y)),not(likes(Y,X)).
