# Fondamenti di Informatica - Archivio Codici

Questo archivio contiene i programmi scritti durante il mio primo approccio al linguaggio C nel corso di Fondamenti di Informatica all'Università.

## Struttura del Repository

```
FI/
├── README.md                 ← Questo file
├── README_COMMENTS.md        ← Report revisione commenti
├── COMMENT_STYLE_GUIDE.md    ← Linee guida di stile
├── example.c                 ← Esempio di codice commentato
│
├── Esercitazione/            ← Esercitazioni in classe
│   ├── 1/                    ← Primi programmi (hello, ascii, ipotenusa, types)
│   ├── 2/                    ← MCD Euclide
│   └── 18ott24/              ← Ordinamento array, rimozione duplicati
│
├── Esercizi miei/            ← Esercizi personali
│   ├── char_freq.c           ← Frequenza caratteri in file
│   ├── default.c             ← Configurazione output immediato
│   └── list_sum.c            ← Manipolazione liste concatenate
│
├── Laboratorio/              ← Esercitazioni di laboratorio
│   ├── 27set24/              ← Primo laboratorio (shift, frazioni, MCD, ecc.)
│   │   ├── Esercizio 1-7/    ← Esercizi base
│   │   └── soluzioni_lab_01/ ← Soluzioni di riferimento
│   ├── 18ott24/              ← Anagrammi, crivello, date, stringhe, temperatura
│   ├── 15nov24/              ← Bubble sort, calcolatrice tempo, esami, matrici
│   ├── 29nov24/              ← Mastermind, hotel, libreria custom
│   └── 13dic24/              ← Cookies, labirinto, lista elfi, palindroma
│
├── Lezioni/                  ← Codice mostrato a lezione
│   ├── 3ott24/               ← MCD (algoritmo ingenuo)
│   ├── 17ott24/              ← Stringhe e array 2D
│   ├── 25ott24/              ← Perimetro poligoni (struct, distanza euclidea)
│   ├── 29nov24/              ← Ricorsione (fattoriale, potenza, strlen)
│   └── 9dic24_liste.c        ← Liste concatenate
│
└── Temi d'esame/             ← Prove d'esame passate
    ├── 28-08-2023/           ← String compare, labirinto, array-to-list
    ├── 20-01-2024/           ← Pulizia file prodotti, carattere minimo
    ├── 13-02-2024/           ← Minuti lavorati, liste
    ├── 13-06-2024/           ← Incremento ricorsivo, provenienze
    ├── 02-09-2024/           ← Plusone ricorsivo, filtra lista, date
    └── ultimi/               ← Temi più recenti
```

## Statistiche

- **Totale file .c**: ~55
- **File header .h**: 1
- **File .txt/.csv/.bin**: vari
- **Anno**: Primo anno universitario

## Come Compilare

```bash
gcc -Wall -Wextra -o programma programma.c -lm
```

Per programmi con `math.h` serve il flag `-lm`.
