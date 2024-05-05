FROM ubuntu:latest

USER root

RUN apt-get update && apt-get install -y gcc

RUN mkdir app

WORKDIR /app

COPY main.c .
COPY lib/ ./lib/
COPY views/ ./views/

RUN gcc -o server main.c

RUN chmod +x ./server

CMD ["./server"]
