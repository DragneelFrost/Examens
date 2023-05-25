class User:
    def __init__(self, username, email):
        self.username = username
        self.email = email


class Novice(User):
    def __init__(self, username, email, level):
        super().__init__(username, email)
        self.level = level