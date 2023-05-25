#include <stdio.h>
#include <string.h>

#define MAX_GAMES 100

// Structure de données pour un jeu
struct Game {
    char title[100];
    char description[500];
    char genre[50];
    char platform[50];
    char actors[200];
    char director[100];
};

struct Game games[MAX_GAMES];
int gameCount = 0;

// Fonction pour ajouter un jeu
void addGame() {
    printf("----- Ajouter un jeu -----\n");

    if (gameCount == MAX_GAMES) {
        printf("La limite du nombre de jeux a été atteinte.\n");
        return;
    }

    struct Game newGame;

    printf("Titre : ");
    fgets(newGame.title, sizeof(newGame.title), stdin);

    printf("Description : ");
    fgets(newGame.description, sizeof(newGame.description), stdin);

    printf("Genre : ");
    fgets(newGame.genre, sizeof(newGame.genre), stdin);

    printf("Plateforme : ");
    fgets(newGame.platform, sizeof(newGame.platform), stdin);

    printf("Acteurs : ");
    fgets(newGame.actors, sizeof(newGame.actors), stdin);

    printf("Réalisateur : ");
    fgets(newGame.director, sizeof(newGame.director), stdin);

    games[gameCount] = newGame;
    gameCount++;

    printf("Le jeu a été ajouté avec succès.\n");
}

// Fonction pour modifier un jeu
void modifyGame() {
    printf("----- Modifier un jeu -----\n");

    if (gameCount == 0) {
        printf("Aucun jeu n'a été ajouté.\n");
        return;
    }

    int index;
    printf("Indice du jeu à modifier : ");
    scanf("%d", &index);
    getchar(); // Pour consommer le caractère de nouvelle ligne

    if (index < 1 || index > gameCount) {
        printf("Indice invalide.\n");
        return;
    }

    struct Game modifiedGame;

    printf("Titre : ");
    fgets(modifiedGame.title, sizeof(modifiedGame.title), stdin);

    printf("Description : ");
    fgets(modifiedGame.description, sizeof(modifiedGame.description), stdin);

    printf("Genre : ");
    fgets(modifiedGame.genre, sizeof(modifiedGame.genre), stdin);

    printf("Plateforme : ");
    fgets(modifiedGame.platform, sizeof(modifiedGame.platform), stdin);

    printf("Acteurs : ");
    fgets(modifiedGame.actors, sizeof(modifiedGame.actors), stdin);

    printf("Réalisateur : ");
    fgets(modifiedGame.director, sizeof(modifiedGame.director), stdin);

    games[index - 1] = modifiedGame;

    printf("Le jeu a été modifié avec succès.\n");
}

// Fonction pour supprimer un jeu
void deleteGame() {
    printf("----- Supprimer un jeu -----\n");

    if (gameCount == 0) {
        printf("Aucun jeu n'a été ajouté.\n");
        return;
    }

    displayGames();

    int index;
    printf("Indice du jeu à supprimer : ");
    scanf("%d", &index);
    getchar(); // Pour consommer le caractère de nouvelle ligne

    if (index < 1 || index > gameCount) {
        printf("Indice invalide. Veuillez réessayer.\n");
        return;
    }

    // Décaler les jeux suivants vers la gauche
    for (int i = index - 1; i < gameCount - 1; i++) {
        games[i] = games[i + 1];
    }

    gameCount--;

    printf("Le jeu a été supprimé avec succès.\n");
}

// Fonction pour afficher les jeux
void displayGames() {
    printf("----- Afficher les jeux -----\n");

    if (gameCount == 0) {
        printf("Aucun jeu n'a été ajouté.\n");
        return;
    }

    for (int i = 0; i < gameCount; i++) {
        printf("Jeu %d\n", i + 1);
        printf("Titre : %s", games[i].title);
        printf("Description : %s", games[i].description);
        printf("Genre : %s", games[i].genre);
        printf("Plateforme : %s", games[i].platform);
        printf("Acteurs : %s", games[i].actors);
        printf("Réalisateur : %s", games[i].director);
        printf("\n");
    }
}

// Fonction pour rechercher un jeu
void searchGame() {
    printf("----- Rechercher un jeu -----\n");

    if (gameCount == 0) {
        printf("Aucun jeu n'a été ajouté.\n");
        return;
    }

    char searchTitle[100];
    printf("Titre du jeu à rechercher : ");
    fgets(searchTitle, sizeof(searchTitle), stdin);

    int found = 0;

    for (int i = 0; i < gameCount; i++) {
        if (strcmp(searchTitle, games[i].title) == 0) {
            printf("Jeu trouvé :\n");
            printf("Titre : %s", games[i].title);
            printf("Description : %s", games[i].description);
            printf("Genre : %s", games[i].genre);
            printf("Plateforme : %s", games[i].platform);
            printf("Acteurs : %s", games[i].actors);
            printf("Réalisateur : %s", games[i].director);
            printf("\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Aucun jeu correspondant trouvé.\n");
    }
}

// Fonction pour afficher le menu
void displayMenu() {
    printf("----- Menu -----\n");
    printf("1. Ajouter un jeu\n");
    printf("2. Modifier un jeu\n");
    printf("3. Supprimer un jeu\n");
    printf("4. Afficher les jeux\n");
    printf("5. Rechercher un jeu\n");
    printf("6. Quitter\n");
}

int main() {
    int choice;

    do {
        displayMenu();
        printf("Choix : ");
        scanf("%d", &choice);
        getchar(); // Pour consommer le caractère de nouvelle ligne

        switch (choice) {
            case 1:
                addGame();
                break;
            case 2:
                modifyGame();
                break;
            case 3:
                deleteGame();
                break;
            case 4:
                displayGames();
                break;
            case 5:
                searchGame();
                break;
            case 6:
                printf("Merci d'avoir utilisé l'application. Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }

        printf("\n");
    } while (choice != 6);

    return 0;
}
