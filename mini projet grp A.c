#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Déclaration des variables globales
int points = 0;
char nomJoueur[50];

// Fonction pour sauvegarder le score avec la date et l'heure
void sauvegarderScore(const char *nom, int score) {
    FILE *fichier = fopen("scores.txt", "a");
    if (fichier == NULL) {
        printf("Erreur : Impossible d'ouvrir scores.txt\n");
        return;
    }

    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    char date[20];
    strftime(date, sizeof(date), "%Y-%m-%d %H:%M:%S", tm_info);

    fprintf(fichier, "%s %d %s\n", nom, score, date);
    fclose(fichier);
}

// Fonction pour charger le score d'un utilisateur
int chargerScore(const char *nom) {
    FILE *fichier = fopen("scores.txt", "r");
    if (fichier == NULL) {
        return 0;
    }

    char nomFichier[50];
    int score, meilleurScore = 0;
    char date[20];

    while (fscanf(fichier, "%s %d %[^\n]", nomFichier, &score, date) != EOF) {
        if (strcmp(nomFichier, nom) == 0 && score > meilleurScore) {
            meilleurScore = score;
        }
    }

    fclose(fichier);
    return meilleurScore;
}

// Affichage du menu principal
void afficherMenu() {
    printf("\n+-----------------------------------+\n");
    printf("|1 : Addition                       |\n");
    printf("|2 : Soustraction                   |\n");
    printf("|3 : Multiplication                 |\n");
    printf("|4 : Tables des multiplications     |\n");
    printf("|5 : Divisions                      |\n");
    printf("|6 : Ordre des nombres              |\n");
    printf("|7 : Operations multiples           |\n");
    printf("|0 : Sortir du jeu                  |\n");
    printf("+-----------------------------------+\n");
    printf("Quel est votre choix ? ");
}

// Mini-jeu : Addition
void addition() {
    int a, b, reponse, essais = 0;
    srand(time(NULL));
    a = rand() % 101;
    b = rand() % 101;

    printf("Addition\n");
    printf("%d + %d = ?\n", a, b);

    do {
        printf("Entrez le resultat : ");
        scanf("%d", &reponse);
        essais++;

        if (reponse == a + b) {
            printf("Bravo !\n");
            if (essais == 1) points += 10;
            else if (essais == 2) points += 5;
            else if (essais == 3) points += 1;
            sauvegarderScore(nomJoueur, points);
            return;
        } else {
            printf("Mauvaise reponse. Essayez encore !\n");
        }
    } while (essais < 3);

    printf("Perdu ! La bonne reponse est %d.\n", a + b);
}

// Mini-jeu : Soustraction
void soustraction() {
    int a, b, reponse, essais = 0;
    srand(time(NULL));
    a = rand() % 101;
    b = rand() % 101;

    if (a < b) {
        int temp = a;
        a = b;
        b = temp;
    }

    printf("Soustraction\n");
    printf("%d - %d = ?\n", a, b);

    do {
        printf("Entrez le resultat : ");
        scanf("%d", &reponse);
        essais++;

        if (reponse == a - b) {
            printf("Bravo !\n");
            if (essais == 1) points += 10;
            else if (essais == 2) points += 5;
            else if (essais == 3) points += 1;
            sauvegarderScore(nomJoueur, points);
            return;
        } else {
            printf("Mauvaise reponse. Essayez encore !\n");
        }
    } while (essais < 3);

    printf("Perdu ! La bonne reponse est %d.\n", a - b);
}

// Mini-jeu : Multiplication
void multiplication() {
    int a, b, reponse, essais = 0;
    srand(time(NULL));
    a = rand() % 11;
    b = rand() % 11;

    printf("Multiplication\n");
    printf("%d * %d = ?\n", a, b);

    do {
        printf("Entrez le resultat : ");
        scanf("%d", &reponse);
        essais++;

        if (reponse == a * b) {
            printf("Bravo !\n");
            if (essais == 1) points += 10;
            else if (essais == 2) points += 5;
            else if (essais == 3) points += 1;
            sauvegarderScore(nomJoueur, points);
            return;
        } else {
            printf("Mauvaise reponse. Essayez encore !\n");
        }
    } while (essais < 3);

    printf("Perdu ! La bonne reponse est %d.\n", a * b);
}

// Mini-jeu : Tables des multiplications
void tablesMultiplication() {
    int table, i, reponse, essais = 0;

    printf("Choisissez une table de multiplication (1 a 10) : ");
    scanf("%d", &table);

    if (table < 1 || table > 10) {
        printf("Choix invalide !\n");
        return;
    }

    printf("Table de %d :\n", table);
    for (i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", table, i, table * i);
    }

    printf("\nEssayez maintenant !\n");
    for (i = 1; i <= 10; i++) {
        printf("%d x %d = ? ", table, i);
        scanf("%d", &reponse);
        essais++;

        if (reponse == table * i) {
            printf("Correct !\n");
            if (essais == 1) points += 10;
            else if (essais == 2) points += 5;
            else if (essais == 3) points += 1;
            sauvegarderScore(nomJoueur, points);
        } else {
            printf("Perdu ! La bonne reponse est %d.\n", table * i);
        }
    }
}

