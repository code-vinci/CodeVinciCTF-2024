from flask import Flask

app = Flask(__name__)

@app.route('/', methods=['CODEVINCI'])
def code_vinci():
    return 'CodeVinciCTF{m1_p14cc10n0_qu3st1_nu0v1_m3t0d1_HTTP}'

@app.route('/')
def other_requests():
    return 'PERCHÉ NON MI FAI RICHIESTE CON IL METODO "CODEVINCI" 😠😠😠😠😠'

if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0')
