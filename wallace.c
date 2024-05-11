#include <stdio.h>
#include <stdlib.h>

#define MACROCOLUMN_SIZE    7  /* The number of minicolumns in a macrocolumn */
#define MACROCOLUMN_SHAPE   6   /* The number of neighbors for each macrocolumn */

struct {
    int label;
    int state;
} typedef MiniColumn;

typedef struct MacroColumn {
    int label;
    MiniColumn *columns[MACROCOLUMN_SIZE];
    struct MacroColumn *neighbors[MACROCOLUMN_SHAPE];
} MacroColumn;

MiniColumn *make_minicolumn(int label);
MacroColumn *make_macrocolumn(int label);

void free_minicolumn(MiniColumn *c);
void free_macrocolumn(MacroColumn *c);

void print_mini(MiniColumn *c);
void print_macro(MacroColumn *c);

int main(void) {
    MacroColumn *test = make_macrocolumn(1);
    print_macro(test);

    free_macrocolumn(test);

    return 0;
}

void print_mini(MiniColumn *c) {
    printf("\tMini: %3d  State: %3d\n", c->label, c->state);
}

void print_macro(MacroColumn *c) {
    printf("Macro: %3d\n", c->label);
    for (int i = 0; i < MACROCOLUMN_SIZE; i++) {
        print_mini(c->columns[i]);
    }
}

MiniColumn *make_minicolumn(int label) {
    MiniColumn *output = malloc(sizeof(MiniColumn));

    output->label = label;
    output->state = 0;

    return output;
}

MacroColumn *make_macrocolumn(int label) {
    MacroColumn *output = malloc(sizeof(MacroColumn));

    output->label = label;

    for (int i = 0; i < MACROCOLUMN_SIZE; i++) {
        output->columns[i] = make_minicolumn(i);
    }

    return output;
}

void free_minicolumn(MiniColumn *c) {
    free(c);
}

void free_macrocolumn(MacroColumn *c) {
    for (int i = 0; i < MACROCOLUMN_SIZE; i++) {
        free_minicolumn(c->columns[i]);
    }
    free(c);
}

















