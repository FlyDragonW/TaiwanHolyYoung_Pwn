FROM alpine

RUN apk add --no-cache python3 py3-pip socat

RUN mkdir -p /chal
WORKDIR /chal

COPY ./src /chal

CMD ["socat", "TCP-LISTEN:20000,fork", "EXEC:'timeout 30 python3 server.py'"]
