FROM ubuntu:latest

RUN apt-get update && apt-get upgrade -y
#RUN apt-get install -y gcc

RUN mkdir app

WORKDIR /app

COPY ./server ./server
COPY ./views/ ./views/

RUN chmod +x ./server

CMD ["./server"]
