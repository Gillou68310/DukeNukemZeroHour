FROM ubuntu:20.04 as build

ENV DEBIAN_FRONTEND=noninteractive

COPY requirements.txt /pip3/
WORKDIR /pip3

RUN apt update
RUN apt install -yq make git build-essential binutils-mips-linux-gnu cpp-mips-linux-gnu gcc-mips-linux-gnu python3 python3-pip curl gdb
RUN sh -c '(curl https://practicerom.com/public/packages/debian/pgp.pub || wget -O - https://practicerom.com/public/packages/debian/pgp.pub) | apt-key add - && echo deb http://practicerom.com/public/packages/debian staging main >/etc/apt/sources.list.d/practicerom.list && apt update'
RUN apt install -yq n64-ultra
RUN pip3 install --upgrade pip
RUN pip3 install -U splat64[mips]
RUN pip3 install -r requirements.txt

RUN mkdir /dukenukemzerohour
WORKDIR /dukenukemzerohour