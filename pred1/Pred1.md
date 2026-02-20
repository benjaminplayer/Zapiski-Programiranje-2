# Pred 1
## Prog jezik C
Hello world v C:
```C
// stdio => standart in/out
#include <stdio.h> // podobno kot import v java

//main ima isto fucn kot public static void main
int main()
{
    printf("Hello world\n");
    return 0;
}
```

## metoda vs func
- metoda je del razreda npr `public class HelloWorld`
- v C classa ni treba napisat, saj nima razderov -> starost jezika
- funkcija je samostojen del programa
- v javi bi `printf()` napisali kot `System.out.printf()`

## How to compile a C program?
Recimo, da je hello world `prg.c`
V cli napisemo:
```bash
gcc prg.c
```
ta ukaz prevede datoteko `prg.c` v `a.out`. V tej datoteki je isti program napisan v machine code. Ta program executas v UNIX z `./a.out`

Razlika z javo je da, ce imas v javi `Main.java`, compiler javac prevede .java datoteko v .class, v kateri je program napisan v javanski byte code, ki je processor ne zna izvajati, zato rabimo program java (jvm), ki izvede Main.class.

TLDR: Pri javi rabis compiler in izvajalnik, pri C pa **samo compiler**

to ima par posledic:
v javi lahko program prevedes v .class datoteko, ki jo lahko posljes nekomu in jo lahko sam zazene.

Pri C, ci datoteko a.out, posljes nekomu nimas garancije da bo delala.

1. Ce ukaz izdelas na Linuxu in posljes v Windowse ali Mac ne bo delal. Preveden mora biti na istem OS in mora imeti isto stdlib.
2. Ker je to prevod v machine code, pomeni, da ce mas razlicen processor v pc, v drugem pc ne bo delal.<br> Npr. ce imas Intel 64b arhitekturo, ima en strojni jezik. Mac ima drugo arhitekturo. Ce se program prevede na Intel CPU dobis Intlovo machine code, na MAC-u pa Arm machine code, ki sta si zelo razlicna.

**bolj jasna verzija:**
```bash
gcc -o prg.c prg
```
to vrne program `prg`, ki ga pozenes kot `./prg`
ime out programa je lahko poljubno, sepravi namesto prg bi lahko napisali karkoli, npr primer1, test...

## .c in .h
program v c vedno shranjujes z .c in ne .C ki lahko pomeni cpp.
.h pomeni header, ki pove, da je v tej datoteki, ki je del compilerja in je nekje na disku, da so not deklaracije razlicnih tipov in funkcij.

Locimo:
- zaglavne datoteke: .h -> deklaracijska datoteka za prog jezik C
- programi: .c

## complining in multiple steps

```bash
gcc -c prg.c
```
prg.c -> prg.o

Ta ukaz pomeni: iz izvorne kode v objektno datoteko.
Tukaj izvajamo **prevajanje**, tukaj ni knjiznic zraven (stdio)

```bash
gcc -o prg prg.o
```
prg.o -> prg

Ta pa iz objektne v izvršljivo datoteko.
Tukaj se izvaja **povezovanje (linking)**

```bash
./prg
```
to je useful za vecje programe iz vec datotek, ali za programe ko jih dobis na netu.

## uporabnost
- pisanje drivers
- pisanje OS
- ...

## primer, brannje stevk
- program naj bere znake (stevke od 0 - 9)
- ce char ni stevka, naj program stevilo parsa v int in ga izpise

### code:
primer2.c
```C
#include <stdio.h>
#include <stdbool.h>

int readInt()
{
    int c;
    int i = 0;
    
    while (true)
    {
        c = getchar(); // prebere znak iz tipkovnice in ga vrne kot int
        if (('0' <= c) && (c <= '9'))
            i = i*10 + (c-'0');
        else
            break;
    }

    return i;
}

int main()
{
    printf("int = %d\n",readInt());
    return 0;
}
```
V C je vrstni red funkcij pomemben! Ker v main klicemo readInt(), mora ta biti **nujno** definiran pred main funknicjo, cene se program ne prevede!

```C
int readInt()
{
    int c;
    int i; //pozabis i = 0;
    
    while (true)
    {
        c = getchar(); // prebere znak iz tipkovnice in ga vrne kot int
        if (('0' <= c) && (c <= '9'))
            i = i*10 + (c-'0');
        else
            break;
    }

    return i;
}
```

Recimo da pozabimo inicializirati vrednost i-ja v readInt().
V javi nam bi compiler javil napako, medtem ko C ta program prevede.
Napaka nastane pri izvajanju!

C ne predpostavi, da je v i ničla. Predpostavi pa, da je v njem neka vrednost. (Če v MAC-u uzges O2 dobis neko st, ki bo vedno ista [clang]). Use je odvisno, kako compiler prevede kodo.

Niti ce gcc-ju da izpise warnings, ne najde tezave.

Ce je program prou napisan, se bo povsod obnasal isto. Ce je narobe napian, lahko pride do varijaci. Take napake je **bistveno tezje najti** kot v javi.

## optimizacija kode pri prevajanju
flag: -O = optimize
stevilke:
1-> malo; 2-> veliko; 3-> nevarne optimizacije
```bash
gcc -O2 -o prg prg.c
```