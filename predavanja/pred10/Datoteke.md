# Datoteke

FILE je tip, ki opisuje dostop do datotek

args:
fopen(ime, kaj_bos_delu);

kaj_bos_Delu:
- w -> write
- r -> read
- ostalo: man fopen()

```C++
#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *f;
    f = fopen("dat.txt","w");
    if (f == NULL)
    {
        // error, datoteke ni moc odpreti
        printf("Niggatron max, the C stole your ram")
        exit(1);
    }
    //code
    
    fclose(f);
}
```

## writing in a file

```C++
fprinf(FILE *f, char* fstr,...);
//printf je samo:
fprinf(stdout,"",...);
fprintf(stdout,"OUT\n");
fprintf(stderr,"err\n");
```