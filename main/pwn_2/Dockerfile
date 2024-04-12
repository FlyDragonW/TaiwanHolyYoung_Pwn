FROM alpine

RUN apk add --no-cache python3 py3-pip socat

RUN mkdir -p /chal
WORKDIR /chal

COPY ./src /chal

CMD ["socat", "TCP-LISTEN:10000,fork", "EXEC:'timeout 60 ./bof_var'"]
