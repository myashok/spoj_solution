#include <stdio.h>
#include <stdlib.h>
# include<string.h>

int main()
{
    int a,b,c,d,e,f,g,h,n,i,num,j;
    scanf("%d",&n);
    char str[41];
    for(i=0;i<n;i++)
    {
        a=0;
        b=0;
        c=0;
        d=0;
        e=0;
        f=0;
        g=0;
        h=0;
      scanf("%d",&num);
      scanf("%s",str);
      for(j=0;j<38;j++)
      {
        if(strncmp(&str[j],"TTT",3)==0)
          a++;
          if(strncmp(&str[j],"TTH",3)==0)
          b++;
          if(strncmp(&str[j],"THT",3)==0)
          c++;
          if(strncmp(&str[j],"THH",3)==0)
          d++;
          if(strncmp(&str[j],"HTT",3)==0)
          e++;
          if(strncmp(&str[j],"HTH",3)==0)
          f++;
          if(strncmp(&str[j],"HHT",3)==0)
          g++;
          if(strncmp(&str[j],"HHH",3)==0)
          h++;

 }
      printf("%d %d %d %d %d %d %d %d %d\n",num,a,b,c,d,e,f,g,h) ;
    }
    return 0;
}

