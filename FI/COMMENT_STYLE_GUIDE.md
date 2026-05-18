# Linee Guida Complete - FI Folder

## Filosofia Generale

Il codice dovrebbe essere **leggibile, auto-documentante e manutenibile**. I commenti devono spiegare *perché* si fa qualcosa, non *cosa* si sta facendo. Se il codice non è chiaro, migliorate il codice — non aggiungete commenti per spiegare codice oscuro.

---

## 1. Stile dei Commenti

### 1.1 File Header
Header minimale, solo se utile:

```c
// temperature.c - Analisi statistiche temperature
```

### 1.2 Commenti alle Funzioni
Spiegare solo comportamento non ovvio o valore di ritorno:

```c
// Ritorna stringa invertita (memoria allocata dinamicamente)
char* invertiStringa(char *str) { ... }

// Ricerca lineare: non ottimale per array grandi
int findMax(int *arr, int size) { ... }
```

### 1.3 Commenti a Logiche Complesse
Spiegare il *ragionamento*, non i singoli passi:

```c
// Circular right shift: a → c, b → a, c → b
a2 = b; b2 = c; c2 = a;

// Gestione wrap-around 9→0 per incremento cifra
if (digit == 9) digit = 0;
```

### 1.4 Edge Case e Note
Segnalare limitazioni, bug noti, TODO:

```c
// Rimuove newline aggiunto da fgets
word[strlen(word)-1] = '\0';

// BUG: non gestisce case o spazi
if (same_letter == strlen(word)) { ... }

// TODO: Ottimizzare con hash table (O(n) invece di O(n²))
```

### 1.5 Cosa NON Commentare Mai

```c
// ❌ SBAGLIATO:
x = x + 1;  // Incrementa x
for (i=0; i<n; i++) {  // Loop
if (x > 0) {  // Controlla se x > 0

// ✅ GIUSTO:
x++;
for (i=0; i<n; i++) { ... }
if (x > 0) { ... }
```

### 1.6 Sezioni/Intestazioni (NO)
Niente `=== SEZIONE ===`, `--- VARIABILI ---`. Il codice deve essere auto-esplicativo.

---

## 2. Convenzioni di Codice

### 2.1 Nomenclatura
| Cosa | Convenzione | Esempio |
|------|-------------|---------|
| Variabili | snake_case | `tempo_medio`, `num_studenti` |
| Funzioni | camelCase o snake_case | `calcolaMedia()`, `find_max()` |
| Costanti/Macro | UPPER_SNAKE_CASE | `MAX_STUDENTI`, `NUM_GIORNI` |
| Struct | PascalCase o snake_case | `DataNascita`, `punto_geo` |
| Typedef | PascalCase o _t | `Coordinata`, `exam_t` |

### 2.2 Indentazione e Spaziatura
- Usare **spazi** (non tab), 4 spazi per livello
- One True Brace Style (OTBS): `{` sulla stessa riga
- Spazio dopo `if`, `while`, `for`, prima di `{`
- Operatori binari con spazi attorno: `a + b`, non `a+b`

```c
// ✅ Corretto
for (int i = 0; i < n; i++) {
    if (x > 0) {
        y = a + b;
    }
}
```

### 2.3 Dichiarazioni
- Una variabile per riga (dichiarazioni semplici)
- Inizializzare sempre le variabili
- Dichiarare le variabili nel blocco più interno possibile
- Dichiarare i puntatori come `tipo* nome` (asterisco vicino al tipo)

```c
int somma = 0;
float media = 0.0f;
int* puntatore = NULL;
```

### 2.4 Strutture e Typedef
```c
typedef struct {
    int x;
    int y;
} Punto;
```

### 2.5 Funzioni
- Lunghezza massima: ~30-40 righe (se più lunga, refactor)
- Una funzione = una responsabilità
- Return type sulla stessa riga del nome

```c
float calcolaMedia(int array[], int size) {
    float somma = 0.0f;
    for (int i = 0; i < size; i++) {
        somma += array[i];
    }
    return somma / size;
}
```

---

## 3. Best Practice di Programmazione C

### 3.1 Gestione Memoria
- **Sempre** abbinare `malloc`/`calloc` con `free`
- Controllare sempre che `malloc` non ritorni `NULL`
- Quando possibile, preferire stack a heap
- In funzioni che allocano memoria, documentare la responsabilità del free

```c
int* creaArray(int size) {
    int* arr = malloc(sizeof(int) * size);
    if (arr == NULL) {
        fprintf(stderr, "Errore allocazione memoria\n");
        exit(EXIT_FAILURE);
    }
    return arr;
}
// Nota: il chiamante deve fare free()
```

