#include <stdio.h>

int main(void) {
    int  t, flag, count;
    long long int  i, n, c, d, m, con;
    scanf ( "%d",  &t );
    while ( t-- ) {
        c = 0;
        scanf ( "%lld",  &n );
        m = n;
        count = 0;
        while ( m > 0 ) {
            m /= 10;
            count++;
        }
        for ( i = 0; i < count; i++ ) {
            c += 9;
            c *= 10;
        }
        c /= 10;
        if ( c == n ) {
            c *= 10;
            c += 9;
        }
        d = abs ( ( c - n ) - n );
             if ( d == 1 ) {
            printf ( "-1\n" );
            continue;
        }
        con = sqrt ( d );
        flag = 0;
        for ( i = 2; i <= con; i++ ) {
            if ( d % i == 0 ) {
                flag = 1;
                break;
            }
        }
        if ( flag == 0 )
        printf ( "%lld\n",  d );
        else
        printf ( "%lld\n",  i );
    }
    // your code goes here
    return 0;
}
