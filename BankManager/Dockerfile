FROM ubuntu:18.04 as builder

RUN apt-get update && apt-get upgrade -y && \
  apt-get install -y build-essential

RUN mkdir -p /workdir

WORKDIR /workdir

COPY ./main.c /workdir/main.c
COPY ./accounts.txt /workdir/accounts.txt

RUN gcc main.c -o main

FROM pwn.red/jail

COPY --from=ubuntu:18.04 / /srv
COPY --from=builder /workdir/main /srv/app/run
COPY --from=builder /workdir/accounts.txt /srv/app/accounts.txt
