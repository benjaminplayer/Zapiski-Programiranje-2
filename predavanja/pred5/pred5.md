# pred 5
## memory allcoation
```c++
int *p;
p = (int*)malloc(sizeof(int));
```

na heapu dodeli zahtevano stevilo bytov
void pointer -> pointer, ki kaže nekam v memory, 
ne ve pa kaj je tip podatka. Ker malloc vrača void 
pointer, je priporočeno castat v datatype, za katerega
hočemo allocate-at memory.

Ko z malloc allocate-am memory na heapu, ostane dodeljen dokler ga ne free-am
```c++
free(p);
```

delanje arrays z pointerji:
```c++
int p* = (int*)malloc(100*sizeof(int)); // 100 el array
*p = 3; // prvi el je 3
p[0] = 5; // prvi el je 5
for (int i = 0; i < 100; i++) p[i] = 2*i;
free(p);
```

```c++
int p* = (int*)malloc(100*sizeof(int));
p--;
// ker shiftas pointer z 1 nazaj, se idx zacnejo z 1
for (int i = 1; i <= 100; i++) p[i] = 3*i;

//do not p[0] here otherwise bum bum
```


```c++
int a[100]; // static
int f(int n)
{
    int b[n]; //automatic
    int c[100]; // automatic
    static int d[100]; //static
}
```

pošiljanje arrayov v funkcijo:
```c++
int f(int *a, int len)
{
    for (int i = 0; i < len; i++)
        a[i] = 0;
    return 0;
}

int a(int arr[], int len);

int b(int a[100], int len)
```

primer:
```c++
int a[100];
int *pi = (int*) malloc(sizeof(int) * 200);

f(a, 100);
f(&a[0],100);
f(a,33); //posljes en deu tabele
```

### Strings
1D arrays znakov. Na koncu stringa moras na kocnu vedno pisati null znake \0

```c++
char str[100+1];
str[0] = 'F'; str[1] = 'R'; str[2] = 'I'; str[3] = '\0';
printf("%s\n",str);

// za rabo strlen: <string.h>
int i = strlen(str) //3 (ne steje \0)
```

## 2D arrays
```c++
int m[10][20];
for (int i = 0; i < 10; i++)
    for (int j = 0; j < 20; j++)
        m[i][j] = 0;

// ali

int *p = &m[0][0];
for (int i = 0; i < m*n; i++)
    *p[i] = 0;
```
kako C ve kje se nahaja element m\[i]\[j]?

nahaja se na naslovu m + i*20+j (pointer arithmetic)
kaj pa za ``arr[10][20][30]?``?

``arr[i][j][k]`` = arr + i * 20 * 30 + j * 30 + k

```c++
int f(int a[10][20]);
int f(int a[][20]); // zaradi pointer arithemetica, 1. dimenzija "ni vazna"
int f(int a[][20][30]);

```

### tabela z pointers
recimo, da ne vem, kakšne dimenzije bi imel 2 array:
```c++
int **arr;
arr = (int**)malloc(10 * sizeof(int*)); // ne allocas intov, temvec pointerje
for (int i = 0; i < 10; i++)
    arr[i] = (int*)malloc(20 * sizeof(int));

// arr -> pointer na pointer intov
// arr[i] -> pointer na int
// arr[i][j] -> int
```

kako freejam 2d array?

ravno naokrog_
```c++
for (int i = 0; i < 10; i++)
        free(arr[i])
free(arr);
```

kako poslati tak array?

polsjes mem address in velikosti

