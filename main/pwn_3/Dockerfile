FROM ubuntu:20.04

RUN apt-get update && \
    apt-get install -y socat

RUN mkdir -p /chal
WORKDIR /chal

COPY ./src /chal

CMD ["socat", "TCP-LISTEN:10002,fork", "EXEC:'timeout 60 ./ret2text'"]
