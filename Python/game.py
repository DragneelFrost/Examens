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