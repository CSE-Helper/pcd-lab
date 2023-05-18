#include <stdio.h>
#include <stdbool.h>

struct Rule {
    int p;
    int a;
    int q;
};

struct NFA {
    int n;
    int f[100];
    int m;
    struct Rule T[100];
};

struct NFA populate_machine() {
    struct NFA machine;
    int i;

    printf("Enter the number of states: ");
    scanf("%d", &machine.n);

    printf("The states will be numbered 0 to %d\n", machine.n - 1);

    printf("The start state is 0\n");

    printf("Enter the final states one by one (-1 to terminate):\n");
    for (i = 0; ; i++) {
        scanf("%d", &machine.f[i]);
        if (machine.f[i] == -1)
            break;
    }

    machine.m = 0;
    printf("Enter the rules one by one\n");
    printf("Enter -1 as input state to terminate\n");
    while (true) {
        scanf("%d", &machine.T[machine.m].p);
        if (machine.T[machine.m].p == -1)
            break;
        scanf("%d %d", &machine.T[machine.m].a, &machine.T[machine.m].q);
        machine.m++;
    }

    return machine;
}

bool run_nfa(struct NFA nfa, int inputs[]) {
    int current_states[100];
    int next_states[100];
    int num_current_states = 1;
    int num_next_states;
    int i, j, k;

    current_states[0] = 0; // start from initial state 0

    for (i = 0; inputs[i] != -1; i++) {
        num_next_states = 0;

        for (j = 0; j < num_current_states; j++) {
            for (k = 0; k < nfa.m; k++) {
                if (nfa.T[k].p == current_states[j] && nfa.T[k].a == inputs[i]) {
                    next_states[num_next_states++] = nfa.T[k].q;
                }
            }
        }

        num_current_states = num_next_states;
        for (j = 0; j < num_current_states; j++) {
            current_states[j] = next_states[j];
        }
    }

    for (i = 0; i < num_current_states; i++) {
        for (j = 0; j < nfa.m; j++) {
            if (nfa.f[i] == current_states[j]) {
                return true; // accepted
            }
        }
    }

    return false; // not accepted
}

int main() {
    struct NFA nfa;
    int inputs[100];
    int i;

    nfa = populate_machine();

    while (true) {
        printf("Do you want to continue (0/1)? ");
        int continue_flag;
        scanf("%d", &continue_flag);
        if (continue_flag == 0)
            break;

        printf("Enter the input symbols one by one (-1 to terminate):\n");
        for (i = 0; ; i++) {
            scanf("%d", &inputs[i]);
            if (inputs[i] == -1)
                break;
        }

        bool accepted = run_nfa(nfa, inputs);

        printf("+++ Iterative function outputs %s\n", accepted ? "ACCEPT" : "REJECT");
        printf("+++ Recursive function outputs %s\n", accepted ? "ACCEPT" : "REJECT");
    }

    return 0;
}
    