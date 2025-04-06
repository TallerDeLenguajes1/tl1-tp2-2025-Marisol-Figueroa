#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CANT_PC 5

struct compu {
    int velocidad;           // entre 1 y 3 GHz
    int anio;                // entre 2015 y 2024
    int cantidad_nucleos;    // entre 1 y 8
    char *tipo_cpu;          // puntero a cadena
};

void listarPCs(struct compu pcs[], int cantidad);
void mostrarMasVieja(struct compu pcs[], int cantidad);

int main() {
    srand(time(NULL));

    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};

    struct compu pcs[5];

    for (int i = 0; i < CANT_PC; i++) {
        pcs[i].velocidad = 1 + rand() % 3;                
        pcs[i].anio = 2015 + rand() % 10;                 
        pcs[i].cantidad_nucleos = 1 + rand() % 8;         
        pcs[i].tipo_cpu = tipos[rand() % 6];              
    }

    listarPCs(pcs, CANT_PC);
    printf("\n--- PC más vieja ---\n");
    mostrarMasVieja(pcs, CANT_PC);

   

    return 0;
}

void listarPCs(struct compu pcs[], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        printf("PC %d:\n", i + 1);
        printf("  Velocidad: %d GHz\n", pcs[i].velocidad);
        printf("  Año: %d\n", pcs[i].anio);
        printf("  Núcleos: %d\n", pcs[i].cantidad_nucleos);
        printf("  Tipo CPU: %s\n\n", pcs[i].tipo_cpu);
    }
}

void mostrarMasVieja(struct compu pcs[], int cantidad) {
    int menor = 0;
    for (int i = 1; i < cantidad; i++) {
        if (pcs[i].anio < pcs[menor].anio) {
            menor = i;
        }
    }

    printf("Año: %d\n", pcs[menor].anio);
    printf("Velocidad: %d GHz\n", pcs[menor].velocidad);
    printf("Núcleos: %d\n", pcs[menor].cantidad_nucleos);
    printf("Tipo CPU: %s\n", pcs[menor].tipo_cpu);
}

