max(X,Y,X) :- X>=Y.
max(X,Y,Y) :- X<Y.
max_cal(X,Y,Max) :- X >=Y, ! , Max = X ; Max=Y.