// Mini-jeu : Division
void divisions() {
    int a, b, reponse, essais = 0;
    srand(time(NULL));
    b = rand() % 10 + 1;
    a = b * (rand() % 11);

    printf("Divisions\n");
    printf("%d / %d = ?\n", a, b);

    do {
        printf("Entrez le resultat : ");
        scanf("%d", &reponse);
        essais++;

        if (reponse == a / b) {
            printf("Bravo !\n");
            if (essais == 1) points += 10;
            else if (essais == 2) points += 5;
            else if (essais == 3) points += 1;
            sauvegarderScore(nomJoueur, points);
            return;
        } else {
            printf("Mauvaise reponse. Essayez encore !\n");
        }
    } while (essais < 3);

    printf("Perdu ! La bonne reponse est %d.\n", a / b);
}

// Mini-jeu : Ordre des nombres
void ordreNombres() {
    int i, j, temp, essais = 0;
    int nombres[5], copie[5], reponse[5];

    srand(time(NULL));
    printf("Ordre des nombres\n");

    for (i = 0; i < 5; i++) {
        nombres[i] = rand() % 100;
        copie[i] = nombres[i];
        printf("%d ", nombres[i]);
    }
    printf("\n");

    for (i = 0; i < 5; i++) {
        for (j = i + 1; j < 5; j++) {
            if (copie[i] > copie[j]) {
                temp = copie[i];
                copie[i] = copie[j];
                copie[j] = temp;
            }
        }
    }

    do {
        printf("Entrez les nombres dans l ordre croissant : ");
        for (i = 0; i < 5; i++) {
            scanf("%d", &reponse[i]);
        }

        essais++;

        int correct = 1;
        for (i = 0; i < 5; i++) {
            if (reponse[i] != copie[i]) {
                correct = 0;
                break;
            }
        }

        if (correct) {
            printf("Bravo !\n");
            if (essais == 1) points += 10;
            else if (essais == 2) points += 5;
            else if (essais == 3) points += 1;
            sauvegarderScore(nomJoueur, points);
            return;
        } else {
            printf("Mauvaise reponse. Essayez encore !\n");
        }

    } while (essais < 3);

    printf("Perdu ! La bonne reponse est : ");
    for (i = 0; i < 5; i++) {
        printf("%d ", copie[i]);
    }
    printf("\n");
}

// Mini-jeu : Operations multiples
void operationsMultiples() {
    int a, b, c, d, result, reponse, essais = 0;
    char op1, op2, op3;

    srand(time(NULL));

    a = rand() % 101;
    b = rand() % 101;
    c = rand() % 101;
    d = rand() % 101;

    char ops[] = {'+', '-', '*'};
    op1 = ops[rand() % 3];
    op2 = ops[rand() % 3];
    op3 = ops[rand() % 3];

    printf("Calcul : %d %c %d %c %d %c %d = ?\n", a, op1, b, op2, c, op3, d);

    int tab[4] = {a, b, c, d};
    char opsFinal[3] = {op1, op2, op3};

    for (int i = 0; i < 3; i++) {
        if (opsFinal[i] == '*') {
            tab[i] = tab[i] * tab[i + 1];
            for (int j = i + 1; j < 3; j++) {
                tab[j] = tab[j + 1];
                opsFinal[j - 1] = opsFinal[j];
            }
            i--;
        }
    }

    result = tab[0];
    for (int i = 0; i < 2; i++) {
        if (opsFinal[i] == '+') result += tab[i + 1];
        else if (opsFinal[i] == '-') result -= tab[i + 1];
    }

    do {
        printf("Entrez le resultat : ");
        scanf("%d", &reponse);
        essais++;

        if (reponse == result) {
            printf("Bravo !\n");
            if (essais == 1) points += 10;
            else if (essais == 2) points += 5;
            else if (essais == 3) points += 1;

            sauvegarderScore(nomJoueur, points);
            return;
        } else {
            printf("Mauvaise reponse. Essayez encore !\n");
        }
    } while (essais < 3);

    printf("Perdu ! La bonne reponse est %d.\n", result);
}

// Fonction principale
int main() {
    int choix;

    printf("Entrez votre nom : ");
    scanf("%s", nomJoueur);

    points = chargerScore(nomJoueur);
    printf("Bienvenue %s ! Votre score actuel est de %d points.\n", nomJoueur, points);

    do {
        afficherMenu();
        if (scanf("%d", &choix) != 1) {
            printf("Entree invalide. Veuillez entrer un nombre.\n");
            while (getchar() != '\n');
            choix = -1;
        }

        switch (choix) {
            case 1: addition(); break;
            case 2: soustraction(); break;
            case 3: multiplication(); break;
            case 4: tablesMultiplication(); break;
            case 5: divisions(); break;
            case 6: ordreNombres(); break;
            case 7: operationsMultiples(); break;
            case 0:
                printf("Merci de votre visite. Vous avez accumule %d points !\n", points);
                break;
            default:
                printf("Choix invalide, veuillez recommencer.\n");
        }
    } while (choix != 0);

    return 0;
}
