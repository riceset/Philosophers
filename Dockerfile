FROM ubuntu:latest

RUN apt-get update
RUN apt-get install -y \
build-essential \
gdb \
valgrind

WORKDIR /usr/src/philosophers

COPY . /usr/src/philosophers

RUN make
