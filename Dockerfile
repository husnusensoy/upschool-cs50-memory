FROM ubuntu:20.04

ENV TZ=Europe/Istanbul
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

RUN apt-get update && apt-get install -y build-essential valgrind &&  apt-get clean && apt-get autoremove

WORKDIR /code