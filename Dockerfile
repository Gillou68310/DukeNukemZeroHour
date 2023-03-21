FROM ubuntu:20.04 as build

ENV DEBIAN_FRONTEND=noninteractive

COPY requirements.txt /pip3/
COPY tools/splat/requirements.txt /pip3/tools/splat/
WORKDIR /pip3

RUN apt update
RUN apt install -yq make git build-essential binutils-mips-linux-gnu cpp-mips-linux-gnu gcc-mips-linux-gnu python3 python3-pip
RUN pip3 install --upgrade pip
RUN pip3 install -r requirements.txt

RUN mkdir /dukenukemzerohour
WORKDIR /dukenukemzerohour