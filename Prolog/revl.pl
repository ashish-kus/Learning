reverse([], Y, R) :-
    R = Y.
reverse([H|T] , Y, R) :-
    reverse(T, [H|Y], R).
