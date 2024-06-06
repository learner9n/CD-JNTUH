#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void pm();
void plus();
void divide();

int i, ch, j, l, addr = 100;
char expression[10], exp[10], exp1[10], exp2[10], id1[5], op[5], id2[5];

char* strrev(char* str) {
    if (!str || !*str) {
        return str;
    }
    int i = strlen(str) - 1, j = 0;
    char ch;
    while (i > j) {
        ch = str[i];
        str[i] = str[j];
        str[j] = ch;
        i--;
        j++;
    }
    return str;
}

int main() {
    // clrscr(); // Not needed in most modern compilers, commenting out.

    while (1) {
        printf("\n1.assignment\n2.arithmetic\n3.relational\n4.Exit\nEnter the choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\nEnter the expression with assignment operator: ");
                scanf("%s", exp);
                l = strlen(exp);
                exp2[0] = '\0';
                i = 0;
                while (exp[i] != '=') {
                    i++;
                }
                strncat(exp2, exp, i);
                strrev(exp);
                exp1[0] = '\0';
                strncat(exp1, exp, l - (i + 1));
                strrev(exp1);
                printf("Three address code:\ntemp = %s\n%s = temp\n", exp1, exp2);
                break;
            case 2:
                printf("\nEnter the expression with arithmetic operator: ");
                scanf("%s", expression);
                strcpy(exp, expression);
                l = strlen(exp);
                exp1[0] = '\0';
                for (i = 0; i < l; i++) {
                    if (exp[i] == '+' || exp[i] == '-') {
                        if (exp[i + 2] == '/' || exp[i + 2] == '*') {
                            pm();
                            break;
                        } else {
                            plus();
                            break;
                        }
                    } else if (exp[i] == '/' || exp[i] == '*') {
                        divide();
                        break;
                    }
                }
                break;
            case 3:
                printf("Enter the expression with relational operator: ");
                scanf("%s %s %s", id1, op, id2);
                if (strcmp(op, "<") == 0 || strcmp(op, ">") == 0 || strcmp(op, "<=") == 0 || strcmp(op, ">=") == 0 || strcmp(op, "==") == 0 || strcmp(op, "!=") == 0) {
                    printf("\n%d if %s %s %s goto %d", addr, id1, op, id2, addr + 3);
                    addr++;
                    printf("\n%d T := 0", addr);
                    addr++;
                    printf("\n%d goto %d", addr, addr + 2);
                    addr++;
                    printf("\n%d T := 1", addr);
                    addr++;
                } else {
                    printf("Expression is error");
                }
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.");
                break;
        }
    }

    return 0;
}

void pm() {
    strrev(exp);
    j = l - i - 1;
    strncat(exp1, exp, j);
    strrev(exp1);
    printf("Three address code:\ntemp = %s\ntemp1 = %c%ctemp\n", exp1, exp[j + 1], exp[j]);
}

void divide() {
    strncat(exp1, exp, i + 2);
    printf("Three address code:\ntemp = %s\ntemp1 = temp %c%c\n", exp1, exp[i + 2], exp[i + 3]);
}

void plus() {
    strncat(exp1, exp, i + 2);
    printf("Three address code:\ntemp = %s\ntemp1 = temp %c%c\n", exp1, exp[i + 2], exp[i + 3]);
}