### 3.2 Gestione File
- Controllare sempre che `fopen` non ritorni `NULL`
- Chiudere sempre i file con `fclose`
- Non chiamare `fclose` su un puntatore NULL

```c
FILE* f = fopen("file.txt", "r");
if (f == NULL) {
    perror("Errore apertura file");
    return -1;
}
// ... operazioni ...
fclose(f);
```

### 3.3 Gestione Stringhe
- Usare `fgets` invece di `scanf` per stringhe (sicurezza)
- Usare `strncpy` invece di `strcpy` (buffer overflow)
- *Sempre* verificare la lunghezza prima di copiare
- Rimuovere il `\n` di `fgets` con: `str[strcspn(str, "\n")] = '\0'`

### 3.4 Uso di `scanf`
- Controllare il valore di ritorno (`scanf` ritorna numero di match)
- Non usare `%s` senza limitatore (`%19s` su buffer da 20)
- `scanf` lascia `\n` nel buffer — fare attenzione con `fgets` successivi

### 3.5 Validazione Input
**Sempre** validare l'input dell'utente. Mai fidarsi dell'utente.

### 3.6 Array e Limiti
- Mai superare i limiti dell'array (C non controlla i bounds)
- Usare `#define` o `const` per dimensioni array
- Array multidimensionali: specificare sempre la seconda dimensione nei parametri

---

## 4. Pattern da Seguire

### 4.1 Divisione in Funzioni
Non mettere tutto in `main()`. Dividere in funzioni piccole e testabili.

### 4.2 Puntatori
- Passare struct grandi per riferimento invece che per valore
- Documentare quando una funzione modifica i parametri tramite puntatore
- Usare `const` per parametri che non devono essere modificati

### 4.3 Ricorsione
- Sempre includere un caso base
- Assicurarsi che le chiamate ricorsive convergano al caso base
- Considerare lo stack overflow per ricorsione troppo profonda

### 4.4 Allocazione Dinamica di Array 2D
```c
int** matrix = malloc(sizeof(int*) * righe);
for (int i = 0; i < righe; i++) {
    matrix[i] = malloc(sizeof(int) * colonne);
}
// Deallocazione:
for (int i = 0; i < righe; i++) free(matrix[i]);
free(matrix);
```

---

## 5. Errori Comuni da Evitare (Rilevati nei Codici Esistenti)

| Errore | Dove | Come Risolvere |
|--------|------|----------------|
| `int mat[][]` come parametro | q3 labirinto | `int mat[N][M]` o `int (*mat)[M]` |
| `scanf("%d", a)` invece di `&a` | shift_wrong | Usare `&a` per variabili semplici |
| Chiamate multiple a funzione che alloca | custom_lib_program | Salvare risultato in variabile |
| `fclose(NULL)` | hotel_da_incubo | Controllare NULL prima di chiudere |
| Memory leak | christmas.c | Aggiungere `free()` per ogni `malloc()` |
| `a[14][23]` fuori range | strings.c | Controllare dimensioni array |
| Bug in `count_check` (typo `row`→`rows`) | christmas.c, 2_labirinto.c | Correggere nome variabile |
| Bug condizione base `strcmpRec` | q2 28-08-2023 | `*s1 == '\0' \|\| *s2 == '\0'` |
| Duplicazione codice | tic_tac_toe.c | Creare funzione per stampa griglia |
| Algoritmi inefficienti (O(somma)) | max_min_med.c | Usare confronti semplici |
| Variabili globali | hotel_da_incubo.c, types.c | Passare parametri o usare variabili locali |

---

## 6. Checklist per la Revisione

Prima di considerare un programma "completo":

- [ ] Il codice compila senza warning (`gcc -Wall -Wextra`)
- [ ] Non ci sono memory leak
- [ ] Tutti i file sono chiusi dopo l'uso
- [ ] L'input è validato
- [ ] I nomi di variabili/funzioni sono descrittivi
- [ ] Non ci sono commenti ovvi o superflui
- [ ] I commenti spiegano *perché*, non *cosa*
- [ ] Le funzioni sono corte e con una singola responsabilità
- [ ] Non c'è codice duplicato (DRY: Don't Repeat Yourself)
- [ ] Le costanti magiche sono definite con `#define`
- [ ] I puntatori sono controllati per `NULL` prima del dereferenziamento

---

## 7. Riepilogo Rapido

| Cosa | Regola |
|------|--------|
| Commenti | Spiega *perché*, non *cosa* |
| Nomi | Descrittivi e consistenti |
| Funzioni | Una responsabilità, corta |
| Memoria | malloc → free, controlla NULL |
| File | fopen → fclose, controlla NULL |
| Input | Sempre validato |
| Array | Mai superare i limiti |
| DRY | Non ripetere codice |
