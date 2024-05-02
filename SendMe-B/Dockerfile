FROM ubuntu:18.04 as builder

RUN apt-get update && apt-get upgrade -y && \
  apt-get install -y build-essential

RUN mkdir -p /workdir

WORKDIR /workdir

COPY ./main.c /workdir/main.c

RUN gcc main.c -o cow -fno-stack-protector -O0

FROM pwn.red/jail

COPY --from=ubuntu:18.04 / /srv
COPY --from=builder /workdir/cow /srv/app/run


