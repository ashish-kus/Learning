gcd(X,Y,Z):- (
    X=0 -> (
        Z is Y
    );
    Y=0 -> (
        Z is X
    );
    X=Y -> (
        Z is X
    );
    X>Y -> (
        Y1 is X-Y,
        gcd(Y1,Y,Z)
    );
    X<Y->(
        Y1 is Y-X,
        gcd(X,Y1,Z)
    )
).
