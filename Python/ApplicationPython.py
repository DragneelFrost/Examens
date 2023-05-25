from user import User
from game import Game

class Game:
    def __init__(self, title, description, genre, platform, actors, director):
        self.title = title
        self.description = description
        self.genre = genre
        self.platform = platform
        self.actors = actors
        self.director = director
        self.reviews = []  # Liste des critiques associées au jeu

    def add_review(self, review):
        self.reviews.append(review)


class Movie(Game):
    def __init__(self, title, description, genre, platform, actors, director, duration):
        super().__init__(title, description, genre, platform, actors, director)
        self.duration = duration


class Genre:
    def __init__(self, name):
        self.name = name
        self.games = []  # Liste des jeux associés à ce genre

    def add_game(self, game):
        self.games.append(game)


class Review:
    def __init__(self, content, rating, user):
        self.content = content
        self.rating = rating
        self.user = user


class User:
    def __init__(self, username, email):
        self.username = username
        self.email = email


class Novice(User):
    def __init__(self, username, email, level):
        super().__init__(username, email)
        self.level = level


class Application:
    def __init__(self):
        self.gameList = []  # Liste des jeux
        self.userList = []  # Liste des utilisateurs

    def add_game(self):
        print("----- Ajouter un jeu -----")
        # Logique pour ajouter un jeu

    def modify_game(self):
        print("----- Modifier un jeu -----")
        # Logique pour modifier un jeu

    def delete_game(self):
        print("----- Supprimer un jeu -----")
        # Logique pour supprimer un jeu

    def display_games(self):
        print("----- Afficher les jeux -----")
        if not self.gameList:
            print("Aucun jeu n'a été ajouté.")
        else:
            print("Liste des jeux :")
            for index, game in enumerate(self.gameList):
                print(f"{index}. {game.title}")

    def search_game(self):
        print("----- Rechercher un jeu -----")
        # Logique pour rechercher un jeu

    def add_review(self):
        print("----- Ajouter une critique -----")
        # Logique pour ajouter une critique

    def add_user(self):
        print("----- Ajouter un utilisateur -----")
        # Logique pour ajouter un utilisateur

    def menu(self):
        while True:
            print("----- Menu -----")
            print("1. Ajouter un jeu")
            print("2. Modifier un jeu")
            print("3. Supprimer un jeu")
            print("4. Afficher les jeux")
            print("5. Rechercher un jeu")
            print("6. Ajouter une critique")
            print("7. Ajouter un utilisateur")
            print("8. Quitter")

            choice = input("Choix : ")

            if choice == "1":
                self.add_game()
            elif choice == "2":
                self.modify_game()
            elif choice == "3":
                self.delete_game()
            elif choice == "4":
                self.display_games()
            elif choice == "5":
                self.search_game()
            elif choice == "6":
                self.add_review()
            elif choice == "7":
                self.add_user()
            elif choice == "8":
                print("Merci d'avoir utilisé l'application. Au revoir!")
                break
            else:
                print("Choix invalide. Veuillez réessayer.")


# Programme principal
app = Application()
app.menu()
