FROM python:3.8-slim
WORKDIR /app

RUN pip3 install flask
COPY . .
EXPOSE 5000
CMD ["python3", "main.py"]
