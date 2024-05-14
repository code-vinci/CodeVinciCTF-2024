FROM python:3.9

WORKDIR /app
RUN pip install --no-cache-dir flask databases

COPY . .

EXPOSE 5000

CMD ["python", "app.py"]
