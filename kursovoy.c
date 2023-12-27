#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int calculateGridSize(int difficulty) {
    int size;
    if (difficulty == 1) {
        size = 5; // Легкий уровень сложности
    }
    else if (difficulty == 2) {
        size = 7; // Средний уровень сложности
    }
    else {
        size = 9; // Тяжелый уровень сложности
    }
    return size;
}

void printGrid(int** grid, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

void createRandomGrid(int** grid, int size, int difficulty) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (difficulty == 1) {
                grid[i][j] = rand() % 2; // Легкий уровень сложности
            }
            else if (difficulty == 2) {
                grid[i][j] = rand() % 3; // Средний уровень сложности
            }
            else {
                grid[i][j] = rand() % 4; // Тяжелый уровень сложности
            }
        }
    }
    printGrid(grid, size);
}

void fillGridManually(int** grid, int size) {
    printf("Введите элементы игрового поля:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    printGrid(grid, size);
}
void writeGridToFile(int** grid, int size) {
    FILE* file;
    file = fopen("grid.txt", "w");
    if (file == NULL) {
        printf("Ошибка при открытии файла.\n");
        return;
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            fprintf(file, "%d ", grid[i][j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

int main() {
    setlocale(LC_ALL, "RUS");
    int choice;
    int difficulty;
    int size;
    printf("Добро пожаловать в головоломку Куротто.\n");
    printf("Задача головоломки: определить цвет ячеек головоломки (черный или белый) по правилам.\n");
    printf("Вот правила игры:\n");
    printf("Черные ячейки образуют области, соприкасаясь по горизонтали и по вертикали.\n");
    printf("Число внутри кружка равняется количеству черных ячеек, содержащихся во всех соприкасающихся с ним областях.\n");
    printf("Если внутри кружка нет числа, с ним могут соприкасаться области черных ячеек любой площади.\n");

    do {
        printf("Выберите действие:\n");
        printf("1. Создать случайное игровое поле\n");
        printf("2. Заполнить игровое поле вручную\n");
        printf("3. Выбрать уровень сложности\n");
        printf("4. Выйти\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Выберите уровень сложности (1 - Легкий, 2 - Средний, 3 - Тяжелый): ");
            scanf("%d", &difficulty);
            size = calculateGridSize(difficulty);
            int** grid = (int**)malloc(size * sizeof(int*));
            for (int i = 0; i < size; i++) {
                grid[i] = (int*)malloc(size * sizeof(int));
            }
            createRandomGrid(grid, size, difficulty);
            writeGridToFile(grid, size); // Записываем сгенерированное игровое поле в файл
            break;
        case 2:
            printf("Выберите уровень сложности (1 - Легкий, 2 - Средний, 3 - Тяжелый): ");
            scanf("%d", &difficulty);
            size = calculateGridSize(difficulty);
            int** manualGrid = (int**)malloc(size * sizeof(int*));
            for (int i = 0; i < size; i++) {
                manualGrid[i] = (int*)malloc(size * sizeof(int));
            }
            fillGridManually(manualGrid, size);
            writeGridToFile(manualGrid, size); // Записываем заполненное вручную игровое поле в файл
            break;
        case 3:
            printf("Выберите уровень сложности (1 - Легкий, 2 - Средний, 3 - Тяжелый): ");
            scanf("%d", &difficulty);
            break;
        case 4:
            printf("Игра окончена.\nДо свидания.\n");
            break;
        default:
            printf("Неверный выбор. Попробуйте снова.\n");
        }
    } while (choice != 4);

    return 0;
}