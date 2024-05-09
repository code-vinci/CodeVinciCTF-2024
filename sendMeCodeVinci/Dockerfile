FROM python:3.9

WORKDIR /app
RUN pip install --no-cache-dir flask

COPY ./main.py ./main.py

EXPOSE 5000

CMD ["python", "main.py"]
