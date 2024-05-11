from flask import Flask, render_template, request, Blueprint
import json, os

internal_api = Blueprint('api_v1', __name__)

@internal_api.route('/ping', methods=['POST'])
def ping():
    req_data = json.loads(request.data)
    cmd = req_data["host"]
    
    if " " in cmd or "%20" in cmd:
        os.system("ping -c 1 " + cmd)  

        data = {
            "command": "Non sono permessi spazi negli url!",
            "result": "Success"
        }
    else:
        data = {
            "command": "ping -c 1 " + cmd,
            "result": "Error"
        }

    return data 
    