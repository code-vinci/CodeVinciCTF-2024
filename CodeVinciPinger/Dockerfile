FROM python:3.12

WORKDIR /app
RUN pip install --no-cache-dir flask

COPY . .

EXPOSE 5000

CMD ["python3", "./run.py"]
