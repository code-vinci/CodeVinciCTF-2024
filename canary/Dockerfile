FROM pwn.red/jail as base

COPY --from=ubuntu:22.04 / /srv
COPY ./canary /srv/app/run
COPY ./logo.txt /srv/app/logo.txt

RUN chmod +x /srv/app/run
