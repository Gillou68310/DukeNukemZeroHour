FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

COPY requirements.txt /pip3/
WORKDIR /pip3

RUN apt update \
    && apt install -yq \
    make \
    git \
    build-essential \
    binutils-mips-linux-gnu \
    cpp-mips-linux-gnu \
    gcc-mips-linux-gnu \
    python3 \
    python3-pip \
    curl \
    gdb \
    && rm -rf /var/lib/apt/lists/*

RUN pip3 install --upgrade pip
RUN pip3 install -U splat64[mips]
RUN pip3 install -r requirements.txt

RUN mkdir /dukenukemzerohour
WORKDIR /dukenukemzerohour