from flask import Flask, render_template, request, Blueprint
from api import internal_api

app = Flask(__name__, template_folder='./templates')
app.register_blueprint(internal_api, url_prefix='/api/v1')

@app.route("/")
def home():
    return render_template("index.html")

if __name__ == "__main__":
    app.run(debug=True, host="0.0.0.0")