# Structs
```c++
struct s 
{
    int i;      // 4B 
    char c;     // 1B
    double d;   // 8B
};


struct s x;
struct s y = {1,'1',1.0};

printf("%d %c $lf\n",x.i, x.c, x.d);

struct s *p:
p = &x;

printf("%d %c %lf\n", (*p).i, (*p).c, (*p).d);
//ali lazje
printf("%d %c %lf\n", p->i, p->c, p->d);
```

## struct in functions
```c++
//s1 po vrednosti, s2 po referenci
//ker je s2 samo mem addr, leti v function samo 8B
//za s1 pa posljemoo 16B
int f(struct s st, struct s* s2)
{
    s1.i = 10*s1.i;
    s2->i = s2->i*10;
    return s1.i + s2->i;
}


//klic
f(x,&y) // x ostane enak, y spremenjen
```

struct je velik 16B zaradi poravnanosti podatkov v pomnilniku.
Da bi processor lazje deloval z structi, vrine podatke notr v struct.

### kako dobiti size polnila?
```c++
unsigned long a1, a2, a3; // mem locations
a1 = (unsigned long)&(x.i);
a2 = (unsigned long)&(x.c);
a3 = (unsigned long)&(x.d);
printf("%ln , %ln, %ln",a1,a2,a3);
```
##


## se en nacin ustvarjanja structa

```c++
typedef struct_s
{
    int i;
    char c;
    double d;
} s;
```
