    int call_div(char *number,int div){
    char result[252];
    int len=strlen(number);
    int now;
    long extra;
    char Res[252];
    for(now=0,extra=0;now<len;now++){
    extra=extra*10 + (number[now]-'0');
    Res[now]=extra / div +'0';
    extra%=div;
    }
    Res[now]='\0';
    for(now=0;Res[now]=='0';now++);
    strcpy(result, &Res[now]);
    if(strlen(result)==0)
    strcpy(result, "0");
    return extra;
    }
    int gcd(int a, int b)
    {
    if (b==0) return a;
    else return gcd(b,a%b);
    }
    main()
    {
    int N,A,B;
    char b[252];
    scanf("%d",&N);
    while(N--){
    scanf("%d %s",&B,b);
    if(B==0) {printf("%s\n",b);continue;}
    if(B==1) {printf("1\n");continue;}
    A = call_div(b,B);
    printf("%d\n",gcd(A,B));
    }
    return 0;
    }

