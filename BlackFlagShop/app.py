from flask import Flask, request, render_template, redirect, url_for
from database import init_database, Database

init_database()

app = Flask(
    import_name = __name__,
    static_folder = 'webui/static_source',
    template_folder = 'webui/template_source'
)

@app.route('/', methods=["GET"])
def _home():
    data = Database()
    return render_template(
        'shop.html',
        title = 'Black Flags Shop',
        navigator = [{"label": "Shop","route": "/"},{"label": "Admin Research","route": "/searchbar"}],
        items = data.select(['nome', 'immagine', 'descrizione'], "nome <> 'Flag'")
    )

@app.route('/searchbar', methods=["GET"])
def _searchebar():
    return render_template(
        'ricerca.html',
        title = 'Black Flags Search',
        navigator = [{"label": "Shop","route": "/"},{"label": "Admin Research","route": "/searchbar"}]
    )


@app.route('/research', methods=["POST"])
def _parsequery():
    try:
        data = Database()
        return data.select(
            ['nome', 'immagine'],
            f"nome LIKE '%{ request.data.decode() }%' AND  nome <> 'Flag'"
        )
    except:
        return "Secondo me stai facendo gabole strane !", 500


app.run(host="0.0.0.0")
