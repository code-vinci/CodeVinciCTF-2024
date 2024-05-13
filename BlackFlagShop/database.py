import sqlite3

def init_database():
    connection = sqlite3.connect('navi.db')
    cursor = connection.cursor()

    cursor.execute("SELECT name FROM sqlite_master WHERE type='table' AND name='navi'")
    table_exists = cursor.fetchone()

    if not table_exists:
        cursor.execute('''CREATE TABLE IF NOT EXISTS navi (
                            id INTEGER PRIMARY KEY,
                            nome TEXT NOT NULL,
                            immagine TEXT NOT NULL,
                            descrizione TEXT NOT NULL
                        )''')

        cursor.execute("INSERT INTO navi (id, nome, immagine, descrizione) VALUES (1, 'Odin 1365', '_d774cf20-fca9-4826-af29-937bf32c965e.png', 'Bellissima caravella del 1365')")
        cursor.execute("INSERT INTO navi (id, nome, immagine, descrizione) VALUES (2, 'Flag', '_9h06eu_f340fes_8sdgs_e66_7yf64at_r3f42.png', 'Credi sia così facile ?')")
        cursor.execute("INSERT INTO navi (id, nome, immagine, descrizione) VALUES (3, 'Thor 1455', '_3b4031e0-e5c1-4f17-82ae-b8a266870b5c.png', 'Galeone spagnolo del 1455')")
        cursor.execute("INSERT INTO navi (id, nome, immagine, descrizione) VALUES (4, 'Lorena 1255', '_dcb3f12b-f521-46f2-a291-0c646150c39c.png', 'Galeone Imperiale del 1255')")
        cursor.execute("INSERT INTO navi (id, nome, immagine, descrizione) VALUES (5, 'Luana 1611', '_dcb4b516-b97c-4cfa-820b-cbfd34a658fb.png', 'Nave di un ricco mercante risalente al 1611')")

        connection.commit()

    cursor.close()
    connection.close()

class Database:
    def __init__(self):
        self.connection = sqlite3.connect('navi.db')
        self.cursor = self.connection.cursor()

    def select( self, colonne:list[str], condizione:str ):
        return  [
            dict(zip(colonne, row))
            for row in
            self.cursor.execute(f"SELECT { ', '.join(colonne) } FROM navi WHERE {condizione};").fetchall()
        ]

    def __del__(self):
        self.cursor.close()
        self.connection.close()