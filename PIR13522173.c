#include <stdio.h>
#include <math.h>
int main(void) {
	// your code goes here
	int i, j, k, l, n;
	double U,V,W,u,v,w, ans1, ans2, ans3,a , b, c, d, X, x, Y, y, Z, z;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
	scanf("%lf %lf %lf %lf %lf %lf", &U, &V, &w, &W, &v, &u);
	X=(w-U+v)*(U+v+w);
	x=(U-v+w)*(U-w+v);
	Y=(u+w-V)*(V+u+w);
	y=(u-w+V)*(w-u+V);
	Z=(u+v-W)*(u+v+W);
	z=(u-v+W)*(v-u+W);
	a = (x*Y*Z);
	b = (y*Z*X);
	c = (z*X*Y);
	d = (x*y*z);
	a = sqrt(a);
	b = sqrt(b);
	c = sqrt(c);
	d = sqrt(d);
	ans1 = (-a+b+c+d)*(a-b+c+d)*(a+b-c+d)*(a+b+c-d);
	ans2 = sqrt(ans1);
	ans3 = ans2/(192*u*v*w);
	printf("%.4lf\n",ans3);
	}
	return 0;
}
