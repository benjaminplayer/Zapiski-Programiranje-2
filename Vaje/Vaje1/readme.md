## Vaje 1

>[!NOTE]
>Te datoteke so bile testirane na Ubuntu 24.04.4 LTS

### how to compile?
```bash
   gcc ime.c -o ime -std=c99 -wall -pedantic
```

``std=c99`` -> standard c99

``-wall`` -> warnings all

``-predantic `` -> opozori na vse stvari, ki niso v standardu, ne naredi errorja
ce hoces da se ustavi: ``-pedantics-errors``

### kaj c99 prinasa?
- mesanje deklaracije in kode
- //, prej samo /**/
- novi data headers -> stdbool.h, <complex.h>
- novi datatypes -> double complex
- inline functions -> compiler use inline func spremeni v text in ga kopira, kamor se klice
- flekesbulni elementi v struct:
```C
struct Oseba {
    char ime[];
} 
```
- inicializatorji
```C
struct point{
    .x=1,.y=2;
}
```
- keriranje spremenljivk s privzetimi vrednostimi
```C
    int *p = (int[]){2,3,4};

```
- variable length arrays
```C
int n = 3;
int arr[n];

//prej:
int arr[3];
```
- makri & staff

### size helloworld
```
TEXT DATA BSS DEC HEX FILENAME
```

<table>
    <tr>
    CLI args
    </tr>
    <tr>
        STACK    
    </tr>
    <tr></tr>
    <tr>HEAP</tr>
    <tr>
        <td>
        BSS -> UNINITIALIZED DATA(int c;)
            -> static var
        </td>
    </tr>
    <tr>
        <td>
        DATA -> init data (int c = 10)
             -> static var 
        </td>
    </tr>
    <tr>
        <td>DATA</td>
    </tr>
    <tr>
        <td>TEXT(Binary code)</td>
    </tr>
</table>

### static var
var ki ohrani vrednost -> nekako global var v funkcijah

### vstopne tocke
1. int main(void)
2. int main(int argc, char **argv)
3. int main(int argc, char **argv, char *envp[])
- envp -> enviroment variables
- argv 0-> ime programa, 1... args

### pisanje v file:
```C
    getc(FILE*);
    putc(char c, FILE*);
    // FILE-> stdin, stdout, stderr;
    getc(stdin);
    putc(ch, stdout);
```

## use of makefile
```bash
  #samo compila v object files
  gcc program.c -c program.o;
  gcc naslov.c -c naslov.o;
  gcc prostopek.c -c postopek.o;
  gcc oseba.c -c oseba.o;
  make test;
  
  #${name}: ${name}.c -> odvisen od var programa
  
```
**primer za vsaenaka:**
```bash
  # za linux
    export name=VsaEnaka; #set ime variable
    make;
    make test;
    make clean;
```