FROM python:slim AS app
RUN pip install --no-cache-dir progress

FROM pwn.red/jail
COPY --from=app / /srv
COPY ./challenge.py /srv/app/run

RUN chmod +x /srv/app/run

ENV JAIL_MEM=20M JAIL_POW=0 JAIL_ENV_NUM=5
