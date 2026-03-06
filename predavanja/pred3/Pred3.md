# Pred 3
## Osnovni podatkovni tipi
char int float double
v javi:
- $ \text{int: }2^{-31}\space ... \space 2^{31}-1 \text{ vseh }2^{32}$

V C je priblizno tko v javi, samo da v C ne mormo vedt kolko je exponent.
V c imamo $ 2^m; m = n + 1$. Lahko predpostavimo, da je m veckratnik 8-ke. int je sirok **vsaj 2B**.   

Zakaj?
Java je bla narjeda, da je prenosljiva, zato je "zelo zdravo" nastavit velikost inta na 4B. C je narejen za hitrost ne pa prenosljivost, zato je int v C  sirok tolk, kolkr je sirok register.

V C:
- int obicajno 4B
- short int obicajno 2B
- long int obicajno 8B
- unsigned int $0...2^{32}-1$
- signed int $\equiv$

pravila:
1. int je sirok vsaj 16b
2. $|\text{short int}| \leq |\text{int}| \leq |\text{long int}|$

TLDR: Java ima zaradi prenosljivosti fixed vrednosti medtem ko C ima variable da se prilagodi processorju

Da preveris datatype length:
```C
#include <stdio.h>
int main()
{
    printf("%lu\n",sizeof(int)); // izpise datatype length
    //sizeof(long int);
    return 0;
}
```

char -> hranimo znake oz. hranimo stevilo, ki coresponda v char v ASCII tabeli, sirok 8B.

```C
char c;
c  = 65; //oboje je isto
c = 'A'; // 'A' je ascii koda znaka A, C zastopi kot stevilo
```

to je the case, ce racunalnik rabi ASCII kodo. Dandanes rabijo usi pc ascii ali UTF, ki je razsiritev ascii standarda, zato se predpostavi da je to ascii. Na starejsih racunalnikih se zna zgodit, da 'A' ne mappa na 65, vendar na nekaj drugega (EBCDIT).

### float in double
float enojna in double dvojna natancnost

- float 
- double
```C
float x = 0.1;
//halts
while(x != 1.0)
{
    x = x+0.1;
}
```

0.1 se ne da predstavt v double in float tocn.

$$ 0.1 = 0*10^0 + 1*10^{-1} \\
    0.1 = 0*2^0 + 0*2^{-1}... \\
    0.1 = 0.1 + 0 * \frac{1}{2} + 0*\frac{1}{4}...\\
    0.1 = d_0*2^0 + d_1*2^{-1} + d_2 * 2^{-2} +... + d_n*2^n\\
    2^m = 10(d_0*2^m + d_1*2^{m-1} + d_2 * 2^{m-2} +... + d_m*2^0)\\
    2^m \not ={5(d_0*2^m+1 + d_1*2^m + d_2 * 2^{m-1} +... + d_m*2^1)}
$$

to ni stvar C-ja temvec stvar processorja. Ker vecinoma usi delujejo po istem standndardu se bo ta zanaka zaciklala povsod.

```C
printf("%f",0.1); //0.100000
printf("%30.25f") //0.1000000000000000055511151
```

```C
float x,y,z;
x = 2.0; y = 3.0; z = 4.0;
printf("%f\n",x+y+z);
printf("30.25%f\n"x+y+z);

//to dovoje ni nujno enako!
//vcasih je vcasih ni
float res = x + (y + z);
float res1 = (x + y) + z; // ta je ok; C racuna L -> R 
```

$$ \space \space \space \space 0.1234 \\
    +0.0005 \\
   \space \space \space \space \space 0.12345 \space
   \text{to je v } \Reals
$$

v float je to: 0.1234 <- 4 dec mesta

Kako se prepricam, da se mi to lahko zgodi? Katera 3 stevila, da mi to ne velja?

```C
float x = 1.0, y = 1.0;
while((x+y) + y == x +(y + y))
    y /=2.0;

printf("%30.25f %30.25f\n"x,y); // 1.0000000000000000000000000    0.0000000596046447753906250
printf("%30.25f %30.25f\n"(x+y)+y, x+(y+y)); // 1.0000000000000000000000000    1.0000001192092895507812500
```

racunalnik v splosnem ne more pogruntat ali 2 programa isto delujeta.

### tip void

>[!TIP]
> ![VOID](image.png)

metoda lahko vraca void, ma variable ne more bit void.
```C
//prefered
int f(void); // funkcija, ki vrne int, ki je brez param

int f(); // funkcija, ki vrne int, za param ti bom pole povedu
```
razlog, da pri main func ne pisemo void je, da ima main 3 "overrides".

```C
int i = 10;
i = i + (5 << 2); // bitshift za 2 mesti (*4)
```

