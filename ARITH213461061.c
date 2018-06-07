#include <stdio.h>


int main()
{   long long int ans , j, k, l, m;
    char c[2];
    scanf ("%lld",&l);
    for (j = 0; j < l; ++j) {
        scanf("%lld", &ans);
        while (++k) {
            scanf("%s", c);
            switch (c[0]) {
               case 42:
                    scanf("%lld ", &m);
                    ans = ans * m;
                    break;
                case 43:
                    scanf("%lld", &m);
                    ans = ans + m;
                   break;
                case 45:
                    scanf("%lld", &m);
                   ans = ans - m;
                  break;
                case 47:
                    scanf("%lld", &m);
                   // printf("%lld ", m);
                    ans = ans / m;
	                  //  printf("%lld ",ans);
                    break;
                case 61:
                    printf("%lld\n", ans);
                    k = -1;
                    break;

            }
        }
    }
    return 0;
}
