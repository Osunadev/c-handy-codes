#include <stdio.h>
#include<string.h>

struct estudiante {
    char nombre[20];
    char carrera[20];
    float promedio;
    int creditosCursados;
};

// prototipos de funciones
void quicksort(struct estudiante *students, int low, int high);
int particion(struct estudiante *students, int low, int high);
void swap(struct estudiante *students, int i, int j);
void printStudents(struct estudiante *students);

int main() {
    struct estudiante students[10] = {
        {"Omar","Ing. en Computacion",90, 160},
        {"Roberto","Ing. Robotica",76, 300},
        {"Saul","Ing. en Electronica",100, 300},
        {"Leonardo","Ing. en Petroleo",80, 120},
        {"Leonor","Ing. en Energias R.",95, 200},
        {"Saira","Ing. Civil",70, 340},
        {"Michelle","Ing. Industrial",86, 290},
        {"Marco","Ing. Farmaceutica",78, 270},
        {"Nadia","Ing. Quimica",83, 80},
        {"Raul","Ing. Fisica",68, 123}
    };

    printf("Estudiantes antes de estar ordenados: \n");
    printStudents(students);

    printf("\n\nEstudiantes ya ordenados: \n");
    quicksort(students,0,9);
    printStudents(students);

    return 0;
}

void quicksort(struct estudiante *students, int low, int high) {
    if(low < high) {
        int pivote = particion(students,low,high);
        quicksort(students,low,pivote-1);
        quicksort(students,pivote+1,high);
    }
}

int particion(struct estudiante *students, int low, int high) {
    struct estudiante pivote = students[high];  // pivote es el ultimo elemento de nuestro arreglo
    int j, i = low - 1;

    for (j=low; j<=high-1; j++) {
        if(strcmp(students[j].nombre,pivote.nombre) <= 0) {
            i++;
            swap(students, i, j);
        }
    }
        swap(students,i+1,high);
        return i+1;
}

void swap(struct estudiante *students, int i, int j) {
    struct estudiante aux;
    aux = students[i];      // se crea una copia temporal
    students[i] = students[j];
    students[j] = aux;
}

void printStudents(struct estudiante *students) {
    int i;

    for(i=0; i<10; i++)
        printf("Estudiante %d: %s\n", i+1,students[i].nombre);
}