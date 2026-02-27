# Predavanja 2
## Struktura C programa
- programska koda v C
- ukazi predprocesorja
- whitespace in komentarji (whitespace => besedilo k nc ne vidis ma tm neki je npr. space)

### ukazi processorja:
oblika #....

prg.c -> predprocesor -> compiler -> prg.o -> linker -> a.out

predprocessor -> program, ki vhodni program prebere in ga mal spremeni in ga da prevajat v compiler.
V predprocessor vstvmo program, napisan v text obliki, kar gre vn je v tekst obliki

predprocesor prilepi vsebino stdio.h na mesto, kamor pise ``#include <stdio.h>``

### programska koda v C
vsebina datoteke s c programom je zaporedje definicij in deklaracij tipov, var pa funkcij
- funkcija -> samostojna enota, ki je del necesa

Primer: prastevila:
```C
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n)
{
    for(int i = 2; i < n; i++)
        if(n % i == 0) return false;
    return true;
}

int main()
{
    for (int i = 1; i <= 100; i++)
        if(isPrime(i)) printf("%d\n",i);
    printf("\n");
    return 0;
}
```

Else spada k najblizjemu if statement
```C 
if (a == 0)
{
    if(b == 0)
    {
        printf("b");
    }
    else
    {
        printf("a");
    }
}

// isto kot
if(a == 0)
if(b == 0)
    printf("b");
else
    printf("a");
```

if izracuna pogoj in poleda ali je pomnilniska slika 0. Ce je je false, ce je razlicna je true.

>[!CAUTION] NE UPORABLJAJ
>C ima stavek ``` goto label```, ki skoci na del kode, ki je marked z label.
>Primer:
>```C
> int d = 2
> loop:
> if(d < n)
> {
>    if(n % d == 0) return false;
>     d++;
>     goto loop;
> }
>```

```C
int d = 2;
loop:
    if(d < n) goto body;
    goto end;
body:
    if(n % d == 0) goto fail;
    d++;
    goto loop;
fail:
    return false;
end:
```
### functions
ce rabis nek function more bit def pred tisto, ki jo rabi. Lahko se zgodi, da ena klice drugo, druga pa prvo. To odpravimo z ti **function prototype**

#### function header / prototype
primer prototipa: 
```C
bool isPrime(int n);
```
potem lahko pises:
```C
bool isPrime(int n);
int main()
{
    isPrime(n);
    return 0;
}

bool isPrime(int n)
{
    //code
    return true;
}
```
>[!NOTE]
>Temu se poskusamo izogibati, saj ni toliko pregledo. Se pa zgodi, da je tak zapis uporaben

zakaj lahko v javi damo functione kjerkol?
Vcasih je biu ram limited, C prebere function, compile-a, shrani in gre naprej. Java pa celoten program da celoten program v pomnilnik, kar si v 70s niso morali privosciti.

Prototypes lahko pisemo na razlicne nacine. Npr:
```C
bool isprime(int n); //priporoceno, saj pogosto z imenom parametra povemo,
                     // cemu sluzi
//ali
bool isprime(int); // compiler imena parametra niti ne potrebuje

//starejsa razlicica:
bool isprime(n)
int n;
{
    //code
}
```

v header files so prototipi funkcij, ki zivijo v .c files

če funkciji ne definiram tipa, potem C prevzame da je tip int
>[!WARNING] tega se res ne uporablja!
```C
add(int a, int b)
{
    return a + b;
}
```