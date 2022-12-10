compare(X,Y):-
(
X>Y -> Z is X,
write(Z),write(' is greater.');

X<Y -> Z is X,
write(Z),write(' is greater.');

X=:=Y -> write('Both are Equal');

X=\=Y -> write('Both are Unequal');

X=<Y -> Z is Y,
write(Z),write(' is greater or equal.');

X>=Y -> Z is X,
write(Z),write(' is greater or equal.')

). 
