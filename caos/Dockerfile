FROM pwn.red/jail as base

COPY --from=ubuntu:22.04 / /srv
COPY ./caos /srv/app/run