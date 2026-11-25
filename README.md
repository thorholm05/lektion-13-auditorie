# Auditorieopgaver i Lektion 13

Live coding foregår i [src/live.c](src/live.c).


## Auditorieopgave A: Det fulde beløb
Opgaven kan laves i [src/list_cashier.c](src/list_cashier.c).

> Udvid programmet så den samlede pris og antal udskrives, ved at gennemløbe listen med varerne.
> 1) Skriv en funktion der beregner antal varer i listen.
> 2) Skriv en funktion der beregner summen af varernes pris i listen.
> 
> ---
> 
> (Bonus: Udskriv i samme rækkefølge som varerne er indtastet.)


---

## Auditorieopgave B: Den unikke bon
Opgaven kan laves i [src/tree_cashier.c](src/tree_cashier.c).

> 1) Opdatér programmet så varerne sorteres efter navn.
>    - Sammenlign tekst med `strcmp(char* x, char* y)`, hvis 0 så er teksten ens, hvis < 0 så er x mindre end y.
>      - Fx: `strcmp("apples", "oranges") < 0`
> 
> 
> 2) Udvid programmet så varer med samme navn ikke kan indgå to gange.
>    - Udvid `item_t` med et `int count` felt som tælles op.
>      - Vi bruger den første pris.
> 
> 
> 3) Beregn den samlede pris.
>    - Skriv en rekursiv funktion der beregner summen.
> 
> Eksempel:
> ```
> ┌──────────────────────────────────────┐
> │  Input                Output         │
> │  ─────                ──────         │
> │  Apples 10            Apples 2 x 10  │
> │  Oranges 5     ──►    Oranges 1 x 5  │
> │  Apples 7                            │
> │                       Total 25       │
> └──────────────────────────────────────┘
> ```
> 
> ---
> 
> (Bonus: Gør det mulig at slette en vare igen)
