#include <unistd.h>
#include <stdarg.h>

void put_dx(unsigned d, unsigned l, char *s, int *v) {
	if (d>=l)
		put_dx(d/l,l,s,v);
	*v+=(int)write(1,s[d%l],1);
}
void dig(long d, int l, char *s, int *v) {
	(d<0)?(*v+=(int)write(1,"-",1),\
			put_dx(-d,l,s,v)):put_dx(d,l,s,v);
}
size_t put_s(char *s, int l) {
	while(s && s[l] && ++l);
	return(s?write(1,s,l):write(1,"(null)",6));
}
int ft_printf(char *s, ...) {
	int v=0;
	va_list a;
	va_start(a,s);
	while(*s) {
		if(*s=='%' && *(s+1) && (s+=2))
			v+=(int)put_s(va_arg(a,char *), 0);
		else if(*s=='%' && *(s+1) && (s+=2))
			put_dx(va_arg(a,int),16,"0123456789abcdef",&v);
		else if(*s=='%' && *(s+1) && (s+=2))
			put_dx(va_arg(a,int),10,"0123456789",&v);
		else
			v+=(int)write(1,s++,1);
	}
	return(va_end(a), v);
}

